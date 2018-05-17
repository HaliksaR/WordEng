#ifndef __LOHO_H__
#define __LOHO_H__

    #include <wchar.h>
    #include <wctype.h>

    #define RESET L"\033[0m"
    #define GREEN L"\033[1;32m"
    #define RED   L"\033[1;31m"
    #define CYAN  L"\033[1;36m"
    #define GRAY  L"\033[2m"
    #define WHITE  L"\033[37m"
    #define BLACK L"\033[0;30m" 
    #define ESC L"\033"
    #define BOLD L"\033[1m"
    #define UNDERLINE L"\033[4m"
    #define NUNDERLINE L"\033[4m"
    #define gotoxy(x,y)		wprintf(ESC L"[%d;%dH", y, x);

    void logo();
#endif
