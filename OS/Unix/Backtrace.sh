#!/bin/bash


CPP_BASE_NAME="./Backtrace"

c++ -g -O0 ./${CPP_BASE_NAME}.cpp -rdynamic -ldl -fpermissive -o ./${CPP_BASE_NAME}.exe
./${CPP_BASE_NAME}.exe
