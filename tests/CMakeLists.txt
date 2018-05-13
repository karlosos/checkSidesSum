project(checksidessumtests)
add_subdirectory(googletest/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(runchecksidessumtests checksidessumtests.cpp)
target_link_libraries(runchecksidessumtests gtest gtest_main)
target_link_libraries(runchecksidessumtests checksidessum)
