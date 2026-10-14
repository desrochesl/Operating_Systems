#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

// TODO: Include more header files (read the manpages to find out more!)

/** Out of x arguments, echo the middle element or middle two if there are an even amount of arguments. 
 * @param argc number of arguments
 * @param argv arguments given when run
 * @returns boolean 0 if success, 1 if failure
 */
int main(int argc, const char* argv[]) {
    if (argc == 1) {
        printf("ERROR: No arguments");
        return 1;
    }

    bool even = (argc - 1) % 2 == 0;
    int middle = (argc) / 2;

    char* eargs[] = {"echo", argv[middle], NULL, NULL};

    if (even) eargs[2] = argv[middle + 1];

    int eret = execv("/bin/echo", eargs);
    if (eret == -1) {
        perror("exec");
        return 1;
    }
    return 0;
}
