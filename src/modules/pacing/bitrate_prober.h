#ifndef __TEMPLE_RTC_PACING_BITRATE_PROBER_H__
#define __TEMPLE_RTC_PACING_BITRATE_PROBER_H__

#include <stdint.h>
#include "base/types.h"
#include "base/queue.h"


// TODO: move paced packet info to another header files
typedef struct {
    int send_bitrate_bps;
    int probe_cluster_id;
    int probe_cluster_min_probes;
    int probe_cluster_min_bytes;
    int probe_cluster_bytes_sent;
} paced_packet_info;

typedef struct bitrate_prober_cfg {
    int         min_probe_packets_sent;
    int64_t     min_probe_delta;
    int64_t     min_probe_duration;
    int64_t     max_probe_delay;
} bitrate_prober_cfg;

typedef enum {
    PROBING_DISABLEED,
    PROBING_INACTIVE,
    PROBING_ACTIVE,
    PROBING_SUSPENDED
} probing_state;

typedef struct {
    paced_packet_info   pace_info;
    int                 sent_probes;
    int                 sent_bytes;
    int64_t             created_at;
    int64_t             started_at;
    int                 retries;
} probe_cluster;

typedef struct bitrate_prober {
    probing_state       _state;
    // TODO: queue of probe_cluster
    rtc_queue*          _probe_clusters;
    int64_t             _next_probe_time;
    int                 _total_probe_count;
    int                 _total_failed_probe_count;
    bitrate_prober_cfg  _cfg;
} bitrate_prober;

bitrate_prober* bitrate_prober_new(bitrate_prober* prob, bitrate_prober_cfg* cfg);
void bitrate_prober_delete(bitrate_prober* prob);
void bitrate_prober_set_enable(bitrate_prober* prob, rtc_bool enable);
rtc_bool bitrate_prober_is_probing(bitrate_prober* prob);
void bitrate_prober_on_incomming_packet(bitrate_prober* prob, size_t packet_size);
void bitrate_prober_create_probe_cluster(bitrate_prober* prob, int bitrate, int64_t now, int cluster_id);
int64_t bitrate_prober_next_probe_time(bitrate_prober* prob, int64_t now);

void bitrate_prober_current_cluster(bitrate_prober* prob);

size_t bitrate_prober_recommended_min_probe_size(bitrate_prober* prob);
void bitrate_prober_probe_sent(bitrate_prober* prob, int64_t now, size_t probe_size);

#endif // __TEMPLE_RTC_PACING_BITRATE_PROBER_H__
