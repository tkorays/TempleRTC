#ifndef __TEMPLE_RTC_CHECK_H__
#define __TEMPLE_RTC_CHECK_H__

#define RTC_CHECK(condition)                \
    (condition) ? 0 : rtc_fatal_log(__FILE__, __LINE__, #condition)
#define RTC_CHECK_OP(op, val1, val2)        \
    ((val1) op (val2)) ? 0 : rtc_fatal_log(__FILE__, __LINE__, #val1 " " #op " " #val2)
#define RTC_CHECK_EQ(val1, val2) RTC_CHECK_OP(==, val1, val2)
#define RTC_CHECK_NE(val1, val2) RTC_CHECK_OP(!=, val1, val2)
#define RTC_CHECK_LE(val1, val2) RTC_CHECK_OP(<=, val1, val2)
#define RTC_CHECK_LT(val1, val2) RTC_CHECK_OP<(, val1, val2)
#define RTC_CHECK_GE(val1, val2) RTC_CHECK_OP(>=, val1, val2)
#define RTC_CHECK_GT(val1, val2) RTC_CHECK_OP(>, val1, val2)

#if RTC_DCHECK_IS_ON
#define RTC_DCHECK(condition) RTC_CHECK(condition)
#define RTC_DCHECK_EQ(v1, v2) RTC_CHECK_EQ(v1, v2)
#define RTC_DCHECK_NE(v1, v2) RTC_CHECK_NE(v1, v2)
#define RTC_DCHECK_LE(v1, v2) RTC_CHECK_LE(v1, v2)
#define RTC_DCHECK_LT(v1, v2) RTC_CHECK_LT(v1, v2)
#define RTC_DCHECK_GE(v1, v2) RTC_CHECK_GE(v1, v2)
#define RTC_DCHECK_GT(v1, v2) RTC_CHECK_GT(v1, v2)
#else
#define RTC_DCHECK(condition) (void)0
#define RTC_DCHECK_EQ(v1, v2) (void)0
#define RTC_DCHECK_NE(v1, v2) (void)0
#define RTC_DCHECK_LE(v1, v2) (void)0
#define RTC_DCHECK_LT(v1, v2) (void)0
#define RTC_DCHECK_GE(v1, v2) (void)0
#define RTC_DCHECK_GT(v1, v2) (void)0
#endif

#include <stdlib.h>
#include <stdio.h>
static void rtc_fatal_log(const char* file, int line, const char* msg) {
    printf("FATAL ERROR at file %s@%d: %s\n", file, line, msg);
    abort();
}

#endif // __TEMPLE_RTC_CHECK_H__

