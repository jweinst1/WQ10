# sample png lib #

cmake_minimum_required(VERSION 3.5)

project(wq10)

add_subdirectory(libpng)

# PNG writing library
add_library(dopng STATIC dopng.c)
target_link_libraries(dopng png)
target_include_directories(dopng PUBLIC
                    ${PROJECT_SOURCE_DIR}/libpng
                    ${PROJECT_BINARY_DIR}/libpng)



# Builds the main CLI program.
add_executable(wq10 main.c)
target_link_libraries(wq10 dopng)
