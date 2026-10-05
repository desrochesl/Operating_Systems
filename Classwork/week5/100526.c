#include <stdio.h>

void forkEX()
{
    int pid = fork();

    if (pid > 0)
    {
        // parent process
    }

    else if (pid == 0)
    {
        // child process
    }

    else
    {
        // pid < 0
        // error condition
    }
    return;
}

void execEX()
{
    // create array of args
    char *args[4];
    args[0] = "java";
    args[1] = "- jar";
    args[2] = "prog.jar";

    // end with null
    args[3] = NULL;

    // execute
    execv("java", args);

    // never returns
}

void forkexecEx(args)
{
    int pid = fork();

    if (pid > 0)
    {
        // parent wait()
        int status;
        wait(&status);
    }
    else if (pid < 0)
    {
        // err
        perror("fork error");
    }
    else
    {
        // child
        int r = execv("/usr/bin/ls", args);
        if (r == -1)
        {
            // failed
            perror("exec error");
        }
    }
    // never returns
}

int main(int argc, char *argv[])
{
    forkexecEx();

    return 0;
}