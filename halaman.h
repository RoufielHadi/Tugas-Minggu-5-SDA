/*
Author: Roufiel Hadi  
NIM: 241524028  
Kelas: 1A  
Prodi: Sarjana Terapan Teknik Informatika  
Jurusan: Teknik Komputer dan Informatika  
Politeknik Negeri Bandung  
*/

#ifndef HALAMAN_H
#define HALAMAN_H

#include <stdlib.h>
#include <string.h>
#include "linked.h"

#define FILE_NAME "dataMahasiswa.txt"

// =====================================================
// ===================== UTILITAS ======================
// =====================================================
void clearScreen();
// Tujuan : Membersihkan layar

void welcomeScreen();
// Tujuan : Menampilkan layar selamat datang

// =====================================================
// ============= OPERASI FILE DAN DATA ================
// =====================================================
void loadFromFile(List *L);
// Tujuan : Memuat data dari file ke dalam linked list
// IS     : List mungkin kosong atau sudah berisi elemen
// FS     : List berisi data dari file jika tersedia

void saveToFile(List L);
// Tujuan : Menyimpan data dari linked list ke file
// IS     : List mungkin kosong atau berisi elemen
// FS     : Data dalam list disimpan ke dalam file

// =====================================================
// =============== NAVIGASI DAN MENU ==================
// =====================================================
void dashboard(List *L);
// Tujuan : Menampilkan dashboard utama

void tambahDataMahasiswa(List *L);
// Tujuan : Menu untuk menambah data mahasiswa

void editDataMahasiswa(List *L);
// Tujuan : Menu untuk mengedit data mahasiswa

void hapusDataMahasiswa(List *L);
// Tujuan : Menu untuk menghapus data mahasiswa

void lihatDataMahasiswa(List L);
// Tujuan : Menu untuk melihat data mahasiswa dengan berbagai sorting

#endif

