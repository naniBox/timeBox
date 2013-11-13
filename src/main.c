/*
	kuroBox / naniBox
	Copyright (c) 2013
	david morris-oliveros // naniBox.com

    This file is part of kuroBox / naniBox.

    kuroBox / naniBox is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    kuroBox / naniBox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/


#include <ch.h>
#include <hal.h>
#include <string.h>
#include <chprintf.h>
#include <chrtclib.h>
#include "ltc_time.h"
#include "seg77.h"

//-----------------------------------------------------------------------------
#define CALIBRATION_MODE

//-----------------------------------------------------------------------------
#define DISPLAY_TIMEOUT 5000

#define prnt ((BaseSequentialStream *)&SD1)

//-----------------------------------------------------------------------------
static uint8_t DISPLAY_MAP[] = {0xee, 0x82, 0xdc, 0xd6, 0xb2, 0x76, 0x7e, 0xc2, 0xfe, 0xf6}; // 77seg driver shifter
#define DECIMAL_POINT 0x01
#define DASH 0x10
static uint8_t display_data[8];
static bool_t valid_timecode;
smpte_timecode_t linear_timecode;
void btn_1_exti_cb(EXTDriver *extp, expchannel_t channel);
void pps_cb(EXTDriver *extp, expchannel_t channel);
bool_t btn_1_pressed;
static VirtualTimer display_off_vt;

extern uint16_t this_edge_time;
extern uint32_t timediff;
extern uint16_t this_edge_time_s;
extern uint32_t timediff_s;
extern uint16_t this_edge_time_l;
extern uint32_t timediff_l;
extern uint16_t this_edge_time_o;
extern uint32_t timediff_o;

//-----------------------------------------------------------------------------
static const EXTConfig extcfg = {
  {
	{EXT_CH_MODE_BOTH_EDGES | EXT_CH_MODE_AUTOSTART | EXT_MODE_GPIOA, btn_1_exti_cb},	// 0
	{EXT_CH_MODE_BOTH_EDGES | EXT_CH_MODE_AUTOSTART | EXT_MODE_GPIOA, ltc_exti_cb},	// 1
    {EXT_CH_MODE_DISABLED, NULL},	// 2
    {EXT_CH_MODE_DISABLED, NULL},	// 3
#ifdef CALIBRATION_MODE
	{EXT_CH_MODE_FALLING_EDGE | EXT_CH_MODE_AUTOSTART | EXT_MODE_GPIOA, pps_cb},	// 4
#else
    {EXT_CH_MODE_DISABLED, NULL},	// 4
#endif
    {EXT_CH_MODE_DISABLED, NULL},	// 5
    {EXT_CH_MODE_DISABLED, NULL},	// 6
    {EXT_CH_MODE_DISABLED, NULL},	// 7
    {EXT_CH_MODE_DISABLED, NULL},	// 8
	{EXT_CH_MODE_DISABLED, NULL},	// 9
    {EXT_CH_MODE_DISABLED, NULL},	// 10
    {EXT_CH_MODE_DISABLED, NULL},	// 11
    {EXT_CH_MODE_DISABLED, NULL},	// 12
    {EXT_CH_MODE_DISABLED, NULL},	// 13
    {EXT_CH_MODE_DISABLED, NULL},	// 14
    {EXT_CH_MODE_DISABLED, NULL},	// 15
    {EXT_CH_MODE_DISABLED, NULL},	// 16
    {EXT_CH_MODE_DISABLED, NULL},	// 17
    {EXT_CH_MODE_DISABLED, NULL},	// 18
    {EXT_CH_MODE_DISABLED, NULL},	// 19
    {EXT_CH_MODE_DISABLED, NULL},	// 20
    {EXT_CH_MODE_DISABLED, NULL},	// 21
    {EXT_CH_MODE_DISABLED, NULL}	// 22
  }
};

//-----------------------------------------------------------------------------
static void
display_off(void * arg)
{
	(void)arg;

	palSetPad(GPIOA, GPIOA_7SEG_OE);
}

//-----------------------------------------------------------------------------
void btn_1_exti_cb(EXTDriver *extp, expchannel_t channel)
{
	(void)extp;
	(void)channel;
	btn_1_pressed = palReadPad(GPIOA, GPIOA_BTN1) == 1;
	if ( btn_1_pressed )
	{
		palClearPad(GPIOA, GPIOA_7SEG_OE);
	}
	else
	{
		chSysLockFromIsr();
		if (chVTIsArmedI(&display_off_vt))
			chVTResetI(&display_off_vt);
		chVTSetI(&display_off_vt, MS2ST(DISPLAY_TIMEOUT), display_off, NULL);
		chSysUnlockFromIsr();
	}
}

//-----------------------------------------------------------------------------
void
pps_cb(EXTDriver *extp, expchannel_t channel)
{
	(void)extp;
	(void)channel;
}

//-----------------------------------------------------------------------------
void spi_end_cb(SPIDriver * spip)
{
	spiUnselectI(spip);
}

//-----------------------------------------------------------------------------
static const SPIConfig spicfg = {
	spi_end_cb,
	GPIOA,
	GPIOA_SPI1_CS,
	SPI_CR1_BR_2 | SPI_CR1_BR_1,
	SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0
};

//-----------------------------------------------------------------------------
static WORKING_AREA(display_thread_wa, 2048);
static Thread * display_thread;
static msg_t display_run(void * arg)
{
	(void)arg;
	chRegSetThreadName("display");
	//int8_t last_second = -1;
	while ( !chThdShouldTerminate() )
	{
		msg_t ret = RDY_OK;
		chSysLock();
			display_thread = chThdSelf();
			ret = chSchGoSleepTimeoutS(THD_STATE_SUSPENDED, MS2ST(500));
			display_thread = NULL;
		chSysUnlock();

		if ( valid_timecode && ret != RDY_TIMEOUT )
		{
			display_data[0] = DISPLAY_MAP[linear_timecode.hours/10];
			display_data[1] = DISPLAY_MAP[linear_timecode.hours%10]|DECIMAL_POINT;
			display_data[2] = DISPLAY_MAP[linear_timecode.minutes/10];
			display_data[3] = DISPLAY_MAP[linear_timecode.minutes%10]|DECIMAL_POINT;
			display_data[4] = DISPLAY_MAP[linear_timecode.seconds/10];
			display_data[5] = DISPLAY_MAP[linear_timecode.seconds%10]|DECIMAL_POINT;
			display_data[6] = DISPLAY_MAP[linear_timecode.frames/10];
			display_data[7] = DISPLAY_MAP[linear_timecode.frames%10];
			if ( linear_timecode.frames == 0 )
				display_data[7] |= DECIMAL_POINT;

			struct tm timp;
			rtcGetTimeTm(&RTCD1, &timp);
			timp.tm_hour = linear_timecode.hours;
			timp.tm_min = linear_timecode.minutes;
			timp.tm_sec = linear_timecode.seconds;
			rtcSetTimeTm(&RTCD1, &timp);
		}
		else
		{
			struct tm timp;
			rtcGetTimeTm(&RTCD1, &timp);
			display_data[0] = DISPLAY_MAP[timp.tm_hour/10];
			display_data[1] = DISPLAY_MAP[timp.tm_hour%10]|DECIMAL_POINT;
			display_data[2] = DISPLAY_MAP[timp.tm_min/10];
			display_data[3] = DISPLAY_MAP[timp.tm_min%10]|DECIMAL_POINT;
			display_data[4] = DISPLAY_MAP[timp.tm_sec/10];
			display_data[5] = DISPLAY_MAP[timp.tm_sec%10]|DECIMAL_POINT;
			display_data[6] = DASH;
			display_data[7] = DASH;
		}

		spiSelect(&SPID1);
		spiStartSend(&SPID1,sizeof(display_data), display_data);

		if (linear_timecode.frames%2 == 0 )
		{
			//last_second = linear_timecode.seconds;
			chprintf(prnt, "%.2d:%.2d:%.2d.%.2d",
					linear_timecode.hours, linear_timecode.minutes,
					linear_timecode.seconds, linear_timecode.frames);
			chprintf(prnt, " // t: %7d, d: %4d", this_edge_time, timediff);
			chprintf(prnt, " // t: %7d, d: %4d", this_edge_time_s, timediff_s);
			chprintf(prnt, " // t: %7d, d: %4d", this_edge_time_l, timediff_l);
			chprintf(prnt, " // t: %7d, d: %4d", this_edge_time_o, timediff_o);
			chprintf(prnt, "\n");
		}
	}
	return 0;
}

//-----------------------------------------------------------------------------
void setLTC(smpte_timecode_t * tc)
{
	palTogglePad(GPIOB, GPIOB_LED2);
	memcpy(&linear_timecode, tc, sizeof(linear_timecode));
	valid_timecode = TRUE;
	if (display_thread)
	{
		display_thread->p_u.rdymsg = (msg_t)1;
		chSchReadyI(display_thread);
		display_thread = NULL;
	}

}

//-----------------------------------------------------------------------------
static WORKING_AREA(blink_thread_wa, 128);
static msg_t blink_run(void *arg)
{
	(void)arg;
	chRegSetThreadName("blinker");
	while ( !chThdShouldTerminate() )
	{
		palClearPad(GPIOB, GPIOB_LED1);
		chThdSleepMilliseconds(10);
		palSetPad(GPIOB, GPIOB_LED1);
		chThdSleepMilliseconds(10);
	}
	return 0;
}

//-----------------------------------------------------------------------------
int main(void)
{
	halInit();
	chSysInit();
	sdStart(&SD1, NULL);

	valid_timecode = FALSE;

	palClearPad(GPIOB, GPIOB_LED1);
	palClearPad(GPIOB, GPIOB_LED2);

	seg77_change_to_spi();

	palSetPadMode(GPIOA, GPIOA_7SEG_OE, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);
	seg77_adjust_current(0, 0, 63);
	palClearPad(GPIOA, GPIOA_7SEG_OE);

	spiStart(&SPID1, &spicfg);

	chThdCreateStatic(blink_thread_wa, sizeof(blink_thread_wa), NORMALPRIO, blink_run, NULL);
	chThdCreateStatic(display_thread_wa, sizeof(display_thread_wa), NORMALPRIO, display_run, NULL);

	kuroBoxTimeInit();

	extStart(&EXTD1, &extcfg);

	chprintf(prnt, "%s\n\r\n\r%d\n\r\n\r", BOARD_NAME, STM32_HCLK);

	chSysLock();
	if (chVTIsArmedI(&display_off_vt))
		chVTResetI(&display_off_vt);
	chVTSetI(&display_off_vt, MS2ST(DISPLAY_TIMEOUT*2), display_off, NULL);
	chSysUnlock();

/*
	for ( int i = 0 ; i < 8 ; i++ )
		display_data[i] = DISPLAY_MAP[8];

	spiSelect(&SPID1);
	spiStartSend(&SPID1, sizeof(display_data), display_data);

	chThdSleepMilliseconds(500);
*/
	while ( 1 )
	{
		/*
		static uint8_t current = 0xFF;
		adjust_current(current++);

		static int blah = 0;
		for ( int i = 0 ; i < 8 ; i++ )
			display_data[i] = DISPLAY_MAP[blah%10];
		blah++;

		spiSelect(&SPID1);
		spiStartSend(&SPID1, sizeof(display_data), display_data);

		*/

		chThdSleepMilliseconds(250);
	}
}
