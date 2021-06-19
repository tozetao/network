#include "include/common.h"
#include "include/tcp_server.h"
#include "include/log.h"

#include <sys/epoll.h>

#define MAX_EVENTS 2000


int acceptor(int listenfd)
{
    struct sockaddr_in client_addr;
    bzero(&client_addr, 0);
    socklen_t client_addr_len = sizeof(client_addr);
    int socket_fd = accept(listenfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (socket_fd < 0) {
        error("accept error", socket_fd);
    }
    return socket_fd;
}

int main()
{
    int epoll_fd = epoll_create(128);
    if (epoll_fd < 0) {
        error("epoll_create error", epoll_fd);
    }

    // 注册监听描述符
    int listen_fd = tcp_server();
    struct epoll_event event;
    event.data.fd = listen_fd;
    event.events = EPOLLIN;

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &event) == -1) {
        error("epoll_ctl add listen fd error", -1);
    }

    // 再将event对象加入到epoll实例后，如果触发事件，epoll实例会将之前event对象做一份拷贝，添加到返回的event数组中。

    // 开始处理新连接
    struct epoll_event *events = calloc(MAX_EVENTS, sizeof(struct epoll_event));

    while (1) {
        int n = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        printf("epoll_wait wakeup\n");

        sleep(1);
        
        for (size_t i = 0; i < n; i++) {
            // 处理新连接
            if (events[i].data.fd == listen_fd) {
                struct sockaddr_storage ss;
                socklen_t slen = sizeof(ss);
                int fd = accept(listen_fd, (struct sockaddr *)&ss, &slen);

                if (fd < 0) {
                    error("accept error", fd);
                } else {
                    printf("accept a new connection, fd = %d\n", fd);
                    event.events = EPOLLOUT | EPOLLET;
                    event.data.fd = fd;
                    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event) == -1) {
                        error("epoll_ctl add connection fd error", -1);
                    }
                }
                continue;
            }
            // 处理连接请求
            int socket_fd = events[i].data.fd;
            printf("handle socket event\n");

            // while (1) {
            //     char buffer[1024];
            //     int cnt = read(socket_fd, buffer, 1024);
            //     if (cnt < 0) {
            //         printf("socket fd = %d read error\n", socket_fd);
            //         event.data.fd = socket_fd;
            //         event.events = 0;
            //         epoll_ctl(epoll_fd, EPOLL_CTL_DEL, socket_fd, &event);
            //         break;
            //     } else if (cnt == 0) {
            //         printf("socket fd %d closed\n", socket_fd);
            //         event.data.fd = socket_fd;
            //         event.events = 0;
            //         epoll_ctl(epoll_fd, EPOLL_CTL_DEL, socket_fd, &event);
            //         break;
            //     }

            //     // buffer[cnt] = '\0';
            //     // printf("data: %s, len: %d\n", buffer, cnt);
            //     // printf("len: %d, char: %d \n", cnt, buffer[0]);

            //     int write_cnt = write(socket_fd, buffer, cnt);
            //     if (write_cnt < 0) {
            //         printf("socket fd = %d write error\n", socket_fd);
            //     }
            //     break;
            // }
        }
    }
}