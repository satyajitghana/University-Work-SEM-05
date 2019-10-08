cmake_minimum_required(VERSION 3.0.0)
project(gst-c VERSION 0.1.0)

set(CMAKE_C_STANDARD 99)

include(CTest)
enable_testing()

add_executable(gst-c main.c array_list.h array_list.c gst_item.h gst_item.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
