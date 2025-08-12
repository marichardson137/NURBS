cmake_minimum_required(VERSION 3.15)
project(MyRaylibProject)

set(CMAKE_CXX_STANDARD 17)

# Path to raylib headers and compiled lib
set(RAYLIB_DIR "${CMAKE_SOURCE_DIR}/external/raylib")
set(RAYLIB_INCLUDE_DIR "${RAYLIB_DIR}/include")
set(RAYLIB_LIB_DIR "${RAYLIB_DIR}/build")

# Add executable
add_executable(MyRaylibApp src/Main.cpp)

# Include raylib headers
target_include_directories(MyRaylibApp PRIVATE ${RAYLIB_INCLUDE_DIR})

# Link raylib static library
target_link_libraries(MyRaylibApp PRIVATE
    ${RAYLIB_LIB_DIR}/libraylib.a
)

# Link required macOS frameworks
target_link_libraries(MyRaylibApp PRIVATE
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)
