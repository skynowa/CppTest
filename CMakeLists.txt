#--------------------------------------------------------------------------------------------------
# \file  CMakeLists.txt
# \brief Build CppTest
#--------------------------------------------------------------------------------------------------


project("CppTest")
cmake_minimum_required(VERSION 2.6)

#--------------------------------------------------------------------------------------------------
# options
set(PROJECT_TYPE                "CXX")

set(CMAKE_COLOR_MAKEFILE        ON)
set(CMAKE_VERBOSE_MAKEFILE      OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_REQUIRED_QUIET        ON)

set(CMAKE_CXX_STANDARD          17)
#--------------------------------------------------------------------------------------------------
# Boost
find_package(Boost COMPONENTS program_options filesystem system)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()
#--------------------------------------------------------------------------------------------------
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/StdStream)
include_directories(${CMAKE_SOURCE_DIR}/StdTest)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -Wextra -Weffc++")
set(LIBRARIES ${CMAKE_THREAD_LIBS} ${CMAKE_DL_LIBS} stdc++fs pthread rt m z)
#--------------------------------------------------------------------------------------------------
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)

foreach(IT_SOURCE ${SOURCES})
	# ignores
	if(WIN32)
		# TODO: ignores
	else()
		if ("${IT_SOURCE}" MATCHES "Windows/" OR
			"${IT_SOURCE}" MATCHES "WinException/"
		)
			message(STATUS "Skip: ${IT_SOURCE}" )
			continue()
		endif()
	endif()

	if ("${IT_SOURCE}" MATCHES "Libs/")
		message(STATUS "Skip: ${IT_SOURCE}" )
		continue()
	endif()

	get_filename_component(CPP_TEST ${IT_SOURCE} NAME_WE [CACHE])
	add_executable(${CPP_TEST} ${IT_SOURCE})
	target_link_libraries(${CPP_TEST} ${LIBRARIES})
endforeach()
#--------------------------------------------------------------------------------------------------
