#ifndef __TEMPLE_RTC_PIPELINE_H__
#define __TEMPLE_RTC_PIPELINE_H__

#include "base/types.h"

typedef struct {
    char a;
} rtc_pipeline;

typedef struct rtc_pipeline_node rtc_pipeline_node;

typedef struct rtc_pipeline_node_interface {
    typedef void(*abc)();
} rtc_pipeline_node_interface;

rtc_pipeline* rtc_pipeline_new(rtc_pipeline* self, const char* name);
void rtc_pipeline_delete(rtc_pipeline* self);
rtc_bool rtc_pipeline_start(rtc_pipeline* self);
rtc_bool rtc_pipeline_stop(rtc_pipeline* self);

rtc_bool rtc_pipeline_add_node(rtc_pipeline* self, rtc_pipeline_node* node);

rtc_bool rtc_pipeline_link(rtc_pipeline* self, rtc_pipeline_node* prev, rtc_pipeline_node* next, uint8_t topo);
rtc_bool rtc_pipeline_unlink(rtc_pipeline* self, rtc_pipeline_node* prev, rtc_pipeline_node* next);



#endif // __TEMPLE_RTC_PIPELINE_H__
