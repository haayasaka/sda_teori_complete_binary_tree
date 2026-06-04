/*
    Main Program - Perfect Binary Tree
    File        : main.c
    Deskripsi   : Program utama dengan menu interaktif untuk operasi Binary Tree
                  menggunakan ADT BinSTree (suffix BT).
                  Insert dan Delete otomatis menjaga struktur Complete/Perfect Binary Tree.
*/

#include "BinSTree.h"

int main() {
    BinTreeBT root = NilBT;
    int pilihan;
    infotypeBT nilai;

    do {
        printf("\n========================================\n");
        printf("        MENU BINARY TREE\n");
        printf("========================================\n");
        printf("1.  Insert Node\n");
        printf("2.  Print Tree\n");
        printf("3.  Transversal PreOrder\n");
        printf("4.  Transversal InOrder\n");
        printf("5.  Transversal PostOrder\n");
        printf("6.  Transversal LevelOrder\n");
        printf("7.  Search Node Tree\n");
        printf("8.  Jumlah Daun/Leaf\n");
        printf("9.  Mencari Kedalaman Node Tree\n");
        printf("10. Membandingkan 2 Node Tree\n");
        printf("11. Exit\n");
        printf("========================================\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        printf("\n");

        switch (pilihan) {

            /* ============================== */
            /* 1. Insert Node (Level-Order)   */
            /* ============================== */
            case 1: {
                printf("Masukkan info node baru: ");
                while (scanf("%d", &nilai) != 1) {
                    printf("Input salah! Coba lagi: ");
                    while (getchar() != '\n');
                }
                InsertNodeBT(&root, nilai);

                /* Tampilkan status Perfect Binary Tree setelah insert */
                if (IsPerfectBT(root)) {
                    printf(">> Status: Tree saat ini adalah PERFECT Binary Tree.\n");
                } else {
                    printf(">> Status: Tree saat ini BELUM perfect (masih Complete Binary Tree).\n");
                }
                break;
            }

            /* ============================== */
            /* 2. Print Tree (Visualisasi)    */
            /* ============================== */
            case 2: {
                if (IsEmptyBT(root)) {
                    printf(">> Tree kosong!\n");
                } else {
                    printf("Visualisasi Tree (dirotasi 90 derajat):\n\n");
                    PrintTreeBT(root, 0);
                    printf("\n>> Jumlah node  : %d\n", nbElmtBT(root));
                    printf(">> Kedalaman    : %d\n", DepthBT(root));
                    if (IsPerfectBT(root)) {
                        printf(">> Status       : PERFECT Binary Tree\n");
                    } else {
                        printf(">> Status       : Complete Binary Tree (belum Perfect)\n");
                    }
                }
                break;
            }

            /* ============================== */
            /* 3. Traversal PreOrder          */
            /* ============================== */
            case 3: {
                if (IsEmptyBT(root)) {
                    printf(">> Tree kosong!\n");
                } else {
                    printf("PreOrder  : ");
                    PreOrderBT(root);
                    printf("\n");
                }
                break;
            }

            /* ============================== */
            /* 4. Traversal InOrder           */
            /* ============================== */
            case 4: {
                if (IsEmptyBT(root)) {
                    printf(">> Tree kosong!\n");
                } else {
                    printf("InOrder   : ");
                    InOrderBT(root);
                    printf("\n");
                }
                break;
            }

            /* ============================== */
            /* 5. Traversal PostOrder         */
            /* ============================== */
            case 5: {
                if (IsEmptyBT(root)) {
                    printf(">> Tree kosong!\n");
                } else {
                    printf("PostOrder : ");
                    PostOrderBT(root);
                    printf("\n");
                }
                break;
            }

            /* ============================== */
            /* 6. Traversal LevelOrder        */
            /* ============================== */
            case 6: {
                if (IsEmptyBT(root)) {
                    printf(">> Tree kosong!\n");
                } else {
                    printf("LevelOrder: ");
                    LevelOrderBT(root);
                    printf("\n");
                }
                break;
            }

            /* ============================== */
            /* 7. Search Node                 */
            /* ============================== */
            case 7: {
                if (IsEmptyBT(root)) {
                    printf(">> Tree kosong!\n");
                } else {
                    printf("Masukkan nilai yang dicari: ");
                    scanf("%d", &nilai);
                    if (SearchBT(root, nilai)) {
                        printf(">> Node %d DITEMUKAN di level %d.\n", nilai, LevelBT(root, nilai));
                    } else {
                        printf(">> Node %d TIDAK ditemukan.\n", nilai);
                    }
                }
                break;
            }

            /* ============================== */
            /* 8. Jumlah Daun / Leaf          */
            /* ============================== */
            case 8: {
                printf(">> Jumlah daun/leaf = %d\n", nbDaunBT(root));
                break;
            }

            /* ============================== */
            /* 9. Kedalaman (Depth) Tree      */
            /* ============================== */
            case 9: {
                if (IsEmptyBT(root)) {
                    printf(">> Tree kosong!\n");
                } else {
                    printf(">> Kedalaman (depth) tree = %d\n", DepthBT(root));
                }
                break;
            }

            /* ============================== */
            /* 10. Bandingkan Level 2 Node    */
            /* ============================== */
            case 10: {
                if (IsEmptyBT(root)) {
                    printf(">> Tree kosong!\n");
                } else {
                    infotypeBT A, B;
                    printf("Masukkan nilai node pertama : ");
                    scanf("%d", &A);
                    printf("Masukkan nilai node kedua   : ");
                    scanf("%d", &B);

                    if (!SearchBT(root, A)) {
                        printf(">> Node %d tidak ditemukan!\n", A);
                        break;
                    }
                    if (!SearchBT(root, B)) {
                        printf(">> Node %d tidak ditemukan!\n", B);
                        break;
                    }

                    int levelA = LevelBT(root, A);
                    int levelB = LevelBT(root, B);

                    printf("\n>> Node %d berada di level %d\n", A, levelA);
                    printf(">> Node %d berada di level %d\n", B, levelB);

                    if (levelA == levelB) {
                        printf(">> Kesimpulan: Kedua node berada di LEVEL YANG SAMA.\n");
                    } else if (levelA < levelB) {
                        printf(">> Kesimpulan: Node %d LEBIH TINGGI (lebih dekat ke akar).\n", A);
                    } else {
                        printf(">> Kesimpulan: Node %d LEBIH TINGGI (lebih dekat ke akar).\n", B);
                    }
                }
                break;
            }

            /* ============================== */
            /* 11. Exit                       */
            /* ============================== */
            case 11: {
                /* Dealokasi seluruh tree sebelum keluar */
                DestroyTreeBT(&root);
                printf(">> Keluar program. Terima kasih!\n");
                break;
            }

            default:
                printf(">> Pilihan tidak valid!\n");
                break;
        }

    } while (pilihan != 11);

    return 0;
}
