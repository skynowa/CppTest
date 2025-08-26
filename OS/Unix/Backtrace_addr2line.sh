#!/bin/bash
#
# \file  Backtrace_addr2line.sh
# \brief Compile
#


#--------------------------------------------------------------------------------------------------
# vars
CPP_BASE_NAME="Backtrace_addr2line"

CPP_STANDART="c++20"
INCLUDE_DIR="/home/skynowa/Projects/CppTest"
#---------------------------------------------------------------------------------------------------
# Clean
if [ -f "${CPP_BASE_NAME}.exe" ]; then
    echo "${CPP_BASE_NAME}.exe - Clean..."

    rm "${CPP_BASE_NAME}.exe"
fi
#---------------------------------------------------------------------------------------------------
# Build
echo "${CPP_BASE_NAME}.cpp - Compile..."

c++ -std=${CPP_STANDART} -g -O0 -rdynamic ./${CPP_BASE_NAME}.cpp -ldl -fno-omit-frame-pointer -fno-inline -no-pie -fpermissive -I ${INCLUDE_DIR} -o ./${CPP_BASE_NAME}.exe
#---------------------------------------------------------------------------------------------------
# Run
echo -e "${CPP_BASE_NAME}.exe - Run...\n"

./${CPP_BASE_NAME}.exe
#---------------------------------------------------------------------------------------------------
echo -e "\nOK.\n"
#---------------------------------------------------------------------------------------------------
