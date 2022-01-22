#include "base/array.h"
#include "base/memory.h"


struct rtc_array {
    size_t size;
    void* data;
};

rtc_array* rtc_array_new(size_t array_size, size_t elm_size) {
    size_t size = array_size * elm_size;
    rtc_array* arr = RTC_NULL_PTR;
    void* data = RTC_NULL_PTR;
    if (0 == size) return RTC_NULL_PTR;

    data = rtc_malloc(size + sizeof(rtc_array));
    if (RTC_NULL_PTR == data) return RTC_NULL_PTR;
    arr = (rtc_array*)data;
    arr->size = size;
    arr->data = (void*)((uint8_t*)data + sizeof(rtc_array));

    rtc_array_init(arr);
    return arr;
}

void rtc_array_delete(rtc_array* arr) {
    if (RTC_NULL_PTR == arr) return;
    rtc_array_deinit(arr);
    rtc_free(arr);
}

void rtc_array_init(rtc_array* arr) {

}

void rtc_array_deinit(rtc_array* arr) {

}

int rtc_array_add(rtc_array* arr, void* data) {
    if (RTC_NULL_PTR == arr) return -1;
    return -1;
}


