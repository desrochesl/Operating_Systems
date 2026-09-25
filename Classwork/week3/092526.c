#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("length of args: %d \n", argc);
    int i;
    for (i = 1; i < argc; i++)
        printf("length of args: %s \n", argv[i]);
    return 0;
}