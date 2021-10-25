#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input(void);
void view(void);
int del(void);

struct dataminuman
{
        char nama[10];
        char size[10];
        char penyajian[10];
        int harga;
};

struct dataminuman history[100];
int ind = 0;

int main(void)
{
    FILE * dm;
    dm = fopen("dataminuman.txt", "r");
    if (dm == NULL)
    {
        printf("Belum ada history penjualan minuman\n");
        dm = fopen("dataminuman.txt", "w+");
    }
    char temp[100];
    char buffer[20];
    int menu = 0;
    int i = 0;
    if (fgetc(dm)!= EOF)
    {
        fgets(temp, 100, dm);
        while (fgetc(dm)!= EOF)
        {
            fscanf(dm,"%d %s %s %s %d", &ind, history[i].nama, history[i].size, history[i].penyajian, &history[i].harga);
            i++;
            fgets(buffer, 1 , dm);
        }
        printf("\t%s", temp);
        i = 0;
        while (history[i].harga != 0)
        {
            printf("\t%-10d%-20s%-20s%-20s%-10d\n", i + 1, history[i].nama, history[i].size, history[i].penyajian, history[i].harga);
            i++;
        }
    }
    while (menu != 4)
    {
        printf("\n a. Input data (tekan tombol 1)\n b. View history (tekan tombol 2)\n c. Delete history (tekan tombol 3)\n d. Exit (tekan tombol 4)\n ");
        scanf("\n");
        fgets(buffer, 20, stdin);
        menu = atoi (buffer);
        if (menu == 1)
        {
           if (input() == 0)
           {
               printf(" Input data berhasil\n");
           };
        }
        if (menu == 2)
        {
            view();
        }
        if (menu == 3)
        {
            if (del() == 0)
           {
               printf(" Data succesfully deleted...\n\n");
           };
        }
    }
    dm = freopen("dataminuman.txt", "w", stdout);
    fprintf(dm,"\t%-10s%-20s%-20s%-20s%-10s\n", "No", "Nama Pesanan", "Size", "Penyajian", "Harga");
    i = 0;
    while (history[i].harga != 0)
    {
        fprintf(dm, "\t%-10d%-20s%-20s%-20s%-10d\n", i + 1, history[i].nama, history[i].size, history[i].penyajian, history[i].harga);
        i++;
    }
    fclose(dm);
    return 0;
}

