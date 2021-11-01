set(PROJECT_NAME "toy")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(utility)
add_subdirectory(algorithm)

include_directories(utility)
include_directories(algorithm)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} utility)
