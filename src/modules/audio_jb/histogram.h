#ifndef __TEMPLE_RTC_AUDIO_JB_HISTOGRAM_H__
#define __TEMPLE_RTC_AUDIO_JB_HISTOGRAM_H__

#include "base/vector.h"

typedef struct {
    rtc_vector  _buckets;
    int         _forget_factor;
    int         _base_forget_factor;
    int         _add_count;
    double      _start_forget_weight;
    rtc_bool    _self_managed;
} histogram;

histogram* histogram_new(histogram* self, size_t num_buckets, int forget_factor, double start_forget_factor);
void histogram_delete(histogram* self);
void histogram_reset(histogram* self);
void histogram_add(histogram* self, int index);
void histogram_quantile(histogram* self, int probality);
int histogram_num_of_buckets(histogram* self);

#endif // __TEMPLE_RTC_AUDIO_JB_HISTOGRAM_H__

