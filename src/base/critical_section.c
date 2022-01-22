#include "base/critical_section.h"
#include "base/memory.h"


struct rtc_cs {
#if defined(RTC_WIN)
    CRITICAL_SECTION crit;
#elif defined(RTC_UNIX)
    pthread_mutex_t mutex;
#else
#error "Unsported platform."
#endif

};

rtc_cs* rtc_cs_create() {
    rtc_cs* cs = rtc_malloc(sizeof(rtc_cs));
    return cs;
}

void rtc_cs_destroy(rtc_cs* cs) {
    if (cs) {
        rtc_free(cs);
    }
}

void rtc_cs_enter(rtc_cs* cs) {

}

void rtc_cs_try_enter(rtc_cs* cs) {

}

void rtc_cs_leave(rtc_cs* cs) {

}

