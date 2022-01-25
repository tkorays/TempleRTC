#ifndef __TEMPLE_RTC_PACING_ROUND_ROBIN_PACKET_QUEUE_H__
#define __TEMPLE_RTC_PACING_ROUND_ROBIN_PACKET_QUEUE_H__

#include <stdint.h>
#include "base/types.h"

typedef struct packet_queue packet_queue;

packet_queue* packet_queue_new();
void packet_queue_delete(packet_queue* q);
void packet_queue_init(packet_queue* q);
void packet_queue_deinit(packet_queue* q);
void packet_queue_push(packet_queue* q, int priority, int64_t enque_time, void* packet);
void packet_queue_pop(packet_queue* q);
rtc_bool packet_queue_empty(packet_queue* q);
size_t packet_queue_packets(packet_queue* q);
size_t packet_queue_size(packet_queue* q);
int64_t packet_queue_avg_qtime(packet_queue* q);

#endif // __TEMPLE_RTC_PACING_ROUND_ROBIN_PACKET_QUEUE_H__

