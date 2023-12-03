cmake_minimum_required(VERSION 3.12)

project(unitTesting)

# Include subdirectories
add_subdirectory(src)
add_subdirectory(app)

option(BUILD_TEST "Builds the tests." ON)

if(BUILD_TEST)
	message("Building Test")
	add_subdirectory(test)
elseif()
	message("Test Disabled")
endif()