#include <stdio.h>
#include <string.h>
void assign(int c, char kalimat[], int huruf[]);
int hitung (int huruf[]);
void print (int huruf[]);

int main(void)
{
    //Initialasi array:
    char kalimat[100] = {'\0'};
    int huruf[26] = {0};
    
    //Terima input user:
    printf("Masukkan sebuah kalimat: ");
    scanf("%[^\n]s", kalimat);
    
    //Jabarkan huruf:
    assign (strlen(kalimat), kalimat, huruf);
    
    //Tampilkan huruf unik:
    printf("\n%d huruf unik:\n", hitung(huruf));
    print(huruf);
    
    return 0;
}

void assign(int c, char kalimat[], int huruf[])
{
    //Masukkan jumlah kemunculan setiap huruf ke dalam array. (Index: a = huruf[0], b = huruf[1], c = huruf[2], dll):
    for (int i = 0; i < c; i++)
    {
        if (kalimat[i] >= 'a' && kalimat[i] <= 'z')
        {
            huruf[kalimat[i] - 'a']++;
        }
        if (kalimat[i] >= 'A' && kalimat[i] <= 'Z')
        {
            huruf[kalimat[i] - 'A']++;
        }
    }
}

int hitung (int huruf[])
{
    //Initialasi variabel:
    int count = 0;
    
    //Hitung jumlah array huruf unik yang ada isinya (misalnya, jika huruf[a] lebih dari 0 berarti huruf a dihitung):
    for (int i = 0; i < 26; i++)
    {
        if (huruf[i] > 0)
        {
            count++;
        }
    }
    return count;
}

void print(int huruf[])
{
    //Tampilkan jumlah setiap huruf (yang sudah ditambahkan ke array huruf dengan index yang sesuai):
    for (int i = 0; i < 26; i++)
    {
        if (huruf[i] > 0)
            printf("%c = %d\n", i + 'a', huruf[i]);
    } 
}
