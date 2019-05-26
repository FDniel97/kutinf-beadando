cmake_minimum_required (VERSION 2.8.12)
project (Application LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp) ##add executable
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11) # enable c++11

add_custom_command(COMMAND Application
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                   OUTPUT ${CMAKE_BINARY_DIR}/plot/data.dat
                   DEPENDS Application
COMMENT "Generating data set")

add_custom_target(data ALL DEPENDS ${CMAKE_BINARY_DIR}/plot/data.dat)

