#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int input_Data(void);
int input_Nilai(void);
int lihat_Status(void);
struct mahasiswa
{
    char nama[40];
    int nim;
    char matkul[40];
    int hadir;
    int tugas;
    int quiz;
    int forum;
    int uas;
    float nilai;
};
struct mahasiswa tahunini[1000];
int main()
{
    int menu;
    while (menu != 4)
    {
        char input[20];
        printf("~~~~~~~PROGRAM PENGHITUNGAN NILAI MAHASISWA~~~~~~~\nKetik nomor sesuai pilihan berikut:\n");
        printf("\t1: Input data mahasiswa\n\t2: Input nilai mahasiswa\n\t3: Lihat status dan nilai mahasiswa\n\t4: Keluar\n\t");
        scanf("\n");
        fgets(input, 20, stdin);
        menu = atoi(input);
        if (menu == 1)
        {
            input_Data();
            menu = 0;
        }
        if (menu == 2)
        {
            input_Nilai();
            menu = 0;
        }
        if (menu == 3)
        {
            lihat_Status();
            menu = 0;
        }
    }
    return 0;
}

int input_Data(void)
{
    int n = 0;
    while (n == 0)
    {
        char inp[20];
        printf("\tMasukkan NIM (harus kurang dari sepuluh digit): ");
        scanf("\n");
        fgets(inp,20, stdin);
        n = atoi(inp);
    }
    n %= 1000;
        if (strlen(tahunini[n].nama) != 0)
        {
            printf("\tData mahasiswa ini sudah dimasukkan:\n\tNama: %s\n\tMata Kuliah: %s\n", tahunini[n].nama, tahunini[n].matkul);
            return(1);
        }
        else
        {
            tahunini[n].nim = n;
            printf("\tMasukkan nama mahasiswa: ");
            fgets(tahunini[n].nama, 50, stdin);
            strtok(tahunini[n].nama, "\n");
            printf("\tMasukkan mata kuliah: ");
            fgets(tahunini[n].matkul, 50, stdin);
            strtok(tahunini[n].matkul, "\n");
            printf("\n");
            return(0);
        }
}
int input_Nilai(void)
{
    int n = 0;
    printf("\tMasukkan NIM: ");
    char input[20];
    char nilhad[20];
    char niltug[20];
    char nilquiz[20];
    char nilfor[20];
    char niluas[20];
    fgets(input,20, stdin);
    n = atoi(input);
    n %= 1000;
    if (strlen(tahunini[n].nama) == 0)
        {
            printf("\tMasukkan data mahasiswa itu dulu!\n\n");
            return(1);
        }
    printf("\tNama mahasiswa: %s\n\tMata kuliah: %s\n\t" , tahunini[n].nama, tahunini[n].matkul);
    while (tahunini[n].hadir == 0 || tahunini[n].hadir > 100)
    {
        printf("Nilai Hadir: ");
        fgets(nilhad,20, stdin);
        tahunini[n].hadir = atoi(nilhad);
    }
    while (tahunini[n].tugas == 0 || tahunini[n].tugas > 100)
    {
        printf("\tNilai Tugas: ");
        fgets(niltug,20, stdin);
        tahunini[n].tugas = atoi(niltug);
    }
    while (tahunini[n].quiz == 0 || tahunini[n].quiz > 100)
    {
    printf("\tNilai Quiz: ");
    fgets(nilquiz,20, stdin);
    tahunini[n].quiz = atoi(nilquiz);
    }
    while (tahunini[n].forum == 0 || tahunini[n].forum > 100)
    {
    printf("\tNilai keaktifan forum: ");
    fgets(nilfor,20, stdin);
    tahunini[n].forum = atoi(nilfor);
    }
    while (tahunini[n].uas == 0 || tahunini[n].uas > 100)
    {
    printf("\tNilai UAS: ");
    fgets(niluas,20, stdin);
    tahunini[n].uas = atoi(niluas);
    }
    printf("\tNilai %s berhasil dimasukkan.\n\n", tahunini[n].nama);
    return (0);
}
int lihat_Status (void)
{
    int n = 0;
    char lanj;
    char input[20];
    printf("\tMasukkan NIM: ");
    fgets(input, 20, stdin);
    n = atoi(input);
    n %= 1000;
    if (tahunini[n].hadir == 0 &&  tahunini[n].tugas == 0 &&  tahunini[n].quiz == 0 &&  tahunini[n].forum == 0 &&  tahunini[n].uas == 0)
    {
        printf("\tNilai mahasiswa belum dimasukkan.\n");
    }
    else
    {
        tahunini[n].nilai = (tahunini[n].hadir * 0.1 + tahunini[n].tugas * 0.2 + tahunini[n].quiz * 0.1 + tahunini[n].forum * 0.1 + tahunini[n].uas * 0.5);
        printf("\tNama mahasiswa: %s\n\tMata kuliah: %s\n", tahunini[n].nama, tahunini[n].matkul);
        printf("\tNilai hadir: %d\n\tNilai tugas: %d\n\tNilai quiz: %d\n\tNilai forum: %d\n\tNilai UAS: %d\n\tNilai akhir: %.0f\n", tahunini[n].hadir, tahunini[n].tugas, tahunini[n].quiz, tahunini[n].forum, tahunini[n].uas, tahunini[n].nilai);
        if (tahunini[n].nilai <= 100 && tahunini[n].nilai >= 90)
        {
            printf("\t%s mendapatkan grade A.\n", tahunini[n].nama);
            printf("\t%s lulus kelas %s\n", tahunini[n].nama, tahunini[n].matkul);
        }
        else if (tahunini[n].nilai <= 89 && tahunini[n].nilai >= 80)
        {
            printf("\t%s mendapatkan grade B.\n", tahunini[n].nama);
            printf("\t%s lulus kelas %s\n", tahunini[n].nama, tahunini[n].matkul);
        }
        else if (tahunini[n].nilai <= 79 && tahunini[n].nilai >= 70)
        {
            printf("\t%s mendapatkan grade C.\n", tahunini[n].nama);
            printf("\t%s lulus kelas %s\n", tahunini[n].nama, tahunini[n].matkul);
        }
        else if (tahunini[n].nilai <= 69 && tahunini[n].nilai >= 60)
        {
            printf("\t%s mendapatkan grade D.\n", tahunini[n].nama);
            printf("\t%s lulus kelas %s\n", tahunini[n].nama, tahunini[n].matkul);
        }
        else if (tahunini[n].nilai <= 59 && tahunini[n].nilai >= 50)
        {
            printf("\t%s mendapatkan grade E.\n", tahunini[n].nama);
            printf("\t%s tidak lulus kelas %s\n", tahunini[n].nama, tahunini[n].matkul);
        }
        else
        {
            printf("\t%s tidak lulus kelas %s\n", tahunini[n].nama, tahunini[n].matkul);
        }
        printf("\n\tKetik tombol apa saja lalu enter untuk lanjut.\n\t");
        scanf("\n%c", &lanj);
        printf("\n");
    }
}
