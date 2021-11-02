message("compile astar")

aux_source_directory(. SRCS)

add_library(algorithm_astar ${SRCS})