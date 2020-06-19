# CMake最低版本要求，如果低于3.10.1版本，则构建过程会被终止 
cmake_minimum_required(VERSION 3.5.1)

file(GLOB_RECURSE mains RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/main*.cpp")
foreach(mainfile IN LISTS mains)
    # Get file name without directory
    get_filename_component(mainname ${mainfile} NAME_WE)
    add_executable(${mainname} ${mainfile} BaseSocket.cpp XEpoll.cpp)
endforeach()