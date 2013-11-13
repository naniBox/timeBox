/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for ST STM32F0-Discovery board.
 */

/*
 * Board identifier.
 */
#define BOARD_ST_STM32F0_DISCOVERY
#define BOARD_NAME                  "naniBox / timeBox"

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 * NOTE: HSE not fitted.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                32768
#endif

#define STM32_LSEDRV                (3 << 3)

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                26000000
#endif

//#define STM32_HSE_BYPASS

/*
 * MCU type as defined in the ST header file stm32f0xx.h.
 */
#define STM32F0XX



#define GPIOD_PIN0                  0
#define GPIOD_PIN1                  1
#define GPIOD_PIN2                  2
#define GPIOD_PIN3                  3
#define GPIOD_PIN4                  4
#define GPIOD_PIN5                  5
#define GPIOD_PIN6                  6
#define GPIOD_PIN7                  7
#define GPIOD_PIN8                  8
#define GPIOD_PIN9                  9
#define GPIOD_PIN10                 10
#define GPIOD_PIN11                 11
#define GPIOD_PIN12                 12
#define GPIOD_PIN13                 13
#define GPIOD_PIN14                 14
#define GPIOD_PIN15                 15

#define GPIOF_OSC_IN                0
#define GPIOF_OSC_OUT               1
#define GPIOF_PIN2                  2
#define GPIOF_PIN3                  3
#define GPIOF_PIN4                  4
#define GPIOF_PIN5                  5
#define GPIOF_PIN6                  6
#define GPIOF_PIN7                  7
#define GPIOF_PIN8                  8
#define GPIOF_PIN9                  9
#define GPIOF_PIN10                 10
#define GPIOF_PIN11                 11
#define GPIOF_PIN12                 12
#define GPIOF_PIN13                 13
#define GPIOF_PIN14                 14
#define GPIOF_PIN15                 15

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_2M(n)            (0U << ((n) * 2))
#define PIN_OSPEED_10M(n)           (1U << ((n) * 2))
#define PIN_OSPEED_40M(n)           (3U << ((n) * 2))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2))
#define PIN_AFIO_AF(n, v)           ((v##U) << ((n % 8) * 4))

/*
 */
#define GPIOA_BTN1                  0
#define GPIOA_LTC_TTL               1
#define GPIOA__PA02                 2
#define GPIOA_SPI1_CS               3
#define GPIOA_7SEG_OE               4
#define GPIOA_SPI1_SCK              5
#define GPIOA_SPI1_MISO             6
#define GPIOA_SPI1_MOSI             7
#define GPIOA__PA08                 8
#define GPIOA_USART1_TX             9
#define GPIOA_USART1_RX             10
#define GPIOA__PA11                 11
#define GPIOA__PA12                 12
#define GPIOA_SWDAT                 13
#define GPIOA_SWCLK                 14
#define GPIOA__PA15                 15

