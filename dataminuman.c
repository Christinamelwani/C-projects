#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    int navigasi = 0;
    int i = 0;
    char temp[100];
    char buffer[20];

    //Membuka file “dataminuman.txt” dalam mode 'read':
    FILE *dm;
    dm = fopen("dataminuman.txt", "r");

    //Membuat file “dataminuman.txt” jika belum ada.
    if (dm == NULL)
    {
        printf(" Belum ada history penjualan minuman!");
        dm = fopen("dataminuman.txt", "w+");
    }
      
    //Membaca header dan isi “dataminuman.txt”
    else
    {
        if (fgetc(dm) != EOF)
        {
            fgets(temp, 100, dm);
            while (fgetc(dm) != EOF)
            {
                fscanf(dm, "%d %s %s %s %d", &ind, history[i].nama, history[i].size, history[i].penyajian, &history[i].harga);
                i++;
                fgets(buffer, 1, dm);
            }

            //Menampilkan header dan isi file:
            printf("\t%s", temp);
            i = 0;
            while (history[i].harga != 0)
            {
                printf("\t%-10d%-20s%-20s%-20s%-10d\n", i + 1, history[i].nama, history[i].size, history[i].penyajian, history[i].harga);
                i++;
            }
        }

        //Jika file kosong:
        else
        {
            printf(" Belum ada history penjualan minuman!");
        }
    }

    //Menampilkan menu dan menerima pilihan user:
    while (navigasi != 4)
    {
        printf("\n a. Input data (tekan tombol 1)\n b. View history (tekan tombol 2)\n c. Delete history (tekan tombol 3)\n d. Exit (tekan tombol 4)\n ");
        scanf("\n");
        fgets(buffer, 20, stdin);
        navigasi = atoi(buffer);
        if (navigasi == 1)
        {
            if (input() == 0)
            {
                printf(" Input data berhasil.\n");
            };
        }
        if (navigasi == 2)
        {
            view();
        }
        if (navigasi == 3)
        {
            if (del() == 0)
            {
                printf(" Data succesfully deleted...\n");
            };
        }
    }

    //Menulis data history ke dalam file (HANYA JIKA 4 DITEKAN):
    dm = freopen("dataminuman.txt", "w", stdout);
    if (history[0].harga != 0)
    {
        fprintf(dm, "\t%-10s%-20s%-20s%-20s%-10s\n", "No", "Nama Pesanan", "Size", "Penyajian", "Harga");
    }
    i = 0;
    while (history[i].harga != 0)
    {
        fprintf(dm, "\t%-10d%-20s%-20s%-20s%-10d\n", i + 1, history[i].nama, history[i].size, history[i].penyajian, history[i].harga);
        i++;
    }

    //Menutup file:
    fclose(dm);
    return 0;
}


int input(void)
{
    //Deklarasi struct temp untuk menyimpan data pesanan sebelum konfirmasi user:
    typedef struct m
    {
        char nama[10];
        char size[10];
        char penyajian[10];
        int harga;
    } m;
    m minuman;

    //Input nama minuman:
    printf(" Masukkan nama minuman (Kopi, Teh, Coklat, Soda): ");
    scanf("\n");
    fgets(minuman.nama, 10, stdin);
    strtok(minuman.nama, "\n");

    //Validasi nama minuman:
    for (int i = 0; i < 10; i++)
    {
        minuman.nama[i] = toupper(minuman.nama[i]);
    }
    if (    strcmp(minuman.nama, "KOPI") == 0
         || strcmp(minuman.nama, "TEH") == 0
         || strcmp(minuman.nama, "COKLAT") == 0
         || strcmp(minuman.nama, "SODA") == 0)
    {
        for (int i = 1; i < 10; i++)
        {
            minuman.nama[i] = tolower(minuman.nama[i]);
        }
    }
    else
    {
        printf(" %s tidak tersedia!\n\n", minuman.nama);
        input();
    }

    //Input size minuman:
    printf(" Masukkan size minuman (Small, Medium, Largest): ");
    scanf("\n");
    fgets(minuman.size, 10, stdin);
    strtok(minuman.size, "\n");

    //Validasi size minuman:
    for (int i = 0; i < 10; i++)
    {
        minuman.size[i] = toupper(minuman.size[i]);
    }
    if (    strcmp(minuman.size, "LARGEST") == 0
        ||  strcmp(minuman.size, "SMALL") == 0
        ||  strcmp(minuman.size, "MEDIUM") == 0)
    {
        for (int i = 1; i < 10; i++)
        {
            minuman.size[i] = tolower(minuman.size[i]);
        }
    }
    else
    {
        printf(" Ukuran %s tidak tersedia!\n\n", minuman.size);
        input();
    }

    //Input penyajian minuman:
    printf(" Masukkan penyajian minuman (Panas, Hangat, Dingin): ");
    scanf("\n");
    fgets(minuman.penyajian, 10, stdin);
    strtok(minuman.penyajian, "\n");

    //Validasi penyajian minuman:
    for (int i = 0; i < 10; i++)
    {
        minuman.penyajian[i] = toupper(minuman.penyajian[i]);
    }
    if (    strcmp(minuman.penyajian, "PANAS") == 0
        ||  strcmp(minuman.penyajian, "DINGIN") == 0
        ||  strcmp(minuman.penyajian, "HANGAT") == 0  )
    {
        for (int i = 1; i < 10; i++)
        {
            minuman.penyajian[i] = tolower(minuman.penyajian[i]);
        }
    }
    else
    {
        printf(" Penyajian %s tidak tersedia!\n\n", minuman.penyajian);
        input();
    }

    //Penghitungan harga minuman:
    minuman.harga = (strlen(minuman.size) * strlen(minuman.penyajian) * strlen(minuman.nama) * 100);

    //Konfirmasi:
    printf(" Detail pembelian:\n \tNama Minuman: %s\n \tSize: %s\n \tPenyajian: %s\n \tHarga: %i\n", 
             minuman.nama, minuman.size, minuman.penyajian, minuman.harga);
    char val;
    for (;;)
    {
        val = 0;
        printf(" Pencet tombol y untuk mengonfirmasi\n Pencet tombol n untuk batal\n ");
        scanf(" %c", &val);

        //Data ditambahkan ke data history:
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
        {
            return 1;
        }
        else
        {
            continue;
        }
    }
}

