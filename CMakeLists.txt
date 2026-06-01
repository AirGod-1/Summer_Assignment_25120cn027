cmake_minimum_required(VERSION 3.20)
project(Summer_Assignment C)

set(CMAKE_C_STANDARD 99)

# This automatically finds every .c file in your DAY_ folders
file(GLOB_RECURSE SOURCES "DAY_*/*.c")

# This loop turns every .c file into its own runnable program
foreach(SOURCE ${SOURCES})
    get_filename_component(TARGET_NAME ${SOURCE} NAME_WE)
    add_executable(${TARGET_NAME} ${SOURCE})
endforeach()