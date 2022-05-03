#!/usr/bin/env bash
#
# Dev: skynowa-pc
#


# vars
PROJECT_NAME="CppTest"
DIR_BUILD="../${PROJECT_NAME}_build"

conan install \
	conan_file.txt \
	--install-folder="${DIR_BUILD}" \
	--output-folder="${DIR_BUILD}" \
	--profile=conan_profile_dev.txt \
	--build=missing \
	--update