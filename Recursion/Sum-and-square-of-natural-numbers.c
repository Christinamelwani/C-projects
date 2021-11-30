#include <stdio.h>
#include <stdlib.h>

int square(int n);
int sum(int n);
int main (void)
{
    char buffer[20];
    int select = 0;
    int n = 0;
    printf("Welcome!\nThis is a static variables demo.\n");
    for(;;)
    {
        while (select < 1 || select > 2)
        {
            printf("Please select what you would like to calculate:\n\t1.Sum of N natural numbers.\n\t2.n squared.\n\t");
            fgets(buffer,20,stdin);
            select = atoi(buffer);
            if (select == 1)
            {
                printf(" Calculate the sum of the first natural numbers until:\n\tn = ");
                fgets(buffer,20,stdin);
                n = atoi(buffer);
                printf(" Answer: %d\n Press any key to continue.\n ", sum(n));
                fgets(buffer, 20, stdin);
            }
            else if (select == 2)
            {
                printf(" Enter a number to be squared: ");
                fgets(buffer,20,stdin);
                n = atoi(buffer);
                printf(" Answer: %d\n Press any key to continue.\n ", square(n));
                fgets(buffer, 20, stdin);
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

int sum(int n)
{
    if (n > 0)
    {
        return sum(n-1) + n;
    }
    return 0;
}
