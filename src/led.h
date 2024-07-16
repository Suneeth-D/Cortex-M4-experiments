/*
 * led.h
 *
 *  Created on: Mar 2, 2024
 *      Author: Lenovo
 */

#ifndef LED_H_
#define LED_H_

#include<stdint.h>
#include<stdio.h>

#define LED_GREEN 12
#define LED_ORANGE 13
#define LED_RED 14
#define LED_BLUE 15

#define DELAY_1MS 1250U
#define DELAY_1S (1000U * DELAY_1MS)
#define DELAY_500MS (500 * DELAY_1MS)
#define DELAY_250MS (250 * DELAY_1MS)
#define DELAY_125MS (125 * DELAY_1MS)

#define AHB1_RCC_BASE 0x40023800
#define AHB1_GPIO_BASE 0x40020C00

void delay(uint32_t delay_num);
void init_leds();
void led_on(uint8_t pin);
void led_off(uint8_t pin);


#endif /* LED_H_ */
