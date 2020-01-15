cmake_minimum_required(VERSION 3.8)

project(mapbyenum LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(3rdparty/magic_enum/include)

include_directories(include)

add_executable(${CMAKE_PROJECT_NAME} example/main.cpp)

