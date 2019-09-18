cmake_minimum_required(VERSION 3.0.0)
project(Lab04 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Lab04 main.cpp graph.cpp graph.hpp routing_table.cpp routing_table.hpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
