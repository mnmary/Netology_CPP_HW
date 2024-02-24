#Leaver_lib_exe
cmake_minimum_required(VERSION 3.22.0)
project(Leaver_lib_exe VERSION 0.1)
include_directories("Leaver_lib_dynamic")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "f:/CPP Homeworks/HW11/3/Leaver_client/bin")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY  "f:/CPP Homeworks/HW11/3/Leaver_client/bin")
add_executable(Leaver_lib_exe leaver_client.cpp)
add_subdirectory(Leaver_lib_dynamic)
target_link_libraries (Leaver_lib_exe Leaver_lib)
