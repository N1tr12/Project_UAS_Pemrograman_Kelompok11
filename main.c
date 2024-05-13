#include <stdio.h>
#include "intro.h"
#include "tambah.h"

int main () {
    int numBarang;

    welcomeScreen();

    printf("Masukkan jumlah barang: ");
    scanf("%d", &numBarang);

    struct Barang *daftarBarang = (struct Barang *)malloc(numBarang * sizeof(struct Barang));
    if (daftarBarang == NULL) {
        printf("Alokasi memori gagal.\n");
        return 1;
    }

    for (int i = 0; i < numBarang; i++) {
        printf("Barang ke-%d\n", i + 1);
        printf("Masukkan nomor barang: ");
        scanf("%d", &daftarBarang[i].nomor);
        printf("Masukkan nama barang: ");
        scanf("%s", daftarBarang[i].nama);
        printf("Masukkan harga barang: ");
        scanf("%f", &daftarBarang[i].harga);
        printf("Masukkan jumlah barang: ");
        scanf("%d", &daftarBarang[i].stok);
    }

    tambahBarang(daftarBarang, numBarang);
    printf("Data barang berhasil disimpan ke dalam file.\n");

    free(daftarBarang);
    
    return 0;
}