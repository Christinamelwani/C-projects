#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int count = 0;
    int n = 0;

    // Enter the limit, dynamically create array.
    printf("Display prime numbers until N\n N = ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);

    // Initialize array with 1s (Assume EVERY number except for 0 and 1 until N is prime)
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = 1;
    }

    // Set the element inside every multiple of each index (starting from 2) to 0, signifying that they are not prime.
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (arr[i] == 1)
        {
            for (int j = 2; i * j <= n; j++)
            {
                arr[i * j] = 0;
            }
        }
    }

    // Print every number where arr[i] = 1. These are all prime
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            printf("%d ", i);
        }
    }

    //Print number of primes in range
    printf("\n%d prime numbers total.\n", count);

    free(arr);

    return 0;
}
