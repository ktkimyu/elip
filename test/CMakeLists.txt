SET(TEST_DIR
    stats
   )

foreach(directory ${TEST_DIR})
    add_subdirectory(${directory})
endforeach()

