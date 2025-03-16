
#include "halaman.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");  // Untuk Windows
#else
    system("clear"); // Untuk Linux/Mac
#endif
}

void welcomeScreen() {
    clearScreen();
    puts("******************************************");
    puts("*   APLIKASI ADMINISTRASI NILAI UAS     *");
    puts("******************************************");
    puts("Tekan Enter untuk masuk ke Dashboard...");
    getchar();
}

void loadFromFile(List *L) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) return;
    
    char nama[50];
    int nilai;
    while (fscanf(file, "%[^,],%d\n", nama, &nilai) != EOF) {
        if (Search(*L, nama) == NULL) {
            address newNode = CreateNode(nama, nilai);
            InsertLast(L, newNode);
        }
    }
    fclose(file);
}

void saveToFile(List L) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) return;
    
    address P = L.First;
    while (P != NULL) {
        fprintf(file, "%s,%d\n", P->namaMahasiswa, P->nilai);
        P = P->next;
    }
    fclose(file);
}

void tambahDataMahasiswa(List *L) {
    int choice;
    do {
        clearScreen();
        puts("**************************TAMBAH DATA MAHASISWA**************************");
        puts("1. Tambah Mahasiswa");
        puts("2. Kembali ke Dashboard");
        printf("Pilihan: ");
        while (scanf("%d", &choice) != 1) {
            printf("Input tidak valid! Masukkan angka: ");
            while (getchar() != '\n');
        }
        getchar();

        if (choice == 1) {
            char nama[50];
            int nilai;
            printf("Masukkan Nama: ");
            fgets(nama, sizeof(nama), stdin);
            nama[strcspn(nama, "\n")] = 0;
            
            if (Search(*L, nama) != NULL) {
                printf("Nama sudah ada!\n");
                continue;
            }

            printf("Masukkan Nilai: ");
            scanf("%d", &nilai);
            getchar();

            address newNode = CreateNode(nama, nilai);
            InsertLast(L, newNode);
            saveToFile(*L);
            printf("Data berhasil ditambahkan!\n");
        }
    } while (choice != 2);
}

void editDataMahasiswa(List *L) {
    clearScreen();
    puts("**************************EDIT DATA MAHASISWA**************************");
    PrintList(*L);
    char nama[50];
    printf("Masukkan Nama Mahasiswa yang ingin diubah: ");
    scanf("%s", nama);
    getchar();

    address P = Search(*L, nama);
    if (P == NULL) {
        printf("Mahasiswa tidak ditemukan!\n");
        return;
    }

    char namaBaru[50];
    int nilaiBaru;
    printf("Masukkan Nama Baru: ");
    fgets(namaBaru, sizeof(namaBaru), stdin);
    namaBaru[strcspn(namaBaru, "\n")] = 0;
    printf("Masukkan Nilai Baru: ");
    scanf("%d", &nilaiBaru);
    getchar();
    
    EditMahasiswa(P, namaBaru, nilaiBaru);
    saveToFile(*L);
    printf("Data berhasil diperbarui!\n");
}

void hapusDataMahasiswa(List *L) {
    clearScreen();
    puts("**************************HAPUS DATA MAHASISWA**************************");
    PrintList(*L);
    
    char nama[50];
    printf("Masukkan Nama Mahasiswa yang ingin dihapus: ");
    scanf("%s", nama);
    getchar();

    address P = Search(*L, nama);
    if (P == NULL) {
        printf("Mahasiswa tidak ditemukan!\n");
        return;
    }

    // Jika elemen pertama yang akan dihapus
    if (P == L->First) {
        DeleteFirst(L);
    } else {
        // Cari node sebelum P
        address prev = L->First;
        while (prev->next != NULL && prev->next != P) {
            prev = prev->next;
        }

        // Jika ditemukan, hapus setelah prev (yaitu P)
        if (prev->next == P) {
            DeleteAfter(prev);
        }
    }

    saveToFile(*L);
    printf("Data berhasil dihapus!\n");
}

void lihatDataMahasiswa(List L) {
    int choice;
    do {
        clearScreen();
        puts("**************************LIHAT DATA MAHASISWA**************************");
        puts("1. Urutkan berdasarkan Nama (Ascending)");
        puts("2. Urutkan berdasarkan Nama (Descending)");
        puts("3. Urutkan berdasarkan Nilai (Ascending)");
        puts("4. Urutkan berdasarkan Nilai (Descending)");
        puts("5. Kembali ke Dashboard");
        printf("Pilihan: ");
        while (scanf("%d", &choice) != 1) {
            printf("Input tidak valid! Masukkan angka: ");
            while (getchar() != '\n');
        }
        getchar();

        switch (choice) {
            case 1:
                PrintNamaAscending(L);
                break;
            case 2:
                PrintDescending(L);
                break;
            case 3:
                PrintNilaiAscending(L);
                break;
            case 4:
                PrintNilaiDescending(L);
                break;
        }

        if (choice != 5) {
            printf("\nTekan Enter untuk kembali ke menu...");
            getchar();  // Menunggu input sebelum kembali
        }
    } while (choice != 5);
}


void dashboard(List *L) {
    int choice;
    do {
        clearScreen();
        puts("**************************DASHBOARD UTAMA**************************");
        puts("1. Tambah Data Mahasiswa");
        puts("2. Edit Data Mahasiswa");
        puts("3. Hapus Data Mahasiswa");
        puts("4. Lihat Data Mahasiswa");
        puts("5. Algoritma Awal");
        puts("6. Keluar");
        printf("Pilihan: ");
        while (scanf("%d", &choice) != 1) {
            printf("Input tidak valid! Masukkan angka: ");
            while (getchar() != '\n');
        }
        getchar();

        switch (choice) {
            case 1:
                tambahDataMahasiswa(L);
                break;
            case 2:
                editDataMahasiswa(L);
                break;
            case 3:
                hapusDataMahasiswa(L);
                break;
            case 4:
                lihatDataMahasiswa(*L);
                break;
            case 5:
                PrintAlgoritmaAwal();
                break;                
        }
    } while (choice != 6);
}
