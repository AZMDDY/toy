message("compile utility")

aux_source_directory(. SRCS)

add_subdirectory(fsm)

add_library(utility ${SRCS})