#define VAL_GPIOA_MODER             (PIN_MODE_INPUT(GPIOA_BTN1) |         \
                                     PIN_MODE_INPUT(GPIOA_LTC_TTL) |           \
                                     PIN_MODE_INPUT(GPIOA__PA02) |           \
                                     PIN_MODE_OUTPUT(GPIOA_SPI1_CS) |           \
                                     PIN_MODE_OUTPUT(GPIOA_7SEG_OE) |           \
                                     PIN_MODE_INPUT(GPIOA_SPI1_SCK) |           \
                                     PIN_MODE_INPUT(GPIOA_SPI1_MISO) |           \
                                     PIN_MODE_INPUT(GPIOA_SPI1_MOSI) |           \
                                     PIN_MODE_INPUT(GPIOA__PA08) |           \
                                     PIN_MODE_ALTERNATE(GPIOA_USART1_TX) |           \
                                     PIN_MODE_ALTERNATE(GPIOA_USART1_RX) |          \
                                     PIN_MODE_INPUT(GPIOA__PA11) |          \
                                     PIN_MODE_INPUT(GPIOA__PA12) |          \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDAT) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK) |      \
                                     PIN_MODE_INPUT(GPIOA__PA15))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_BTN1) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_LTC_TTL) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA__PA02) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SPI1_CS) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_7SEG_OE) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SPI1_SCK) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SPI1_MISO) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SPI1_MOSI) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA__PA08) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USART1_TX) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USART1_RX) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA__PA11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA__PA12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDAT) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA__PA15))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_2M(GPIOA_BTN1) |          \
                                     PIN_OSPEED_40M(GPIOA_LTC_TTL) |            \
                                     PIN_OSPEED_2M(GPIOA__PA02) |            \
                                     PIN_OSPEED_40M(GPIOA_SPI1_CS) |            \
                                     PIN_OSPEED_40M(GPIOA_7SEG_OE) |            \
                                     PIN_OSPEED_40M(GPIOA_SPI1_SCK) |            \
                                     PIN_OSPEED_40M(GPIOA_SPI1_MISO) |            \
                                     PIN_OSPEED_40M(GPIOA_SPI1_MOSI) |            \
                                     PIN_OSPEED_2M(GPIOA__PA08) |            \
                                     PIN_OSPEED_40M(GPIOA_USART1_TX) |            \
                                     PIN_OSPEED_40M(GPIOA_USART1_RX) |           \
                                     PIN_OSPEED_2M(GPIOA__PA11) |           \
                                     PIN_OSPEED_2M(GPIOA__PA12) |           \
                                     PIN_OSPEED_40M(GPIOA_SWDAT) |          \
                                     PIN_OSPEED_40M(GPIOA_SWCLK) |          \
                                     PIN_OSPEED_40M(GPIOA__PA15))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOA_BTN1) |     \
                                     PIN_PUPDR_PULLUP(GPIOA_LTC_TTL) |         \
                                     PIN_PUPDR_PULLUP(GPIOA__PA02) |         \
                                     PIN_PUPDR_PULLUP(GPIOA_SPI1_CS) |         \
                                     PIN_PUPDR_PULLUP(GPIOA_7SEG_OE) |         \
                                     PIN_PUPDR_PULLUP(GPIOA_SPI1_SCK) |         \
                                     PIN_PUPDR_PULLUP(GPIOA_SPI1_MISO) |         \
                                     PIN_PUPDR_PULLUP(GPIOA_SPI1_MOSI) |         \
                                     PIN_PUPDR_PULLUP(GPIOA__PA08) |         \
                                     PIN_PUPDR_PULLUP(GPIOA_USART1_TX) |         \
                                     PIN_PUPDR_PULLUP(GPIOA_USART1_RX) |        \
                                     PIN_PUPDR_PULLUP(GPIOA__PA11) |        \
                                     PIN_PUPDR_PULLUP(GPIOA__PA12) |        \
                                     PIN_PUPDR_PULLUP(GPIOA_SWDAT) |        \
                                     PIN_PUPDR_PULLDOWN(GPIOA_SWCLK) |      \
                                     PIN_PUPDR_PULLUP(GPIOA__PA15))
#define VAL_GPIOA_ODR               (PIN_ODR_HIGH(GPIOA_BTN1) |           \
                                     PIN_ODR_HIGH(GPIOA_LTC_TTL) |             \
                                     PIN_ODR_HIGH(GPIOA__PA02) |             \
                                     PIN_ODR_HIGH(GPIOA_SPI1_CS) |             \
                                     PIN_ODR_HIGH(GPIOA_7SEG_OE) |             \
                                     PIN_ODR_HIGH(GPIOA_SPI1_SCK) |             \
                                     PIN_ODR_HIGH(GPIOA_SPI1_MISO) |             \
                                     PIN_ODR_HIGH(GPIOA_SPI1_MOSI) |             \
                                     PIN_ODR_HIGH(GPIOA__PA08) |             \
                                     PIN_ODR_HIGH(GPIOA_USART1_TX) |             \
                                     PIN_ODR_HIGH(GPIOA_USART1_RX) |            \
                                     PIN_ODR_HIGH(GPIOA__PA11) |            \
                                     PIN_ODR_HIGH(GPIOA__PA12) |            \
                                     PIN_ODR_HIGH(GPIOA_SWDAT) |            \
                                     PIN_ODR_HIGH(GPIOA_SWCLK) |            \
                                     PIN_ODR_HIGH(GPIOA__PA15))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_BTN1, 0) |         \
                                     PIN_AFIO_AF(GPIOA_LTC_TTL, 0) |           \
                                     PIN_AFIO_AF(GPIOA__PA02, 0) |           \
                                     PIN_AFIO_AF(GPIOA_SPI1_CS, 0) |           \
                                     PIN_AFIO_AF(GPIOA_7SEG_OE, 0) |           \
                                     PIN_AFIO_AF(GPIOA_SPI1_SCK, 0) |           \
                                     PIN_AFIO_AF(GPIOA_SPI1_MISO, 0) |           \
                                     PIN_AFIO_AF(GPIOA_SPI1_MOSI, 0))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA__PA08, 0) |           \
                                     PIN_AFIO_AF(GPIOA_USART1_TX, 1) |           \
                                     PIN_AFIO_AF(GPIOA_USART1_RX, 1) |          \
                                     PIN_AFIO_AF(GPIOA__PA11, 0) |          \
                                     PIN_AFIO_AF(GPIOA__PA12, 0) |          \
                                     PIN_AFIO_AF(GPIOA_SWDAT, 0) |          \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0) |          \
                                     PIN_AFIO_AF(GPIOA__PA15, 0))

