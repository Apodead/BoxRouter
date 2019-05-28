cmake_minimum_required(VERSION 3.14)
project(Router_clion)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

add_subdirectory(flute)
#add_subdirectory(br_64bit_release)

find_package(Threads)

include_directories(br_64bit_release)
include_directories(include)
include_directories(include/def)
include_directories(include/glpk-4.10)
include_directories(include/glpk-4.10/include)
include_directories(include/lef)

link_directories(lib)
link_directories(lib/def)
link_directories(lib/lef)

#aux_source_directory(br_64bit_release BoxRouter64_SRC)
set(BoxRouter64_SRC
        br_64bit_release/BBox.cpp
        br_64bit_release/Boundary.cpp
        br_64bit_release/BoxRouter.cpp
        br_64bit_release/Design.cpp
        br_64bit_release/Grid.cpp
        br_64bit_release/GRouter.cpp
        br_64bit_release/ILPSolver.cpp
        br_64bit_release/Layer.cpp
        br_64bit_release/Net.cpp
        br_64bit_release/Object.cpp
        br_64bit_release/Param.cpp
        br_64bit_release/Pin.cpp
        br_64bit_release/Point.cpp
        br_64bit_release/Segment.cpp
        br_64bit_release/Util.cpp
        br_64bit_release/Wire.cpp
        br_64bit_release/MazeHeap.cpp)

add_executable(Router ${BoxRouter64_SRC})
target_link_libraries(Router flute glpk curses)
target_link_libraries(Router ${CMAKE_THREAD_LIBS_INIT})

add_executable(test test/testReader.cpp)
target_link_libraries(test lef def)

