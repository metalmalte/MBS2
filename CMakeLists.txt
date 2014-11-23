cmake_minimum_required(VERSION 2.8.4)
project(MIPExercise2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/ContrastStretchingFilter.cpp
    src/ContrastStretchingFilter.h
    src/Image.cpp
    src/Image.h
    src/ImageFilter.cpp
    src/ImageFilter.h
    src/ImageIO.cpp
    src/ImageIO.h
    src/MIPContrastStretching.cpp
    src/MIPShiftScale.cpp
    src/MIPWindowLevel.cpp
    src/ShiftScaleFilter.cpp
    src/ShiftScaleFilter.h
    src/WindowLevelFilter.cpp
    src/WindowLevelFilter.h)

add_executable(MIPExercise2 ${SOURCE_FILES})