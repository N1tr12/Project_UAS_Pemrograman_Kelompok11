#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct transaksi {
    char namaPembeli[50];
    char namaBarang[30];
    char tanggal[50];
    int jumlah;
    float total;
    float harga;
};

struct pembayaran {
    int idPembayaran;
    char typePembayaran[20];
    float harga;
    struct transaksi trans;
};



void transaksi() {
    char namaPembeli[50], tanggal[50], namaBarang[30]; 
    int jumlah; 
    float total = 0, harga;
    printf("Masukkan nama pembeli: ");
    scanf("%s", &namaPembeli);
    strcpy(tanggal,__DATE__);
    printf("\nMasukkan nama barang yang ingin dibeli: ");
    scanf("%s", &namaBarang);
    printf("\nMasukkan jumlah barang yang ingin dibeli: ");
    scanf("%d", &jumlah);
    printf("\nMasukkan harga barang: ");
    scanf("%f", &harga);
    
    
    printf("\n\n");
    printf("\t      TOKO SERBA ADA\n");
    printf("\t     ----------------\n");
    printf("\nAtas Nama : %s", namaPembeli);
    printf("\nTanggal : %s\n", tanggal);
    printf("\n------------------------------------------------");
    printf("\nBarang\t\t");
    printf("Jumlah\t\t");
    printf("Harga Satuan\t\t");
    printf("\n------------------------------------------------");
    printf("\n%s\t\t", namaBarang);
    printf("%d\t\t", jumlah);
    printf("%.2f\t\t", harga);
    printf("\n\n------------------------------------------------");
    printf("\nTOTAL\t\t\t\t%.2f", jumlah * harga);
    printf("\n------------------------------------------------");
}

void pembayaran(struct pembayaran byr, int bayar) {
    FILE *file;
    file = fopen("pembayaran.txt", "a");

    if (file == NULL)
    {
        printf("Gagal membuka file");
        return;
    }

    printf("Masukkan id pembayaran: ");
    scanf("%d", &byr.idPembayaran);
    printf("\nTipe pembayaran: ");
    scanf("%s", &byr.typePembayaran);
    printf("\nMasukkan total harga yang dibayar: ");
    scanf("%f", &byr.harga);

    fclose(file);
}
