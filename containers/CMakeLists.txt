CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

project(c_containers)

file(GLOB SOURCES   src/*.c         src/*.cc
                    src/math/*.c    src/math/*.cc
                    src/core/*.c    src/core/*.cc
                    src/utils/*.c   src/utils/*.cc  )

add_library(${PROJECT_NAME} SHARED ${SOURCES})

add_definitions(-DCCONTAINERS_BUILD)

if (UNIX)
    set ( CMAKE_C_FLAGS "-Wall -std=c99")
endif (UNIX)

if (MINGW)
	set (CMAKE_C_FLAGS "-Wall -std=c99")
endif (MINGW)

target_include_directories(${PROJECT_NAME} PUBLIC include/)
