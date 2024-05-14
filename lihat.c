#include <stdio.h>
#include <stdlib.h>

#define NAMA_FILE "stokbarang.txt"

struct Barang {
    int nomor;
    char nama[50];
    float harga;
    int stok;
};

void lihatDaftarBarang() {
    FILE *file = fopen(NAMA_FILE, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    struct Barang barang;
    printf("Daftar Barang:\n");
    while (fscanf(file, "%d %s %f %d", &barang.nomor, barang.nama, &barang.harga, &barang.stok) != EOF) {
        printf("%d %s %.2f %d\n", barang.nomor, barang.nama, barang.harga, barang.stok);
    }

    fclose(file);
}

int main() {
    struct Barang daftarBarang[3] = {{11, "Pensil", 3000, 100},
                                      {32, "Pulpen", 7000, 99},
                                      {35, "Penggaris", 5000, 20}};
    int numBarang = sizeof(daftarBarang) / sizeof(struct Barang);

    lihatDaftarBarang();

    return 0;
}
