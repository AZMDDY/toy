message("compile utility")

aux_source_directory(. SRCS)

add_library(utility ${SRCS})