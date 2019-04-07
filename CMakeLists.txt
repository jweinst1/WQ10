# sample png lib #

cmake_minimum_required(VERSION 3.5)

project(png_template)

add_subdirectory(libpng)


add_library(dopng STATIC dopng.c)
target_link_libraries(dopng png)
target_include_directories(dopng PUBLIC
                    ${PROJECT_SOURCE_DIR}/libpng
                    ${PROJECT_BINARY_DIR}/libpng)

# Builds the sample executable program
add_subdirectory(example)