/*
 * GPIOB setup:
 *
  */
#define GPIOB__PB00                  0
#define GPIOB__PB01                  1
#define GPIOB__PB02                  2
#define GPIOB__PB03                  3
#define GPIOB__PB04                  4
#define GPIOB__PB05                  5
#define GPIOB_LED1                   6
#define GPIOB_LED2                   7
#define GPIOB__PB08                  8
#define GPIOB__PB09                  9
#define GPIOB__PB10                 10
#define GPIOB__PB11                 11
#define GPIOB__PB12                 12
#define GPIOB__PB13                 13
#define GPIOB__PB14                 14
#define GPIOB__PB15                 15
#define VAL_GPIOB_MODER             (PIN_MODE_INPUT(GPIOB__PB00) |           \
                                     PIN_MODE_INPUT(GPIOB__PB01) |           \
                                     PIN_MODE_INPUT(GPIOB__PB02) |           \
                                     PIN_MODE_INPUT(GPIOB__PB03) |           \
                                     PIN_MODE_INPUT(GPIOB__PB04) |           \
                                     PIN_MODE_INPUT(GPIOB__PB05) |           \
                                     PIN_MODE_OUTPUT(GPIOB_LED1) |           \
                                     PIN_MODE_OUTPUT(GPIOB_LED2) |           \
                                     PIN_MODE_INPUT(GPIOB__PB08) |           \
                                     PIN_MODE_INPUT(GPIOB__PB09) |           \
                                     PIN_MODE_INPUT(GPIOB__PB10) |          \
                                     PIN_MODE_INPUT(GPIOB__PB11) |          \
                                     PIN_MODE_INPUT(GPIOB__PB12) |          \
                                     PIN_MODE_INPUT(GPIOB__PB13) |          \
                                     PIN_MODE_INPUT(GPIOB__PB14) |          \
                                     PIN_MODE_INPUT(GPIOB__PB15))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB__PB00) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB__PB01) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB__PB02) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB__PB03) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB__PB04) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB__PB05) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_LED1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_LED2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB__PB08) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB__PB09) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB__PB10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB__PB11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB__PB12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB__PB13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB__PB14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB__PB15))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_2M(GPIOB__PB00) |            \
                                     PIN_OSPEED_2M(GPIOB__PB01) |            \
                                     PIN_OSPEED_2M(GPIOB__PB02) |           \
                                     PIN_OSPEED_2M(GPIOB__PB03) |           \
                                     PIN_OSPEED_2M(GPIOB__PB04) |           \
                                     PIN_OSPEED_2M(GPIOB__PB05) |            \
                                     PIN_OSPEED_40M(GPIOB_LED1) |            \
                                     PIN_OSPEED_40M(GPIOB_LED2) |            \
                                     PIN_OSPEED_2M(GPIOB__PB08) |            \
                                     PIN_OSPEED_2M(GPIOB__PB09) |            \
                                     PIN_OSPEED_2M(GPIOB__PB10) |           \
                                     PIN_OSPEED_2M(GPIOB__PB11) |           \
                                     PIN_OSPEED_2M(GPIOB__PB12) |           \
                                     PIN_OSPEED_2M(GPIOB__PB13) |           \
                                     PIN_OSPEED_2M(GPIOB__PB14) |           \
                                     PIN_OSPEED_2M(GPIOB__PB15))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_PULLUP(GPIOB__PB00) |         \
                                     PIN_PUPDR_PULLUP(GPIOB__PB01) |         \
                                     PIN_PUPDR_PULLUP(GPIOB__PB02) |         \
                                     PIN_PUPDR_PULLUP(GPIOB__PB03) |         \
                                     PIN_PUPDR_PULLUP(GPIOB__PB04) |         \
                                     PIN_PUPDR_PULLUP(GPIOB__PB05) |         \
                                     PIN_ODR_LOW(GPIOB_LED1) |         \
                                     PIN_ODR_LOW(GPIOB_LED2) |         \
                                     PIN_PUPDR_PULLUP(GPIOB__PB08) |         \
                                     PIN_PUPDR_PULLUP(GPIOB__PB09) |         \
                                     PIN_PUPDR_PULLUP(GPIOB__PB10) |        \
                                     PIN_PUPDR_PULLUP(GPIOB__PB11) |        \
                                     PIN_PUPDR_PULLUP(GPIOB__PB12) |        \
                                     PIN_PUPDR_PULLUP(GPIOB__PB13) |        \
                                     PIN_PUPDR_PULLUP(GPIOB__PB14) |        \
                                     PIN_PUPDR_PULLUP(GPIOB__PB15))
