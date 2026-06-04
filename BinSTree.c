/*
File        : BinSTree.c
Deskripsi   : Implementasi ADT Binary Tree Dinamis
Author      : Ade Chandra Nugraha (dimodifikasi)
Suffix      : BT (Binary Tree)
*/

#include "BinSTree.h"

/****************************************************/
/*              SELEKTOR                             */
/****************************************************/

infotypeBT GetAkarBT(BinTreeBT P) {
    return P->info;
}

BinTreeBT GetLeftBT(BinTreeBT P) {
    return P->left;
}

BinTreeBT GetRightBT(BinTreeBT P) {
    return P->right;
}

/****************************************************/
/*              KONSTRUKTOR                          */
/****************************************************/

addressBT AlokasiBT(infotypeBT X) {
    addressBT P = (addressBT) malloc(sizeof(NodeBT));
    if (P != NilBT) {
        P->info = X;
        P->left = NilBT;
        P->right = NilBT;
    }
    return P;
}

BinTreeBT TreeBT(infotypeBT Akar, BinTreeBT L, BinTreeBT R) {
    addressBT P = AlokasiBT(Akar);
    if (P != NilBT) {
        P->left = L;
        P->right = R;
    }
    return P;
}

void MakeTreeBT(infotypeBT Akar, BinTreeBT L, BinTreeBT R, BinTreeBT *P) {
    *P = TreeBT(Akar, L, R);
}

/****************************************************/
/*              PREDIKAT                             */
/****************************************************/

boolean IsEmptyBT(BinTreeBT P) {
    return (P == NilBT);
}

boolean IsUnerLeftBT(BinTreeBT P) {
    return (!IsEmptyBT(P) && P->left != NilBT && P->right == NilBT);
}

boolean IsUnerRightBT(BinTreeBT P) {
    return (!IsEmptyBT(P) && P->left == NilBT && P->right != NilBT);
}

boolean IsBinerBT(BinTreeBT P) {
    return (!IsEmptyBT(P) && P->left != NilBT && P->right != NilBT);
}

/****************************************************/
/*              TRAVERSAL                            */
/****************************************************/

void PreOrderBT(BinTreeBT P) {
    if (!IsEmptyBT(P)) {
        printf("%d ", GetAkarBT(P));
        PreOrderBT(GetLeftBT(P));
        PreOrderBT(GetRightBT(P));
    }
}

void InOrderBT(BinTreeBT P) {
    if (!IsEmptyBT(P)) {
        InOrderBT(GetLeftBT(P));
        printf("%d ", GetAkarBT(P));
        InOrderBT(GetRightBT(P));
    }
}

void PostOrderBT(BinTreeBT P) {
    if (!IsEmptyBT(P)) {
        PostOrderBT(GetLeftBT(P));
        PostOrderBT(GetRightBT(P));
        printf("%d ", GetAkarBT(P));
    }
}

void PrintTreeBT(BinTreeBT P, int h) {
    if (!IsEmptyBT(P)) {
        PrintTreeBT(GetRightBT(P), h + 1);
        for (int i = 0; i < h; i++) printf("    ");
        printf("%d\n", GetAkarBT(P));
        PrintTreeBT(GetLeftBT(P), h + 1);
    }
}

/****************************************************/
/*              SEARCH                               */
/****************************************************/

boolean SearchBT(BinTreeBT P, infotypeBT X) {
    if (IsEmptyBT(P)) return false;
    if (GetAkarBT(P) == X) return true;
    if (SearchBT(GetLeftBT(P), X)) return true;
    return SearchBT(GetRightBT(P), X);
}

/****************************************************/
/*              FUNGSI LAIN                          */
/****************************************************/

int nbElmtBT(BinTreeBT P) {
    if (IsEmptyBT(P)) return 0;
    return 1 + nbElmtBT(GetLeftBT(P)) + nbElmtBT(GetRightBT(P));
}

