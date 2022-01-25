#ifndef __TEMPLE_RTC_RTP_PACKETS_H__
#define __TEMPLE_RTC_RTP_PACKETS_H__

#include "base/types.h"

typedef struct rtc_rtp_packet {
    rtc_bool    marker;
    uint8_t     pt;
    uint16_t    seq;
    uint32_t    timestamp;
    uint32_t    ssrc;
    size_t      offset;
    size_t      payload_size;
    uint8_t     padding_size;

    uint8_t*    buffer;
    size_t      buffer_size;
} rtc_rtp_packet;

rtc_bool rtc_rtp_packet_parse(rtc_rtp_packet* rtp, const char* buffer, size_t size);


#endif // __TEMPLE_RTC_RTP_PACKETS_H__
