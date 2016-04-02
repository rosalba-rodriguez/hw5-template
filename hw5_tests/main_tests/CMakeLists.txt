include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runMainHW5Tests ../main_tests/main_check.cpp)

target_link_libraries(runMainHW5Tests gtest gtest_main)
target_link_libraries(runMainHW5Tests hw5_library)