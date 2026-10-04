cmake_minimum_required(VERSION 3.10)
project(fs)

# Use pkg-config to find PCRE2
find_package(PkgConfig REQUIRED)
pkg_check_modules(PCRE2 REQUIRED libpcre2-8)

# Include the src directory for the .c includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${PCRE2_INCLUDE_DIRS})

# The executable: we only compile main.c because it includes the other .c files
add_executable(fs src/main.c)

# Link against PCRE2
target_link_libraries(fs ${PCRE2_LIBRARIES})