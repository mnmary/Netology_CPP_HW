#Greeter_lib
cmake_minimum_required(VERSION 3.22.0)
project(Greeter_lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "f:/CPP Homeworks/HW11/1/Greet_client/bin")
set(SOURCES_LIB Greeter.cpp Greeter.h)
add_library(Greeter_lib STATIC ${SOURCES_LIB})