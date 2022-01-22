#ifndef __TEMPLE_RTC_PACING_PACED_SENDER_H__
#define __TEMPLE_RTC_PACING_PACED_SENDER_H__

typedef struct rtc_pacer rtc_pacer;

rtc_pacer* rtc_pacer_create();
void rtc_pacer_destroy(rtc_pacer* pacer);
void rtc_pacer_add_packet(rtc_pacer* pacer, void* pkt);
void rtc_pacer_create_probe_cluster(rtc_pacer* pacer, int probe_kbps, int cluster_id);
void rtc_pacer_pause(rtc_pacer* pacer);
void rtc_pacer_resume(rtc_pacer* pacer);
void rtc_pacer_set_pacing_rate(rtc_pacer* pacer, int kbps, int pading_kbps);
int rtc_pacer_queued_size(rtc_pacer* pacer);
int rtc_pacer_exp_queue_time(rtc_pacer* pacer);

#endif // __TEMPLE_RTC_PACING_PACED_SENDER_H__

