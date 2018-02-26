CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

project(bms)

file(GLOB SOURCES src/*.c)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include/)

link_directories(${PROJECT_SOURCE_DIR}/build)
