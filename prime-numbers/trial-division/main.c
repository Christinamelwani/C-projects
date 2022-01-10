#include <stdio.h>
#include <stdbool.h>

bool check(int possible_prime);
int print_primes(int N, int possible_prime);

//to do- add comments

int main (void)
{
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    printf("\nPrime numbers until %d:\n", N);
    int count = print_primes(N, 2);
    printf("\nNumber of primes = %d\n", count);
}

int print_primes(int N, int possible_prime)
{
    static int count = 0;
    if (possible_prime > N)
        return count;
    else
    {
        if (check(possible_prime) == true)
        {
            printf("%d ", possible_prime);
            count++;
        }
        print_primes(N, possible_prime + 1);
    }
}

bool check(int possible_prime)
{
    int factor = 0;
    for (int i = 2; i <= possible_prime / 2 ;i++)
    {
        if (possible_prime % i == 0)
            factor++;
    }
    if (factor == 0)
            return true;
    return false;
}
