/*
Author: Roufiel Hadi  
NIM: 241524028  
Kelas: 1A  
Prodi: Sarjana Terapan Teknik Informatika  
Jurusan: Teknik Komputer dan Informatika  
Politeknik Negeri Bandung  
*/

#include "linked.h"

// Konstruktor: Inisialisasi List Kosong
void CreateList(List *L) {
    L->First = NULL;
}

// Destruktor: Hapus semua elemen dalam list
void DeleteList(List *L) {
    address temp;
    while (L->First != NULL) {
        temp = L->First;
        L->First = L->First->next;
        free(temp);
    }
}

// Validator: Mengecek apakah list kosong
boolean isEmpty(List L) {
    return (L.First == NULL);
}

// Membuat node baru dengan data yang diberikan
address CreateNode(char *nama, int nilai) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != NULL) {
        strcpy(P->namaMahasiswa, nama);
        P->nilai = nilai;
        P->next = NULL;
    }
    return P;
}

// Insert di awal list
void InsertFirst(List *L, address P) {
    P->next = L->First;
    L->First = P;
}

// Insert di akhir list
void InsertLast(List *L, address P) {
    if (isEmpty(*L)) {
        L->First = P;
    } else {
        address temp = L->First;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = P;
    }
}

// Insert setelah node tertentu
void InsertAfter(address pBef, address PNew) {
    if (pBef != NULL) {
        PNew->next = pBef->next;
        pBef->next = PNew;
    }
}

// Hapus elemen pertama
void DeleteFirst(List *L) {
    if (!isEmpty(*L)) {
        address temp = L->First;
        L->First = L->First->next;
        free(temp);
    }
}

