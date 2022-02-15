#ifndef __TEMPLE_RTC_CRITICAL_SECTION_H__
#define __TEMPLE_RTC_CRITICAL_SECTION_H__

typedef struct rtc_cs rtc_cs;

rtc_cs* rtc_cs_create();
void rtc_cs_destroy(rtc_cs* cs);
void rtc_cs_enter(rtc_cs* cs);
void rtc_cs_try_enter(rtc_cs* cs);
void rtc_cs_leave(rtc_cs* cs);

#endif // __TEMPLE_RTC_CRITICAL_SECTION_H__
