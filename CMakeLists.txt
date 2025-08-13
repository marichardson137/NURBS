cmake_minimum_required(VERSION 3.15)
project(MyRaylibProject)

set(CMAKE_CXX_STANDARD 17)

# Path to raylib headers and compiled lib
set(RAYLIB_DIR "${CMAKE_SOURCE_DIR}/external/raylib")
set(RAYLIB_INCLUDE_DIR "${RAYLIB_DIR}/include")
set(RAYLIB_LIB_DIR "${RAYLIB_DIR}/build")

# Executable name
set(EXECUTABLE_NAME "App")

# Add executable
add_executable(${EXECUTABLE_NAME} src/Main.cpp)

# Include raylib headers
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${RAYLIB_INCLUDE_DIR})

# Platform-specific linking
if(APPLE)
    message(STATUS "Configuring for macOS")

    # Link static raylib (.a)
    target_link_libraries(${EXECUTABLE_NAME} PRIVATE
        ${RAYLIB_LIB_DIR}/libraylib.a
    )

    # macOS frameworks
    target_link_libraries(${EXECUTABLE_NAME} PRIVATE
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
    )

elseif(WIN32)
    message(STATUS "Configuring for Windows")

    # Link static raylib (.lib)
    target_link_libraries(${EXECUTABLE_NAME} PRIVATE
        ${RAYLIB_LIB_DIR}/raylib.lib
    )

    # Windows-specific libraries required by raylib
    target_link_libraries(${EXECUTABLE_NAME} PRIVATE
        winmm
        gdi32
        opengl32
        shell32
    )
endif()
