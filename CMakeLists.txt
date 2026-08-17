cmake_minimum_required(VERSION 3.20)

project(FileTree)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FileTree
    src/main.cpp
    src/Node.cpp
    src/File.cpp
    src/Directory.cpp
    src/FileSystem.cpp
    src/Shell.cpp
)

target_include_directories(FileTree PRIVATE include)