#!/usr/bin/env bash
#
# \file  eclipse.sh
# \brief CMake configure project
#


# vars
PROJECT_NAME=$(basename ${PWD})
DIR_PROJECT="../${PROJECT_NAME}"
DIR_BUILD="../${PROJECT_NAME}_eclipse"

# prepare
mkdir -p $DIR_BUILD
cd $DIR_BUILD

# build
cmake \
	-G"Eclipse CDT4 - Unix Makefiles" \
	$DIR_PROJECT
