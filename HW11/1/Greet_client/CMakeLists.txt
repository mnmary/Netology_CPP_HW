#Greeter_lib_exe
cmake_minimum_required(VERSION 3.22.0)
project(Greeter_lib_exe VERSION 0.1)
include_directories(Greeter_lib_static)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY  "f:/CPP Homeworks/HW11/1/Greet_client/bin")
add_executable(Greeter_lib_exe Greet_client.cpp)
add_subdirectory(Greeter_lib_static)
target_link_libraries (Greeter_lib_exe Greeter_lib)