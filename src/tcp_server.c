#include "include/common.h"
#include "include/log.h"
#include "include/tcp_server.h"

// 返回一个监听套接字
int tcp_server()
{
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        error("socket error", listenfd);
    }

    int res = 0;
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int on = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    // bind
    res = bind(listenfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (res < 0) {
        error("bind error", res);
    }
    // listen
    res = listen(listenfd, 128);
    if (res < 0) {
        error("listen error", res);
    }
    return listenfd;
}