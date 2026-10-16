#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

/** Out of x arguments, echo the middle element or middle two if there are an
 * even amount of arguments.
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

    const char* eargs[] = {"echo", (char*)argv[middle], even ? (char*)argv[middle + 1] : NULL,
                           NULL};

    execvp("/bin/echo", (char* const*) eargs);

    return 0;
}
