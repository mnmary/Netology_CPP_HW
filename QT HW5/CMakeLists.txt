cmake_minimum_required(VERSION 3.5)

project(StopWatch VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        stopwatch.h
        stopwatch.cpp

)

add_executable(StopWatch
        ${PROJECT_SOURCES}
    )


target_link_libraries(StopWatch PRIVATE Qt6::Widgets)


