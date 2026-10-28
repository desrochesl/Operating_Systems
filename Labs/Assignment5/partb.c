#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * Redirects the result from parta.c to an output file.
 * @param argc Number of arguments
 * @param argv Filenames for input and output files.
 * @return 0: success; 1: failure
 */
int main(int argc, char* argv[]) {
    // TODO: Complete and document
    if (argc != 3) {
        printf("USAGE: partb FILEIN FILEOUT");
        return 1;
    }
    const char* input_filename = argv[1];
    const char* output_filename = argv[2];

    int fd = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, 0770);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(fd);
        return 1;
    }

    printf("Category,Count\n");
    fflush(stdout);


    char* parta_args[] = {"./parta", (char*)input_filename, NULL};
    int eret = execv("./parta", parta_args);

    close(fd);

    perror("execv parta");

    return 0;
}
