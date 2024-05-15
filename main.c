#include <stdio.h>
#include <stdlib.h>
#include "intro.h"
#include "fungsibarang.h"
void registerUser() {
    #define MAX_USERNAME_LENGTH 50
    #define MAX_PASSWORD_LENGTH 50
    
    struct User {
        char username[MAX_USERNAME_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
    };
    
    struct User user;
    
    printf("Username: ");
    fgets(user.username, sizeof(user.username), stdin);
    user.username[strcspn(user.username, "\n")] = '\0';
    
    printf("Password: ");
    fgets(user.password, sizeof(user.password), stdin);
    user.password[strcspn(user.password, "\n")] = '\0';
    
    FILE *file = fopen("data_akun_kasir.txt", "a");  
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    
    fprintf(file, "%s,%s\n", user.username, user.password);
    fclose(file);
    
    printf("Registrasi berhasil!\n");
}

int loginUser() {
    #define MAX_USERNAME_LENGTH 50
    #define MAX_PASSWORD_LENGTH 50
    
    struct User {
        char username[MAX_USERNAME_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
    };
    struct User user;
    
    printf("Username: ");
    fgets(user.username, sizeof(user.username), stdin);
    user.username[strcspn(user.username, "\n")] = '\0';
    
    printf("Password: ");
    fgets(user.password, sizeof(user.password), stdin);
    user.password[strcspn(user.password, "\n")] = '\0';
    
    FILE *file = fopen("data_akun_kasir.txt", "r");   
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 0;
    }
    
    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 2];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        char *username = strtok(line, ",");
        char *password = strtok(NULL, ",");
        
        if (username != NULL && password != NULL) {
            if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
                fclose(file);
                return 1;
            }
        }
    }
    
    fclose(file);
    
    return 0;

}

int main() {
    int choice;
    
    do {
        printf("=== Program Login ===\n");
        printf("1. Registrasi\n");
        printf("2. Login\n");
        printf("3. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);
        getchar();  // Menghapus karakter newline (\n) setelah membaca angka
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    printf("Login berhasil!\n");
                } else {
                    printf("Username atau password salah. Login gagal.\n");
                }
                break;
            case 3:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih kembali.\n");
        }
        
        printf("\n");
    } while (choice != 3);
    
    return 0;
}
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
