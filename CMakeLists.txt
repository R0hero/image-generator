cmake_minimum_required(VERSION 3.16)
project(image_generator CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    stb
    GIT_REPOSITORY https://github.com/nothings/stb.git
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(stb)

add_executable(image_generator
    src/main.cpp
)

target_include_directories(image_generator PRIVATE ${stb_SOURCE_DIR})