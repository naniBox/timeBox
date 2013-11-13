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

#ifndef _naniBox_kuroBox_seg77
#define _naniBox_kuroBox_seg77

#include <ch.h>
#include <hal.h>

//-----------------------------------------------------------------------------
void seg77_change_to_spi(void);
void seg77_change_to_gpio(void);
void seg77_change_to_config(void);
void seg77_change_to_data(void);
void seg77_adjust_current(uint8_t cm, uint8_t hc, uint8_t div);



#endif // _naniBox_kuroBox_seg77
