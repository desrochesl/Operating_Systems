#include <stdio.h>

/**
 * Returns the price of the package based on weight.
 *
 * @param weight The weight of the package
 * @return The price of the package
 */
float package_price(float weight)
{
    if (0 < weight && weight <= 1)
    {
        return 3.5;
    }
    else if (1.0 < weight && weight <= 3.0)
    {
        return 5.5;
    }
    else if (3.0 < weight && weight <= 10.0)
    {
        return 8.5;
    }
    else if (10.0 < weight && weight <= 20.0)
    {
        return 10.5;
    }
    else
    {
        return -1;
    }
}

int main()
{
    float weight;
    printf("Input the weight of the package:\n");
    scanf("%f", &weight);
    printf("The price of the %.2flb package is: %.2f\n", weight, package_price(weight));
    return 0;
}
