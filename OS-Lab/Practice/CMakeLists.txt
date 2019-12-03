cmake_minimum_required(VERSION 3.10.0)
project(Practice VERSION 0.1.0)

include(CTest)
enable_testing()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(Practice main.cpp fileio.cpp rw.cpp banker.cpp)

target_link_libraries(Practice Threads::Threads)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
