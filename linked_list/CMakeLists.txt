CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

project(linked_list)

file(GLOB SOURCES *.c)

add_executable(${PROJECT_NAME} ${SOURCES})
