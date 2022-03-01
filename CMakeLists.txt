cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

project(img2ascii)

find_package(OpenCV PATHS contrib/build)

message(STATUS "OpenCV_INCLUDE_DIRS - ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBS - ${OpenCV_LIBS}")

# Additional Include Directories
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Additional Library Directories
link_directories( ${OpenCV_LIB_DIR} )

file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} opencv_imgcodecs)
