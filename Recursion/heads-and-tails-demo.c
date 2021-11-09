#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void up(int n);
void down (int n);

int main(void)
{
    int x = 0;
    char choose[20];
    printf("Countdown start: ");
    scanf("%d", &x);
    printf("Count up (heads recursion) or down (tails recursion)?\n");
    scanf("%s", choose);
    for (int i = 0, n = strlen(choose); i <= n; i++)
    {
        choose[i] = toupper(choose[i]);
    }
    if (strcmp("UP", choose) == 0 || strcmp("HEADS", choose) == 0)
    {
        up(x);
    }
    if (strcmp("DOWN", choose) == 0|| strcmp("TAILS", choose) == 0)
    {
        down(x);
    }
    return 0;
}

void up(int n)
{
    if (n > 0)
    {
        up(n - 1);
        printf("%d\n", n);
    }
    else
    {
        printf("done!\n");
    }
}

void down(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        down(n - 1);
    }
    else
    {
        printf("blast off!\n");
    }
}
