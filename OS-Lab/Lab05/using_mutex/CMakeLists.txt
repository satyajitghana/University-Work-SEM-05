cmake_minimum_required(VERSION 3.0.0)
project(Lab05 VERSION 0.1.0)

include(CTest)
enable_testing()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(Lab05 main.cpp)

target_link_libraries(Lab05 Threads::Threads)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