int input(void)
{
    typedef struct m
    {
        char nama[10];
        char size[10];
        char penyajian[10];
        int harga;
    } m;
    m minuman;
    printf(" Masukkan nama minuman (Kopi, Teh, Coklat, Soda): ");
    scanf("\n");
    fgets(minuman.nama, 10, stdin);
    strtok(minuman.nama,"\n");
    if (   strcmp(minuman.nama, "kopi") == 0 || strcmp(minuman.nama, "Kopi") == 0
        || strcmp(minuman.nama, "teh") == 0 || strcmp(minuman.nama, "Teh") == 0
        || strcmp(minuman.nama, "coklat") == 0 || strcmp(minuman.nama, "Coklat") == 0
        || strcmp(minuman.nama, "soda") == 0 || strcmp(minuman.nama, "Soda") == 0)
    {
        printf(" Masukkan size minuman (Small, Medium, Largest): ");
        scanf("\n");
        fgets(minuman.size, 10, stdin);
        strtok(minuman.size,"\n");
        if (        strcmp(minuman.size, "largest") == 0 || strcmp(minuman.size, "Largest") == 0
                ||  strcmp(minuman.size, "small") == 0 || strcmp(minuman.size, "Small") == 0
                ||  strcmp(minuman.size, "medium") == 0 || strcmp(minuman.size, "Medium") == 0)
        {
            printf(" Masukkan penyajian minuman (Panas, Hangat, Dingin): ");
            scanf("\n");
            fgets(minuman.penyajian, 10, stdin);
            strtok(minuman.penyajian,"\n");
            if (        strcmp(minuman.penyajian, "panas") == 0 ||  strcmp(minuman.penyajian, "Panas") == 0
                    ||  strcmp(minuman.penyajian, "hangat") == 0 || strcmp(minuman.penyajian, "Hangat") == 0
                    ||  strcmp(minuman.penyajian, "dingin") == 0 || strcmp(minuman.penyajian, "Dingin") == 0)
            {
                minuman.harga = (strlen(minuman.size) * strlen (minuman.penyajian) * strlen(minuman.nama) * 100);
                printf(" Detail pembelian:\n \tNama Minuman: %s\n \tSize: %s\n \tPenyajian: %s\n \tHarga: %i\n", minuman.nama, minuman.size, minuman.penyajian, minuman.harga);
                 char val;
                 for (;;)
                {
                val = 0;
                printf(" Pencet tombol y untuk mengonfirmasi\n Pencet tombol n untuk batal\n ");
                scanf("\n%c", &val);
                if (val == 'y' || val == 'Y')
                {
                    strcpy(history[ind].nama, minuman.nama);
                    strcpy(history[ind].penyajian, minuman.penyajian);
                    strcpy(history[ind].size, minuman.size);
                    history[ind].harga = minuman.harga;
                    ind++;
                    return 0;
                }
                else if (val == 'n' || val == 'N')
                    return 1;
                else
                    continue;
                }
            }
            else
            {
                printf(" Penyajian %s tidak tersedia!\n\n", minuman.penyajian);
                input();
            }
        }
        else
        {
            printf(" Ukuran %s tidak tersedia!\n\n", minuman.size);
            input();
        }
    }
    else
    {
        printf(" %s tidak tersedia!\n\n", minuman.nama);
        input();
    }
    return 1;
}

void view(void)
{
    int i = 0;
    printf("\t%-10s%-20s%-20s%-20s%-10s\n", "No", "Nama Pesanan", "Size", "Penyajian", "Harga");
    while (history[i].harga != 0)
    {
        printf("\t%-10d%-20s%-20s%-20s%-10d\n", i + 1, history[i].nama, history[i].size, history[i].penyajian, history[i].harga);
        i++;
    }
    getchar();
}

int del(void)
{
    int i = 0;
    int s = 0;
    int n;
    printf("\t%-10s%-20s%-20s%-20s%-10s\n", "No", "Nama Pesanan", "Size", "Penyajian", "Harga");
    while (history[i].harga != 0)
    {
        printf("\t%-10d%-20s%-20s%-20s%-10d\n", i + 1, history[i].nama, history[i].size, history[i].penyajian, history[i].harga);
        i++;
    }

    do
    {
        printf("\n Masukkan nomor yang ingin dihapus: ");
        scanf("%d", &s);
    }while (history[s - 1].harga == 0);
    s--;
    strcpy(history[s].nama, "\0");
    strcpy(history[s].size, "\0");
    strcpy(history[s].penyajian, "\0");
    history[s].harga = 0;
    for (n = (s + 1); history[n].harga != 0; n++)
    {
        strcpy(history[n - 1].nama, history[n].nama);
        strcpy(history[n - 1].size, history[n].size);
        strcpy(history[n - 1].penyajian, history[n].penyajian);
        history[n - 1].harga = history[n].harga;
    }
    strcpy(history[n-1].nama, "\0");
    strcpy(history[n-1].size, "\0");
    strcpy(history[n-1].penyajian, "\0");
    history[n-1].harga = 0;
    ind--;
    i = 0;
    printf("\t%-10s%-20s%-20s%-20s%-10s\n", "No", "Nama Pesanan", "Size", "Penyajian", "Harga");
    while (history[i].harga != 0)
    {
        printf("\t%-10d%-20s%-20s%-20s%-10d\n", i + 1, history[i].nama, history[i].size, history[i].penyajian, history[i].harga);
        i++;
    }
    return 0;
}
