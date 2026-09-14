#include <stdio.h>

int get_min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int quick_quiz()
{
    int sugar_content[4] = {0, 0, 0, 0};
    sugar_content[1] += 2;
    sugar_content[4] += 3;

    printf("Sugar content in item 1: %d\n", sugar_content[1]);
    printf("Sugar content in item 4: %d\n", sugar_content[4]);
    return 0;
}

float avg_i(int a, int b) { return (a + b) / 2.0; }
float avg_f(float a, float b) { return (a + b) / 2.0; }

int main()
{
    // int result = get_min(5, 10);
    // printf("Minimum value: %d\n", result);
    // quick_quiz();

    float a1 = avg_i(5, 6);
    float a2 = avg_f(5.5, 5.7);
    float a3 = avg_i(5.5, 5.7);

    printf("Average of 5 and 6: %f\n", a1);
    printf("Average of 5.5 and 5.7: %f\n", a2);
    printf("Average of 5.5 and 5.7 (integer): %f\n", a3);
    return 0;
}