//Menampilkan data history penjualan:
void view(void)
{
    int i = 0;
    printf("\t%-10s%-20s%-20s%-20s%-10s\n", "No", "Nama Pesanan", "Size", "Penyajian", "Harga");
    while (history[i].harga != 0)
    {
        printf("\t%-10d%-20s%-20s%-20s%-10d\n", i + 1, history[i].nama, history[i].size, history[i].penyajian, history[i].harga);
        i++;
    }
    printf("\n Tekan enter untuk kembali ke menu utama.\n ");
    getchar();
}

int del(void)
{
    char buffer[10];
    int i = 0;
    int s = 0;
    int n;

    //Menampilkan list data history penjualan:
    printf("\t%-10s%-20s%-20s%-20s%-10s\n", "No", "Nama Pesanan", "Size", "Penyajian", "Harga");
    while (history[i].harga != 0)
    {
        printf("\t%-10d%-20s%-20s%-20s%-10d\n", i + 1, history[i].nama, history[i].size, history[i].penyajian, history[i].harga);
        i++;
    }

    do
    {
        //Meminta inputan index:
        printf("\n Masukkan nomor data yang ingin dihapus (tekan tombol 0 untuk batal): ");
        fgets(buffer, 10, stdin);
        s = atoi(buffer);
        if (s == 0)
        {
            return 1;
        }
    } //Validasi input minimal 1 (jika ada data history)  dan maksimal sebanyak jumlah data:
    while (history[s - 1].harga == 0);

    //Mengapus data sesuai dengan index yang diinput(-1 karena array mulai dari 0)
    s--;
    strcpy(history[s].nama, "\0");
    strcpy(history[s].size, "\0");
    strcpy(history[s].penyajian, "\0");
    history[s].harga = 0;

    //Menggeser ke belakang setiap inputan setelah data yang dihapus:
    for (n = (s + 1); history[n].harga != 0; n++)
    {
        strcpy(history[n - 1].nama, history[n].nama);
        strcpy(history[n - 1].size, history[n].size);
        strcpy(history[n - 1].penyajian, history[n].penyajian);
        history[n - 1].harga = history[n].harga;
    }
    strcpy(history[n - 1].nama, "\0");
    strcpy(history[n - 1].size, "\0");
    strcpy(history[n - 1].penyajian, "\0");
    history[n - 1].harga = 0;

    //mengurangi index
    ind--;

    //Menampilkan data history lagi:
    printf("\n");
    i = 0;
    printf("\t%-10s%-20s%-20s%-20s%-10s\n", "No", "Nama Pesanan", "Size", "Penyajian", "Harga");
    while (history[i].harga != 0)
    {
        printf("\t%-10d%-20s%-20s%-20s%-10d\n", i + 1, history[i].nama, history[i].size, history[i].penyajian, history[i].harga);
        i++;
    }
    printf("\n");
    return 0;
}
