cmake_minimum_required(VERSION 3.8)
project(GLTest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp lesson_1/LessonOne.cpp lesson_1/LessonOne.h)
#增加链接库
link_libraries(-lglut -lGL -lGLU )
add_executable(GLTest ${SOURCE_FILES})