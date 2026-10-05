#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    char line[100];
    while (1)
    {
        printf("mysh> ");
        fgets(line, 100, stdin);
        line[strlen(line) - 1] = 0;

        if (strcmp(line, "exit") == 0)
            break;

        pid_t pid = fork();
        if (pid == 0)
        {
            execlp(line, line, NULL);
            perror("exec failed");
            _exit(1);
        }
        else
        {
            int status;
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}
