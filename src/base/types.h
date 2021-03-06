#ifndef __TEMPLE_RTC_TYPES_H__
#define __TEMPLE_RTC_TYPES_H__

#include <stddef.h>
#include <stdint.h>

#define RTC_NULL        0
#define RTC_NULL_PTR    (void*)0
#define RTC_TRUE        1
#define RTC_FALSE       0

#define RTC_MAX(a, b) ((a) > (b) ? (a) : (b))
#define RTC_MIN(a, b) ((a) < (b) ? (a) : (b))
#define RTC_ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define RTC_CAST(tn, a) ((tn)(a))

#define RTC_MAX_INT32   0x7fffffff
#define RTC_MAX_UINT32  0xffffffff
#define RTC_MIN_INT32   0x80000000
#define RTC_MAX_INT64   9223372036854775807L
#define RTC_MAX_UINT64  18446744073709551615UL
#define RTC_MIN_INT64   (-RTC_MAX_INT64 - 1L)

typedef int rtc_errno;
typedef int rtc_bool;
typedef int(*rtc_compare_func)(void* a, void* b);

typedef int64_t rtc_datarate_t;
typedef int64_t rtc_timedelta_t;
typedef uint32_t rtc_timestamp_t;

#define rtc_datarate_bps(r) (r)
#define rtc_datarate_kbps(r) ((r) / 1000)
#define rtc_datarate_bps_or(r, v) ((r) > 0 ? (r) : (v))
#define rtc_datarate_kbps_or(r, v) ((r) > 0 ? ((r) / 1000) : (v))
#define rtc_datarate_bytes_per_sec(r) ((r) / 8)


#endif // __TEMPLE_RTC_TYPES_H__

