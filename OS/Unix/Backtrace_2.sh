#!/bin/bash


CPP_BASE_NAME="./Backtrace_2"

echo "Compile ${CPP_BASE_NAME}.cpp ..."
c++ -g -O0 ./${CPP_BASE_NAME}.cpp -rdynamic -ldl -fpermissive -o ./${CPP_BASE_NAME}.exe

echo "Run..."
./${CPP_BASE_NAME}.exe
