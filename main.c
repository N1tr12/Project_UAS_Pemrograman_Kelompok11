#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "barang.h"
#include "welcome.h"
#include "login.h"

int main() {
    struct Barang daftarBarang[MAX_BARANG];
    int jumlahBarang = 0;
    int pilih, fungsi_barang, role;
    
    muatDariFile(daftarBarang, &jumlahBarang);

    welcome();

    printf("\nSilahkan Login jika anda telah mempunyai akun, Jika belum silahkan Register terlebih dahulu!\n");

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                register_akun();
                break;
            case 2:
                login();
                printf("\nRole :\n");
                printf("1. Admin\n");
                printf("2. User\n");
                printf("3. Keluar\n");
                printf("Pilih:");
                scanf("%d", &role);

                switch (role)
                {
                case 1:
                    do
                    {
                        printf("\nMenu:\n");
                        printf("1. Tambah Barang\n");
                        printf("2. Lihat Barang\n");
                        printf("3. Hapus Barang\n");
                        printf("4. Simpan ke File\n");
                        printf("5. Keluar\n");
                        printf("Pilih menu: ");
                        scanf("%d", &fungsi_barang);

                        switch (fungsi_barang)
                        {
                        case 1:
                            tambahBarang(daftarBarang, &jumlahBarang);
                            break;
                        case 2:
                            lihatBarang(daftarBarang, jumlahBarang);
                            break;
                        case 3:
                            if (jumlahBarang == 0) {
                                printf("Belum ada barang yang tersimpan.\n");
                            } else {
                                int index;
                                printf("Masukkan indeks barang yang ingin dihapus: ");
                                scanf("%d", &index);
                                hapusBarang(daftarBarang, &jumlahBarang, index - 1);
                            }
                            break;
                        case 4:
                            simpanKeFile(daftarBarang, jumlahBarang);
                            break;
                        case 5:
                            printf("Terima kasih!\n");
                            break;
                        default:
                            printf("Waduh, yang kamu cari gak ada nih. Coba lagi!\n");
                            break;
                        }
                    } while (fungsi_barang != 5);
                case 2:
                    do
                    {
                        printf("\nMenu:\n");
                        printf("1. Lihat barang yang tersedia\n");
                        printf("2. Beli\n");
                        printf("3. Keluar\n");
                        printf("Pilih menu:");
                        scanf("%d", &fungsi_barang);

                        switch (fungsi_barang)
                        {
                        case 1:
                            lihatBarang(daftarBarang, jumlahBarang);
                            break;
                        case 2:
                            printf("Mau Beli apa?");
                        case 3:
                            exit(0);
                        default:
                            break;
                        }
                    } while (fungsi_barang != 3);
                break;
                case 3:
                    exit(0);
                    break;
                }
            case 3:
                printf("Terima kasih! Semoga kita berjumpa lagi.");
                exit(0);
            default:
                printf("Waduh, yang kamu cari gak ada nih. Coba lagi!\n");
        }
    }    
    return 0;
}
