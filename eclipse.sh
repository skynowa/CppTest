#!/usr/bin/env bash
#
# \file  eclipse.sh
# \brief CMake configure project
#


# vars
PROJECT_NAME=$(basename ${PWD})
DIR_PROJECT="../${PROJECT_NAME}"
DIR_BUILD="../${PROJECT_NAME}_eclipse"
ECLIPSE_VERSION="4.17" # 2020-09

echo "PROJECT_NAME: ${PROJECT_NAME}"
echo "DIR_PROJECT: ${DIR_PROJECT}"
echo "DIR_BUILD: ${DIR_BUILD}"
echo "ECLIPSE_VERSION: ${ECLIPSE_VERSION}"

# prepare
mkdir -p $DIR_BUILD
cd $DIR_BUILD

# build
cmake \
	-G"Eclipse CDT4 - Unix Makefiles" \
	-D_ECLIPSE_VERSION=${ECLIPSE_VERSION} \
	-DCMAKE_ECLIPSE_GENERATE_SOURCE_PROJECT=TRUE \
	$DIR_PROJECT
