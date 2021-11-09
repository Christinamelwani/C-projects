#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void up(int n);
void down(int n);

int main(void)
{
    for (;;)
    {
        int x = 0;
        char buffer[20];
        while (x == 0)
        {
            printf("Press e to exit.\nCount from/until: ");
            scanf("%s", buffer);
            if (buffer[0] == 'e' || buffer[0] == 'E')
            {
             return 0;
            }
            x = atoi(buffer);
        }
        printf("Count up or down?\n");
        scanf("%s", buffer);
        for (int i = 0, n = strlen(buffer); i <= n; i++)
        {
            buffer[i] = toupper(buffer[i]);
        }
        if (strcmp("UP", buffer) == 0)
        {
            up(x);
        }
        if (strcmp("DOWN", buffer) == 0)
        {
            down(x);
        }
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
        printf("Start:\n");
    }
}

void down(int n)
{
    if (n > 0)
    {
        printf("%d...\n", n);
        down(n - 1);
    }
    else
    {
        printf("blast off!\n");
    }
}
