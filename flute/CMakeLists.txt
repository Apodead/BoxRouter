cmake_minimum_required(VERSION 3.14)
project(Router_clion)

set(CMAKE_C_STANDARD 11)

set(flute_SRC dl.c dist.c dl.c err.c heap.c mst2.c neighbors.c
        bookshelf_IO.c memAlloc.c flute.c flute_mst.c)
#set(flute_SRC flute.c)

include_directories(.)

add_library(flute ${flute_SRC})
target_link_libraries(flute m)
