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

FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.16.0
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(catch2)

add_library(image_generator_lib
    src/canvas.cpp
    src/colormap.cpp
)
target_include_directories(image_generator_lib PUBLIC include PRIVATE ${stb_SOURCE_DIR})

add_executable(tests 
    tests/test_colormap.cpp
)
target_link_libraries(tests PRIVATE image_generator_lib Catch2::Catch2WithMain)

add_executable(image_generator
    src/main.cpp
)
target_link_libraries(image_generator PRIVATE image_generator_lib)