#ifndef __TEMPLE_RTC_BASE_QUEUE_H__
#define __TEMPLE_RTC_BASE_QUEUE_H__

#include "base/types.h"

typedef struct rtc_queue rtc_queue;

rtc_queue* rtc_queue_new(rtc_queue* q, size_t elm_size, size_t reserve_cnt);
void rtc_queue_delete(rtc_queue* q);
rtc_bool rtc_queue_push_back(rtc_queue* q, void* elm, size_t elm_size);
void* rtc_queue_pop_front(rtc_queue* q);
void rtc_queue_clear(rtc_queue* q);
size_t rtc_queue_size(rtc_queue* q);

#endif // __TEMPLE_RTC_BASE_QUEUE_H__
