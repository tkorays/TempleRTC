#include "base/queue.h"
#include "base/memory.h"


rtc_queue* rtc_queue_new(rtc_queue* q, size_t elm_size, size_t reserve_cnt) {
    size_t capacity = 0;
    if (elm_size == 0) return RTC_NULL;
    if (reserve_cnt == 0 ) reserve_cnt = 10;

    if (!q) {
        q = RTC_CAST(rtc_queue*, rtc_malloc(capacity));
        if (!q) return RTC_NULL;
        q->_self_managed = RTC_TRUE;
    } else {
        q->_self_managed = RTC_FALSE;
    }

    capacity =  reserve_cnt;
    q->_buffer = rtc_malloc(capacity * elm_size);
    if (!q->_buffer) {
        if (q->_self_managed) {
            rtc_free(q);
        }
        return RTC_NULL;
    }
    q->_capacity    = capacity;
    q->_elm_size    = elm_size;
    q->_elm_cnt     = 0;
    q->_front_idx   = 0;
    q->_back_idx    = 0;

    return RTC_NULL;
}

void rtc_queue_delete(rtc_queue* q) {
    if (!q) return;
    if (q->_buffer) {
        rtc_free(q->_buffer);
    }
    if (q->_self_managed) {
        rtc_free(q);
    }
}

rtc_bool rtc_queue_push_back(rtc_queue* q, void* elm, size_t elm_size) {
    size_t capacity;
    void* new_buffer;
    if (!q || !elm || elm_size != q->_elm_size) return RTC_FALSE;
    if (q->_elm_cnt > q->_capacity) {
        capacity = q->_capacity * 2;
        new_buffer = rtc_malloc(capacity * elm_size);
        if (!new_buffer) return RTC_FALSE;
        if (q->_front_idx > q->_back_idx) {
            memcpy(new_buffer,
                (uint8_t*)q->_buffer + q->_front_idx * elm_size, (q->_capacity - q->_front_idx) * elm_size);
            if (q->_back_idx > 0) {
                memcpy((uint8_t*)new_buffer + (q->_capacity - q->_front_idx) * elm_size, 
                    (uint8_t*)q->_buffer, q->_back_idx * elm_size);
            }
            q->_front_idx   = 0;
            q->_back_idx    = q->_capacity - q->_front_idx + q->_back_idx;

        } else {
            memcpy(new_buffer, (uint8_t*)q->_buffer + q->_front_idx * elm_size, (q->_back_idx - q->_front_idx) * elm_size);
            q->_front_idx   = 0;
            q->_back_idx    = q->_back_idx - q->_front_idx;
        }
    }
    memcpy((uint8_t*)q->_buffer + q->_back_idx * q->_elm_size, elm, elm_size);
    q->_back_idx = (q->_back_idx + 1) % q->_capacity;
    q->_elm_cnt += 1;
    return RTC_TRUE;
}

void* rtc_queue_pop_front(rtc_queue* q) {
    uint8_t* data;
    if (!q || q->_elm_cnt == 0) return RTC_NULL;
    data = (uint8_t*)q->_buffer + q->_front_idx * q->_elm_size;
    q->_front_idx = (q->_front_idx + 1) % q->_capacity;
    q->_elm_cnt = 0;
    return (void*)data;;
}

void rtc_queue_clear(rtc_queue* q) {
    if (!q) return;
    q->_front_idx   = 0;
    q->_back_idx    = 0;
    q->_elm_cnt     = 0;
}

size_t rtc_queue_size(rtc_queue* q) {
    if (!q) return 0;
    return q->_elm_cnt;
}
