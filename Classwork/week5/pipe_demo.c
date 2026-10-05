#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execlp("ls", "ls -la", NULL);
        perror("exec failed");
        _exit(1);
    }
    else
    {
        close(fd[1]);
        char buf[256];
        int n = read(fd[0], buf, 255);
        buf[n] = 0;
        printf("Child said:\n%s", buf);
        close(fd[0]);
        wait(NULL);
    }
}