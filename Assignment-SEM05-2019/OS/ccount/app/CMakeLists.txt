project(ccount VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(ccount main.cpp file_ops.cpp file_ops.hpp threader.cpp threader.hpp)

target_compile_features(ccount PRIVATE cxx_std_17)

target_link_libraries(ccount Threads::Threads)
target_link_libraries(ccount stdc++fs)