cmake_minimum_required(VERSION 3.1)
project(network)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(net_lib 
    src/tcp_server.c
)

add_executable(epoll_server epoll_demo.c)
target_link_libraries(epoll_server net_lib)

add_executable(main main.c)
target_link_libraries(main net_lib)