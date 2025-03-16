/*
Author: Roufiel Hadi  
NIM: 241524028  
Kelas: 1A  
Prodi: Sarjana Terapan Teknik Informatika  
Jurusan: Teknik Komputer dan Informatika  
Politeknik Negeri Bandung  
*/

#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

typedef struct tElmtList *address;
typedef struct tElmtList {
    char namaMahasiswa[50]; // Menyimpan nama mahasiswa
    int nilai;              // Menyimpan nilai mahasiswa
    address next;           // Pointer ke elemen berikutnya
} ElmtList;

typedef struct {
    address First; // Pointer ke elemen pertama dalam linked list
} List;

// =====================================================
// ===================== KONSTRUKTOR ===================
// =====================================================
void CreateList(List *L);
// Tujuan : Membuat list kosong
// IS     : L sembarang
// FS     : Terbentuk list kosong (First = NULL)

void DeleteList(List *L);
// Tujuan : Menghapus semua elemen dalam list
// IS     : L mungkin kosong atau berisi elemen
// FS     : Semua elemen dalam list dihapus dan didealokasi

// =====================================================
// ===================== VALIDATOR =====================
// =====================================================
boolean isEmpty(List L);
// Tujuan : Mengecek apakah list kosong
// Mengembalikan TRUE jika list kosong, FALSE jika tidak

// =====================================================
// ================== OPERASI DASAR ====================
// =====================================================
address CreateNode(char *nama, int nilai);
// Tujuan : Membuat node baru dengan data nama dan nilai
// IS     : nama dan nilai terdefinisi
// FS     : Mengembalikan address node baru, atau NULL jika gagal

void InsertFirst(List *L, address P);
// Tujuan : Menambahkan elemen P sebagai elemen pertama
// IS     : L mungkin kosong
// FS     : P menjadi elemen pertama dalam list

void InsertLast(List *L, address P);
// Tujuan : Menambahkan elemen P sebagai elemen terakhir
// IS     : L mungkin kosong
// FS     : P menjadi elemen terakhir dalam list

void InsertAfter(address pBef, address PNew);
// Tujuan : Menyisipkan elemen PNew setelah elemen pBef
// IS     : pBef tidak NULL
// FS     : PNew menjadi elemen setelah pBef

void DeleteFirst(List *L);
// Tujuan : Menghapus elemen pertama dari list
// IS     : List tidak kosong
// FS     : Elemen pertama dihapus dan didealokasi

void DeleteLast(List *L);
// Tujuan : Menghapus elemen terakhir dari list
// IS     : List tidak kosong
// FS     : Elemen terakhir dihapus dan didealokasi

void DeleteAfter(address pBef);
// Tujuan : Menghapus elemen setelah pBef
// IS     : pBef tidak NULL dan memiliki elemen setelahnya
// FS     : Elemen setelah pBef dihapus dan didealokasi

void DeAlokasi(address *P);
// Tujuan : Mengembalikan memori dari suatu node ke sistem
// IS     : P terdefinisi
// FS     : Memori yang ditempati oleh P dikembalikan ke sistem

// =====================================================
// ================= OPERASI TAMBAHAN =================
// =====================================================
int NbElmt(List L);
// Tujuan : Menghitung jumlah elemen dalam list
// Mengembalikan jumlah elemen dalam list (0 jika kosong)

address Search(List L, char *nama);
// Tujuan : Mencari elemen berdasarkan nama mahasiswa
// Mengembalikan address jika ditemukan, NULL jika tidak

int Min(List L);
// Tujuan : Mengembalikan nilai minimum dalam list
// IS     : List tidak kosong
// FS     : Nilai minimum dikembalikan

float Rerata(List L);
// Tujuan : Mengembalikan rata-rata nilai dalam list
// IS     : List tidak kosong
// FS     : Mengembalikan nilai rata-rata dari semua elemen

void PrintList(List L);
// Tujuan : Menampilkan semua elemen dalam list
// IS     : List mungkin kosong atau berisi elemen
// FS     : Data dalam list ditampilkan di layar

List BalikList(List L);
// Tujuan : Membalik urutan elemen dalam list
// IS     : List mungkin kosong atau berisi elemen
// FS     : Elemen dalam list dibalik

// =====================================================
// =========== FUNGSI TAMBAHAN UNTUK PROGRAM ==========
// =====================================================

void InsertSorted(List *L, address P);
// Tujuan : Menambahkan elemen P ke dalam list dalam urutan ascending berdasarkan nama
// IS     : L mungkin kosong atau sudah berisi elemen yang terurut berdasarkan nama
// FS     : P dimasukkan ke posisi yang tepat agar list tetap terurut secara ascending berdasarkan nama

void PrintDescending(List L);
// Tujuan : Menampilkan semua elemen dalam list secara descending berdasarkan nama
// IS     : List mungkin kosong atau berisi elemen
// FS     : Data dalam list ditampilkan dari nilai terbesar ke terkecil

void PrintNamaAscending(List L);
// Tujuan : Menampilkan semua elemen dalam list secara ascending berdasarkan nama
// IS     : List mungkin kosong atau berisi elemen
// FS     : Data dalam list ditampilkan dari nilai terkecil ke terbesar

void CopyNilaiDiAtas70(List L1, List *L2);
// Tujuan : Menyalin elemen dari L1 ke L2 jika nilai > 70
// IS     : L1 mungkin kosong atau berisi elemen
// FS     : L2 berisi salinan elemen dari L1 dengan nilai > 70

void RemoveDuplicates(List *L);
// Tujuan : Menghapus elemen dengan nama yang sama dalam list, hanya menyisakan satu
// IS     : List mungkin kosong atau berisi elemen dengan duplikasi nama
// FS     : Semua elemen dalam list unik berdasarkan nama

// =====================================================
// =========== FUNGSI UNTUK MEMASUKKAN & EDIT DATA =====
// =====================================================

void InputMahasiswa(char *nama, int *nilai);
// Tujuan : Memasukkan data nama dan nilai mahasiswa dari input pengguna
// IS     : nama dan nilai belum diisi
// FS     : nama dan nilai diisi oleh pengguna

void EditMahasiswa(address P, char *namaBaru, int nilaiBaru);
// Tujuan : Mengedit data nama dan nilai mahasiswa pada node tertentu
// IS     : P terdefinisi
// FS     : Data dalam node P diperbarui dengan namaBaru dan nilaiBaru

// =====================================================
// ========== FUNGSI SORTING BERDASARKAN NILAI =========
// =====================================================

void PrintNilaiAscending(List L);
// Tujuan : Menampilkan daftar mahasiswa berdasarkan nilai secara ascending
// IS     : List mungkin kosong atau berisi elemen
// FS     : Data dalam list ditampilkan dalam urutan nilai dari terkecil ke terbesar

void PrintNilaiDescending(List L);
// Tujuan : Menampilkan daftar mahasiswa berdasarkan nilai secara descending
// IS     : List mungkin kosong atau berisi elemen
// FS     : Data dalam list ditampilkan dalam urutan nilai dari terbesar ke terkecil

#endif
