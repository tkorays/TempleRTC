#include <gtest/gtest.h>
extern "C" {
#include "base/array.h"
}

TEST(rtc_array_test, array_basic) {
    rtc_array* array = rtc_array_new(10, sizeof(int));
    EXPECT_NE(array, (rtc_array*)0);
}
