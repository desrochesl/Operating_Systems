#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    int p2c[2], c2p[2];

    // Create two pipes

    if (pipe(p2c) == -1 || pipe(c2p) == -1)
    {

        perror("pipe failed");

        exit(1);
    }

    // p2c: parent -> child

    // c2p: child -> parent

    pid_t pid = fork();

    if (pid < 0)
    {

        perror("fork failed");

        exit(1);
    }

    if (pid > 0)
    {

        // Parent

        close(p2c[0]);

        close(c2p[1]);

        write(p2c[1], "PING", 4);

        char buf[16] = {0};

        read(c2p[0], buf, 15);

        printf("Parent received: %s\n", buf);

        close(p2c[1]);

        close(c2p[0]);

        waitpid(pid, NULL, 0);
    }

    if (pid == 0)
    {

        // Child

        close(p2c[1]);

        close(c2p[0]);

        char buf[16] = {0};

        read(p2c[0], buf, 15);

        printf("Child received: %s\n", buf);

        write(c2p[1], "PONG", 4);

        close(p2c[0]);

        close(c2p[1]);
    }

    return 0;
}
