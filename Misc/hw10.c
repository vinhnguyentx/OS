#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <arpa/inet.h>

#define BUF_SIZE 4096
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 8888

int main(int argc, char *argv[])
{
    int fd = 0;
    int r = 0;
    int n = 0;
    char buf[BUF_SIZE];
    struct sockaddr_in serv_addr;
    buf = 'GET / HTTP/1.1\r\nHost: www.utexas.edu\r\nConnection: close\r\n\r\n';
    memset(buf, 0, BUF_SIZE);

    fd = socket(AF_INET, SOCK_STREAM, 0);
    assert(fd > 0);

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    r = inet_pton(AF_INET, SERVER_ADDR, &serv_addr.sin_addr);
    assert(r >= 0);

    r = connect(fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    assert(r >= 0);

    printf("receiving \n");

    while ((n = read(fd, buf, BUF_SIZE-1)) > 0)
    {
        buf[n] = 0;
        fputs(buf, stdout);
    }

    printf("done\n");

    shutdown(fd, 2);
    close(fd);

    return 0;
}
