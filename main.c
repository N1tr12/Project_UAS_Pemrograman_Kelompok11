#include <stdio.h>
#include <stdlib.h>
#include "intro.h"
#include "fungsibarang.h"

int main() {
    int numBarang, pilih, loop = 1; // Initialize loop

    welcomeScreen();

    while (loop) { // Use while loop for better control
        printf("Pilih : \n");
        printf("1. Tambah Barang\n");
        printf("2. Melihat Barang\n");
        printf("3. Keluar\n"); // Added an option to exit
        printf("Pilihan Anda : ");
        scanf("%d", &pilih);

        switch (pilih) {
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
                printf("Data barang berhasil disimpan ke dalam file.\n");

                free(daftarBarang);
                break;

            case 2:
                lihatDaftarBarang();
                break;

            case 3:
                loop = 0; // Exit the loop
                break;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    }

    return 0;
}
