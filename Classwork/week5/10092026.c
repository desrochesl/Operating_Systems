#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    int fdesc[2];

    int pipe_v = pipe(fdesc);

    if (pipe_v == -1)
    {
        perror("file descriptor creation failed");
        exit(1);
    }

    int read_fd = fdesc[0];
    int write_fd = fdesc[1];

    pid = fork();

    if (pid == -1)
    {
        perror("forking error occured");
        exit(1);
    }

    if (pid > 0)
    {
        close(read_fd);
        FILE *filex = fdopen(write_fd, "w");

        fprintf(filex, "HELLO\n");
        fclose(filex);
        exit(EXIT_SUCCESS);
    }

    if (pid == 0)
    {
        close(write_fd);
        FILE *in = fdopen(read_fd, "r");
        char buffer[100];
        // fgets(buffer, 64, in);

        if (fscanf(in, "%99s", buffer) != 1)
        {
            perror("fscan error");
            exit(1);
        }
        printf("read data : %s \n", buffer);
        fclose(in);
        exit(EXIT_SUCCESS);
    }
    return 0;
}