int nbDaunBT(BinTreeBT P) {
    if (IsEmptyBT(P)) return 0;
    if (GetLeftBT(P) == NilBT && GetRightBT(P) == NilBT) return 1;
    return nbDaunBT(GetLeftBT(P)) + nbDaunBT(GetRightBT(P));
}

boolean IsSkewLeftBT(BinTreeBT P) {
    if (IsEmptyBT(P) || (GetLeftBT(P) == NilBT && GetRightBT(P) == NilBT))
        return false;
    if (GetRightBT(P) != NilBT) return false;
    if (GetLeftBT(P) == NilBT && GetRightBT(P) == NilBT) return true;
    return IsSkewLeftBT(GetLeftBT(P));
}

boolean IsSkewRightBT(BinTreeBT P) {
    if (IsEmptyBT(P) || (GetLeftBT(P) == NilBT && GetRightBT(P) == NilBT))
        return false;
    if (GetLeftBT(P) != NilBT) return false;
    if (GetLeftBT(P) == NilBT && GetRightBT(P) == NilBT) return true;
    return IsSkewRightBT(GetRightBT(P));
}

int LevelBT(BinTreeBT P, infotypeBT X) {
    if (IsEmptyBT(P)) return 0;
    if (GetAkarBT(P) == X) return 1;
    int leftLevel = LevelBT(GetLeftBT(P), X);
    if (leftLevel > 0) return leftLevel + 1;
    int rightLevel = LevelBT(GetRightBT(P), X);
    if (rightLevel > 0) return rightLevel + 1;
    return 0;
}

int DepthBT(BinTreeBT P) {
    if (IsEmptyBT(P)) return 0;
    return 1 + MaxBT(DepthBT(GetLeftBT(P)), DepthBT(GetRightBT(P)));
}

int MaxBT(infotypeBT Data1, infotypeBT Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}

/****************************************************/
/*              OPERASI MODIFIKASI                  */
/****************************************************/

void AddDaunTerkiriBT(BinTreeBT *P, infotypeBT X) {
    if (IsEmptyBT(*P)) {
        *P = AlokasiBT(X);
    } else {
        AddDaunTerkiriBT(&((*P)->left), X);
    }
}

void AddDaunBT(BinTreeBT *P, infotypeBT X, infotypeBT Y, boolean Kiri) {
    if (!IsEmptyBT(*P)) {
        if (GetAkarBT(*P) == X) {
            if (Kiri) {
                (*P)->left = AlokasiBT(Y);
            } else {
                (*P)->right = AlokasiBT(Y);
            }
        } else {
            AddDaunBT(&((*P)->left), X, Y, Kiri);
            AddDaunBT(&((*P)->right), X, Y, Kiri);
        }
    }
}

void DelDaunTerkiriBT(BinTreeBT *T, infotypeBT *X) {
    if ((*T)->left == NilBT && (*T)->right == NilBT) {
        *X = (*T)->info;
        free(*T);
        *T = NilBT;
    } else if ((*T)->left != NilBT) {
        DelDaunTerkiriBT(&((*T)->left), X);
    } else {
        DelDaunTerkiriBT(&((*T)->right), X);
    }
}

/****************************************************/
/*              MANIPULASI LIST OF NODE             */
/****************************************************/

/* Membuat list kosong untuk ListOfNode */
ListOfNodeBT MakeListEmptyBT() {
    return NilBT;
}

/* Alokasi elemen list untuk ListOfNode */
addressListBT AlokasiListNodeBT(infotypeBT X) {
    addressListBT P = (addressListBT) malloc(sizeof(ElmtListBT));
    if (P != NilBT) {
        P->info = X;
        P->next = NilBT;
    }
    return P;
}

/* Insert elemen di akhir list */
void InsertLastListNodeBT(ListOfNodeBT *L, infotypeBT X) {
    addressListBT P = AlokasiListNodeBT(X);
    if (P != NilBT) {
        if (*L == NilBT) {
            *L = P;
        } else {
            addressListBT last = *L;
            while (last->next != NilBT) last = last->next;
            last->next = P;
        }
    }
}