// Hapus elemen terakhir
void DeleteLast(List *L) {
    if (!isEmpty(*L)) {
        address temp = L->First;
        if (temp->next == NULL) {
            free(temp);
            L->First = NULL;
        } else {
            address prev = NULL;
            while (temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            free(temp);
        }
    }
}

// Hapus elemen setelah node tertentu
void DeleteAfter(address pBef) {
    if (pBef != NULL && pBef->next != NULL) {
        address temp = pBef->next;
        pBef->next = temp->next;
        free(temp);
    }
}

// Mengembalikan memori node ke sistem
void DeAlokasi(address *P) {
    free(*P);
    *P = NULL;
}

// Menghitung jumlah elemen dalam list
int NbElmt(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

// Mencari elemen berdasarkan nama mahasiswa
address Search(List L, char *nama) {
    address P = L.First;
    while (P != NULL) {
        if (strcmp(P->namaMahasiswa, nama) == 0)
            return P;
        P = P->next;
    }
    return NULL;
}

// Mengembalikan nilai minimum dalam list
int Min(List L) {
    if (isEmpty(L)) return -1;
    int minVal = L.First->nilai;
    address P = L.First->next;
    while (P != NULL) {
        if (P->nilai < minVal) minVal = P->nilai;
        P = P->next;
    }
    return minVal;
}

// Mengembalikan rata-rata nilai dalam list
float Rerata(List L) {
    if (isEmpty(L)) return 0;
    int total = 0, count = 0;
    address P = L.First;
    while (P != NULL) {
        total += P->nilai;
        count++;
        P = P->next;
    }
    return (float)total / count;
}

// Menampilkan isi list
void PrintList(List L) {
    address P = L.First;
    while (P != NULL) {
        printf("Nama: %s, Nilai: %d\n", P->namaMahasiswa, P->nilai);
        P = P->next;
    }
}

// Membalik urutan elemen dalam list
List BalikList(List L) {
    List newList;
    CreateList(&newList);
    address P = L.First;
    while (P != NULL) {
        InsertFirst(&newList, CreateNode(P->namaMahasiswa, P->nilai));
        P = P->next;
    }
    return newList;
}

// Memasukkan elemen secara ascending berdasarkan nama
void InsertSorted(List *L, address P) {
    if (isEmpty(*L) || strcmp(P->namaMahasiswa, L->First->namaMahasiswa) < 0) {
        InsertFirst(L, P);
    } else {
        address temp = L->First;
        while (temp->next != NULL && strcmp(temp->next->namaMahasiswa, P->namaMahasiswa) < 0) {
            temp = temp->next;
        }
        InsertAfter(temp, P);
    }
}

// Menampilkan list secara ascending berdasarkan nama
void PrintNamaAscending(List L) {
    if (isEmpty(L)) {
        printf("List kosong!\n");
        return;
    }
    
    int count = NbElmt(L);
    address *arr = (address *)malloc(count * sizeof(address));
    address P = L.First;
    for (int i = 0; i < count; i++) {
        arr[i] = P;
        P = P->next;
    }
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(arr[j]->namaMahasiswa, arr[j + 1]->namaMahasiswa) > 0) {
                address temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("\nDaftar Mahasiswa Berdasarkan Nama (Ascending):\n");
    for (int i = 0; i < count; i++) {
        printf("Nama: %s, Nilai: %d\n", arr[i]->namaMahasiswa, arr[i]->nilai);
    }
    free(arr);
}

// Menampilkan list secara descending berdasarkan nama
void PrintDescending(List L) {
    if (isEmpty(L)) {
        printf("List kosong!\n");
        return;
    }
    
    int count = NbElmt(L);
    address *arr = (address *)malloc(count * sizeof(address));
    address P = L.First;
    for (int i = 0; i < count; i++) {
        arr[i] = P;
        P = P->next;
    }
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(arr[j]->namaMahasiswa, arr[j + 1]->namaMahasiswa) < 0) {
                address temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("\nDaftar Mahasiswa Berdasarkan Nama (Descending):\n");
    for (int i = 0; i < count; i++) {
        printf("Nama: %s, Nilai: %d\n", arr[i]->namaMahasiswa, arr[i]->nilai);
    }
    free(arr);
}

// Menyalin elemen dengan nilai > 70 ke L2
void CopyNilaiDiAtas70(List L1, List *L2) {
    address P = L1.First;
    while (P != NULL) {
        if (P->nilai > 70) {
            address newNode = CreateNode(P->namaMahasiswa, P->nilai);
            InsertSorted(L2, newNode);
        }
        P = P->next;
    }
}

// Menghapus elemen duplikat berdasarkan nama
void RemoveDuplicates(List *L) {
    if (isEmpty(*L)) return;
    
    address P = L->First;
    while (P != NULL && P->next != NULL) {
        if (strcmp(P->namaMahasiswa, P->next->namaMahasiswa) == 0) {
            address temp = P->next;
            P->next = P->next->next;
            free(temp);
        } else {
            P = P->next;
        }
    }
}

// Memasukkan data mahasiswa
void InputMahasiswa(char *nama, int *nilai) {
    printf("Masukkan Nama: ");
    scanf("%s", nama);
    printf("Masukkan Nilai: ");
    scanf("%d", nilai);
}

// Mengedit data mahasiswa
void EditMahasiswa(address P, char *namaBaru, int nilaiBaru) {
    if (P != NULL) {
        strcpy(P->namaMahasiswa, namaBaru);
        P->nilai = nilaiBaru;
    }
}

// Menampilkan daftar mahasiswa berdasarkan nilai secara ascending
void PrintNilaiAscending(List L) {
    if (L.First == NULL) {
        printf("List kosong!\n");
        return;
    }
    
    // Salin elemen ke array
    int count = NbElmt(L);
    address arr[count];
    address P = L.First;
    for (int i = 0; i < count; i++) {
        arr[i] = P;
        P = P->next;
    }
    
    // Bubble sort ascending berdasarkan nilai
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j]->nilai > arr[j + 1]->nilai) {
                address temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // Cetak hasil
    printf("\nDaftar Mahasiswa Berdasarkan Nilai (Ascending):\n");
    for (int i = 0; i < count; i++) {
        printf("Nama: %s, Nilai: %d\n", arr[i]->namaMahasiswa, arr[i]->nilai);
    }
}

// Menampilkan daftar mahasiswa berdasarkan nilai secara descending
void PrintNilaiDescending(List L) {
    if (L.First == NULL) {
        printf("List kosong!\n");
        return;
    }
    
    // Salin elemen ke array
    int count = NbElmt(L);
    address arr[count];
    address P = L.First;
    for (int i = 0; i < count; i++) {
        arr[i] = P;
        P = P->next;
    }
    
    // Bubble sort descending berdasarkan nilai
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j]->nilai < arr[j + 1]->nilai) {
                address temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // Cetak hasil
    printf("\nDaftar Mahasiswa Berdasarkan Nilai (Descending):\n");
    for (int i = 0; i < count; i++) {
        printf("Nama: %s, Nilai: %d\n", arr[i]->namaMahasiswa, arr[i]->nilai);
    }
}
