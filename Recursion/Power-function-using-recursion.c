#include <stdio.h>

int exponent(int base, int power);
int main (void)
{
    int base = 0;
    int power = 0;
    printf("Power calculator to demonstrate recursion:\n");
    for(;;)
    {
        while (power == 0|| base == 0)
        {
                printf(" Enter a number ^ power: ");
                scanf("%d ^ %d", &base, &power);
                printf(" Answer %d\n", exponent(base, power));
                power, base = 0;
        }
    }
    return 0;
}

int exponent(int base, int power)
{
    if (power > 0)
        return base *= exponent(base, --power);
    else
        return 1;
}
