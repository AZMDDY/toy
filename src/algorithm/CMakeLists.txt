message("compile algorithm")

include_directories(../utility)

aux_source_directory(. SRCS)

add_library(algorithm ${SRCS})