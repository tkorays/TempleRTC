#ifndef __RTC_PEERCONNECTION_H__
#define __RTC_PEERCONNECTION_H__

typedef struct rtc_pc rtc_pc_t;
typedef struct rtc_tx_track rtc_tx_track_t;
typedef struct rtc_rx_track rtc_rx_track_t;
typedef struct rtc_tx_rtp rtc_tx_rtp_t;
typedef struct rtc_rx_rtp rtc_rx_rtp_t;

typedef struct rtc_pc_capability rtc_pc_capability_t;
typedef struct rtc_pc_config rtc_pc_config_t;
typedef struct rtc_pc_observer rtc_pc_observer_t;

typedef void(*rtc_pc_on_rx_track_t)(rtc_rx_rtp_t* rtp);

struct rtc_pc_config {
    int a;
};

struct rtc_pc_capability {
    int a;
};

struct rtc_pc_observer {
    rtc_pc_on_rx_track_t on_rx_track;
};

rtc_pc_t* rtc_pc_new(rtc_pc_config_t* cfg, rtc_pc_observer_t observer);
void rtc_pc_destroy(rtc_pc_t* self);

void rtc_pc_set_observer(rtc_pc_observer_t* ob);

rtc_tx_rtp_t* rtc_pc_add_track(rtc_pc_t* self, rtc_tx_track_t* track);
bool rtc_pc_remove_track(rtc_pc_t* self, rtc_tx_rtp_t* rtp);

bool rtc_pc_negotiate(rtc_pc_t* self);
void rtc_pc_set_local_cap(rtc_pc_t* self, rtc_pc_capability_t* cap);
void rtc_pc_set_remote_cap(rtc_pc_t* self, rtc_pc_capability_t* cap);
const rtc_pc_capability_t* rtc_pc_local_cap(rtc_pc_t* self);
const rtc_pc_capability_t* rtc_pc_remote_cap(rtc_pc_t* self);

#endif // __RTC_PEERCONNECTION_H__
