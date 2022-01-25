#ifndef __TEMPLE_RTC_PACING_INTERVAL_BUDGET_H__
#define __TEMPLE_RTC_PACING_INTERVAL_BUDGET_H__

#include "base/types.h"

#define RTC_INTERVAL_BUDGET_DEF_WIN 500

typedef struct rtc_interval_budget {
    rtc_bool    _self_managed;
    int         _target_kbps;
    int         _max_bytes_in_budget;
    int         _byte_remaining;
    rtc_bool    _can_build_up_underuse;
    int         _max_build_up_ms;
} rtc_interval_budget;

rtc_interval_budget* rtc_interval_budget_new(
        rtc_interval_budget* budget,
        int target_kbps,
        rtc_bool can_build_up,
        int build_up_ms
        );
void rtc_interval_budget_delete(rtc_interval_budget* budget);
void rtc_interval_budget_set(rtc_interval_budget* budget, int target_kbps);
void rtc_interval_budget_add(rtc_interval_budget* budget, int delta_time_ms);
void rtc_interval_budget_take(rtc_interval_budget* budget, size_t bytes);
int rtc_interval_budget_byte_remaining(rtc_interval_budget* budget);
int rtc_interval_budget_target_kbps(rtc_interval_budget* budget);

#endif // __TEMPLE_RTC_PACING_INTERVAL_BUDGET_H__

