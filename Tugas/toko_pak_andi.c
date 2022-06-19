#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sembako
{
    char nama[50];
    int stock;
    char detail[200];
    int harga;
    int active_psuedobool;
    struct Sembako *left;
    struct Sembako *right;
} * head, *tail;

int totalOmset = 0;

void inputNumber(int *pointer);
void inputString(char *pointer);
void tamplikanList(void);
struct Sembako *pilihBarang(int pilihan);
void inputBaru(void);
void tambahStok(void);
void inputPenjualan(void);
void lihatStok(void);
void hapusBarang(void);

int main(void)
{
    int navigasi = 0;
    printf("Selamat datang di interface toko Pak Andi!\n");

    while (navigasi != 6)
    {
        printf("\nTotal omset: Rp. %d", totalOmset);
        printf("\nTekan nomor sesuai dengan fitur yang diinginkan:\n\n"
               "1. Input barang baru\n"
               "2. Tambah stok barang\n"
               "3. Input data penjualan\n"
               "4. Lihat stok dan detail barang\n"
               "5. Hapus Barang\n"
               "6. Keluar\n");

        inputNumber(&navigasi);

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
        if (navigasi == 5)
        {
            hapusBarang();
        };
    }
    return 0;
};

void inputString(char *pointer)
{
    // User input dilakukan melalui fungsi ini untuk menghindari infinite loop jika input tidak sesuai
    char buffer[200];
    scanf("\n");
    fgets(buffer, 50, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    strcpy(pointer, buffer);
};

void inputNumber(int *pointer)
{
    int temp = 0;
    char buffer[200];
    scanf("\n");
    fgets(buffer, 40, stdin);
    temp = atoi(buffer);
    *pointer = temp;
};

void tampilkanList(void)
{
    struct Sembako *pointer = head;
    int count = 0;
    while (pointer != NULL)
    {
        count++;
        printf("%d. %s: sisa %d\n", count, pointer->nama, pointer->stock);
        pointer = pointer->right;
    }
}

struct Sembako *pilihBarang(int pilihan)
{
    if (head == NULL)
    {
        printf("Input barang dulu!\n");
        return NULL;
    }

    struct Sembako *pointer = head;
    int count = 1;
    while (pointer != tail && count < pilihan)
    {
        count++;
        pointer = pointer->right;
    }

    return pointer;
}

void inputBaru(void)
{
    struct Sembako *tambahan = (struct Sembako *)malloc(sizeof(struct Sembako));

    printf("Masukkan nama product baru: ");
    inputString(tambahan->nama);

    printf("Masukkan harga %s: ", tambahan->nama);
    inputNumber(&(tambahan->harga));

    printf("Masukkan stock awal %s: ", tambahan->nama);
    inputNumber(&(tambahan->stock));

    printf("Masukkan detail %s: ", tambahan->nama);
    inputString(tambahan->detail);

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

    printf("%s sukses ditambahkan.\n", tambahan->nama);
};

void tambahStok(void)
{
    int pilihan = 0;
    int count = 0;
    int tambahanStok = 0;

    printf("Tekan nomor produk yang ingin di-restock.\n");
    tampilkanList();

    inputNumber(&pilihan);
    struct Sembako *pointer = pilihBarang(pilihan);
    if (pointer == NULL)
    {
        return;
    }

    printf("Ketik jumlah %s yang ingin ditambahkan ke stock: ", pointer->nama);
    inputNumber(&tambahanStok);
    pointer->stock += tambahanStok;

    printf("%s sukses di-restock.\n", pointer->nama);
};

void inputPenjualan(void)
{
    int pilihan = 0;
    int pembelian = 0;

    printf("Tekan nomor produk yang ingin dibeli.\n");
    tampilkanList();
    inputNumber(&pilihan);

    struct Sembako *pointer = pilihBarang(pilihan);
    if (pointer == NULL)
    {
        return;
    }

    printf("Ketik jumlah %s yang ingin dibeli: ", pointer->nama);
    inputNumber(&pembelian);

    if (pointer->stock - pembelian < 0)
    {
        printf("Stock tidak cukup! Mohon tambahin stock dulu.\n");
        return;
    }

    pointer->stock -= pembelian;
    totalOmset += pointer->harga * pembelian;

    printf("Stok %s sukses dikurangi.\n", pointer->nama);
};

void lihatStok(void)
{
    printf("Tekan nomor yang sesuai untuk melihat detail produk:\n");
    tampilkanList();

    int pilihan = 0;
    inputNumber(&pilihan);
    struct Sembako *pointer = pilihBarang(pilihan);

    printf("\n----%s---\nStock: %d\nHarga: Rp. %i\nDetail: %s\n", pointer->nama, pointer->stock, pointer->harga, pointer->detail);
    getchar();
};

void hapusBarang(void)
{
    printf("Tekan nomor barang yang ingin dihapus:\n");
    tampilkanList();
    int pilihan = 0;
    inputNumber(&pilihan);
    struct Sembako *pointer = pilihBarang(pilihan);
    if (pointer == NULL)
    {
        return;
    }

    if (pointer == head)
    {
        head = pointer->right;
    }
    if (pointer->left != NULL)
    {
        pointer->left->right = pointer->right;
    }
    if (pointer->right != NULL)
    {
        pointer->right->left = pointer->left;
    }

    free(pointer);
    printf("Barang sukses dihapus:\n");
}