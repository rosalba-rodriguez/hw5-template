include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicHW5Tests ../basic_tests/basic_check.cpp)

target_link_libraries(runBasicHW5Tests gtest gtest_main)
target_link_libraries(runBasicHW5Tests hw5_library)