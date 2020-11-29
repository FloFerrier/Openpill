/*
 * console_debug.c
 *
 *  Created on: 18 nov. 2020
 *      Author: Ferri
 */
#include <dbg/console_debug.h>

#include "string.h"
#include "stdio.h"
#include "stdarg.h"

#include <dbg/panic_debug.h>

static char bufferConsoleFormat[CONSOLE_DEBUG_MSG_LEN_MAX+1]= "";
static char bufferConsoleDebug[CONSOLE_DEBUG_MSG_LEN_MAX+1]= "";

void console_debug(const char *format, ...)
{
  static va_list arg;
  static osStatus_t statusQueue;
	va_start(arg, format);
	vsnprintf(bufferConsoleFormat, CONSOLE_DEBUG_MSG_LEN_MAX, format, arg);
	statusQueue = osMessageQueuePut(queueConsoleDebugHandle, (char*)bufferConsoleFormat, 0, 0);
	if(statusQueue != osOK)
	{
		panic_alert_msg("[KERNEL] Error to send item on the queue\r\n");
	}
	va_end(arg);
}

/* Task FreeRTOS */
void TaskConsoleDebug(void *argument)
{
	static osStatus_t statusQueue;
	static size_t bufferConsoleDebugLen = 0;

  for(;;)
  {
    statusQueue = osMessageQueueGet(queueConsoleDebugHandle, (char*)bufferConsoleDebug, NULL, osWaitForever);
    if(statusQueue != osOK)
    {
      panic_alert_msg("[KERNEL] Error to receive item on the queue\r\n");
    }
    else
    {
      bufferConsoleDebugLen = strlen(bufferConsoleDebug);
      if(bufferConsoleDebugLen > 0)
      {
        HAL_UART_Transmit(&huart2, (uint8_t*)bufferConsoleDebug, (uint16_t)bufferConsoleDebugLen, 1000);
      }
    }
  }
}
