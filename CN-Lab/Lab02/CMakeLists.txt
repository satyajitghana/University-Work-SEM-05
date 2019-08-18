cmake_minimum_required(VERSION 3.0.0)
project(Lab02 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Lab02 main.cpp crc_lib.cpp crc_lib.hpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
