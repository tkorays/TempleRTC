#include <gtest/gtest.h>
extern "C" {
#include "modules/pacing/interval_budget.h"
}

TEST(rtc_interval_budget, basic) {
    rtc_interval_budget* budget = rtc_interval_budget_new(RTC_CAST(rtc_interval_budget*, 0), 1000, true, 100);
    EXPECT_NE(budget, (rtc_interval_budget*)0);
    EXPECT_EQ(rtc_interval_budget_target_kbps(budget), 1000);
}
