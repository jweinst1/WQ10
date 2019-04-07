# Example png-template program

include_directories(${PROJECT_SOURCE_DIR})

add_executable(png-example example_png.c)
target_link_libraries(png-example dopng)
