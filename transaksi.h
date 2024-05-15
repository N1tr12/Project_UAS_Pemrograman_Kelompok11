#include <stdio.h>
#include <string.h>

struct transaksi {
    char namaPembeli[50];
    char namaBarang[30];
    char tanggal[50];
    int jumlah;
    float total;
    float harga;
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
