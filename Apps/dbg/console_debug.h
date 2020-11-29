/*
 * console_debug.h
 *
 *  Created on: Nov 18, 2020
 *      Author: Ferri
 */

#ifndef APPS_CONSOLE_DEBUG_H_
#define APPS_CONSOLE_DEBUG_H_

#include "main.h"
#include "cmsis_os.h"

#define CONSOLE_DEBUG_MSG_NB_MAX    (5)
#define CONSOLE_DEBUG_MSG_LEN_MAX   (255)

osMessageQueueId_t queueConsoleDebugHandle;
osThreadId_t taskConsoleDebugHandle;

void console_debug(const char *format, ...);

void TaskConsoleDebug(void *argument);

#endif /* APPS_CONSOLE_DEBUG_H_ */
