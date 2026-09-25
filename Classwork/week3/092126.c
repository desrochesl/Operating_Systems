#include <stdio.h>
#include <stdlib.h>

int mal_ex()
{
    size_t arr_size = sizeof(int) * 4;

    int *arr = malloc(arr_size);

    arr[0] = 20;
    arr[1] = 30;
    arr[2] = 24;
    arr[3] = 27;

    printf("size of int is: %zu \n", arr_size);
    printf("the value at location 3 is: %d \n", arr[3]);
    free(arr);

    return 0;
}

int students()
{
    struct student
    {
        int age;
        int class;
    };
    size_t arr_size = sizeof(struct student) * 4;

    struct student *struct_arr = malloc(arr_size);
    printf("size of int: %zu \n", arr_size);

    struct student student_one = struct_arr[0];
    struct student student_two = struct_arr[1];
    struct student student_three = struct_arr[2];
    struct student student_four = struct_arr[3];

    student_one.age = 10;
    student_one.class = 1;

    student_two.age = 9;
    student_two.class = 1;

    student_three.age = 12;
    student_three.class = 2;

    student_four.age = 13;
    student_four.class = 2;

    printf(" print the information for student of class: %d with age %d \n", student_one.class, student_one.age);

    free(struct_arr);

    return 0;
}

void createStaff(int num_of_staff)
{
    int *staff_arr = malloc(sizeof(int) * num_of_staff);

    for (int x = 0; x < num_of_staff; x++)
    {
        staff_arr[x] = 1000 + x;
        printf("staff %d has the staff num ID-%d \n", x, staff_arr[x]);
    }

    free(staff_arr);
}

int main()
{
    mal_ex();

    students();

    createStaff(-10);

    return 0;
}