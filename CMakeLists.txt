cmake_minimum_required(VERSION 3.23)
project(EvolutionSimulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SHARED_LIB TRUE)

add_subdirectory(src)

add_subdirectory(vendor)