ListOfNodeBT MakeListDaunBT(BinTreeBT P) {
    ListOfNodeBT L = MakeListEmptyBT();
    if (!IsEmptyBT(P)) {
        if (GetLeftBT(P) == NilBT && GetRightBT(P) == NilBT) {
            InsertLastListNodeBT(&L, GetAkarBT(P));
        } else {
            ListOfNodeBT LLeft = MakeListDaunBT(GetLeftBT(P));
            ListOfNodeBT LRight = MakeListDaunBT(GetRightBT(P));
            L = LLeft;
            if (LRight != NilBT) {
                if (L == NilBT) {
                    L = LRight;
                } else {
                    addressListBT last = L;
                    while (last->next != NilBT) last = last->next;
                    last->next = LRight;
                }
            }
        }
    }
    return L;
}

ListOfNodeBT MakeListPreOrderBT(BinTreeBT P) {
    ListOfNodeBT L = MakeListEmptyBT();
    if (!IsEmptyBT(P)) {
        InsertLastListNodeBT(&L, GetAkarBT(P));
        ListOfNodeBT LLeft = MakeListPreOrderBT(GetLeftBT(P));
        ListOfNodeBT LRight = MakeListPreOrderBT(GetRightBT(P));
        if (LLeft != NilBT) {
            if (L == NilBT) {
                L = LLeft;
            } else {
                addressListBT last = L;
                while (last->next != NilBT) last = last->next;
                last->next = LLeft;
            }
        }
        if (LRight != NilBT) {
            addressListBT last = L;
            while (last->next != NilBT) last = last->next;
            last->next = LRight;
        }
    }
    return L;
}

/****************************************************/
/*         FUNGSI TAMBAHAN UNTUK MENU               */
/****************************************************/

addressBT SearchNodeBT(BinTreeBT P, infotypeBT X) {
/* Mencari node dengan nilai X secara rekursif */
    if (IsEmptyBT(P)) return NilBT;
    if (GetAkarBT(P) == X) return P;
    addressBT found = SearchNodeBT(GetLeftBT(P), X);
    if (found != NilBT) return found;
    return SearchNodeBT(GetRightBT(P), X);
}

void LevelOrderBT(BinTreeBT P) {
/* Traversal Level-Order menggunakan antrian (queue) array */
    if (IsEmptyBT(P)) return;

    BinTreeBT queue[200];
    int front = 0, rear = 0;
    queue[rear++] = P;

    while (front < rear) {
        BinTreeBT current = queue[front++];
        printf("%d ", GetAkarBT(current));

        if (GetLeftBT(current) != NilBT)  queue[rear++] = GetLeftBT(current);
        if (GetRightBT(current) != NilBT) queue[rear++] = GetRightBT(current);
    }
}

void InsertNodeBT(BinTreeBT *P, infotypeBT X) {
/* Insert node baru secara Level-Order (Complete Binary Tree insertion) */
    addressBT newNode = AlokasiBT(X);
    if (newNode == NilBT) {
        printf(">> Gagal alokasi memori!\n");
        return;
    }

    /* Case: Tree masih kosong -> jadikan akar */
    if (IsEmptyBT(*P)) {
        *P = newNode;
        printf(">> Node %d berhasil dijadikan AKAR.\n", X);
        return;
    }

    /* Traversal Level-Order untuk mencari posisi kosong pertama */
    BinTreeBT queue[200];
    int front = 0, rear = 0;
    queue[rear++] = *P;

    while (front < rear) {
        BinTreeBT current = queue[front++];

        /* Cek anak kiri */
        if (GetLeftBT(current) == NilBT) {
            current->left = newNode;
            printf(">> Node %d diinsert sebagai LEFT SON dari %d (Level-Order).\n", X, GetAkarBT(current));
            return;
        } else {
            queue[rear++] = GetLeftBT(current);
        }

        /* Cek anak kanan */
        if (GetRightBT(current) == NilBT) {
            current->right = newNode;
            printf(">> Node %d diinsert sebagai RIGHT SON dari %d (Level-Order).\n", X, GetAkarBT(current));
            return;
        } else {
            queue[rear++] = GetRightBT(current);
        }
    }
}

