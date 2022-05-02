#--------------------------------------------------------------------------------------------------
# \file  CMakeLists.txt
# \brief Build CppTest
#--------------------------------------------------------------------------------------------------


#--------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.5.0)

project("CppTest")
#--------------------------------------------------------------------------------------------------
# options
set(PROJECT_TYPE                "CXX")
set(CMAKE_COLOR_MAKEFILE        ON)
set(CMAKE_VERBOSE_MAKEFILE      OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_REQUIRED_QUIET        ON)
set(CMAKE_CXX_STANDARD          17)
#--------------------------------------------------------------------------------------------------
# CONAN
set(CONAN_BUILD_INFO "${CMAKE_SOURCE_DIR}/../CppTest_conan/conanbuildinfo.cmake")
include(${CONAN_BUILD_INFO})
conan_basic_setup()
#--------------------------------------------------------------------------------------------------
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/StdStream)
include_directories(${CMAKE_SOURCE_DIR}/StdTest)
#--------------------------------------------------------------------------------------------------
file(GLOB_RECURSE SOURCES
	${CMAKE_SOURCE_DIR}/*.c
	${CMAKE_SOURCE_DIR}/*.cpp)

foreach(IT_SOURCE ${SOURCES})
	# ignores
	if (WIN32)
		# TODO: ignores
	else()
		if ("${IT_SOURCE}" MATCHES "Windows/" OR
			"${IT_SOURCE}" MATCHES "WinException/"
		)
			message(STATUS "Skip: ${IT_SOURCE}" )
			continue()
		endif()
	endif()

	if ("${IT_SOURCE}" MATCHES "Libs/Qt/"   OR
	    "${IT_SOURCE}" MATCHES "Libs/Pcre/" OR
		"${IT_SOURCE}" MATCHES "Libs/XLib/"
	)
		message(STATUS "Skip: ${IT_SOURCE}" )
		continue()
	endif()

	get_filename_component(CPP_TEST ${IT_SOURCE} NAME_WE [CACHE])
	add_executable(${CPP_TEST} ${IT_SOURCE})
	target_link_libraries(${CPP_TEST} ${CONAN_LIBS})

	# Targets - Build and run test
	add_custom_target(
		test_${CPP_TEST}
		COMMAND           ${CPP_TEST}
		DEPENDS           ${CPP_TEST}
		WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

endforeach()
#--------------------------------------------------------------------------------------------------
# Targets
add_custom_target(
	roadmap
	COMMAND           "${CMAKE_SOURCE_DIR}/Roadmap.py"
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
#--------------------------------------------------------------------------------------------------
