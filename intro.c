#include "intro.h"

void welcomeScreen() {
    char intro[] = "TOKO SERBA ADA";

#ifdef _WIN32
    int delay = 100; // Delay in milliseconds for Sleep
#else
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 100000000L; // 100 milliseconds for nanosleep
#endif

    for (int i = 0; intro[i] != '\0'; i++) {
        printf("\033[H\033[J");
        for (int j = 0; j < i; j++) {
            printf("%c ", intro[j]);
        }
        printf("%c\n", intro[i]);

#ifdef _WIN32
        Sleep(delay);
#else
        nanosleep(&ts, NULL);
#endif
    }
}
