/*
 * panic_debug.h
 *
 *  Created on: Nov 15, 2020
 *      Author: Ferri
 */

#ifndef APPS_PANIC_DEBUG_H_
#define APPS_PANIC_DEBUG_H_

#include "stdbool.h"
#include "string.h"

/* Red led is blinking or not (visual alert) */
void panic_alert_led(bool state);

/* UART2 Tx for sending a message to console */
void panic_alert_msg(const char *ptr_msg);

#endif /* APPS_PANIC_DEBUG_H_ */
