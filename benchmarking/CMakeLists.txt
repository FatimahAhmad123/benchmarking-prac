cmake_minimum_required(VERSION 3.12)

project(benchmarking)

set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON CACHE BOOL "Download and build Google Benchmark dependencies.")

set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "Enable testing of the benchmark library.")

set(BENCHMARK_SUBMODULE_BINARY_DIR ${CMAKE_BINARY_DIR}/thirdparty/benchmark)

add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/benchmark ${BENCHMARK_SUBMODULE_BINARY_DIR})
add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/googletest ${BENCHMARK_SUBMODULE_BINARY_DIR}/googletest)

add_executable(benchmarks_executable benchmarking_main.cpp benchmarking.hpp)

target_link_libraries(benchmarks_executable PRIVATE project_lib benchmark::benchmark)