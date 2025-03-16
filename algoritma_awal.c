#include <stdlib.h>
#include <string.h>
#include "algoritma_awal.h"
#include "linked.h"

void InitializeLists(List *L1, List *L2) {
    CreateList(L1);
    CreateList(L2);
}

void CopyGreaterThan(List *L1, List *L2, int threshold) {
    address P = L1->First;
    while (P != NULL) {
        if (P->nilai > threshold) {
            address newNode = CreateNode(P->namaMahasiswa, P->nilai);
            InsertSorted(L2, newNode);
        }
        P = P->next;
    }
}

int CountElements(List L) {
    int count = 0;
    address daus = L.First;
    while (daus != NULL) {
        count++;
        daus = daus->next;
    }
    return count;
}

void DeleteAllLists(List *L1, List *L2) {
    DeleteList(L1);
    DeleteList(L2);
}

void PrintAlgoritmaAwal() {
    List L1, L2;
    InitializeLists(&L1, &L2);
    
    printf("1. Membuat ADT Linked List Mahasiswa (Nama, Nilai UTS SDA)\n");
    printf("2. Membuat dua buah List (L1 dan L2)\n");
    
    printf("3. Mengisi List L1 dengan data mahasiswa secara ascending berdasarkan nama\n");
    InsertSorted(&L1, CreateNode("Andi", 85));
    InsertSorted(&L1, CreateNode("Budi", 90));
    InsertSorted(&L1, CreateNode("Citra", 75));
    InsertSorted(&L1, CreateNode("Dewi", 95));
    InsertSorted(&L1, CreateNode("Eko", 70));
    PrintList(L1);
    
    printf("4. Menampilkan isi List L1 dalam urutan ascending berdasarkan nama\n");
    PrintList(L1);
    
    printf("5. Menampilkan isi List L1 dalam urutan descending berdasarkan nilai\n");
    PrintNilaiDescending(L1);
    
    printf("6. Menghitung jumlah mahasiswa dalam List L1\n");
    printf("Jumlah mahasiswa: %d\n", CountElements(L1));
    
    printf("7. Menyalin elemen List L1 dengan nilai > 70 ke List L2\n");
    CopyGreaterThan(&L1, &L2, 70);
    PrintList(L2);
    
    printf("8. Menampilkan isi List L2\n");
    PrintList(L2);
    
    printf("9. Menghapus data duplikat berdasarkan nama dalam List L2\n");
    RemoveDuplicates(&L2);
    PrintList(L2);
    
    printf("10. Menghapus List L1 dan L2\n");
    DeleteAllLists(&L1, &L2);
    
    printf("\nTekan Enter untuk kembali ke menu...\n");
    getchar();
}

