cmake_minimum_required(VERSION 3.30)
project(disable_me)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        endstone
        GIT_REPOSITORY https://github.com/EndstoneMC/endstone.git
        GIT_TAG v0.5.4.1
)
FetchContent_MakeAvailable(endstone)

endstone_add_plugin(${PROJECT_NAME} src/disable_me.cpp)
