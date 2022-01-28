#ifndef __TEMPLE_RTC_BASE_VECTOR_H__
#define __TEMPLE_RTC_BASE_VECTOR_H__

#include "base/types.h"

typedef struct rtc_vector {
    void*       _buffer;
    size_t      _capacity;
    size_t      _elm_size;
    size_t      _elm_count;
    void*       _front;
    void*       _back;
} rtc_vector;

rtc_vector* rtc_vector_new(rtc_vector* vec);
void rtc_vector_free(rtc_vector* vec);
void rtc_vector_reserve(rtc_vector* vec, size_t cnt);
rtc_bool rtc_vector_push_back(rtc_vector* vec, void* data, size_t size);
rtc_bool rtc_vector_push_front(rtc_vector* vec, void* data, size_t size);
rtc_bool rtc_vector_pop_back(rtc_vector* vec, void* data, size_t size);
rtc_bool rtc_vector_pop_front(rtc_vector* vec, void* data, size_t size);
rtc_bool rtc_vector_back(rtc_vector* vec, void* data, size_t size);
rtc_bool rtc_vector_front(rtc_vector* vec, void* data, size_t size);
rtc_bool rtc_vector_at(rtc_vector* vec, int idx, void* data, size_t size);
rtc_bool rtc_vector_resize(rtc_vector* vec, size_t new_size, void* data);
void rtc_vector_clear(rtc_vector* vec);
size_t rtc_vector_size(rtc_vector* vec);
rtc_bool rtc_vector_is_empty(rtc_vector* vec);

#endif // __TEMPLE_RTC_BASE_VECTOR_H__
