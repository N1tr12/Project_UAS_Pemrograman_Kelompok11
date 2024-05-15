#ifndef INTRO_H
#define INTRO_H

#include <stdio.h>

#ifdef _WIN32
    #include <windows.h>  // Include Windows.h for Sleep
#else
    #include <time.h>     // Include time.h for nanosleep
#endif

void welcomeScreen();

#endif
