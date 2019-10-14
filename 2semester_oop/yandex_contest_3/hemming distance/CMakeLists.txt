cmake_minimum_required(VERSION 3.9)
project(hemming_distance)

set(CMAKE_CXX_STANDARD 17)

add_executable(hemming_distance RE4_gen.cpp RE4.cpp TL40.cpp WA3.cpp TL40_gen.cpp gentest.cpp gentest.h TL40_1.cpp)