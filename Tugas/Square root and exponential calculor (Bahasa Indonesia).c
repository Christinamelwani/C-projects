#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int akar_Kwadrat(void);
int pangkat(void);
int main()
{
    int perintah;
    while (perintah != 3)
    {
        while (perintah != 1 && perintah != 2 && perintah != 3)
        {
            printf("1: Program pencarian akar kuadrat\n2: Program pemangkatkan angka\n3: Keluar\n");
            scanf("%d", &perintah);
            if (perintah =='\n')
        {
            scanf("%d", &perintah);
        }
        }
        if (perintah == 1)
        {
                akar_Kwadrat();
                perintah == 0;
        }
        if (perintah == 2)
        {
              pangkat();
              perintah == 0;
        }
    }
    return 0;
}
int akar_Kwadrat(void)
{
    int ulang;
    double bilangan = 1;
    printf("\nProgram pencarian akar kwadrat-");
    do
    {
    printf("\n\tMasukkan bilangan untuk mencari akar kwadratnya: ");
    scanf("%lf", &bilangan);
    if (fmod(sqrt(bilangan),1) != 0 && ulang != 2)
    {
        printf("\t%.0lf tidak memiliki akar kwadrat!\n\t1:Coba lagi\n\t2:Keluar\n\t", bilangan);
        scanf("%d", &ulang);
        if (ulang == 2)
        {
            printf("\n");
            return 0;
        }
    }
    }
    while (fmod(sqrt(bilangan),1) != 0);
    printf("\tAkar kwadrat %.0lf = %.0lf\n", bilangan, sqrt(bilangan));
    printf("\n");
    return(0);
}
int pangkat(void)
{
    int bilangan;
    int pangkat;
    int hasil = 1;
    printf("\nProgram pemangkatkan angka:\n\tMasukkan bilangan yang hendak dipangkatkan: ");
    scanf("%i", &bilangan);
    printf("\tMasukkan pangkat yang diinginkan: ");
    scanf("%i", &pangkat);
    if (pangkat >= 0)
    {
        for (int n = 0; n < pangkat; n++)
        {
            hasil *= bilangan;
        }
    }
    else
    {
        printf("\tPangkat harus berupa bilangan bulat positif!\n");
    }
    printf("\t%i pangkat %i = %i\n", bilangan, pangkat, hasil);
    return(0);
}
/*
Isu yang diketahui:
 ~ Input yang bukan angka menyebabkan infinite loop perintah.
 ~ Program pemangkatan tidak terlalu berguna karena hanya dapat memproses hasil 9-digit.
*/
