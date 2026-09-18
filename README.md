# Operating Systems

This is a compilation of my classwork in Operating Systems.

This class uses C as it's main language. I hope to see vast improvements as the class goes on. I have never created a project in C before, so I am hoping the project structure is correct.

## Projects:
#### Exercise 1
Calculate the price of a package from a given weight. Using user input as the way to get the weight. 

```C
// User Input:
// The & symbol is the address-of operator. This allows the program to write directly to the memory location of the variable. 
scanf("%f", &weight)
```

Using type casting, I ensure that the weight input does not crash the program when inputting any non number. 

#### Exercise 2
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