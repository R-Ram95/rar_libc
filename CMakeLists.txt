cmake_minimum_required(VERSION 3.29.1)

project(rar_libc)

set(CMAKE_CXX_STANDARD 17)

# Source files for the executable
file(GLOB_RECURSE EXECUTABLE_SOURCE_FILES "src/*.cpp")

# Source files for the statically linked library
file(GLOB_RECURSE LIBRARY_SOURCE_FILES "src/Networking/*.cpp")
file(GLOB_RECURSE LIBRARY_HEADER_FILES "include/*.hpp")

# Create the executable
add_executable(${PROJECT_NAME} ${EXECUTABLE_SOURCE_FILES})

# Create the statically linked library
add_library(${PROJECT_NAME} STATIC ${LIBRARY_SOURCE_FILES})

# Include directories for the library
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Copy header files to binary directory
file(COPY ${LIBRARY_HEADER_FILES} DESTINATION ${CMAKE_BINARY_DIR}/include/RAR)
