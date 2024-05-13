#include <stdio.h>
#include <stdlib.h>

#define NAMA_FILE "stokbarang.txt"

struct Barang {
    int nomor;
    char nama[50];
    float harga;
    int stok;
};

void tambahBarang(struct Barang *daftarBarang, int numBarang) {
    FILE *file = fopen(NAMA_FILE, "a"); 
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    for (int i = 0; i < numBarang; i++) {
        fprintf(file, "%d %s %.2f %d\n", daftarBarang[i].nomor, daftarBarang[i].nama, daftarBarang[i].harga, daftarBarang[i].stok);
    }

    fclose(file);
}
