#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCK_PATH "/tmp/s.sock"

int main()
{
    int soc = socket(AF_UNIX, SOCK_STREAM, 0);
    if (soc == -1)
    {
        perror("socket creation failed");
        close(soc);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_un a = {0};
    a.sun_family = AF_UNIX;
    strncpy(a.sun_path, SOCK_PATH, sizeof(a.sun_path) - 1);
    unlink(SOCK_PATH);

    int b = bind(soc, (struct sockaddr *)&a, sizeof(a));

    if (b == -1)
    {
        perror("Bind failed");
        close(soc);
        exit(EXIT_FAILURE);
    }

    // listen for connection
    if (listen(soc, 1) == -1)
    {
        perror("listen failed");
        close(soc);
        exit(EXIT_FAILURE);
    }

    // # accept client connection
    int c = accept(soc, NULL, NULL);

    if (c == -1)
    {
        perror("Bind failed");
        close(soc);
        exit(EXIT_FAILURE);
    }

    char buf[64] = {0};

    // read(c, buf, 63);
    memset(buf, 0, 63);

    ssize_t bytes_read = read(c, buf, 63);

    if (bytes_read > 0)
    {
        printf("Received: %s", buf);
    }
    else if (bytes_read == 0)
    {
        printf("client disconnected: %s", buf);
    }
    else
    {
        perror("read error");
    }

    close(soc);

    return 0;
}