#include <stdio.h>

float coin_counter()
{
    int pennies;
    int nickels;
    int dimes;
    int quarters;
    printf("Enter number of quarters:");
    scanf("%d", &quarters);
    printf("Enter number of dimes:");
    scanf("%d", &dimes);
    printf("Enter number of nickels:");
    scanf("%d", &nickels);
    printf("Enter number of pennies:");
    scanf("%d", &pennies);

    if (pennies < 0 || nickels < 0 || dimes < 0 || quarters < 0) {
        printf("Negative coins are not allowed, restart and try again\n");
        return 0;
    }

    int change = pennies + (5 * nickels) + (10 * dimes) + (25 * quarters);
    float dollars = (float)change / 100;
    return dollars;
}

int fewest_change()
{
    float dollars;

    printf("Enter total amount:");
    scanf("%f", &dollars);

    if (dollars < 0) {
        printf("Negative currency is not allowed, restart and try again\n");
        return 0;
    }

    int cents = (int)(dollars * 100 + 0.5);

    int quarters = cents / 25;
    cents %= 25;

    int dimes = cents / 10;
    cents %= 10;

    int nickels = cents / 5;

    int pennies = cents % 5;

    printf("You have %d quarters %d dimes %d nickels and %d pennies", quarters, dimes, nickels, pennies);

    return 0;
}

int main()
{
    printf("You have $%.2f in coins\n", coin_counter());

    fewest_change();
    return 0;
}