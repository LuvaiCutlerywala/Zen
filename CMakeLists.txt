cmake_minimum_required(VERSION 3.2)

project(zen
        VERSION 1.0
        DESCRIPTION "A powerful but easy to use upscaler for all your videos and pictures."
        LANGUAGES CXX
)

find_package(Doxygen)
if(Doxygen_FOUND)
    add_subdirectory(docs)
else()
    message(STATUS "Doxygen not found, installing Doxygen.")
    execute_process(COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/scripts/install_dependencies.sh)
    add_subdirectory(docs)
endif()

cmake_policy(SET CMP0079 NEW)

add_subdirectory(src)
add_subdirectory(include)

get_filename_component(HEADERS_PATH ./include ABSOLUTE)
get_filename_component(LIBS_PATH ./libs ABSOLUTE)

target_link_directories(src PUBLIC ${HEADERS_PATH})
target_link_directories(src PUBLIC ${LIBS_PATH})
