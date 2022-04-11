cmake_minimum_required(VERSION 3.10)

project(threadpool)

aux_source_directory(src/ SRC_LIST)
aux_source_directory(test/ SRC_LIST)

include_directories(src)

add_executable(test ${SRC_LIST})
target_link_libraries(test pthread)