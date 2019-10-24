cmake_minimum_required(VERSION 3.0.0)
project(Lab07 VERSION 0.1.0)

include(CTest)
enable_testing()


# set(CXX_STANDARD 17)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(Lab07 main.cpp)

set_property(TARGET Lab07 PROPERTY CXX_STANDARD 17)
target_link_libraries(${PROJECT_NAME} Threads::Threads)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
