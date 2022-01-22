/**
 * Copyright (c) 2022, TempleRTC.
 * All rights reserved.
 */
#ifndef __TEMPLE_RTC_BASE_LOGGING_H__
#define __TEMPLE_RTC_BASE_LOGGING_H__

typedef enum {
    RTC_LOG_LEVEL_VERBOSE,
    RTC_LOG_LEVEL_INFO,
    RTC_LOG_LEVEL_WARNING,
    RTC_LOG_LEVEL_ERROR,
    RTC_LOG_LEVEL_NONE
} rtc_logging_level;

typedef void (*rtc_logging_on_log)(
        rtc_logging_level   level,
        const char*         file,
        int                 line,
        char*               msg,
        int                 len
        );

typedef struct rtc_logging_sink {
    void*                       user_data;
    rtc_logging_on_log          on_log;
    struct rtc_logging_sink*    next;
} rtc_logging_sink;

typedef struct rtc_logging rtc_logging;

rtc_logging* rtc_logging_create();

void rtc_logging_destroy(rtc_logging* logging);

void rtc_logging_add_sink(rtc_logging* logging, rtc_logging_sink* sink);

void rtc_logging_remove_sink(rtc_logging* logging, rtc_logging_sink* sink);

void rtc_logging_add_log(
        rtc_logging*        logging,
        rtc_logging_level   level,
        const char*         file,
        int                 line,
        const char*         fmt,
        ...);

extern rtc_logging* _g_logging_;

#define _RTC_GLOBAL_LOGGING() (_g_logging_)

#define RTC_LOG(lvl, fmt, ...) rtc_logging_add_log( \
        _RTC_GLOBAL_LOGGING(),  \
        (lvl),                  \
        __FILE__,               \
        __LINE__,               \
        (fmt),                  \
        __VA_ARGS__)

#define RTC_LOG_V(fmt, ...) RTC_LOG(RTC_LOG_LEVEL_VERBOSE, (fmt), #__VA_ARGS__)
#define RTC_LOG_I(fmt, ...) RTC_LOG(RTC_LOG_LEVEL_INFO, (fmt), #__VA_ARGS__)
#define RTC_LOG_W(fmt, ...) RTC_LOG(RTC_LOG_LEVEL_WARNING, (fmt), #__VA_ARGS__)
#define RTC_LOG_E(fmt, ...) RTC_LOG(RTC_LOG_LEVEL_ERROR, (fmt), #__VA_ARGS__)

#endif // __TEMPLE_RTC_BASE_LOGGING_H__

