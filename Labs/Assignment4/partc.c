#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

// TODO: Include more header files (read the manpages to find out more!)

/**
 * Scans a given file for a specific word
 * @param argc length of arguments
 * @param argv arguments given: word to find and path to the file. 
 * @returns
 */
int main(int argc, const char* argv[]) {
    // TODO: Complete and document
    if (argc != 3) {
        fprintf(stderr, "ERROR: No arguments\n");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        char* gargs[] = {"grep",         "-s",           "-q",
                         (char*)argv[1], (char*)argv[2], NULL};

        execvp("/usr/bin/grep", gargs);
        perror("execp");
        _exit(1);
    }

    int status;
    if (waitpid(pid, &status, 0) == -1) {
        perror("waitpid");
        return 1;
    }

    if (WIFEXITED(status)) {
        switch (WEXITSTATUS(status)) {
            case 0:
                printf("FOUND: %s\n", argv[1]);
                return 0;
            case 1:
                printf("NOT FOUND: %s\n", argv[1]);
                return 0;
            default:
                printf("ERROR: %s doesn't exist\n", argv[2]);
                return 2;
        }
    }
    return 1;
}
