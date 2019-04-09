# hashing code dir

include_directories(${PROJECT_SOURCE_DIR})

SET(wq10_hash_sources
   image_grid.c
)

add_library(wq10_hash STATIC "${wq10_hash_sources}")
