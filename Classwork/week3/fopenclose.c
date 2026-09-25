#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *f = fopen("Classwork/week3/test.txt", "r");

    if (f == NULL)
    {
        perror("file does not exist");
        return EXIT_FAILURE;
    }

    fclose(f);

    return EXIT_SUCCESS;
}