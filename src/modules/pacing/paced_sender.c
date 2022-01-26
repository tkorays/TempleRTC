#include "modules/pacing/paced_sender.h"
#include "modules/pacing/interval_budget.h"

struct rtc_pacer {
    interval_budget* media_budget;
    interval_budget* padding_budget;
};
