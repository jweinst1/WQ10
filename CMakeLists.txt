# sample png lib #

cmake_minimum_required(VERSION 3.5)

project(wq10)

add_subdirectory(libpng)

# PNG writing library
add_library(dopng STATIC dopngs/dopng.c)
target_link_libraries(dopng png)
target_include_directories(dopng PUBLIC
                    ${PROJECT_SOURCE_DIR}/libpng
                    ${PROJECT_BINARY_DIR}/libpng)

# Makes the dopng header and hash header available
include_directories(${PROJECT_SOURCE_DIR}/dopngs ${PROJECT_SOURCE_DIR}/hash)

# wq10 definitions
# WQ10_OUTPUT_TITLE - Determines meta title written to output PNG
#---------------------------------------------#
add_definitions(-DWQ10_OUTPUT_TITLE="wq10_hash")

# Builds the hash related code.
add_subdirectory(hash)

# Builds the main CLI program.
add_executable(wq10 main.c)
target_link_libraries(wq10 dopng wq10_hash)