#define VAL_GPIOB_ODR               (PIN_ODR_HIGH(GPIOB__PB00) |             \
                                     PIN_ODR_HIGH(GPIOB__PB01) |             \
                                     PIN_ODR_HIGH(GPIOB__PB02) |             \
                                     PIN_ODR_HIGH(GPIOB__PB03) |             \
                                     PIN_ODR_HIGH(GPIOB__PB04) |             \
                                     PIN_ODR_HIGH(GPIOB__PB05) |             \
                                     PIN_ODR_HIGH(GPIOB_LED1) |             \
                                     PIN_ODR_HIGH(GPIOB_LED2) |             \
                                     PIN_ODR_HIGH(GPIOB__PB08) |             \
                                     PIN_ODR_HIGH(GPIOB__PB09) |             \
                                     PIN_ODR_HIGH(GPIOB__PB10) |            \
                                     PIN_ODR_HIGH(GPIOB__PB11) |            \
                                     PIN_ODR_HIGH(GPIOB__PB12) |            \
                                     PIN_ODR_HIGH(GPIOB__PB13) |            \
                                     PIN_ODR_HIGH(GPIOB__PB14) |            \
                                     PIN_ODR_HIGH(GPIOB__PB15))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB__PB00, 0) |           \
                                     PIN_AFIO_AF(GPIOB__PB01, 0) |           \
                                     PIN_AFIO_AF(GPIOB__PB02, 0) |           \
                                     PIN_AFIO_AF(GPIOB__PB03, 0) |           \
                                     PIN_AFIO_AF(GPIOB__PB04, 0) |           \
                                     PIN_AFIO_AF(GPIOB__PB05, 0) |           \
                                     PIN_AFIO_AF(GPIOB_LED1, 0) |           \
                                     PIN_AFIO_AF(GPIOB_LED2, 0))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB__PB08, 0) |           \
                                     PIN_AFIO_AF(GPIOB__PB09, 0) |           \
                                     PIN_AFIO_AF(GPIOB__PB10, 0) |          \
                                     PIN_AFIO_AF(GPIOB__PB11, 0) |          \
                                     PIN_AFIO_AF(GPIOB__PB12, 0) |          \
                                     PIN_AFIO_AF(GPIOB__PB13, 0) |          \
                                     PIN_AFIO_AF(GPIOB__PB14, 0) |          \
                                     PIN_AFIO_AF(GPIOB__PB15, 0))

/*
 * GPIOC setup:
 */
