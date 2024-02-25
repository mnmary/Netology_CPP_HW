#Figure_lib
cmake_minimum_required(VERSION 3.22.0)
project(Figure_lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "../../bin")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../bin")
file(GLOB SOURCES_LIB *.cpp *.h)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(Figure_lib SHARED ${SOURCES_LIB})