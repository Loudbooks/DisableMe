cmake_minimum_required(VERSION 3.30)
project(disable_me)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_NAME "disable_me")

if(WIN32)
    set(OS_NAME "windows")
elseif(UNIX)
    set(OS_NAME "linux")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    set(OUTPUT_NAME "${OUTPUT_NAME}_${OS_NAME}_debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(OUTPUT_NAME "${OUTPUT_NAME}_${OS_NAME}")
endif()

include(FetchContent)
FetchContent_Declare(
        endstone
        GIT_REPOSITORY https://github.com/EndstoneMC/endstone.git
        GIT_TAG v0.5.4.1
)
FetchContent_MakeAvailable(endstone)

endstone_add_plugin(${PROJECT_NAME} src/disable_me.cpp)
set_target_properties(disable_me PROPERTIES OUTPUT_NAME ${OUTPUT_NAME})