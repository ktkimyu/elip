SET(SRC_DIR
    stats
    )

foreach(directory ${SRC_DIR})
    add_subdirectory(${directory})
endforeach()

# Create a library containing all the libraries
add_library(${PROJECT_ROOT_NAME} INTERFACE)

target_link_libraries(${PROJECT_ROOT_NAME} INTERFACE
    )

install(TARGETS ${PROJECT_ROOT_NAME}
    EXPORT "${PROJECT_ROOT_NAME}Targets"
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

# Install all header files
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/elip
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h"
    )

