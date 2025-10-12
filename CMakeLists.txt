cmake_minimum_required(VERSION 4.0)
project(TasksNowSimple)

set(CMAKE_CXX_STANDARD 20)

include_directories(nlohmann)
include_directories(storage)
include_directories(task)

add_executable(TasksNowSimple
        nlohmann/json.hpp
        storage/Storage.cpp
        storage/Storage.h
        task/Task.cpp
        task/Task.h
        TasksNowSimple.cpp)
