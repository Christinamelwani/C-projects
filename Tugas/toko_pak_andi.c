#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sembako
{
    char nama[50];
    int stock;
    char detail[200];
    double harga;
    int active_psuedobool;
    struct Sembako *left;
    struct Sembako *right;
} * head, *tail;

void inputBaru(void);
void tambahStok(void);
void inputPenjualan(void);
void lihatStok(void);

int main(void)
{
    int navigasi = 0;
    int i = 0;
    char buffer[20];
    printf("Selamat datang di interface toko Pak Andi!\n\n");

    while (navigasi != 5)
    {
        printf("Tekan nomor sesuai dengan fitur yang diinginkan:\n\n"
               "1. Input barang baru\n"
               "2. Tambah stok barang\n"
               "3. Input data penjualan\n"
               "4. Lihat stok dan detail barang\n"
               "5. Keluar\n");

        scanf("\n");
        fgets(buffer, 20, stdin);
        navigasi = atoi(buffer);

        if (navigasi == 1)
        {
            inputBaru();
        };
        if (navigasi == 2)
        {
            tambahStok();
        };
        if (navigasi == 3)
        {
            inputPenjualan();
        };
        if (navigasi == 4)
        {
            lihatStok();
        };
    }
    return 0;
};

void inputBaru(void)
{
    struct Sembako *tambahan = (struct Sembako *)malloc(sizeof(struct Sembako));

    int temp = 0;
    char buffer[200];

    printf("Masukkan nama product baru: ");

    // User input dilakukan dengan cara ini untuk menghindari infinite loop jika input tidak sesuai
    scanf("\n");
    fgets(buffer, 50, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    strcpy(tambahan->nama, buffer);
    strcpy(buffer, "");

    printf("Masukkan harga %s: ", tambahan->nama);
    scanf("\n");
    fgets(buffer, 40, stdin);
    temp = atoi(buffer);

    tambahan->harga = temp;

    printf("Masukkan stock awal %s: ", tambahan->nama);
    scanf("\n");
    fgets(buffer, 40, stdin);
    temp = atoi(buffer);

    tambahan->stock = temp;

    printf("Masukkan detail %s: ", tambahan->nama);
    scanf("\n");
    fgets(buffer, 200, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    strcpy(tambahan->detail, buffer);
    strcpy(buffer, "");

    if (head != NULL)
    {
        tambahan->left = tail;
        tail->right = tambahan;
        tail = tambahan;
    }
    else
    {
        head = tail = tambahan;
    }

    head->left = NULL;
    tail->right = NULL;
    printf("%s sukses ditambahkan\n", tambahan->nama);
};

void tambahStok(void)
{
    struct Sembako *pointer = head;
    int count = 0;
    int pilihan = 0;
    int tambahanStok = 0;
    printf("Tekan nomor produk yang ingin di-restock.\n");

    if (pointer == NULL)
    {
        printf("Input barang dulu!\n");
        return;
    }

    while (pointer != NULL)
    {
        count++;
        printf("%d. %s: sisa %d\n", count, pointer->nama, pointer->stock);
        pointer = pointer->right;
    }

    char buffer[20];

    scanf("\n");
    fgets(buffer, 20, stdin);
    pilihan = atoi(buffer);

    count = 1;
    pointer = head;

    while (pointer != tail && count < pilihan)
    {
        count++;
        pointer = pointer->right;
    }

    printf("Ketik jumlah %s yang ingin ditambahkan ke stock: ", pointer->nama);
    scanf("\n");
    fgets(buffer, 20, stdin);
    tambahanStok = atoi(buffer);

    pointer->stock += tambahanStok;
    printf("%s sukses di-restock\n", pointer->nama);
};

void inputPenjualan(void)
{
    struct Sembako *pointer = head;
    int count = 0;
    int pilihan = 0;
    int pembelian = 0;
    printf("Tekan nomor produk yang ingin dibeli.\n");

    if (pointer == NULL)
    {
        printf("Input barang dulu!\n");
        return;
    }

    while (pointer != NULL)
    {
        count++;
        printf("%d. %s: sisa %d\n", count, pointer->nama, pointer->stock);
        pointer = pointer->right;
    }

    char buffer[20];

    scanf("\n");
    fgets(buffer, 20, stdin);
    pilihan = atoi(buffer);

    count = 1;
    pointer = head;

    while (pointer != tail && count < pilihan)
    {
        count++;
        pointer = pointer->right;
    }

    printf("Ketik jumlah %s yang ingin dibeli: ", pointer->nama);
    scanf("\n");
    fgets(buffer, 20, stdin);
    pembelian = atoi(buffer);

    if (pointer->stock - pembelian < 0)
    {
        printf("Stock tidak cukup! Mohon tambahin stock dulu.\n");
        return;
    }

    pointer->stock -= pembelian;
    printf("Stok %s sukses dikurangi.\n", pointer->nama);
};

void lihatStok(void)
{
    struct Sembako *pointer = head;
    int count = 0;
    int pilihan = 0;
    printf("Tekan nomor yang sesuai untuk melihat detail produk.\n");

    while (pointer != NULL)
    {
        count++;
        printf("%d. %s: sisa %d\n", count, pointer->nama, pointer->stock);
        pointer = pointer->right;
    }

    char buffer[20];

    scanf("\n");
    fgets(buffer, 20, stdin);
    pilihan = atoi(buffer);

    count = 1;
    pointer = head;

    while (pointer != tail && count < pilihan)
    {
        count++;
        pointer = pointer->right;
    }

    printf("Tekan tombol apa saja untuk lanjut:\n----%s---\nStock: %d\nHarga: Rp. %0.2lf\nDetail: %s\n", pointer->nama, pointer->stock, pointer->harga, pointer->detail);
    getchar();
};
