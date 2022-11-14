#--------------------------------------------------------------------------------------------------
# \file  CMakeLists.txt
# \brief Build CppTest
#--------------------------------------------------------------------------------------------------


#--------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.5.0)

project("CppTest")
#--------------------------------------------------------------------------------------------------
# options
set(PROJECT_TYPE                CXX)
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)
set(CMAKE_COLOR_MAKEFILE        ON)
set(CMAKE_VERBOSE_MAKEFILE      OFF)
set(CMAKE_REQUIRED_QUIET        ON)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Release - default build type" FORCE)
endif()
#--------------------------------------------------------------------------------------------------
# CONAN
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(X11 REQUIRED)
#--------------------------------------------------------------------------------------------------
file(GLOB_RECURSE SOURCES
   ${CMAKE_SOURCE_DIR}/*.c
   ${CMAKE_SOURCE_DIR}/*.cpp)
#--------------------------------------------------------------------------------------------------
foreach(IT_SOURCE ${SOURCES})
	# Ignores
	if ("${IT_SOURCE}" MATCHES "Libs/Qt/")
		message(STATUS "Skip: ${IT_SOURCE}")
		continue()
	endif()

	if     (WIN32)
		if ("${IT_SOURCE}" MATCHES "Libs/XLib/")
			message(STATUS "Skip: ${IT_SOURCE}")
			continue()
		endif()
	elseif (UNIX)
		if ("${IT_SOURCE}" MATCHES "Windows/" OR
			"${IT_SOURCE}" MATCHES "WinException/"
		)
			message(STATUS "Skip: ${IT_SOURCE}")
			continue()
		endif()
	endif()

	# CPP_TEST
	get_filename_component(CPP_TEST_DIR_PATH ${IT_SOURCE}         DIRECTORY [CACHE])
	get_filename_component(CPP_TEST_DIR_NAME ${CPP_TEST_DIR_PATH} NAME      [CACHE])
	get_filename_component(CPP_TEST_NAME     ${IT_SOURCE}         NAME_WE   [CACHE])

	set(CPP_TEST ${CPP_TEST_DIR_NAME}_${CPP_TEST_NAME})

	add_executable(${CPP_TEST} ${IT_SOURCE})

	# EXTRA_WARNINGS
	if (MSVC)
		set(EXTRA_WARNINGS /W4 /WX)
	else()
		set(EXTRA_WARNINGS -Wall -Wextra -pedantic -Werror)
	endif()

	target_compile_options(${CPP_TEST} PRIVATE ${EXTRA_WARNINGS})

	target_include_directories(${CPP_TEST} PRIVATE
		${CMAKE_SOURCE_DIR}
		${X11_INCLUDE_DIR})

	target_link_libraries(${CPP_TEST} PRIVATE
		${CONAN_LIBS}
		-lstdc++fs
		${X11_LIBRARIES})

	# Targets - Build and run test
	add_custom_target(test_${CPP_TEST}
		COMMAND           ${CPP_TEST}
		DEPENDS           ${CPP_TEST}
		WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
endforeach()
#--------------------------------------------------------------------------------------------------
# Targets
add_custom_target(roadmap
	COMMAND           "${CMAKE_SOURCE_DIR}/Roadmap.py"
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
#--------------------------------------------------------------------------------------------------
