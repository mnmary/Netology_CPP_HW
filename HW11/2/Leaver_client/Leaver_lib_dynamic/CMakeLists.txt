#Leaver_lib
cmake_minimum_required(VERSION 3.22.0)
project(Leaver_lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "f:/CPP Homeworks/HW11/2/Leaver_client/bin")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "f:/CPP Homeworks/HW11/2/Leaver_client/bin")
set(SOURCES_LIB Leaver.cpp Leaver.h)
add_library(Leaver_lib SHARED ${SOURCES_LIB})