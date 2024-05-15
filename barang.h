#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BARANG 100

struct Barang {
    char nama[50];
    int jumlah;
    float harga;
};

void tambahBarang(struct Barang daftarBarang[], int *jumlahBarang) {
    struct Barang barang;
    
    printf("Masukkan nama barang: ");
    scanf("%s", barang.nama);
    
    printf("Masukkan jumlah barang: ");
    scanf("%d", &barang.jumlah);
    
    printf("Masukkan harga barang: ");
    scanf("%f", &barang.harga);
    
    daftarBarang[*jumlahBarang] = barang;
    (*jumlahBarang)++;
    
    printf("Barang berhasil ditambahkan!\n");
}

void lihatBarang(struct Barang daftarBarang[], int jumlahBarang) {
    if (jumlahBarang == 0) {
        printf("Belum ada barang yang tersimpan.\n");
    } else {
        printf("Daftar Barang:\n");
        for (int i = 0; i < jumlahBarang; i++) {
            printf("\n----------------------------");
            printf("Barang %d:\n", i + 1);
            printf("Nama: %s\n", daftarBarang[i].nama);
            printf("Jumlah: %d\n", daftarBarang[i].jumlah);
            printf("Harga: %.2f\n", daftarBarang[i].harga);
            printf("----------------------------\n");
        }
    }
}

void hapusBarang(struct Barang daftarBarang[], int *jumlahBarang, int index) {
    if (index < 0 || index >= *jumlahBarang) {
        printf("Indeks barang tidak valid.\n");
    } else {
        for (int i = index; i < *jumlahBarang - 1; i++) {
            daftarBarang[i] = daftarBarang[i + 1];
        }
        (*jumlahBarang)--;
        printf("Barang berhasil dihapus!\n");
    }
}

void simpanKeFile(struct Barang daftarBarang[], int jumlahBarang) {
    FILE *file = fopen("stokbarang.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }
    
    for (int i = 0; i < jumlahBarang; i++) {
        fprintf(file, "%s,%d,%.2f\n", daftarBarang[i].nama, daftarBarang[i].jumlah, daftarBarang[i].harga);
    }
    
    fclose(file);
    printf("Data barang berhasil disimpan ke dalam file.\n");
}

void muatDariFile(struct Barang daftarBarang[], int *jumlahBarang) {
    FILE *file = fopen("stokbarang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }
    
    char line[100];
    char *token;
    int i = 0;
    
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        strcpy(daftarBarang[i].nama, token);
        
        token = strtok(NULL, ",");
        daftarBarang[i].jumlah = atoi(token);
        
        token = strtok(NULL, ",");
        daftarBarang[i].harga = atof(token);
        
        i++;
    }
    
    *jumlahBarang = i;
    
    fclose(file);
    printf("Data barang berhasil dimuat dari file.\n");
}
