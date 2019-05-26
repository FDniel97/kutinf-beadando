cmake_minimum_required (VERSION 2.8.12)
project (plot)

find_package (Gnuplot REQUIRED)

#Target that generates data file
add_custom_command(COMMAND ${GNUPLOT_EXECUTABLE} ${PROJECT_SOURCE_DIR}/plot.plt
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                   OUTPUT ${CMAKE_BINARY_DIR}/plot.png
                   DEPENDS ${PROJECT_SOURCE_DIR}/plot.plt data
                   COMMENT "Generating plot")


#Making the png
add_custom_target(plottolas DEPENDS ${CMAKE_BINARY_DIR}/plot.png) 

