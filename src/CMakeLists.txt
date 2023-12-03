cmake_minimum_required(VERSION 3.12)

project(unitTesting)

add_library(project_lib STATIC
	student.cpp
	whitelist.cpp
)

target_include_directories(project_lib PUBLIC
	${CMAKE_SOURCE_DIR}/include
)
