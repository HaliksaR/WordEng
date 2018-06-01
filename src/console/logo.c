#include <stdio.h>
#include <time.h>
#include "includes/logo.h"

void logo() {
    gotoxy(12,5);    
    wprintf(L"%ls██████████████████████████████\n" , BLACK);
    gotoxy(12,6);   
    wprintf(L"████████%ls" L"███%ls" L"███████████████████\n", RED, BLACK);
    gotoxy(12,7);   
    wprintf(L"█████%ls" L"██%ls" L"███%ls" L"█████%ls" L"███████████████\n", RED, BLACK, RED, BLACK);
    gotoxy(12,8);   
    wprintf(L"███████%ls" L"█████████████%ls" L"██████████%ls\n", RED, BLACK, RED);
    gotoxy(12,9);   
    wprintf(L"████%ls" L"███%ls" L"█████████████████%ls" L"██████\n", BLACK,RED, BLACK);
    gotoxy(12,10);   
    wprintf(L"█████%ls" L"█████%ls" L"██%ls" L"███████%ls" L"██████████%ls" L"█\n", RED, WHITE, RED, WHITE, BLACK);
    gotoxy(12,11);   
    wprintf(L"█████%ls" L"█████%ls" L"██%ls" L"█████%ls" L"██%ls" L"██%ls" L"██%ls" L"████%ls" L"███%ls\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK, RED);
    gotoxy(12,12);   
    wprintf(L"██%ls" L"█%ls" L"██████%ls" L"██%ls" L"█████%ls" L"██%ls" L"██%ls" L"██%ls" L"██████%ls" L"██\n", BLACK, RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK);
    gotoxy(12,13);   
    wprintf(L"███%ls" L"█████%ls" L"██%ls" L"██%ls" L"██%ls" L"█%ls" L"██%ls" L"██%ls" L"██████%ls" L"███%ls" L"██\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK);
    gotoxy(12,14);   
    wprintf(L"█%ls" L"███████%ls" L"█%ls" L"██%ls" L"██%ls" L"██%ls" L"█%ls" L"██%ls" L"██%ls" L"████████%ls" L"██\n",  RED, WHITE, RED, WHITE, RED, WHITE , RED, WHITE, RED, BLACK);
    gotoxy(12,15);   
    wprintf(L"█%ls" L"██████%ls" L"██%ls" L"█%ls" L"██%ls" L"██%ls" L"█%ls" L"██%ls" L"██%ls" L"█████████%ls" L"██\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK);
    gotoxy(12,16);   
    wprintf(L"███%ls" L"████%ls" L"█%ls" L"█%ls" L"█%ls" L"█%ls" L"█%ls" L"█%ls" L"█%ls" L"██%ls" L"██%ls" L"██%ls" L"███%ls" L"█████%ls" L"██\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK);
    gotoxy(12,17);   
    wprintf(L"████%ls" L"███%ls" L"██%ls" L"██%ls" L"███%ls" L"██%ls" L"████%ls" L"███████%ls" L"███\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK);
    gotoxy(12,18);   
    wprintf(L"█████%ls" L"██%ls" L"█%ls" L"██████████████████%ls" L"████\n", RED, WHITE, RED, BLACK);
    gotoxy(12,19);   
    wprintf(L"███████%ls" L"██████████████████%ls" L"█████\n", RED, BLACK);
    gotoxy(12,20);   
    wprintf(L"██████████%ls" L"███████████%ls" L"█████████%ls\n", RED, BLACK, RESET);
    gotoxy(5,22);   
    wprintf (L"%ls_       __\t\t     __   ______\n",RED);    
    gotoxy(4,23);  
    wprintf (L"| |     / /___  _________/ /  / ____/___  ____ _\n" ); 
    gotoxy(4,24); 
    wprintf (L"| | /| / / __ \\/ ___/ __  /  / __/ / __ \\/ __ `/\n" ); 
    gotoxy(4,25); 
    wprintf (L"| |/ |/ / /_/ / /  / /_/ /  / /___/ / / / /_/ /\n" ); 
    gotoxy(4,26); 
    wprintf (L"|__/|__/\\____/_/   \\__,_/  /_____/_/ /_/\\__, /\n" ); 
    gotoxy(43,27); 
    wprintf (L"/____/\n%ls", RESET);
}
