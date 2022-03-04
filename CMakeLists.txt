cmake_minimum_required(VERSION 3.10)

project(SQDLOG)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Ofast -g -Wfatal-errors -D_MWAITXINTRIN_H_INCLUDED -pthread")


# include_directories(./include)
set(CMAKE_CXX_STANDARD 11)


aux_source_directory(. SOURCE)
# aux_source_directory(./include SOURCE)
add_executable(main ${SOURCE})


if(NOT TARGET spdlog)
    # Stand-alone build
    include_directories(./spd)
    find_package(spdlog REQUIRED)
endif()

# fmt 
find_package(fmt REQUIRED)

find_package(Threads)


target_link_libraries(main PRIVATE spdlog::spdlog ${CMAKE_THREAD_LIBS_INIT} fmt::fmt)
if(SPDLOG_BUILD_EXAMPLE_HO)
    add_executable(main main.cpp)
    target_link_libraries(main PRIVATE spdlog::spdlog_header_only)
endif()

