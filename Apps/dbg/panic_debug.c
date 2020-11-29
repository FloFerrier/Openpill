/*
 * panic_debug.c
 *
 *  Created on: Nov 15, 2020
 *      Author: Ferri
 */
#include <dbg/panic_debug.h>
#include "main.h"

void panic_alert_led(bool state)
{
	if(state == true)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);
	}
}

void panic_alert_msg(const char *ptr_msg)
{
	static size_t msg_len = 0;

	if(ptr_msg != NULL)
	{
		msg_len = strlen(ptr_msg);

		if(msg_len > 0)
		{
			/* To Do : Change for using DMA transmission */
      HAL_UART_Transmit(&huart2, (uint8_t*)ptr_msg, (uint16_t)msg_len, 1000);
		}
	}
}
