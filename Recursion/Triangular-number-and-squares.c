#include <stdio.h>

int square(int n);
int triangular(int n);
int main (void)
{
    char buffer[20];
    int select = 0;
    int n = 0;
    printf("Welcome!This is a static variables demo.\n");
    for(;;)
    {
        while (select < 1 || select > 2)
        {
            printf("Please select what you would like to calculate:\n\t1.n'th triangular number\n\t2.n to the power of 2\n\t");
            fgets(buffer,20,stdin);
            select = atoi(buffer);
            if (select == 1)
            {
                printf(" Find the n'th triangular number:\n n = ");
                fgets(buffer,20,stdin);
                n = atoi(buffer);
                printf(" Answer: %d\n\n", triangular(n));
            }
            else if (select == 2)
            {
                printf(" Enter a number to be squared: ");
                fgets(buffer,20,stdin);
                n = atoi(buffer);
                printf(" Answer: %d\n\n", square(n));
            }
        }
        n, select = 0;
    }
    return 0;
}

int square(int n)
{
    int static x = 0;
    if (n > 0)
    {
        x++;
        return square(n-1) + x;
    }
    return 0;

}

int triangular(int n)
{
    if (n > 0)
    {
        return triangular(n-1) + n;
    }
    return 0;
}
