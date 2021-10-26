//Alphabetic to numerical phone number coverter.
//Key: 2 = ABC, 3 = DEF, 4 = GHI, 5 = JKL, 6 = MNO, 7 = PRS, 8 = TUV, 9 = WXY

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char phoneno[20];
    printf("Enter phone number: ");
    scanf("%s", phoneno);
    int n = strlen(phoneno);
    for (int i = 0; i < n; i++)
    {
        if ((phoneno[i] >= 'a' && phoneno[i] < 'z') || (phoneno[i] >= 'A' && phoneno[i] < 'Z'))
        {
            phoneno[i] = toupper(phoneno[i]);
            phoneno[i] = 2 + ((phoneno[i] - 'A') / 3);
            printf("%i", phoneno[i]);
        }
        else
            printf("%c", phoneno[i]);
    }
}
