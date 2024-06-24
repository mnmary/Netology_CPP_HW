cmake_minimum_required(VERSION 2.20)

project(SQL_HW05)
SET (PostgreSQL_ADDITIONAL_VERSIONS "16")
SET(PostgreSQL_ROOT "c:\\Program Files\\PostgreSQL\\16\\")

add_subdirectory("f:\\libpqxx-7.9.1" libpqxx-build)

add_executable(SQL_HW05 main.cpp "main.cpp" "MyClientBase.cpp" "MyClientBase.h")

target_compile_features(SQL_HW05 PRIVATE cxx_std_17)

target_link_libraries(SQL_HW05 PRIVATE pqxx)