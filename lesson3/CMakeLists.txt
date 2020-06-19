cmake_minimum_required(VERSION 3.5.1)
project(XThread)

aux_source_directory(. SRC_LIST)
add_executable(main ${SRC_LIST})
find_package(Threads)

target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})