#define GPIOC__PC00                  0
#define GPIOC__PC01                  1
#define GPIOC__PC02                  2
#define GPIOC__PC03                  3
#define GPIOC__PC04                  4
#define GPIOC__PC05                  5
#define GPIOC__PC06                  6
#define GPIOC__PC07                  7
#define GPIOC__PC08                  8
#define GPIOC__PC09                  9
#define GPIOC__PC10                 10
#define GPIOC__PC11                 11
#define GPIOC__PC12                 12
#define GPIOC__PC13                 13
#define GPIOC_OSC32_IN              14
#define GPIOC_OSC32_OUT             15
#define VAL_GPIOC_MODER             (PIN_MODE_INPUT(GPIOC__PC00) |           \
                                     PIN_MODE_INPUT(GPIOC__PC01) |           \
                                     PIN_MODE_INPUT(GPIOC__PC02) |           \
                                     PIN_MODE_INPUT(GPIOC__PC03) |           \
                                     PIN_MODE_INPUT(GPIOC__PC04) |           \
                                     PIN_MODE_INPUT(GPIOC__PC05) |           \
                                     PIN_MODE_INPUT(GPIOC__PC06) |           \
                                     PIN_MODE_INPUT(GPIOC__PC07) |           \
                                     PIN_MODE_INPUT(GPIOC__PC08) |          \
                                     PIN_MODE_INPUT(GPIOC__PC09) |          \
                                     PIN_MODE_INPUT(GPIOC__PC10) |          \
                                     PIN_MODE_INPUT(GPIOC__PC11) |          \
                                     PIN_MODE_INPUT(GPIOC__PC12) |          \
                                     PIN_MODE_INPUT(GPIOC__PC13) |          \
                                     PIN_MODE_INPUT(GPIOC_OSC32_IN) |       \
                                     PIN_MODE_INPUT(GPIOC_OSC32_OUT))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOC__PC00) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC__PC01) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC__PC02) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC__PC03) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC__PC04) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC__PC05) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC__PC06) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC__PC07) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC__PC08) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC__PC09) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC__PC10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC__PC11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC__PC12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC__PC13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC_OSC32_IN) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOC_OSC32_OUT))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_2M(GPIOC__PC00) |            \
                                     PIN_OSPEED_2M(GPIOC__PC01) |            \
                                     PIN_OSPEED_2M(GPIOC__PC02) |            \
                                     PIN_OSPEED_2M(GPIOC__PC03) |            \
                                     PIN_OSPEED_2M(GPIOC__PC04) |            \
                                     PIN_OSPEED_2M(GPIOC__PC05) |            \
                                     PIN_OSPEED_2M(GPIOC__PC06) |            \
                                     PIN_OSPEED_2M(GPIOC__PC07) |            \
                                     PIN_OSPEED_2M(GPIOC__PC08) |           \
                                     PIN_OSPEED_2M(GPIOC__PC09) |           \
                                     PIN_OSPEED_2M(GPIOC__PC10) |           \
                                     PIN_OSPEED_2M(GPIOC__PC11) |           \
                                     PIN_OSPEED_2M(GPIOC__PC12) |           \
                                     PIN_OSPEED_2M(GPIOC__PC13) |           \
                                     PIN_OSPEED_40M(GPIOC_OSC32_IN) |       \
                                     PIN_OSPEED_40M(GPIOC_OSC32_OUT))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_PULLUP(GPIOC__PC00) |         \
                                     PIN_PUPDR_PULLUP(GPIOC__PC01) |         \
                                     PIN_PUPDR_PULLUP(GPIOC__PC02) |         \
                                     PIN_PUPDR_PULLUP(GPIOC__PC03) |         \
                                     PIN_PUPDR_PULLUP(GPIOC__PC04) |         \
                                     PIN_PUPDR_PULLUP(GPIOC__PC05) |         \
                                     PIN_PUPDR_PULLUP(GPIOC__PC06) |         \
                                     PIN_PUPDR_PULLUP(GPIOC__PC07) |         \
                                     PIN_PUPDR_PULLUP(GPIOC__PC08) |       \
                                     PIN_PUPDR_PULLUP(GPIOC__PC09) |       \
                                     PIN_PUPDR_PULLUP(GPIOC__PC10) |        \
                                     PIN_PUPDR_PULLUP(GPIOC__PC11) |        \
                                     PIN_PUPDR_PULLUP(GPIOC__PC12) |        \
                                     PIN_PUPDR_PULLUP(GPIOC__PC13) |        \
                                     PIN_PUPDR_FLOATING(GPIOC_OSC32_IN) |   \
                                     PIN_PUPDR_FLOATING(GPIOC_OSC32_OUT))
