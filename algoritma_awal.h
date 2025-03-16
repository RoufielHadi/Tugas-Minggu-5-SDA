/* algoritma_awal.h */
#ifndef ALGORITMA_AWAL_H
#define ALGORITMA_AWAL_H

#include "linked.h"

// 1. Membuat ADT Linked List Mahasiswa
void CreateList(List *L);
void DeleteList(List *L);
boolean isValid(List L);
void SetData(address P, char *nama, int nilai);
void PrintList(List L);

// 2. Inisialisasi List L1 dan L2
void InitializeLists(List *L1, List *L2);

// 3. Menambahkan elemen dalam urutan ascending berdasarkan nama
void InsertSorted(List *L, address P);

// 4. Menampilkan isi List L1 dalam urutan ascending
void PrintListAscending(List L);

// 5. Menampilkan isi List L1 dalam urutan descending berdasarkan nilai
void PrintNilaiDescending(List L);

// 6. Menghitung jumlah mahasiswa dalam List L1
int CountElements(List L);

// 7. Menyalin elemen dengan nilai > 70 ke List L2
void CopyGreaterThan(List *L1, List *L2, int threshold);

// 8. Menampilkan isi List L2
void PrintListL2(List L2);

// 9. Menghapus data duplikat berdasarkan nama dalam List L2
void RemoveDuplicates(List *L);

// 10. Menampilkan List L2 setelah penghapusan duplikat
void PrintListL2Updated(List L2);

// 11. Menghapus List L1 dan L2
void DeleteAllLists(List *L1, List *L2);

void PrintAlgoritmaAwal();

#endif
