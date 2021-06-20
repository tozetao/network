cmake_minimum_required(VERSION 3.1)
project(network)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(net_lib 
    src/tcp_server.c
)

add_executable(epoll_server epoll_server.c)
target_link_libraries(epoll_server net_lib)

add_executable(poll_server poll_server.c)
target_link_libraries(poll_server net_lib)