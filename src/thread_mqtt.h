/*
* Copyright (c) 2013-2015 Vladimir Alemasov
* All rights reserved
*
* This program and the accompanying materials are distributed under 
* the terms of GNU General Public License version 2 
* as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*/

#ifndef THREAD_MQTT_H_
#define THREAD_MQTT_H_

#include "lists.h"

#ifdef _MSC_VER
#include "stdint_msc.h"	/* uint8_t ... uint64_t */
#else
#include <stdint.h>		/* uint8_t ... uint64_t */
#include <stddef.h>		/* size_t */
#endif

//--------------------------------------------
void thread_mqtt_start(void);
void thread_mqtt_stop(void);
void thread_mqtt_user_add(const char *user_name, const char *password, unsigned char publish_enable);
void thread_mqtt_trigger_add(const char *name, uint32_t next_id);
void thread_mqtt_trigger_remove_all(void);
void thread_mqtt_set_rules_topic_data(const char *data, size_t data_len);

#endif /* THREAD_MQTT_H_ */
