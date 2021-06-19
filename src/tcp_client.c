#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void error(char *s, int status)
{
    printf("%s\n", s);
    exit(status);
}

void handle_signal(int signal)
{
    printf("receive signal %d\n", signal);
}


int main(int argc, char const *argv[])
{
    signal(SIGPIPE, handle_signal);


    int port = 9100;
    char *addr = "127.0.0.1";

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_port = htons(port);
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, addr, &server_addr.sin_addr);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    int res = connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (res < 0) {
        error("connect error\n", res);
    }

    // 向服务端发送数据，开始测试。
    char buffer[1024];

    while (fgets(buffer, 1024, stdin)) {
        // 第一次send会发送成功。如果服务器关闭连接了，内核会返回RST包
        int len = strlen(buffer);
        res = send(socket_fd, buffer, len, 0);
        if (res < 0) {
            error("first send error", res);
        }

        // 在返回rst包后，第二次send会失败，并触发一个PIPE信号。
        len = strlen(buffer);
        res = send(socket_fd, buffer, len, 0);
        if (res < 0) {
            error("second send error", res);
        }

        // res = read(socket_fd, buffer, sizeof(buffer));
        // if (res < 0) {
        //     error("read error", res);
        // } else if (res == 0) {
        //     error("peer connection closed", 0);
        // }
        // fputs(buffer, stdout);

    }
    
    
    return 0;
}
