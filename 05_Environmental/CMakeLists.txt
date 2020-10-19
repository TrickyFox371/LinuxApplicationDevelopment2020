cmake_minimum_required(VERSION 3.1)
project(prog)

find_library(CURSES_LIBRARY ncursesw)
find_library(PCRE_LIBRARY pcre2-8)

add_executable(prog prog.c)

target_link_libraries(prog ${CURSES_LIBRARY} ${PCRE_LIBRARY})

option(WITHOUT_UTF "No UTF" OFF)
configure_file(config.h.in config.h)

set (TRASH ${CMAKE_BINARY_DIR}/CMakeCache.txt ${CMAKE_BINARY_DIR}/cmake_install.cmake ${CMAKE_BINARY_DIR}/Makefile ${CMAKE_BINARY_DIR}/CMakeFiles ${CMAKE_BINARY_DIR}/prog ${CMAKE_BINARY_DIR}/config.h)

add_custom_target(allclean
COMMAND rm -rf ${TRASH}
)
