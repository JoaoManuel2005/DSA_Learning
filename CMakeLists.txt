cmake_minimum_required(VERSION 3.10)
project(DSA_learning)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# Include directory
include_directories(include)

add_executable(DSA_learning src/main.cpp src/sorting_algorithms.cpp src/search_algorithms.cpp src/btree.cpp src/btree_node.cpp)