#define VAL_GPIOC_ODR               (PIN_ODR_HIGH(GPIOC__PC00) |             \
                                     PIN_ODR_HIGH(GPIOC__PC01) |             \
                                     PIN_ODR_HIGH(GPIOC__PC02) |             \
                                     PIN_ODR_HIGH(GPIOC__PC03) |             \
                                     PIN_ODR_HIGH(GPIOC__PC04) |             \
                                     PIN_ODR_HIGH(GPIOC__PC05) |             \
                                     PIN_ODR_HIGH(GPIOC__PC06) |             \
                                     PIN_ODR_HIGH(GPIOC__PC07) |             \
                                     PIN_ODR_HIGH(GPIOC__PC08) |              \
                                     PIN_ODR_HIGH(GPIOC__PC09) |              \
                                     PIN_ODR_HIGH(GPIOC__PC10) |            \
                                     PIN_ODR_HIGH(GPIOC__PC11) |            \
                                     PIN_ODR_HIGH(GPIOC__PC12) |            \
                                     PIN_ODR_HIGH(GPIOC__PC13) |            \
                                     PIN_ODR_HIGH(GPIOC_OSC32_IN) |         \
                                     PIN_ODR_HIGH(GPIOC_OSC32_OUT))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIOC__PC00, 0) |           \
                                     PIN_AFIO_AF(GPIOC__PC01, 0) |           \
                                     PIN_AFIO_AF(GPIOC__PC02, 0) |           \
                                     PIN_AFIO_AF(GPIOC__PC03, 0) |           \
                                     PIN_AFIO_AF(GPIOC__PC04, 0) |           \
                                     PIN_AFIO_AF(GPIOC__PC05, 0) |           \
                                     PIN_AFIO_AF(GPIOC__PC06, 0) |           \
                                     PIN_AFIO_AF(GPIOC__PC07, 0))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC__PC08, 0) |           \
                                     PIN_AFIO_AF(GPIOC__PC09, 0) |           \
                                     PIN_AFIO_AF(GPIOC__PC10, 0) |          \
                                     PIN_AFIO_AF(GPIOC__PC11, 0) |          \
                                     PIN_AFIO_AF(GPIOC__PC12, 0) |          \
                                     PIN_AFIO_AF(GPIOC__PC13, 0) |          \
                                     PIN_AFIO_AF(GPIOC_OSC32_IN, 0) |       \
                                     PIN_AFIO_AF(GPIOC_OSC32_OUT, 0))

/*
 * GPIOD setup:
 *
 * PD0  - PIN0                      (input pullup).
 * PD1  - PIN1                      (input pullup).
 * PD2  - PIN2                      (input pullup).
 * PD3  - PIN3                      (input pullup).
 * PD4  - PIN4                      (input pullup).
 * PD5  - PIN5                      (input pullup).
 * PD6  - PIN6                      (input pullup).
 * PD7  - PIN7                      (input pullup).
 * PD8  - PIN8                      (input pullup).
 * PD9  - PIN9                      (input pullup).
 * PD10 - PIN10                     (input pullup).
 * PD11 - PIN11                     (input pullup).
 * PD12 - PIN12                     (input pullup).
 * PD13 - PIN13                     (input pullup).
 * PD14 - PIN14                     (input pullup).
 * PD15 - PIN15                     (input pullup).
 */
#define VAL_GPIOD_MODER             (PIN_MODE_INPUT(GPIOD_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN15))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOD_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN15))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_2M(GPIOD_PIN0) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN1) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN2) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN3) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN4) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN5) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN6) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN7) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN8) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN9) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN10) |           \
                                     PIN_OSPEED_2M(GPIOD_PIN11) |           \
                                     PIN_OSPEED_2M(GPIOD_PIN12) |           \
                                     PIN_OSPEED_2M(GPIOD_PIN13) |           \
                                     PIN_OSPEED_2M(GPIOD_PIN14) |           \
                                     PIN_OSPEED_2M(GPIOD_PIN15))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_PULLUP(GPIOD_PIN0) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN1) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN2) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN3) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN4) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN5) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN7) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN8) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN9) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN10) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN12) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN13) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN14) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN15))
