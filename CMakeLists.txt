cmake_minimum_required(VERSION 3.10)
project(DSA_learning)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# Include directory
include_directories(include)

add_executable(DSA_learning src/main.cpp src/priority_queue.cpp)