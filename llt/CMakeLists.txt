set(PROJECT_NAME toy_llt)

include_directories(${PROJECT_SOURCE_DIR}/thirdparty/include)
include_directories(${PROJECT_SOURCE_DIR}/src/utility)
include_directories(${PROJECT_SOURCE_DIR}/src/algorithm)
include_directories(${PROJECT_SOURCE_DIR}/src/algorithm/astar)

link_directories(${PROJECT_SOURCE_DIR}/thirdparty/lib)

project(${PROJECT_NAME})

aux_source_directory(. SRCS)

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME}
        gtest_main gtest
        pthread
        utility
        algorithm
        algorithm_astar
        )
