cmake_minimum_required(VERSION 3.20)
project(WorkerManagementSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(WorkerManagementSystem

        include/workerManager.h
        include/manager.h
        include/employee.h
        include/cfs.hpp
        include/boss.h
        include/worker.h

        src/workerManager.cpp
        src/manager.cpp
        src/employee.cpp
        src/boss.cpp
        src/main.cpp
)

target_include_directories(
        WorkerManagementSystem
        PRIVATE include
)
