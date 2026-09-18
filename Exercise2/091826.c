#include <stdio.h>

struct student
{
    int id;
    int age;
    float gpa;
};

int card(struct student s)
{
    return s.age > 21;
}

int main()
{
    char str[] = "Game of Thrones";
    int num_spaces = 0;
    int x = 0;

    while (str[x] != '\0')
    {
        if (str[x] == ' ')
            num_spaces++;
        x++;
    }

    printf("Number of spaces is %d \n", num_spaces);
    printf("String Length is %d \n", x);

    struct student s = {12, 24, 4.33};

    int res = card(s);
    printf("the result is: %d \n", res);

    return 0;
}