#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * Interops with parta.c to sort the output in ascending order.
 * @param argc Number of arguments (must be exactly 2 arguments)
 * @param argv Filename of the input file.
 * @return 0: success; 1: failure
 */
int main(int argc, char* argv[]) {
    // TODO: Complete and document
    if (argc != 2) {
        printf("USAGE: partc FILEIN");
        return 1;
    }
    const char* filein = argv[1];

    int pipefd[2];

    if (pipe(pipefd) < 0) {
        perror("pipe failed");
        return 1;
    }

    // Fork Child 1:
    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork pid1");
        close(pipefd[0]);
        close(pipefd[1]);
        return 1;
    }

    if (pid1 == 0) {
        close(pipefd[0]);

        if (dup2(pipefd[1], STDOUT_FILENO) < 0) {
            perror("dup2");
            close(pipefd[1]);
            return 1;
        }

        close(pipefd[1]);

        char* parta_args[] = {"./parta", (char*)filein, NULL};

        execv("./parta", parta_args);

        // Only runs if execvp returns an error
        perror("execv parta");
        _exit(1);
    }

    // Fork Child 2:
    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("fork pid2");
        close(pipefd[0]);
        close(pipefd[1]);
        return 1;
    }
    if (pid2 == 0) {
        close(pipefd[1]);

        if (dup2(pipefd[0], STDIN_FILENO) < 0) {
            perror("dup2");
            close(pipefd[0]);
            return 1;
        }

        printf("Category,Count\n");
        char* sort_args[] = {"sort", "-t", ",", "-k2,2", "-n", NULL};
        execvp("sort", sort_args);

        // Only runs if execvp returns an error
        perror("execvp sort");
        _exit(1);
    }

    // Close pipe descriptors
    close(pipefd[0]);
    close(pipefd[1]);

    // Wait for both chilren
    int status1 = 0;
    int status2 = 0;
    waitpid(pid1, &status1, 0);
    waitpid(pid2, &status2, 0);

    // Verify both children exited normally with status 0
    bool success1 = WIFEXITED(status1) && (WEXITSTATUS(status1) == 0);
    bool success2 = WIFEXITED(status2) && (WEXITSTATUS(status2) == 0);

    if (success1 && success2) {
        return 0;
    }

    return 1;
}
