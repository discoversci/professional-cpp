cmake_minimum_required(VERSION 3.29)

project(example01 VERSION 1.0.0 LANGUAGES CXX)

# system wide settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# user defined settings
set(LIBRARY_NAME "library")
set(EXECUTABLE "application")

add_executable(${EXECUTABLE}
        main.cpp
)

# subdirs include with their own CMakeLists.txt files
add_subdirectory(source)


# link libs into main program
target_link_libraries(${EXECUTABLE} PRIVATE
        ${LIBRARY_NAME}
)

