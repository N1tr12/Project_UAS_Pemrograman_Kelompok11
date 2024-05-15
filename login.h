#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME 100
#define MAX_PASSWORD 100
#define NAMA_FILE "akun.txt"

int cek_akun(const char *username) {
    FILE *file = fopen(NAMA_FILE, "r");
    if (file == NULL) {
        return 0;
    }

    char stored_username[MAX_USERNAME];
    while (fscanf(file, "%s", stored_username) != EOF) {
        if (strcmp(stored_username, username) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void register_akun() {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];

    printf("Masukkan username: ");
    scanf("%s", username);

    if (cek_akun(username)) {
        printf("Username sudah ada. Silakan gunakan username lain.\n");
        return;
    }

    printf("Masukkan password: ");
    scanf("%s", password);

    FILE *file = fopen(NAMA_FILE, "a");
    if (file == NULL) {
        perror("Gagal membuka file");
        return;
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);

    printf("Akun berhasil didaftarkan. Silahkan Login!\n");
}

void login() {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char stored_username[MAX_USERNAME];
    char stored_password[MAX_PASSWORD];

    printf("Masukkan username: ");
    scanf("%s", username);
    printf("Masukkan password: ");
    scanf("%s", password);

    FILE *file = fopen(NAMA_FILE, "r");
    if (file == NULL) {
        perror("Gagal membuka file");
        return;
    }

    int login_berhasil = 0;
    while (fscanf(file, "%s %s", stored_username, stored_password) != EOF) {
        if (strcmp(stored_username, username) == 0 && strcmp(stored_password, password) == 0) {
            login_berhasil = 1;
            break;
        }
    }

    fclose(file);

    if (login_berhasil) {
        printf("Login berhasil.\n");
    } else {
        printf("Username atau password salah.\n");
    }
}
