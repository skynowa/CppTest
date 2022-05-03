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
#--------------------------------------------------------------------------------------------------
# CONAN
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
#--------------------------------------------------------------------------------------------------
file(GLOB_RECURSE SOURCES
   ${CMAKE_SOURCE_DIR}/*.c
   ${CMAKE_SOURCE_DIR}/*.cpp)
#--------------------------------------------------------------------------------------------------
foreach(IT_SOURCE ${SOURCES})
	# Ignores
	if ("${IT_SOURCE}" MATCHES "Windows/"      OR
		"${IT_SOURCE}" MATCHES "WinException/" OR
		"${IT_SOURCE}" MATCHES "Libs/Qt/"      OR
		"${IT_SOURCE}" MATCHES "Libs/Pcre/"    OR
		"${IT_SOURCE}" MATCHES "Libs/XLib/"
	)
		message(STATUS "Skip: ${IT_SOURCE}")
		continue()
	endif()

	get_filename_component(CPP_TEST ${IT_SOURCE} NAME_WE [CACHE])

	add_executable(${CPP_TEST} ${IT_SOURCE})

	target_compile_options(${CPP_TEST} PRIVATE
		-Werror
		-Wall
		-Wextra
		# -pedantic
		# -Wconversion
		# -Wsign-conversion
	)

	target_include_directories(${CPP_TEST} PRIVATE
		${CMAKE_SOURCE_DIR}
		${CMAKE_SOURCE_DIR}/StdStream
		${CMAKE_SOURCE_DIR}/StdTest)

	target_link_libraries(${CPP_TEST} PRIVATE
		${CONAN_LIBS}
		-lstdc++fs)

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
