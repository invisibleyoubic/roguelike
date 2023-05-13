cmake_minimum_required(VERSION 3.2.0)

project(roguelike VERSION 0.0.1)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(glfw3 REQUIRED)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(PROJECT_LIB_DIR ${PROJECT_INCLUDE_DIR}/libs)
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

set(PROJECT_INCLUDES 
    ${PROJECT_INCLUDE_DIR}/test.hpp)

set(PROJECT_LIBS
    ${PROJECT_LIB_DIR}/glad.h
    ${PROJECT_LIB_DIR}/glad.c)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/test.cpp)

add_executable(roguelike
    ${PROJECT_INCLUDES}
    ${PROJECT_LIBS}
    ${PROJECT_SOURCES}
    main.cpp)

target_include_directories(roguelike PRIVATE include)
target_sources(roguelike PRIVATE src)

target_link_libraries(roguelike PRIVATE
    GL
    GLU
    glut
    glfw)