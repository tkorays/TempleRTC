#include "modules/pacing/interval_budget.h"
#include "base/memory.h"


interval_budget* rtc_interval_budget_new(
        interval_budget* budget,
        int target_kbps,
        rtc_bool can_build_up,
        int build_up_ms
        ) {
    interval_budget* budget_new = RTC_NULL_PTR;
    if (!budget) {
        budget_new = rtc_malloc(sizeof(interval_budget));
        if (RTC_NULL_PTR == budget_new) return RTC_NULL_PTR;
        budget = budget_new;
        budget->_self_managed        = RTC_TRUE;
    } else {
        budget->_self_managed        = RTC_FALSE;
    }

    budget->_target_kbps             = 0;
    budget->_max_bytes_in_budget     = 0;
    budget->_byte_remaining          = 0;
    budget->_can_build_up_underuse   = can_build_up;
    budget->_max_build_up_ms         = build_up_ms;
    rtc_interval_budget_set(budget, target_kbps);

    return budget;
}

void rtc_interval_budget_delete(interval_budget* budget) {
    if (budget && budget->_self_managed) {
        rtc_free(budget);
    }
}

void rtc_interval_budget_set(interval_budget* budget, int target_kbps) {
    budget->_target_kbps = target_kbps;
    budget->_max_bytes_in_budget = (budget->_max_build_up_ms * target_kbps) / 8;
    budget->_byte_remaining = RTC_MIN(RTC_MAX(-budget->_max_bytes_in_budget, budget->_byte_remaining),
            budget->_max_bytes_in_budget);
}

void rtc_interval_budget_add(interval_budget* budget, int delta_time_ms) {
    int bytes = budget->_target_kbps * delta_time_ms;
    if (budget->_byte_remaining || budget->_can_build_up_underuse) {
        budget->_byte_remaining = RTC_MIN(budget->_byte_remaining + bytes, budget->_max_bytes_in_budget);
    } else {
        budget->_byte_remaining = RTC_MIN(bytes, budget->_max_bytes_in_budget);
    }
}

void rtc_interval_budget_take(interval_budget* budget, size_t bytes) {
    budget->_byte_remaining = RTC_MAX(budget->_byte_remaining - bytes, -budget->_max_bytes_in_budget);
}

int rtc_interval_budget_byte_remaining(interval_budget* budget) {
    return RTC_MAX(budget->_byte_remaining, 0);
}

inline int rtc_interval_budget_target_kbps(interval_budget* budget) {
    return budget->_target_kbps;
}
