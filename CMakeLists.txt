cmake_minimum_required(VERSION 2.8.9)
project(GAME)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "include/*.h")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(GAME ${SOURCES})

target_link_libraries(GAME SDL2 SDL2_image dl)
