cmake_minimum_required(VERSION 3.22)
project(Main)

set(CMAKE_CXX_STANDARD 20)
#file(GLOB_RECURSE inc ECS/*.h)
#file(GLOB_RECURSE src ECS/*.cpp)
#
#source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${inc})
#source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${src})
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS_DEBUG "-Zc:nrvo")

#string(REPLACE "/O2" "/Od" CMAKE_CXX_FLAGS_DEBUG
#"${CMAKE_CXX_FLAGS_DEBUG}")

add_executable(Main main.cpp ${inc} ${src})

