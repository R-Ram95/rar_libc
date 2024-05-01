cmake_minimum_required(VERSION 3.29.1)

project(HTTP_SERVER)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# source files for executeable
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.hpp")

# source files for statically linked library
file(GLOB_RECURSE LIB_FILES "src/*.cpp" "src/*.hpp" EXCLUDE "src/Networking/Servers/")
file(GLOB_RECURSE HEADER_FILES "src/*.hpp" EXCLUDE "src/Networking/Servers/*.hpp")


# make exectueable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# make library
add_library(rar_libc STATIC ${LIB_FILES})

# include the header files
target_include_directories(rar_libc PUBLIC "src/") 
file(COPY ${HEADER_FILES} DESTINATION ${CMAKE_BINARY_DIR}/headers)