void DeleteNodeBT(BinTreeBT *P, infotypeBT X) {
/* Hapus node bernilai X dengan mempertahankan struktur Complete Binary Tree.
   Algoritma:
   1. Cari node yang berisi nilai X (targetNode).
   2. Cari node TERAKHIR dalam level-order (deepest rightmost node) beserta parentnya.
   3. Salin nilai node terakhir ke targetNode.
   4. Hapus (dealokasi) node terakhir.
   Dengan cara ini struktur Complete Binary Tree tetap terjaga. */

    if (IsEmptyBT(*P)) {
        printf(">> Tree kosong, tidak bisa hapus!\n");
        return;
    }

    /* Jika tree hanya punya 1 node (akar saja) */
    if (GetLeftBT(*P) == NilBT && GetRightBT(*P) == NilBT) {
        if (GetAkarBT(*P) == X) {
            printf(">> Node %d (akar satu-satunya) berhasil dihapus.\n", X);
            DeAlokasiBT(*P);
            *P = NilBT;
        } else {
            printf(">> Node %d TIDAK ditemukan!\n", X);
        }
        return;
    }

    /* Level-Order: cari targetNode dan node terakhir + parentnya */
    BinTreeBT queue[200];
    int front = 0, rear = 0;
    queue[rear++] = *P;

    addressBT targetNode = NilBT;
    addressBT lastNode = NilBT;
    addressBT lastParent = NilBT;

    while (front < rear) {
        BinTreeBT current = queue[front++];

        if (GetAkarBT(current) == X) {
            targetNode = current;
        }

        if (GetLeftBT(current) != NilBT) {
            lastParent = current;
            lastNode = GetLeftBT(current);
            queue[rear++] = GetLeftBT(current);
        }
        if (GetRightBT(current) != NilBT) {
            lastParent = current;
            lastNode = GetRightBT(current);
            queue[rear++] = GetRightBT(current);
        }
    }

    if (targetNode == NilBT) {
        printf(">> Node %d TIDAK ditemukan!\n", X);
        return;
    }

    /* Salin nilai node terakhir ke target, lalu hapus node terakhir */
    infotypeBT lastVal = GetAkarBT(lastNode);
    targetNode->info = lastVal;

    /* Putuskan hubungan parent -> lastNode */
    if (GetRightBT(lastParent) == lastNode) {
        lastParent->right = NilBT;
    } else {
        lastParent->left = NilBT;
    }
    DeAlokasiBT(lastNode);  

    printf(">> Node %d berhasil dihapus (ditukar dengan node terakhir %d).\n", X, lastVal);
}

boolean IsPerfectBT(BinTreeBT P) {
/* Perfect Binary Tree: semua internal node punya 2 anak, semua daun di level sama.
   Cara cek: depth tree = d, jumlah node harus = 2^d - 1 */
    if (IsEmptyBT(P)) return true; /* Tree kosong dianggap perfect */

    int d = DepthBT(P);
    int n = nbElmtBT(P);

    /* Hitung 2^d - 1 */
    int perfect_count = 1;
    int i;
    for (i = 0; i < d; i++) {
        perfect_count *= 2;
    }
    perfect_count -= 1; /* 2^d - 1 */

    return (n == perfect_count);
}

/****************************************************/
/*              DESTRUKTOR                          */
/****************************************************/

void DestroyTreeBT(BinTreeBT *P) {
    if (!IsEmptyBT(*P)) {
        DestroyTreeBT(&((*P)->left));
        DestroyTreeBT(&((*P)->right));
        free(*P);
        *P = NilBT;
    }
}

void DeAlokasiBT(addressBT P) {
    if (P != NilBT) {
        free(P);
    }
}
