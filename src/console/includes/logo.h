#ifndef __LOHO_H__
#define __LOHO_H__

    #define RESET "\033[0m"
    #define GREEN "\033[1;32m"
    #define RED   "\033[1;31m"
    #define CYAN  "\033[1;36m"
    #define GRAY  "\033[2m"
    #define WHITE  "\033[37m"
    #define BLACK "\033[0;30m" 
    #define ESC "\033"
    #define gotoxy(x,y)		printf(ESC "[%d;%dH", y, x);

    void logo();
#endif