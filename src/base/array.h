#ifndef __TEMPLE_RTC_BASE_ARRAY_H__
#define __TEMPLE_RTC_BASE_ARRAY_H__

#include "base/types.h"

typedef struct rtc_array rtc_array;

rtc_array* rtc_array_new(size_t array_size, size_t elm_size);
void rtc_array_delete(rtc_array* arr);
void rtc_array_init(rtc_array* arr);
void rtc_array_deinit(rtc_array* arr);
int rtc_array_add(rtc_array* arr, void* data);
int rtc_array_erase(rtc_array* arr, int pos);
int rtc_array_set(rtc_array* arr, int pos, void* data);
void* rtc_array_get(rtc_array* arr, int pos);
int rtc_array_find(rtc_array* arr, void* data, rtc_compare_func func);

#endif // __TEMPLE_RTC_BASE_ARRAY_H__

