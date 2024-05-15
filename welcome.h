#include <stdio.h>
#include <unistd.h>

void welcome() {
    char intro[] = "SELAMAT DATANG DI TOKO SERBA ADA";
    int delay = 100000;
    
    for (int i = 0; intro[i] != '\0'; i++) {
        printf("\033[H\033[J");
        for (int j = 0; j < i; j++) {
            printf("%c ", intro[j]);
        }
        printf("%c\n", intro[i]);

        usleep(delay);
    }
}
