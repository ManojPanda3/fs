cmake_minimum_required(VERSION 3.10)
project(fs)

# Use pkg-config to find PCRE2
find_package(PkgConfig REQUIRED)
pkg_check_modules(PCRE2 REQUIRED libpcre2-8)

# Include the src directory for the .c includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${PCRE2_INCLUDE_DIRS})

# Collect source files
file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
# Remove hash.c as it requires uthash which may not be installed
list(REMOVE_ITEM SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/hash.c")
# Collect header files for IDE visibility
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")

# Create executable from all source files; headers are added so they appear in IDEs
add_executable(fs ${SRC_FILES} ${HEADER_FILES})

# Link against PCRE2
target_link_libraries(fs ${PCRE2_LIBRARIES})
