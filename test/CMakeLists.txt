cmake_minimum_required(VERSION 3.12)

project(unitTest)

include_directories(
	${CMAKE_SOURCE_DIR}/include
	${CMAKE_SOURCE_DIR}/thirdparty/googletest/googletest/include/
)
message(${CMAKE_SOURCE_DIR}/thirdparty/googletest/googletest/include/)

add_executable(${PROJECT_NAME} test.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main project_lib pthread)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})