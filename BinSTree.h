/* 
File        : BinSTree.h
Deskripsi   : Header ADT Binary Tree Dinamis
              Implementasi pohon biner dengan alokasi memori dinamis
Author      : Ade Chandra Nugraha (dimodifikasi)
Suffix      : BT (Binary Tree)
*/

#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define NilBT NULL

/****************************************************/
/*              DEFINISI TIPE DATA                   */
/****************************************************/

typedef int infotypeBT;
typedef struct tElmtTreeBT *addressBT;

typedef struct tElmtTreeBT {
    infotypeBT info;
    addressBT left;
    addressBT right;
} NodeBT;

typedef addressBT BinTreeBT;

/* Tipe untuk List of Node (digunakan beberapa fungsi) */
typedef struct tElmtListBT *addressListBT;

typedef struct tElmtListBT {
    infotypeBT info;
    addressListBT next;
} ElmtListBT;

typedef addressListBT ListOfNodeBT;

/****************************************************/
/*              SELEKTOR                             */
/****************************************************/

infotypeBT GetAkarBT(BinTreeBT P);
/* Mengirimkan informasi yang tersimpan di akar pohon biner yang tidak kosong */

BinTreeBT GetLeftBT(BinTreeBT P);
/* Mengirimkan anak kiri pohon biner P yang tidak kosong */

BinTreeBT GetRightBT(BinTreeBT P);
/* Mengirimkan anak kanan pohon biner P yang tidak kosong */

/****************************************************/
/*              KONSTRUKTOR                          */
/****************************************************/

addressBT AlokasiBT(infotypeBT X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika Alokasi berhasil, maka address != NilBT dan info = X */

BinTreeBT TreeBT(infotypeBT Akar, BinTreeBT L, BinTreeBT R);
/* Menghasilkan sebuah pohon biner dari Akar, L, dan R */
/* Menghasilkan NilBT jika alokasi gagal */

void MakeTreeBT(infotypeBT Akar, BinTreeBT L, BinTreeBT R, BinTreeBT *P);
/* I.S. BinTree sembarang */
/* F.S. Menghasilkan BinTree dari Akar, L, dan R */

/****************************************************/
/*              PREDIKAT                             */
/****************************************************/

boolean IsEmptyBT(BinTreeBT P);
/* Mengirimkan true jika BinTree KOSONG */

boolean IsUnerLeftBT(BinTreeBT P);
/* true jika P tidak kosong dan hanya mempunyai sub pohon kiri */

boolean IsUnerRightBT(BinTreeBT P);
/* true jika P tidak kosong dan hanya mempunyai sub pohon kanan */

boolean IsBinerBT(BinTreeBT P);
/* true jika P tidak kosong dan mempunyai sub pohon kiri dan kanan */

/****************************************************/
/*              TRAVERSAL                            */
/****************************************************/

void PreOrderBT(BinTreeBT P);
/* Traversal PreOrder: Akar, Kiri, Kanan */

void InOrderBT(BinTreeBT P);
/* Traversal InOrder: Kiri, Akar, Kanan */

void PostOrderBT(BinTreeBT P);
/* Traversal PostOrder: Kiri, Kanan, Akar */

void PrintTreeBT(BinTreeBT P, int h);
/* Menampilkan pohon dengan indentasi h */

/****************************************************/
/*              SEARCH                               */
/****************************************************/

boolean SearchBT(BinTreeBT P, infotypeBT X);
/* true jika ada node dari P yang bernilai X */

/****************************************************/
/*              FUNGSI LAIN                          */
/****************************************************/

int nbElmtBT(BinTreeBT P);
/* Banyak elemen (node) pohon biner P */

int nbDaunBT(BinTreeBT P);
/* Banyak daun (node tanpa anak) pohon biner P */

boolean IsSkewLeftBT(BinTreeBT P);
/* true jika P adalah pohon condong kiri */

boolean IsSkewRightBT(BinTreeBT P);
/* true jika P adalah pohon condong kanan */

int LevelBT(BinTreeBT P, infotypeBT X);
/* Level dari node X (akar level = 1) */

int DepthBT(BinTreeBT P);
/* Tinggi/kedalaman pohon biner (0 jika kosong) */

int MaxBT(infotypeBT Data1, infotypeBT Data2);
/* Nilai terbesar dari dua data */

/****************************************************/
/*              OPERASI MODIFIKASI                  */
/****************************************************/

void AddDaunTerkiriBT(BinTreeBT *P, infotypeBT X);
/* Menambah node sebagai daun terkiri */
/* I.S. P boleh kosong */
/* F.S. P bertambah dengan X sebagai daun terkiri */

void AddDaunBT(BinTreeBT *P, infotypeBT X, infotypeBT Y, boolean Kiri);
/* I.S. P tidak kosong, X adalah salah satu daun */
/* F.S. P bertambah dengan Y sebagai anak kiri X (jika Kiri) */
/*      atau sebagai anak kanan X (jika not Kiri) */

void DelDaunTerkiriBT(BinTreeBT *T, infotypeBT *X);
/* I.S. P tidak kosong */
/* F.S. Daun terkiri dihapus, didealokasi, info disimpan di X */

/****************************************************/
/*              MANIPULASI LIST OF NODE             */
/****************************************************/

ListOfNodeBT MakeListDaunBT(BinTreeBT P);
/* Menghasilkan List yang elemennya adalah semua daun pohon P */

ListOfNodeBT MakeListPreOrderBT(BinTreeBT P);
/* Menghasilkan List dengan elemen urutan PreOrder */

/****************************************************/
/*         FUNGSI TAMBAHAN UNTUK MENU               */
/****************************************************/

void InsertNodeBT(BinTreeBT *P, infotypeBT X);
/* Insert node baru secara Level-Order agar tree tetap Complete/Perfect */
/* I.S. P sembarang (boleh kosong) */
/* F.S. Node baru X ditambahkan di posisi level-order pertama yang kosong */

void DeleteNodeBT(BinTreeBT *P, infotypeBT X);
/* Hapus node bernilai X dengan mempertahankan struktur Complete Binary Tree */
/* Caranya: tukar nilai X dengan node terakhir (level-order), lalu hapus node terakhir */
/* I.S. P tidak kosong, X ada di dalam tree */
/* F.S. Node bernilai X terhapus, struktur tree tetap Complete */

void LevelOrderBT(BinTreeBT P);
/* Traversal Level-Order (Breadth-First) menggunakan antrian array */
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah diproses secara Level-Order */

addressBT SearchNodeBT(BinTreeBT P, infotypeBT X);
/* Mencari node dengan nilai X pada Binary Tree */
/* Mengirimkan address node jika ditemukan, NilBT jika tidak */

boolean IsPerfectBT(BinTreeBT P);
/* Mengirimkan true jika P adalah Perfect Binary Tree */
/* Perfect: semua internal node punya 2 anak, semua daun di level sama */

/****************************************************/
/*              DESTRUKTOR                          */
/****************************************************/

void DestroyTreeBT(BinTreeBT *P);
/* Menghapus seluruh elemen Tree secara PostOrder */

void DeAlokasiBT(addressBT P);
/* Mengembalikan address P ke sistem */

#endif
