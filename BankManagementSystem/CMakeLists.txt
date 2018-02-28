CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

project(bms)

file(GLOB SOURCES src/*.c)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include/)

link_directories(${CMAKE_SOURCE_DIR}/lib ${CMAKE_SOURCE_DIR}/build)

find_library(${SQLITE_LIB} sqlite3 ${CMAKE_SOURCE_DIR}/build)

target_link_libraries(${PROJECT_NAME} ${SQLITE_LIB})
