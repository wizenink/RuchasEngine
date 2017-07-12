cmake_minimum_required (VERSION 2.8.2)
project (Ruchas-Core)

set (CMAKE_CXX_FLAGS "-Wall")
set (CMAKE_CSS_STANDARD 17)
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)
include_directories (${CMAKE_PROJECT_DIR}/src)

option (testing "Enable Google Test" ON)

set (SOURCE_FILES src/main.cpp src/glad/glad.c)
if (testing)

	message("Testing enabled")
	configure_file (CMakeLists.txt.in googletest-download/CMakeLists.txt)
	execute_process (COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
		RESULT_VARIABLE result
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
	if (result)
		message(FATAL_ERROR "CMake step for googletest failed: ${result}")
	endif()

	execute_process(COMMAND ${CMAKE_COMMAND} --build .
  		RESULT_VARIABLE result
  		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
	if(result)
  		message(FATAL_ERROR "Build step for googletest failed: ${result}")
	endif()

	add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

	add_executable (tests ${SOURCE_FILES})
	target_link_libraries(tests gtest_main glfw)
endif()

add_executable (core ${SOURCE_FILES})

target_link_libraries(core glfw)

