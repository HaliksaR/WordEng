#include <stdio.h>
#include <time.h>
#include "includes/logo.h"

void delay_logo()
{
    float milli_seconds = 40000;
    float start_time = clock();
    while (clock() <= start_time + milli_seconds);
}

void logo() {
    gotoxy(12,5);    
    printf("%s██████████████████████████████\n" , BLACK); delay_logo(40000);
    gotoxy(12,6);   
    printf("████████%s" "███%s" "███████████████████\n", RED, BLACK); delay_logo(40000);
    gotoxy(12,7);   
    printf("█████%s" "██%s" "███%s" "█████%s" "███████████████\n", RED, BLACK, RED, BLACK); delay_logo(40000);
    gotoxy(12,8);   
    printf("███████%s" "█████████████%s" "██████████%s\n", RED, BLACK, RED); delay_logo(40000);
    gotoxy(12,9);   
    printf("████%s" "███%s" "█████████████████%s" "██████\n", BLACK,RED, BLACK); delay_logo(40000);
    gotoxy(12,10);   
    printf("█████%s" "█████%s" "██%s" "███████%s" "██████████%s" "█\n", RED, WHITE, RED, WHITE, BLACK); delay_logo(40000);
    gotoxy(12,11);   
    printf("█████%s" "█████%s" "██%s" "█████%s" "██%s" "██%s" "██%s" "████%s" "███%s\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK, RED); delay_logo(40000);
    gotoxy(12,12);   
    printf("██%s" "█%s" "██████%s" "██%s" "█████%s" "██%s" "██%s" "██%s" "██████%s" "██\n", BLACK, RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK); delay_logo(40000);
    gotoxy(12,13);   
    printf("███%s" "█████%s" "██%s" "██%s" "██%s" "█%s" "██%s" "██%s" "██████%s" "███%s" "██\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK); delay_logo(40000);
    gotoxy(12,14);   
    printf("█%s" "███████%s" "█%s" "██%s" "██%s" "██%s" "█%s" "██%s" "██%s" "████████%s" "██\n",  RED, WHITE, RED, WHITE, RED, WHITE , RED, WHITE, RED, BLACK); delay_logo(40000);
    gotoxy(12,15);   
    printf("█%s" "██████%s" "██%s" "█%s" "██%s" "██%s" "█%s" "██%s" "██%s" "█████████%s" "██\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK); delay_logo(40000);
    gotoxy(12,16);   
    printf("███%s" "████%s" "█%s" "█%s" "█%s" "█%s" "█%s" "█%s" "█%s" "██%s" "██%s" "██%s" "███%s" "█████%s" "██\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK); delay_logo(40000);
    gotoxy(12,17);   
    printf("████%s" "███%s" "██%s" "██%s" "███%s" "██%s" "████%s" "███████%s" "███\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK); delay_logo(40000);
    gotoxy(12,18);   
    printf("█████%s" "██%s" "█%s" "██████████████████%s" "████\n", RED, WHITE, RED, BLACK); delay_logo(40000);
    gotoxy(12,19);   
    printf("███████%s" "██████████████████%s" "█████\n", RED, BLACK); delay_logo(40000);
    gotoxy(12,20);   
    printf("██████████%s" "███████████%s" "█████████%s\n", RED, BLACK, RESET); delay_logo(40000);
    gotoxy(5,22);   
    printf ("%s_       __\t\t     __   ______\n",RED); delay_logo(40000);    
    gotoxy(4,23);  
    printf ("| |     / /___  _________/ /  / ____/___  ____ _\n" ); delay_logo(40000); 
    gotoxy(4,24); 
    printf ("| | /| / / __ \\/ ___/ __  /  / __/ / __ \\/ __ `/\n" ); delay_logo(40000); 
    gotoxy(4,25); 
    printf ("| |/ |/ / /_/ / /  / /_/ /  / /___/ / / / /_/ /\n" ); delay_logo(40000); 
    gotoxy(4,26); 
    printf ("|__/|__/\\____/_/   \\__,_/  /_____/_/ /_/\\__, /\n" ); delay_logo(40000); 
    gotoxy(43,27); 
    printf ("/____/\n%s", RESET);
}
