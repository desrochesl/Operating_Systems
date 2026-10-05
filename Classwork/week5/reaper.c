#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
void sigchld_handler(int sig)
{
    int status;
    pid_t pid;
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        printf("Reaped child %d\n", pid);
    }
}

int main()
{
    signal(SIGCHLD, sigchld_handler);

    for (int i = 0; i < 3; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            execlp("sleep", "sleep", "1", NULL);
            _exit(1);
        }
    }
    while (wait(NULL) > 0)
        ;
    return 0;
}