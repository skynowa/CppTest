#!/usr/bin/env bash
#
# Dev: skynowa-pc
#


# vars
PROJECT_NAME="CppTest"
DIR_BUILD="../${PROJECT_NAME}_build"
CONAN_PROFILE="conan_profile_dev.txt"

conan install \
	conan_file.txt \
	--deployer-folder="${DIR_BUILD}" \
	--output-folder="${DIR_BUILD}" \
	--profile="${CONAN_PROFILE}" \
	--build=missing \
	--update
