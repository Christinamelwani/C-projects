#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tanggal
{
    int day;
    int month;
    int year;
};

struct Karyawan
{
    int Employee_ID;
    char Nama_Lengkap[30];
    char Tempat_Lahir[30];
    struct tanggal Tanggal_Lahir;
    char Jabatan[50];
    struct Karyawan *next;
} * head;

int inputString(char *pointer, int limit)
{
    // User input dilakukan melalui fungsi ini untuk menghindari infinite loop jika input tidak sesuai
    char buffer[200];
    scanf("\n");
    fgets(buffer, 50, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    if (strlen(buffer) > limit)
    {
        printf("Input melewati limit karakter.\nCoba lagi: ");
        return 1;
    }
    strcpy(pointer, buffer);
    return 0;
};

int inputNumber(int *pointer)
{
    int temp = 0;
    char buffer[200];
    scanf("\n");
    fgets(buffer, 40, stdin);
    temp = atoi(buffer);
    if (!(temp <= 99999))
    {
        printf("Input melewati limit angka.\nCoba lagi: ");
        return 1;
    }
    *pointer = temp;
    return 0;
};

void transverseList(void)
{
    struct Karyawan *pointer = head;
    printf("\t%-10s%-20s%-20s%-20s%-10s\n", "ID", "Nama Lengkap", "Tanggal Lahir", "Tempat Lahir", "Jabatan");
    while (pointer != NULL)
    {
        printf("\t%-10d%-20s%2d/%2d/%4d\t  %-20s%-10s\n", pointer->Employee_ID, pointer->Nama_Lengkap, pointer->Tanggal_Lahir.day, pointer->Tanggal_Lahir.month, pointer->Tanggal_Lahir.year, pointer->Tempat_Lahir, pointer->Jabatan);
        pointer = pointer->next;
    }
}

void insertNode()
{
    struct Karyawan *pointer = head;
    struct Karyawan *newNode = (struct Karyawan *)malloc(sizeof(struct Karyawan));

    int count = 0;
    while (pointer != NULL)
    {
        pointer = pointer->next;
        count++;
    }
    if (count == 5)
    {
        printf("Daftar sudah penuh!\n");
        return;
    }

    pointer = head;

    if (newNode == NULL)
    {
        printf("Memori tidak cukup!");
        return;
    }

    printf("Masukkan ID karyawan: ");
    while (inputNumber(&(newNode->Employee_ID)) != 0)
        ;

    printf("Masukkan nama lengkap karyawan: ");
    while (inputString(newNode->Nama_Lengkap, 30) != 0)
        ;
    printf("Masukkan tanggal lahir karyawan dengan format DD/MM/YYYY: ");
    scanf("%2d/%2d/%4d", &(newNode->Tanggal_Lahir.day), &(newNode->Tanggal_Lahir.month), &(newNode->Tanggal_Lahir.year));

    printf("Masukkan tempat lahir karyawan: ");
    while (inputString(newNode->Tempat_Lahir, 30) != 0)
        ;
    printf("Masukkan jabatan karyawan: ");
    while (inputString(newNode->Jabatan, 50) != 0)
        ;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else if (newNode->Employee_ID < head->Employee_ID)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct Karyawan *current = head;

        while (current->next != NULL && newNode->Employee_ID < current->Employee_ID)
            current = current->next;

        newNode->next = current->next;
        current->next = newNode;
    }

    return;
}

void hapusNode(void)
{
    printf("Input ID karyawan yang mau dihapus.");
    transverseList();
    int id = 0;
    inputNumber(&id);
    struct Karyawan *temp = head, *prev;

    if (temp != NULL && temp->Employee_ID == id)
    {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->Employee_ID != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("No employee found with that ID!");
        return;
    }

    prev->next = temp->next;

    free(temp);
}
void hapusList(void)
{
    struct Karyawan *current = head;
    struct Karyawan *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
    printf("List berhasil dihapus\n");
};
int main(void)
{
    int navigasi = 0;
    printf("Selamat datang di interface database karyawan!\n");

    while (navigasi != 5)
    {
        printf("\nTekan nomor sesuai dengan fitur yang diinginkan:\n\n"
               "1. Input karyawan baru\n"
               "2. Tampilkan semua daftar Karyawan \n"
               "3. Hapus karyawan menurut ID \n"
               "4. Hapus Seluruh list \n"
               "5. Keluar\n");

        inputNumber(&navigasi);

        if (navigasi == 1)
        {
            insertNode();
        };
        if (navigasi == 2)
        {
            transverseList();
            printf("\tTekan tombol apa saja untuk lanjut.\n");
            getchar();
        };
        if (navigasi == 3)
        {
            hapusNode();
        };
        if (navigasi == 4)
        {
            hapusList();
        };
    }
    return 0;
}
