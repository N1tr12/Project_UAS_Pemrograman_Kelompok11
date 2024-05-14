#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMA_FILE "stokbarang.txt"

void hapusbarang()
{
    printf("\nHapusbarang\n");
    int id_barang;
    printf("Masukkan ID barang yang ingin dihapus: ");
    scanf("%d", &id_barang);
    clearBuffer();

    int index_buku = -1;
    for (int i = 0; i < jumlah_barang; ++i)
    {
        if (barang[i].id == id_barang)
        {
            index_barang = i;
            break;
        }
    }

    if (index_barang == -1)
    {
        printf("Maaf, barang dengan ID tersebut tidak ditemukan.\n");
        return;
    }

    // Geser array untuk menghapus barang
    for (int i = index_barang; i < jumlah_barang - 1; ++i)
    {
        barang[i] = barang[i + 1];
    }
    jumlah_barang--;

    printf("Barang berhasil dihapus.\n");

    // Simpan perubahan ke file
    simpanDataBarang();