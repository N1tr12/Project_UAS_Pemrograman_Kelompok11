#ifndef FUNGSIBARANG_H
#define FUNGSIBARANG_H

#include <stdio.h>
#include <stdlib.h>

#define NAMA_FILE "stokbarang.txt"

struct Barang {
    int nomor;
    char nama[50];
    float harga;
    int stok;
};

void tambahBarang(struct Barang *daftarBarang, int numBarang);
void lihatDaftarBarang();

#endif
