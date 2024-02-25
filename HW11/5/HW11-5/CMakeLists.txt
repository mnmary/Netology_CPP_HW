#Figure_lib_exe
cmake_minimum_required(VERSION 3.22.0)
project(Figure_lib_exe VERSION 0.1)
include_directories("FIGURE_DLL")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "../bin")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY  "../bin")
add_executable(Figure_lib_exe HW11-5.cpp)
add_subdirectory("FIGURE_DLL")
target_link_libraries (Figure_lib_exe Figure_lib)
