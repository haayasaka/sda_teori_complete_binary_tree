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
