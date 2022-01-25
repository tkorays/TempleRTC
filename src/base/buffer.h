#ifndef __TEMPLE_RTC_BASE_BUFFER_H__
#define __TEMPLE_RTC_BASE_BUFFER_H__

#include "base/types.h"

typedef struct rtc_buffer {
    uint8_t*    buffer;
    size_t      size;
    size_t      offset;
} rtc_buffer;

rtc_buffer* rtc_buffer_new();
void rtc_buffer_delete(rtc_buffer* buffer);
void rtc_buffer_init(rtc_buffer* buffer);
void rtc_buffer_deinit(rtc_buffer* buffer);
void* rtc_buffer_data(rtc_buffer* buffer);
size_t rtc_buffer_size(rtc_buffer* buffer);
void rtc_buffer_clear(rtc_buffer* buffer);
void rtc_buffer_append_data(rtc_buffer* buffer, void* data, size_t size);
rtc_bool rtc_buffer_swap(rtc_buffer* buffer, rtc_buffer* other);


#endif // __TEMPLE_RTC_BASE_BUFFER_H__
