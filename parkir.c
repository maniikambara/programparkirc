#include <stdio.h>
#include <stdlib.h>

#define max_rows 100
#define max_cars 10

typedef struct {
    int row;
    int number;
} Car;

typedef struct {
    Car cars[max_cars];
    int hitung;
} Baris;

Baris rows[max_rows];
Baris temp;

int cek_nomor(int row, int number) {
    int i;
    for (i = 0; i < rows[row].hitung; i++) {
        if (rows[row].cars[i].number == number) {
            return 1;
        }
    }
    return 0;
}

void parkir(int row, int number) {
    if (rows[row].hitung < max_cars) {
        if (cek_nomor(row, number)) {
            printf("\nMaaf, nomor mobil %d sudah ada di baris %d.\n", number, row);
            printf("\n+-----------------------------------------+\n\n");
            return;
        }
        rows[row].cars[rows[row].hitung].row = row;
        rows[row].cars[rows[row].hitung].number = number;
        rows[row].hitung++;
        printf("\nMobil dengan nomor %d pada baris %d berhasil diparkir.\n", number, row);
        printf("\n+-----------------------------------------+\n\n");
    } else {
        printf("Maaf, baris %d pada tempat parkir sudah penuh.\n", row);
        printf("\n+-----------------------------------------+\n\n");
    }
}

void keluar(int row, int number) {
    int i, j;
    for (i = 0; i < rows[row].hitung; i++) {
        printf("\nMobil dengan nomor %d pada baris %d berhasil dikeluarkan.", number, row);
        printf("\n\n+-----------------------------------------+\n\n");
        if (rows[row].cars[i].number == number) {
            if (i == rows[row].hitung - 1) {
                rows[row].hitung--;
                return;
            }
            for (j = i + 1; j < rows[row].hitung; j++) {
                temp.cars[temp.hitung++] = rows[row].cars[j];
            }
            for (j = i + 1; j < rows[row].hitung; j++) {
                rows[row].cars[j - 1] = rows[row].cars[j];
            }
            rows[row].hitung--;
            for (j = temp.hitung - 1; j >= 0; j--) {
                parkir(temp.cars[j].row, temp.cars[j].number);
            }
            temp.hitung = 0;
            return;
        }
    }
    printf("\nMobil dengan nomor %d tidak ditemukan di baris %d pada tempat parkir.\n", number, row);
    printf("\n+-----------------------------------------+\n\n");
}

void lihat_parkir() {
    int i, j;
    int ada_mobil = 0;
    printf("Isi Tempat Parkir\n\n");
    for (i = 0; i < max_rows; i++) {
        if (rows[i].hitung > 0) {
            ada_mobil = 1;
            printf("Mobil pada Baris %d : |", i);
            for (j = 0; j < rows[i].hitung; j++) {
                printf(" %d |", rows[i].cars[j].number);
            }
            printf("\n");
        }
    }
    if (ada_mobil == 0) {
        printf("Parkiran Kosong\n");
    }
    printf("\n+-----------------------------------------+\n\n");
}

int main() {
    int pilihan, row, number;
    while (1) {
        system("cls");
        printf("+-----------------------------------------+\n\n");
        printf("\t   PROGRAM TEMPAT PARKIR\n\n");
        printf("+-----------------------------------------+\n\n");
        printf("\t1. Parkir Mobil\n");
        printf("\t2. Keluarkan Mobil\n");
        printf("\t3. Tampilkan Tempat Parkir\n");
        printf("\t4. Keluar\n\n");
        printf("+-----------------------------------------+\n\n");
        printf("\t     KELOMPOK 1 KELAS E\n\n");
        printf("\tPILIHAN (1-4) : ");
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                system("cls");
                printf("+-----------------------------------------+\n\n");
                printf("\t     PARKIR MOBIL\n\n");
                printf("+-----------------------------------------+\n\n");
                printf("\tMasukkan nomor baris : ");
                scanf("%d", &row);
                printf("\tMasukkan nomor mobil : ");
                scanf("%d", &number);
                parkir(row, number);
                system("pause");
                break;
            case 2:
                system("cls");
                printf("+-----------------------------------------+\n\n");
                printf("\t     KELUARKAN MOBIL\n\n");
                printf("+-----------------------------------------+\n\n");
                printf("\tMasukkan nomor baris : ");
                scanf("%d", &row);
                printf("\tMasukkan nomor mobil : ");
                scanf("%d", &number);
                keluar(row, number);
                system("pause");
                break;
            case 3:
                system("cls");
                printf("+-----------------------------------------+\n\n");
                printf("\t     ISI TEMPAT PARKIR\n\n");
                printf("+-----------------------------------------+\n\n");
                lihat_parkir();
                system("pause");
                break;
            case 4:
                printf("\n\t\tTerimakasih!\n");
                return 0;
            default:
                printf("\n\t    Pilihan tidak valid.\n");
                system("pause");
        }
    }
}