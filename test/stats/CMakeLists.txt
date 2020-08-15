add_executable(stats_test stats.cpp)

target_link_libraries(stats_test PRIVATE Stats)

add_test(NAME stats
    COMMAND stats_test)
