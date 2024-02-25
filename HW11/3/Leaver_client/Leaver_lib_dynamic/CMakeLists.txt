#Leaver_lib
cmake_minimum_required(VERSION 3.22.0)
project(Leaver_lib)
set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "../../bin")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../bin")
set(SOURCES_LIB Leaver.cpp Leaver.h)
add_library(Leaver_lib SHARED ${SOURCES_LIB})