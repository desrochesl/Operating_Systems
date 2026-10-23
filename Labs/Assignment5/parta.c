#include <ctype.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * Iterates over a file in 8 byte chunks and counts the amount of uppercase,
 * lowercase, number, space, or other characters
 * @param argc number of arguments
 * @param argv arguments given
 * @returns exit code, 0: success; 1: incorrect usage; 2: file not found
 */
int main(int argc, char* argv[]) {
    // Declare the buffer to use. Do NOT change!
    enum { BUFSIZE = 8 };
    char buffer[BUFSIZE];
    if (argc != 2) {
        printf("USAGE: parta FILEIN");
        return 1;
    }

    const char* f = argv[1];
    int fd = open(f, O_RDONLY);

    ssize_t bytes_read;

    // struct for storing values, not need but I wanted to work on structs.
    struct parta {
        int upper;
        int lower;
        int number;
        int space;
        int other;
    };

    struct parta chunks = {0, 0, 0, 0, 0};

    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        for (int i = 0; buffer[i] != '\0'; i++) {
            char c = buffer[i];

            // Checks for upper,lower,number,spaces, or other
            switch (c) {
                case 'A' ... 'Z':
                    chunks.upper += 1;
                    break;
                case 'a' ... 'z':
                    chunks.lower += 1;
                    break;
                case '0' ... '9':
                    chunks.number += 1;
                    break;
                case ' ':
                case '\t':
                case '\n':
                case '\r':
                    chunks.space += 1;
                    break;
                default:
                    chunks.other += 1;
                    break;
            }
        }
    }

    if (bytes_read == -1) {
        printf("ERROR: %s not found", argv[1]);
        close(fd);
        return 2;
    }

    printf("Upper,%d\n", chunks.upper);
    printf("Lower,%d\n", chunks.lower);
    printf("Number,%d\n", chunks.number);
    printf("Space,%d\n", chunks.space);
    printf("Other,%d\n", chunks.other);

    close(fd);
    return 0;
}
