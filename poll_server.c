#include "include/tcp_server.h"
#include "include/log.h"
#include <poll.h>

#define MAX_FD 1024

int main(int argc, char const *argv[])
{
    int listenfd = tcp_server();
    struct pollfd *fdarray = calloc(MAX_FD, sizeof(struct pollfd));
    for (size_t i = 0; i < MAX_FD; i++) {
        fdarray[i].fd = -1;
    }
    // 监听listen fd
    fdarray[0].fd = listenfd;
    fdarray[0].events = POLLIN;

    int ready_num = 0;
    while (1) {
        ready_num = poll(fdarray, MAX_FD, -1);
        if(ready_num < 0) {
            error("poll error", ready_num);
        }
        printf("poll wakeup, ready_num = %d\n", ready_num);

        for (size_t i = 0; i < MAX_FD; i++) {
            // 新连接的处理
            if (fdarray[i].fd == listenfd && fdarray[i].revents & POLLIN) {
                struct sockaddr_storage ss;
                socklen_t slen = sizeof(ss);
                int connfd = accept(listenfd, (struct sockaddr *)&ss, &slen);
                if (connfd < 0) {
                    printf("accept error\n");
                    continue;
                }
                printf("accept a connection, fd: %d\n", connfd);
                
                short too_many_conn = 1;
                for (size_t j = 1; j < MAX_FD; j++) {
                    if (fdarray[j].fd == -1) {
                        fdarray[j].fd = connfd;
                        fdarray[j].events = POLLIN;
                        too_many_conn = 0;
                        break;
                    }
                }
                if (too_many_conn == 1) {
                    printf("too many connections\n");
                    close(connfd);
                }
                ready_num--;
                continue;
            }

            // 有请求数据
            if (fdarray[i].revents & POLLIN) {
                printf("handle a request\n");
                char buffer[1024];
                int cnt = read(fdarray[i].fd, buffer, 1024);
                if (cnt < 0) {
                    printf("read error\n");
                    close(fdarray[i].fd);
                    fdarray[i].fd = -1;
                    continue;
                } else if (cnt == 0) {
                    printf("connection closed\n");
                    close(fdarray[i].fd);
                    fdarray[i].fd = -1;
                    continue;
                }

                int write_cnt = write(fdarray[i].fd, buffer, cnt);
                if (write_cnt < 0) {
                    printf("write error\n");
                    close(fdarray[i].fd);
                    fdarray[i].fd = -1;
                }
                ready_num--;
            }

            if (ready_num == 0) {
                break;
            }
        }
        
    }
    return 0;
}
