#ifndef __TEMPLE_RTC_BASE_LIST_H__
#define __TEMPLE_RTC_BASE_LIST_H__

#include "base/types.h"

typedef struct rtc_list_node {
    void*                   _data;
    struct rtc_list_node*   _next;
    struct rtc_list_node*   _prev;
} rtc_list_node;

typedef struct rtc_list {
    rtc_list_node*  _front;
    rtc_list_node*  _back;
    size_t          _elm_size;
    rtc_bool        _self_managed;
} rtc_list;

rtc_list* rtc_list_new(rtc_list* li);
void rtc_list_free(rtc_list* li);
rtc_bool rtc_list_push_back(rtc_list* li, void* data, size_t size);
rtc_bool rtc_list_push_front(rtc_list* li, void* data, size_t size);
rtc_bool rtc_list_pop_back(rtc_list* li, void* data, size_t size);
rtc_bool rtc_list_pop_front(rtc_list* li, void* data, size_t size);
rtc_bool rtc_list_back(rtc_list* li, void* data, size_t size);
rtc_bool rtc_list_front(rtc_list* li, void* data, size_t size);
void rtc_list_clear(rtc_list* li);
size_t rtc_list_size(rtc_list* li);
rtc_bool rtc_list_is_empty(rtc_list* li);

#endif // __TEMPLE_RTC_BASE_LIST_H__
