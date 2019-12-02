# CMakeList.txt : CMake project for image_processing, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project(pc4)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)


if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic -Wextra")
endif()

add_executable (pc4 main.cpp lodepng.cpp lodepng.h functions.h functions.cpp)
target_link_libraries(pc4 Threads::Threads)
