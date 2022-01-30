#include <gtest/gtest.h>
extern "C" {
#include "base/vector.h"
}

TEST(TempleRTC_Base, vector_test) {
    rtc_vector vec;
    rtc_vector_new(&vec, sizeof(int));
    EXPECT_EQ(rtc_vector_is_empty(&vec), RTC_TRUE);
    rtc_vector_push_back_int(&vec, 1234);
    EXPECT_EQ(rtc_vector_size(&vec), 1);
    EXPECT_EQ(1234, rtc_vector_pop_front_int(&vec));
    EXPECT_EQ(rtc_vector_is_empty(&vec), RTC_TRUE);
}
