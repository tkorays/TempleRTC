#include "modules/pacing/interval_budget.h"
#include "base/memory.h"

struct rtc_interval_budget {
    int target_kbps;
    int max_bytes_in_budget;
    int byte_remaining;
    rtc_bool can_build_up_underuse;
    int max_build_up_ms;
};

rtc_interval_budget* rtc_interval_budget_new(
        int target_kbps,
        rtc_bool can_build_up,
        int build_up_ms
        ) {
    rtc_interval_budget* budget = RTC_NULL_PTR;
    budget = rtc_malloc(sizeof(rtc_interval_budget));
    if (RTC_NULL_PTR == budget) return RTC_NULL_PTR;

    budget->can_build_up_underuse   = can_build_up;
    budget->max_build_up_ms         = build_up_ms;
    rtc_interval_budget_set(budget, target_kbps);

    return budget;
}

void rtc_interval_budget_delete(rtc_interval_budget* budget) {
    if (budget) {
        rtc_free(budget);
    }
}

void rtc_interval_budget_set(rtc_interval_budget* budget, int target_kbps) {
    budget->target_kbps = target_kbps;
    budget->max_bytes_in_budget = (budget->max_build_up_ms * target_kbps) / 8;
    budget->byte_remaining = RTC_MIN(RTC_MAX(-budget->max_bytes_in_budget, budget->byte_remaining),
            budget->max_bytes_in_budget);
}

void rtc_interval_budget_add(rtc_interval_budget* budget, int delta_time_ms) {
    int bytes = budget->target_kbps * delta_time_ms;
    if (budget->byte_remaining || budget->can_build_up_underuse) {
        budget->byte_remaining = RTC_MIN(budget->byte_remaining + bytes, budget->max_bytes_in_budget);
    } else {
        budget->byte_remaining = RTC_MIN(bytes, budget->max_bytes_in_budget);
    }
}

void rtc_interval_budget_take(rtc_interval_budget* budget, size_t bytes) {
    budget->byte_remaining = RTC_MAX(budget->byte_remaining - bytes, -budget->max_bytes_in_budget);
}

int rtc_interval_budget_byte_remaining(rtc_interval_budget* budget) {
    return RTC_MAX(budget->byte_remaining, 0);
}

