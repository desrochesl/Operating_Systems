# Operating Systems

This is a compilation of my classwork in Operating Systems.

This class uses C as it's main language. I hope to see vast improvements as the class goes on. I have never created a project in C before, so I am hoping the project structure is correct.

## Usage

### Make
```sh
# In main dir
make -C Exercise{{num}} main
./Exercise{{num}}/main
# In exercise dir
make main
./main
```

### Justfile
```sh
# Run
just run path/to/file.c
# Build
just build path/to/file.c
```

## Projects
### Exercise 1
Calculate the price of a package from a given weight. Using user input as the way to get the weight. 

```C
// User Input:
// The & symbol is the address-of operator. This allows the program to write directly to the memory location of the variable. 
scanf("%f", &weight)
```

Using type casting, I ensure that the weight input does not crash the program when inputting any non number. 

### Exercise 2
#### main.c
**Part A**: Convert coins to a $ amount, given a user input of how many quarters, dimes, nickels, pennies

**Part B**: Find the smallest amount of coins needed given a $ amount
```C
// Using a greedy approach, we can use a modulus operator to remove the cents left over. 
    int cents = (int)(dollars * 100 + 0.5);

    int quarters = cents / 25;
    cents %= 25;

    int dimes = cents / 10;
    cents %= 10;

    int nickels = cents / 5;

    int pennies = cents % 5;
```
#### 091826.c
**Part A**: Strings
Take an inputted string as a character array, and count the amount of spaces and the length of the string. 

```c
#include <stdio.h>
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
}
```

**Part B**: Structs
```c
#include <stdio.h>
struct student
{
    // In c, we use a ; to separate fields in a struct
    int id;
    int age;
    float gpa;
}; // Unlike rust, a `;` is require at the end of defining a struct. 

int card(struct student s) 
{
    return s.age > 21;
}
int main()
{
    struct student s = {12, 24, 4.33};

    int res = card(s);
    printf("The result is %d", res);
}
```