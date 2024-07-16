/*
 * led.c
 *
 *  Created on: Mar 2, 2024
 *      Author: Lenovo
 */
#include "led.h"


uint32_t *AHB1_RCC_EN = (uint32_t *)(AHB1_RCC_BASE + 0x30);
uint32_t *GPIO_MODE = (uint32_t *)AHB1_GPIO_BASE;
uint32_t *GPIO_ODR = (uint32_t *)(AHB1_GPIO_BASE + 0x14);

void delay(uint32_t delay_num)
{
	for(int i=0; i<delay_num; i++);
}

void init_leds()
{
	*AHB1_RCC_EN |= (1<<3);
	*GPIO_MODE |= ((1<<24) | (1<<26) | (1<<28) | (1<<30));
}

void led_on(uint8_t pin)
{
	*GPIO_ODR |= (1<<pin);
}

void led_off(uint8_t pin)
{
	*GPIO_ODR &= ~(1<<pin);
}

