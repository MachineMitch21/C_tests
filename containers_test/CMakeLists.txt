CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

project(containers_test)

file(GLOB SOURCES   src/*.c         src/*.cc
                    src/math/*.c    src/math/*.cc
                    src/core/*.c    src/core/*.cc
                    src/utils/*.c   src/utils/*.cc  )

add_executable(${PROJECT_NAME} ${SOURCES})

add_definitions(-DCCONTAINERS_BUILD)

if (UNIX)
    set ( CMAKE_C_FLAGS "-Wall -std=c99")
endif (UNIX)

if (MINGW)
	set (CMAKE_C_FLAGS "-Wall -std=c99")
endif (MINGW)

link_directories(/build)
target_link_libraries(${PROJECT_NAME} c_containers)

target_include_directories(${PROJECT_NAME} PUBLIC include/)
