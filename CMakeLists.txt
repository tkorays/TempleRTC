cmake_minimum_required(VERSION 3.15)

project(TempleRTC C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message("CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
if (WIN32)
    add_definitions(-DRTC_WIN)
    add_definitions(-DHAVE_STRUCT_TIMESPEC)
endif()
if (UNIX)
    add_definitions(-DRTC_UNIX)
endif()
if (APPLE)
    add_definitions(-DRTC_APPLE)
endif()
if (ANDROID)
    add_definitions(-DRTC_ANDROID)
endif()

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    )
file(
    GLOB_RECURSE TEMPLE_RTC_SRC
    ${CMAKE_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/src/*.c
    )
aux_source_directory(
    ${CMAKE_SOURCE_DIR}/src
    TEMPLE_RTC_SRC
    )

add_library(TempleRTC ${TEMPLE_RTC_SRC})
if (UNIX)
    target_link_libraries(TempleRTC pthread)
endif()


set(CMAKE_CXX_STANDARD 11)
add_subdirectory(
    ${CMAKE_SOURCE_DIR}/third_party/googletest/
    EXCLUDE_FROM_ALL)
enable_testing()
add_executable(
  rtc_test
  ${CMAKE_SOURCE_DIR}/src/base/array_test.cpp
  ${CMAKE_SOURCE_DIR}/src/base/vector_test.cpp
  ${CMAKE_SOURCE_DIR}/src/modules/pacing/interval_budget_test.cpp
)
target_link_libraries(
    rtc_test
    TempleRTC
    gtest_main
)
include(googletest)
gtest_discover_tests(rtc_test)

