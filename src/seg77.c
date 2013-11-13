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

//-----------------------------------------------------------------------------

#include "seg77.h"


//-----------------------------------------------------------------------------
void
seg77_change_to_spi(void)
{
	palSetPadMode(GPIOA, GPIOA_SPI1_SCK, PAL_MODE_ALTERNATE(0)  | PAL_STM32_OSPEED_HIGHEST);
	palSetPadMode(GPIOA, GPIOA_SPI1_MISO, PAL_MODE_ALTERNATE(0) | PAL_STM32_OSPEED_HIGHEST);
	palSetPadMode(GPIOA, GPIOA_SPI1_MOSI, PAL_MODE_ALTERNATE(0) | PAL_STM32_OSPEED_HIGHEST);
	palSetPad(GPIOA, GPIOA_SPI1_CS);
	palSetPadMode(GPIOA, GPIOA_SPI1_CS, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);
}

//-----------------------------------------------------------------------------
void
seg77_change_to_gpio(void)
{
	palSetPadMode(GPIOA, GPIOA_SPI1_SCK, PAL_MODE_OUTPUT_PUSHPULL  | PAL_STM32_OSPEED_HIGHEST);
	palSetPadMode(GPIOA, GPIOA_SPI1_MISO, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);
	palSetPadMode(GPIOA, GPIOA_SPI1_MOSI, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);
	palSetPad(GPIOA, GPIOA_SPI1_CS);
	palSetPadMode(GPIOA, GPIOA_SPI1_CS, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);
}

#define OE_1() palWritePad(GPIOA, GPIOA_7SEG_OE,1)
#define OE_0() palWritePad(GPIOA, GPIOA_7SEG_OE,0)

//-----------------------------------------------------------------------------
void
seg77_change_to_config(void)
{
	seg77_change_to_gpio();
	for ( int i = 0 ; i < 8 ; i++ )
	{
		palClearPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_MISO);
		palClearPad(GPIOA, GPIOA_SPI1_MOSI);
		palClearPad(GPIOA, GPIOA_SPI1_CS);
		OE_1();

		// 1
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 2
		OE_0();
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 3
		OE_1();
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 4
		palSetPad(GPIOA, GPIOA_SPI1_CS);
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 5
		palClearPad(GPIOA, GPIOA_SPI1_CS);
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 6
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 7
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 8
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);
	}
}

//-----------------------------------------------------------------------------
void
seg77_change_to_data(void)
{
	for ( int i = 0 ; i < 8 ; i++ )
	{
		palClearPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_MISO);
		palClearPad(GPIOA, GPIOA_SPI1_MOSI);
		palClearPad(GPIOA, GPIOA_SPI1_CS);
		OE_1();

		// 1
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 2
		OE_0();
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 3
		OE_1();
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 4
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 5
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 6
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 7
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 8
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);
	}

	seg77_change_to_spi();
}


//-----------------------------------------------------------------------------
void
seg77_adjust_current(uint8_t cm, uint8_t hc, uint8_t div)
{
	chSysLock();
	seg77_change_to_config();

#define IF_BIT(x) ((x) & 0x01)
#define BIT_SHIFT(x) d>>=1

	for ( int i = 0 ; i < 8 ; i++ )
	{
		uint8_t d = div;
		palClearPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_MISO);
		palClearPad(GPIOA, GPIOA_SPI1_MOSI);
		palClearPad(GPIOA, GPIOA_SPI1_CS);
		OE_1();

		// 1
		palWritePad(GPIOA, GPIOA_SPI1_MOSI, IF_BIT(d));
		BIT_SHIFT(d);
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 2
		palWritePad(GPIOA, GPIOA_SPI1_MOSI, IF_BIT(d));
		BIT_SHIFT(d);
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 3
		palWritePad(GPIOA, GPIOA_SPI1_MOSI, IF_BIT(d));
		BIT_SHIFT(d);
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 4
		palWritePad(GPIOA, GPIOA_SPI1_MOSI, IF_BIT(d));
		BIT_SHIFT(d);
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 5
		palWritePad(GPIOA, GPIOA_SPI1_MOSI, IF_BIT(d));
		BIT_SHIFT(d);
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 6
		palWritePad(GPIOA, GPIOA_SPI1_MOSI, IF_BIT(d));
		BIT_SHIFT(d);
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 7
		palWritePad(GPIOA, GPIOA_SPI1_MOSI, IF_BIT(hc));
		BIT_SHIFT(d);
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);

		// 8
		palWritePad(GPIOA, GPIOA_SPI1_MOSI, IF_BIT(cm));
		d <<= 1;
		palSetPad(GPIOA, GPIOA_SPI1_CS);
		palSetPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_SCK);
		palClearPad(GPIOA, GPIOA_SPI1_CS);
	}

#undef IF_BIT

	seg77_change_to_data();
	chSysUnlock();
}
