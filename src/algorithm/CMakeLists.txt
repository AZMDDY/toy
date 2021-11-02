message("compile algorithm")

include_directories(../utility)

add_subdirectory(astar)

aux_source_directory(. SRCS)

add_library(algorithm ${SRCS} astar/astar.cpp astar/astar.h)