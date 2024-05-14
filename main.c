#include <stdio.h>
#include "intro.h"
#include "fungsibarang.h"

int main () {
    int numBarang, pilih, loop;

    welcomeScreen();

    for (int i = 0; i < loop; i++){
    
        printf("Pilih : \n");
        printf("1. Tambah Barang\n");
        printf("2. Melihat Barang\n");
        printf("Pilihan Anda : ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
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
            ("Data barang berhasil disimpan ke dalam file.\n");

            free(daftarBarang);
            break;
    
        case 2:
            lihatDaftarBarang();
        }
    }
    
    struct Barang daftarBarang[3] = {{11, "Pensil", 3000, 100},
                                      {32, "Pulpen", 7000, 99},
                                      {35, "Penggaris", 5000, 20}};
    numBarang = sizeof(daftarBarang) / sizeof(struct Barang);
    return 0;
}
