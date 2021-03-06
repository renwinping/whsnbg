/*
* Copyright (c) 2013-2018 Vladimir Alemasov
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

#ifndef LISTS_H_
#define LISTS_H_

#include "list.h"


//--------------------------------------------
typedef struct list_name
{
	list_t next;
	uint8_t *name;
	uint16_t name_len;
} list_name_t;

#ifdef __cplusplus
extern "C" {
#endif
//--------------------------------------------
list_name_t *list_name_new(size_t topsize, int addzero, uint8_t *name, uint16_t name_len);
list_name_t *list_name_find_name(list_name_t **list, uint8_t *name, uint16_t name_len);
void list_name_remove(list_name_t **list, list_name_t *item);
void list_name_remove_all(list_name_t **list);
#define list_name_next(a) (list_name_t *)list_next((list_t *)a)
#ifdef __cplusplus
}
#endif


//--------------------------------------------
typedef struct list_sub
{
	list_t next;
	uint8_t *name;
	uint16_t name_len;
	uint8_t qos;
	uint16_t topic_id;
} list_sub_t;

#ifdef __cplusplus
extern "C" {
#endif
//--------------------------------------------
#define list_sub_init(list) list_init((list_t **)list)
#define list_sub_new(a, b) (list_sub_t *)list_name_new(sizeof(list_sub_t), 0, a, b)
#define list_sub_find_name(a, b, c) (list_sub_t *)list_name_find_name((list_name_t **)a, b, c)
list_sub_t *list_sub_add_replace(list_sub_t **list, uint8_t *name, uint16_t name_len, uint8_t qos);
void list_sub_remove_name(list_sub_t **list, uint8_t *name, uint16_t name_len);
void list_sub_remove_topic_id(list_sub_t **list, uint16_t topic_id);
#define list_sub_remove_all(a) list_name_remove_all((list_name_t **)a)
#define list_sub_head(a) (list_sub_t *)list_head((list_t **)a)
#define list_sub_next(a) (list_sub_t *)list_next((list_t *)a)
#define list_sub_add(a, b, c) (list_sub_t *)list_add_item((list_t **)a, (list_t *)list_sub_new(b, c))
#define list_sub_remove(a, b) list_name_remove((list_name_t **)a, (list_name_t *)b)
#ifdef __cplusplus
}
#endif


//--------------------------------------------
typedef struct list_data
{
	list_t next;
	uint8_t *name;
	uint16_t name_len;
	uint8_t *data;
	uint16_t data_len;
} list_data_t;

#ifdef __cplusplus
extern "C" {
#endif
//--------------------------------------------
list_data_t *list_data_new(size_t topsize, uint8_t *name, uint16_t name_len, uint8_t *data, uint16_t data_len);
#define list_data_find_name(a, b, c) (list_data_t *)list_name_find_name((list_name_t **)a, b, c)
list_data_t *list_data_add_replace(list_data_t **list, size_t topsize, uint8_t *name, uint16_t name_len, uint8_t *data, uint16_t data_len, int *added);
list_data_t *list_data_add_ignore(list_data_t **list, size_t topsize, uint8_t *name, uint16_t name_len, uint8_t *data, uint16_t data_len, int *added);
void list_data_replace_data(list_data_t *item, uint8_t *data, uint16_t data_len);
void list_data_remove_all(list_data_t **list);
void list_data_remove(list_data_t *list);
#define list_data_next(a) (list_data_t *)list_next((list_t *)a)
#define list_data_add(a, b, c, d, e, f) (list_data_t *)list_add_item((list_t **)a, (list_t *)list_data_new(b, c, d, e, f))
#ifdef __cplusplus
}
#endif


//--------------------------------------------
typedef struct will
{
	uint8_t *name;
	uint16_t name_len;
	uint8_t *data;
	uint16_t data_len;
	uint8_t retain;
} will_t;

#ifdef __cplusplus
extern "C" {
#endif
//--------------------------------------------
void will_replace(will_t *will, uint8_t *name, uint16_t name_len, uint8_t *data, uint16_t data_len, uint8_t retain);
void will_name_replace(will_t *will, uint8_t *name, uint16_t name_len, uint8_t retain);
void will_data_replace(will_t *will, uint8_t *data, uint16_t data_len);
void will_remove_all(will_t *will);
#ifdef __cplusplus
}
#endif


//--------------------------------------------
typedef struct list_pub
{
	list_t next;
	uint8_t *name;
	uint16_t name_len;
	uint8_t *data;
	uint16_t data_len;
	uint8_t retain;
	uint16_t topic_id;
} list_pub_t;

#ifdef __cplusplus
extern "C" {
#endif
//--------------------------------------------
list_pub_t *list_pub_add_replace(list_pub_t **list, uint8_t *name, uint16_t name_len, uint8_t *data, uint16_t data_len, uint8_t retain);
list_pub_t *list_pub_add_ignore(list_pub_t **list, uint8_t *name, uint16_t name_len, uint8_t *data, uint16_t data_len, uint8_t retain);
#define list_pub_remove_all(a) list_data_remove_all((list_data_t **)a)
#define list_pub_init(list) list_init((list_t **)list)
list_pub_t *list_pub_find_topic_id(list_pub_t **list, uint16_t topic_id);
void list_pub_data_replace(list_pub_t *item, uint8_t *data, uint16_t data_len,  uint8_t retain);
#define list_pub_head(a) (list_pub_t *)list_head((list_t **)a)
#define list_pub_next(a) (list_pub_t *)list_next((list_t *)a)
#ifdef __cplusplus
}
#endif


//--------------------------------------------
typedef struct list_reg
{
	list_t next;
	uint16_t topic_id;
} list_reg_t;

#ifdef __cplusplus
extern "C" {
#endif
//--------------------------------------------
list_reg_t *list_reg_add(list_reg_t **list, uint16_t topic_id);
void list_reg_remove_all(list_reg_t **list);
list_reg_t *list_reg_find_topic_id(list_reg_t **list, uint16_t topic_id);
#define list_reg_next(a) (list_reg_t *)list_next((list_t *)a)
#ifdef __cplusplus
}
#endif


//--------------------------------------------
typedef struct list_clreg
{
	list_t next;
	uint8_t *name;
	uint16_t name_len;
	uint16_t topic_id;
	uint16_t msg_id;
} list_clreg_t;

#ifdef __cplusplus
extern "C" {
#endif
//--------------------------------------------
#define list_clreg_init(a) list_init((list_t **)a)
#define list_clreg_find_name(a, b, c) (list_clreg_t *)list_name_find_name((list_name_t **)a, b, c)
#define list_clreg_new(a, b) (list_clreg_t *)list_name_new(sizeof(list_clreg_t), 1, a, b)
list_clreg_t *list_clreg_add(list_clreg_t **list, uint8_t *name, uint16_t name_len, uint16_t topic_id, uint16_t msg_id);
list_clreg_t *list_clreg_add_msg_id(list_clreg_t **list, uint8_t *name, uint16_t name_len, uint16_t msg_id);
list_clreg_t *list_clreg_find_msg_id(list_clreg_t **list, uint16_t msg_id);
#define list_clreg_remove_all(a) list_name_remove_all((list_name_t **)a)
#define list_clreg_next(a) (list_clreg_t *)list_next((list_t *)a)
#ifdef __cplusplus
}
#endif


//--------------------------------------------
typedef struct list_msg
{
	list_t next;
	uint16_t topic_id;
	uint16_t msg_id;
	uint8_t qos;
	uint8_t tts;
	uint8_t dup;
} list_msg_t;

#ifdef __cplusplus
extern "C" {
#endif
//--------------------------------------------
list_msg_t *list_msg_add(list_msg_t **mtops, uint16_t topic_id, uint8_t qos);
#define list_msg_remove_all(a) list_reg_remove_all((list_reg_t **)a)
list_msg_t *list_msg_find_msg_id(list_msg_t **mtops, uint16_t msg_id);
void list_msg_remove_msg_id(list_msg_t **mtops, uint16_t msg_id);
list_msg_t *list_msg_remove(list_msg_t **mtops, list_msg_t *mtop);
#define list_msg_head(a) (list_msg_t *)list_head((list_t **)a)
#define list_msg_next(a) (list_msg_t *)list_next((list_t *)a)
#define list_msg_length(a) list_get_length((list_t **)a)
#ifdef __cplusplus
}
#endif


//--------------------------------------------
typedef struct list_link
{
	list_t next;
	list_pub_t *pub_item;
} list_link_t;

#ifdef __cplusplus
extern "C" {
#endif
//--------------------------------------------
list_link_t *list_link_add_pubitem(list_link_t **list, list_pub_t *pub_item);
#define list_link_remove_all(list) list_reg_remove_all((list_reg_t **)list)
#define list_link_init(list) list_init((list_t **)list)
#define list_link_head(list) (list_link_t *)list_head((list_t **)list)
#define list_link_next(item) (list_link_t *)list_next((list_t *)item)
#define list_link_add(list, item) (list_data_t *)list_add_item((list_t **)list, (list_t *)item)
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif
//--------------------------------------------
//** publish and subscription topics relations
int name_has_wildcard(uint8_t *name, uint16_t len);
int list_sub_has_wildcard(list_sub_t *sub_item);
void list_sub_pub_matches(list_sub_t *sub_item, list_pub_t **pub_list, list_link_t **link_list);
int list_pub_sub_matches(list_pub_t *pub_item, list_sub_t **sub_list);
#ifdef __cplusplus
}
#endif

#endif /* LISTS_H_ */
