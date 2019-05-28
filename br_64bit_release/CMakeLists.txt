cmake_minimum_required(VERSION 3.14)
project(BoxRouter)

set(CMAKE_CXX_STANDARD 14)

set(BoxRouter64_SRC BBox.cpp Boundary.cpp BoxRouter.cpp Design.cpp Grid.cpp GRouter.cpp ILPSolver.cpp Layer.cpp Net.cpp
        Object.cpp Param.cpp Pin.cpp Point.cpp Segment.cpp Util.cpp Wire.cpp MazeHeap.cpp)

#add_library(BoxRouter ${BoxRouter64_SRC})

