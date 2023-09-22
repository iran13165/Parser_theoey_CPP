cmake_minimum_required(VERSION 3.27)
project(backtrack_parser VERSION 1.0.0 LANGUAGES C CXX)

add_executable(Executable main.cpp)

add_library(Library predictive_parser.cpp)
target_link_libraries(Executable PUBLIC Library)