#define VAL_GPIOD_ODR               (PIN_ODR_HIGH(GPIOD_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN15))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(GPIOD_PIN0, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN1, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN2, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN3, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN4, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN5, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN6, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN7, 0))
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(GPIOD_PIN8, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN9, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN10, 0) |          \
                                     PIN_AFIO_AF(GPIOD_PIN11, 0) |          \
                                     PIN_AFIO_AF(GPIOD_PIN12, 0) |          \
                                     PIN_AFIO_AF(GPIOD_PIN13, 0) |          \
                                     PIN_AFIO_AF(GPIOD_PIN14, 0) |          \
                                     PIN_AFIO_AF(GPIOD_PIN15, 0))

/*
 * GPIOF setup:
 *
 * PF0  - OSC_IN                    (input floating).
 * PF1  - OSC_OUT                   (input floating).
 * PF2  - PIN2                      (input pullup).
 * PF3  - PIN3                      (input pullup).
 * PF4  - PIN4                      (input pullup).
 * PF5  - PIN5                      (input pullup).
 * PF6  - PIN6                      (input pullup).
 * PF7  - PIN7                      (input pullup).
 * PF8  - PIN8                      (input pullup).
 * PF9  - PIN9                      (input pullup).
 * PF10 - PIN10                     (input pullup).
 * PF11 - PIN11                     (input pullup).
 * PF12 - PIN12                     (input pullup).
 * PF13 - PIN13                     (input pullup).
 * PF14 - PIN14                     (input pullup).
 * PF15 - PIN15                     (input pullup).
 */
#define VAL_GPIOF_MODER             (PIN_MODE_INPUT(GPIOF_OSC_IN) |         \
                                     PIN_MODE_INPUT(GPIOF_OSC_OUT) |        \
                                     PIN_MODE_INPUT(GPIOF_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN15))
#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOF_OSC_IN) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOF_OSC_OUT) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN15))
#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_2M(GPIOF_OSC_IN) |          \
                                     PIN_OSPEED_2M(GPIOF_OSC_OUT) |         \
                                     PIN_OSPEED_2M(GPIOF_PIN2) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN3) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN4) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN5) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN6) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN7) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN8) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN9) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN10) |           \
                                     PIN_OSPEED_2M(GPIOF_PIN11) |           \
                                     PIN_OSPEED_2M(GPIOF_PIN12) |           \
                                     PIN_OSPEED_2M(GPIOF_PIN13) |           \
                                     PIN_OSPEED_2M(GPIOF_PIN14) |           \
                                     PIN_OSPEED_2M(GPIOF_PIN15))
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_FLOATING(GPIOF_OSC_IN) |     \
                                     PIN_PUPDR_FLOATING(GPIOF_OSC_OUT) |    \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN2) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN3) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN4) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN5) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN7) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN8) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN9) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN10) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN12) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN13) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN14) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN15))
#define VAL_GPIOF_ODR               (PIN_ODR_HIGH(GPIOF_OSC_IN) |           \
                                     PIN_ODR_HIGH(GPIOF_OSC_OUT) |          \
                                     PIN_ODR_HIGH(GPIOF_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN15))
#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(GPIOF_OSC_IN, 0) |         \
                                     PIN_AFIO_AF(GPIOF_OSC_OUT, 0) |        \
                                     PIN_AFIO_AF(GPIOF_PIN2, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN3, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN4, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN5, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN6, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN7, 0))
#define VAL_GPIOF_AFRH              (PIN_AFIO_AF(GPIOF_PIN8, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN9, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN10, 0) |          \
                                     PIN_AFIO_AF(GPIOF_PIN11, 0) |          \
                                     PIN_AFIO_AF(GPIOF_PIN12, 0) |          \
                                     PIN_AFIO_AF(GPIOF_PIN13, 0) |          \
                                     PIN_AFIO_AF(GPIOF_PIN14, 0) |          \
                                     PIN_AFIO_AF(GPIOF_PIN15, 0))


#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
