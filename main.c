#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int input_Data(void);
int input_Nilai(void);
int lihat_Status(void);
int n = 0;
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
    while (menu == 0)
    {
        printf("\nProgram penghitungan nilai mahasiswa:\nKetik nomor sesuai pilihan berikut:\n");
        printf("1: Input data mahasiswa\n2: Input nilai mahasiswa\n3: Lihat status dan nilai mahasiswa\n4: Keluar\n\n");
        scanf("\n%d", &menu);
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
    while (n == 0)
    {
        printf("Masukkan NIM: ");
        scanf("%d", &n);
    }
    n %= 1000;
        if (strlen(tahunini[n].nama) != 0)
        {
            printf("Data mahasiswa ini sudah dimasukkan:\nNama: %s\nMata Kuliah: %s\n", tahunini[n].nama, tahunini[n].matkul);
            return(1);
        }
        else
        {
            tahunini[n].nim = n-1;
            printf("Masukkan nama mahasiswa: ");
            scanf("\n%[^\n]s", &tahunini[n].nama);
            printf("Masukkan mata kuliah: ");
            scanf("\n%[^\n]s", &tahunini[n].matkul);
            printf("Data berhasil dimasukkan.\n");
            return(0);
        }
}
int input_Nilai(void)
{
    printf("Masukkan NIM mahasiswa: ");
    scanf("%d", &n);
    n %= 1000;
    if (strlen(tahunini[n].nama) == 0)
        {
            printf("Masukkan data mahasiswa itu dulu!\n");
            return(1);
        }
    printf("Nama mahasiswa: %s\nMata kuliah: %s\nNilai Hadir: ", tahunini[n].nama, tahunini[n].matkul);
    scanf("%d", &tahunini[n].hadir);
    printf("Nilai Tugas: ");
    scanf("%d", &tahunini[n].tugas);
    printf("Nilai Quiz: ");
    scanf("%d", &tahunini[n].quiz);
    printf("Nilai keaktifan forum: ");
    scanf("%d", &tahunini[n].forum);
    printf("Nilai UAS: ");
    scanf("%d", &tahunini[n].uas);
    printf("Nilai %s berhasil dimasukkan.\n", tahunini[n].nama);
    return (0);
}
int lihat_Status (void)
{
    printf("Masukkan NIM mahasiswa: ");
    scanf("%d", &n);
    n %= 1000;
    if (tahunini[n].hadir == 0 &&  tahunini[n].tugas == 0 &&  tahunini[n].quiz == 0 &&  tahunini[n].forum == 0 &&  tahunini[n].uas == 0)
    {
        printf("Nilai mahasiswa belum dimasukkan.\n");
    }
    else
    {
        tahunini[n].nilai = (tahunini[n].hadir * 0.1 + tahunini[n].tugas * 0.2 + tahunini[n].quiz * 0.1 + tahunini[n].forum * 0.1 + tahunini[n].uas * 0.5);
        printf("Nama mahasiswa: %s\nMata kuliah: %s\nNilai: %.0f\n", tahunini[n].nama, tahunini[n].matkul, tahunini[n].nilai);
        if (tahunini[n].nilai <= 100 && tahunini[n].nilai >= 90)
        {
            printf("%s mendapatkan grade A.\n", tahunini[n].nama);
            printf("%s lulus kelas %s.\n", tahunini[n].nama, tahunini[n].matkul);
        }
        else if (tahunini[n].nilai <= 89 && tahunini[n].nilai >= 80)
        {
            printf("%s mendapatkan grade B.\n", tahunini[n].nama);
            printf("%s lulus kelas %s.\n", tahunini[n].nama, tahunini[n].matkul);
        }
        else if (tahunini[n].nilai <= 79 && tahunini[n].nilai >= 70)
        {
            printf("%s mendapatkan grade C.\n", tahunini[n].nama);
            printf("%s lulus kelas %s.\n", tahunini[n].nama, tahunini[n].matkul);
        }
        else if (tahunini[n].nilai <= 69 && tahunini[n].nilai >= 60)
        {
            printf("%s mendapatkan grade D.\n", tahunini[n].nama);
            printf("%s lulus kelas %s.\n", tahunini[n].nama, tahunini[n].matkul);
        }
        else if (tahunini[n].nilai <= 59 && tahunini[n].nilai >= 50)
        {
            printf("%s mendapatkan grade E.\n", tahunini[n].nama);
            printf("%s tidak lulus kelas %s.\n", tahunini[n].nama, tahunini[n].matkul);
        }
        else
        {
            printf("%s tidak lulus kelas %s.\n", tahunini[n].nama, tahunini[n].matkul);
        }
        return (0);
    }
}
