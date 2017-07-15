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
add_definitions(-DGLFW_INCLUDE_NONE)
include_directories (${CMAKE_PROJECT_DIR}/src)

option (testing "Enable Google Test" ON)
option(BUILD_DOC "Build documentation" ON)

find_package (Doxygen)
if (DOXYGEN_FOUND)
	set (DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
	set (DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
	configure_file (${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
	message ("Doxygen build started")
	add_custom_target (doc_doxygen ALL
		COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating API documentation with Doxygen"
		VERBATIM)
else (DOXYGEN_FOUND)
	message("Doxygen must be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

set (SOURCE_FILES src/main.cpp src/glad/glad.c src/window/window.h src/window/window.cpp src/shaders/shader.h src/shaders/shader.cpp)
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

