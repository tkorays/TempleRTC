#include "modules/pacing/paced_sender.h"
#include "modules/pacing/interval_budget.h"

struct rtc_pacer {
    rtc_interval_budget* media_budget;
    rtc_interval_budget* padding_budget;
};
