#include <string.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "includes/term.h"
#include "includes/logo.h"
#include "../global.h"

#define resetcolor() wprintf(ESC L"[0m")
#define set_display_atrib(color) 	wprintf(ESC L"[%dm",color); // цвет фона
    
    
    // https://habrahabr.ru/post/119436/

void delay(int msec) {
    float milli_seconds = msec; 
    float start_time = clock();
    while (clock() <= start_time + milli_seconds);
}

int guestion_console(); // выбор интерфейса
//если нет файла профиля
int hello_console();
int name_console();
int level_console();
int words_console();
// если есть
int learn_console();
int retry_console();
//всплывающие окна
int profile_console(int form);
void about_console();

void logo();
int alignment(wchar_t* slovo, int pol);
void frame(int dlina, int shirina);

int main_console () {
   // int error;
  /* guestion_console();
   delay(900000);
   hello_console();
   delay(900000);
   name_console();
   delay(900000);
   level_console();
   delay(900000);
    words_console();
    learn_console();
    delay(1000000);
    retry_console();
*/
  /*  about_console();
    delay(9000000);
    profile_console();
    return 0;*/
    /*system("clear");
    frame(32, 54);
    logo();
    while (error != 1) {
        error = hello_console();
    }
    error = 0;
    while (error != 1) {
        error = name_console();
    }
    error = 0;
    while (error != 1) {
        error = level_console();
    }
    error = 0;
     while (error != 1) {
        error = words_console();
    }*/

    return 0;
}

int guestion_console() {
    int xx = 54;
    int yy = 14;
    wchar_t ansv;
    system("clear");
    frame(yy,xx);
    gotoxy(alignment(L"Выберите интерфейс", xx/2),6);
    wprintf(L"Выберите интерфейс");
    gotoxy(alignment(L"Консольный(C)   Графический(G)", xx/2),7);
    wprintf(L"%lsКонсольный(C)   Графический(G)%ls", CYAN, RESET);
    gotoxy(alignment(L"Для консольного интерфейса разверните", xx/2),11);
    wprintf(L"%lsДля консольного интерфейса разверните",RED);
    gotoxy(alignment(L"консоль на весь экран!", xx/2),12);
    wprintf(L"консоль на весь экран!%ls\n", RESET);
    gotoxy(xx/2,9);
    wscanf(L"%lc", &ansv);
    ansv = towlower(ansv);
    if ( ansv == L'g') {
        return 1;
    }
    if ( ansv == L'c') {
        return 2;
    }
	return -1;
}
/*
int hello_console() {
    int xx = 54;
    //int yy = 32;
    wchar_t ansv[2];
    gotoxy(alignment("Добро подаловать!", xx/2),28);
    wprintf(L"Добро подаловать!");
    gotoxy(alignment("Для начала вы должны заполнить профиль:)", xx/2),29);
    wprintf(L"%sДля начала вы должны заполнить профиль:)%s\n\n", GRAY, RESET);
    gotoxy(alignment("Начать!(N)", xx/2),30);
    wprintf(L"%sНачать!(N)%s\n", RED, RESET);
    gotoxy(xx/2, 31);
    wscanf(L"%ls", ansv);
    if ( ansv[0] == 'N' || ansv[0] == 'n' || strcmp(ansv, "т") == 0 || strcmp(ansv, "Т") == 0) {
        return 1;
    }
	return -1;
}

int name_console() {
    int xx = 54;
    int yy = 32;
    name = (wchar_t*)malloc(100);
    system("clear");
    frame(yy,xx);
    gotoxy(alignment("Как вас зовут?", xx/2),14);
    wprintf(L"%sКак вас зовут?", CYAN);
    gotoxy(alignment("Enter", xx/2),24);
    wprintf(L"%sEnter%s\n\n", RED, RESET);
    gotoxy(18,16);
    wprintf(L"%s", CYAN);
    wscanf(L"%ls", name);
    name = realloc (name, strlen(name));
    wprintf(L"%s", RESET);
    // хз как проверить пока что, время первый час
	return 1;
}

int level_console() {
    int xx = 54;
    int yy = 32;
    system("clear");
    frame(yy,xx);
    wchar_t leveli[2];
    gotoxy(alignment("Каковы твои знания английского языка?",xx/2),6);
    wprintf(L"%sКаковы твои знания английского языка?%s", WHITE, RESET);
    gotoxy(alignment("Низкий(E)",xx/2),8);
    wprintf(L"%sНизкий(E)%s", WHITE, RESET);
    gotoxy(alignment("Средний(N)",xx/2),10);
    wprintf(L"%sСредний(N)%s", WHITE, RESET);
    gotoxy(alignment("Высокий(H)",xx/2),12);
    wprintf(L"%sВысокий(H)%s", WHITE, RESET);
    gotoxy(xx/2,14);
    wscanf(L"%ls", leveli);
    if (leveli[0] == 'E' || leveli[0] == 'e' || strcmp(leveli, "у") == 0 || strcmp(leveli, "У") == 0) {
        level = 1;
        return 1;
    }
    if (leveli[0] == 'N'|| leveli[0] == 'n' || strcmp(leveli, "т") == 0 || strcmp(leveli, "Т") == 0 ) {
        level = 2;
        return 1;
    }
    if (leveli[0] == 'H'|| leveli[0] == 'h' || strcmp(leveli, "р") == 0 || strcmp(leveli, "Р") == 0 ) {
        level = 3;
        return 1;
    }
	else {
        return -1;
    }
}

int words_console() {
    int xx = 54;
    int yy = 32;
    system("clear");
    frame(yy,xx);
    gotoxy(alignment("Сколько слов вы хотите учить за раз?", xx/2),15);
    wprintf(L"%sСколько слов вы хотите учить за раз?%s", WHITE, RESET);
    gotoxy(2,17);
    wprintf(L"\t\t1\t2\t3\t4");
    gotoxy(26,18);
    wscanf(L"%ld", &words);
    if ( words == 1 || words == 2 || words == 3 || words == 4 ) {
	    return 1;
    }
    else {
        return -1;
    }
}

int learn_console() { // проверка русских сделать
    int xx = 54;
    int yy = 32;
    int form = 1;
    wchar_t next[1];
    system("clear");
    frame(yy,xx);
    gotoxy(2,5);
    wprintf(L" Учить(L) Повторение(R) Профиль(P) Справка(A)");
    gotoxy(2,7);
    wprintf(L"%s Слов: %d\t\t\t\t%d/%d слов", GRAY, max_index, 1, words);
    gotoxy(2,8);
    wprintf(L" Выученных: %d", max_learn);
    gotoxy(2,9);
    wprintf(L" Ошибок: %d%s", fail, RESET);
    gotoxy(alignment(english, xx/2),11);
    wprintf(L"%s%s%s%s", UNDERLINE, CYAN, english, RESET);
    gotoxy(alignment(russian, xx/2),14);
    wprintf(L"%s", russian);
    gotoxy(alignment("Далее(N)", xx/2),20);
    wprintf(L"%sДалее(N)%s", RED, RESET);
    wscanf(L"%ls", next);
    gotoxy(xx/2,22);
    if ( next[0] == 'n' || next[0] == 'N' || strcmp(next, "т") == 0 || 
        strcmp(next, "Т") == 0) {
        // 
    } else {
        if ( next[0] == 'l' || next[0] == 'L' || strcmp(next, "д") == 0 || 
            strcmp(next, "Д") == 0) {
            // 
        } else {
            if ( next[0] == 'r' || next[0] == 'R' || strcmp(next, "к") == 0 || 
                strcmp(next, "К") == 0) {
                //
            } else {
                if ( next[0] == 'p' || next[0] == 'P' || strcmp(next, "з") == 0 || 
                    strcmp(next, "З") == 0) {
                    profile_console(form);
                } else {
                    if ( next[0] == 'a' || next[0] == 'A' || strcmp(next, "ф") == 0 || 
                        strcmp(next, "Ф") == 0 || next[0] == 'f' || next[0] == 'F' || 
                        strcmp(next, "а") == 0 || strcmp(next, "А") == 0) {
                        //
                    } else {
                        return -1;
                    }
                }
            }
        }
    }
    return 0;
}

int retry_console() {
    int xx = 54;
    int yy = 32;
    int form = 2;
    system("clear");
    frame(yy,xx);
    gotoxy(2,5);
    wprintf(L" Учить(L) Повторение(R) Профиль(P) Справка(A)");
    gotoxy(2,7);
    wprintf(L"%s Слов: %d\t\t\t\t%d/%d слов", GRAY, max_index, 1, words);
    gotoxy(2,8);
    wprintf(L" Выученных: %d", max_learn);
    gotoxy(2,9);
    wprintf(L" Ошибок: %d%s", fail, RESET);
    gotoxy(alignment(english,xx/2),12);
    wprintf(L"%s%s%s%s", UNDERLINE, CYAN, english, RESET);
    gotoxy(12,18);
    wprintf(L"Ответ:");

    gotoxy(alignment("НЕВЕРНО!",xx/2),22);
    wprintf(L"%sНЕВЕРНО!%s", RED, RESET); /// надо условие

    gotoxy(alignment("Стоп(S)        Далее(N)",xx/2),28);
    wprintf(L"%sСтоп(S)        %sДалее(N)%s", RED, GREEN, RESET);
    gotoxy(12,19);
    wchar_t *russ =(wchar_t*)malloc(100);
    wprintf(L"%s",CYAN);
    wscanf(L"%ls", russ);
    wprintf(L"%s",RESET);
    return 0;
}


int profile_console(int form) {
    int xx = 54;
    int yy = 16;
    int yyk = yy + 10;
    wchar_t exit[2];
    gotoxy(xx,yy); 
    wprintf(L"┤");
    gotoxy(1,yy); 
    wprintf(L"├");
    for (int i = 2; i < xx; i++) {
        for (int j = yy; j < yyk; j++){
             gotoxy(i,j);
             wprintf(L" ");
        }
    }
    for ( int i = 2; i < xx; i++) {
        gotoxy(i,yy); wprintf(L"─");
    }
    gotoxy(xx - 8,yy); 
    wprintf(L"%s Exit(Q)%s", RED , RESET);\
    yy++;
    gotoxy(alignment("Wordeng", xx/2),yy); 
    wprintf(L"%s%sWordeng%s", RED, UNDERLINE, RESET);
    yy++;
    gotoxy(alignment("Учи английский с радостью!", xx/2),yy); 
    wprintf(L"%sУчи английский с радостью!%s", GRAY, RESET);
    yy++;
    gotoxy(alignment( name, xx/2),yy);
    wprintf(L"%s", name);
    yy = yy + 2;
    gotoxy(alignment( "Выученных:", xx/2),yy);
    wprintf(L"Выученных: %d", max_learn);
    yy++;
    gotoxy(alignment( "Ошибок: ", xx/2),yy);
    wprintf(L"Ошибок: %d", fail);
    yy++;
    gotoxy(xx,yyk); 
    wprintf(L"┤");
    gotoxy(1,yyk); 
    wprintf(L"├");
    for ( int i = 2; i < xx; i++) {
        gotoxy(i,yyk); wprintf(L"─");
    }
    yy++;
    gotoxy(alignment( "Назад (R)", xx/2),yy);
    wprintf(L"Назад (R)");
    yy++;
    gotoxy(alignment( "Назад (R)", xx/2),yy);
    wscanf(L"%ls", exit);
    if ( exit[0] == 'r' || exit[0] == 'R' || strcmp(exit, "к") == 0 || strcmp(exit, "К") == 0){
        return form;
    }
    return 0;
}

void about_console() {
    int xx = 54;
    int yy = 18;
    system("clear");
    frame(yy,xx);

    gotoxy(alignment("WordEnd", xx/2),5);
    wprintf(L"WordEnd");

    gotoxy(alignment("1.0 Beta", xx/2),7);
    wprintf(L"1.0 Beta");

    gotoxy(alignment("Программа для заучивания слов иностранного языка", xx/2),9);
    wprintf(L"Программа для заучивания слов иностранного языка");

    gotoxy(alignment("(английского)", xx/2),10);
    wprintf(L"(английского)");

    gotoxy(alignment("Курсовая работа студентов Сибирского", xx/2),12);
    wprintf(L"Курсовая работа студентов Сибирского");

    gotoxy(alignment("государственного университета телекоммуникации", xx/2),13);
    wprintf(L"государственного университета телекоммуникации");

    gotoxy(alignment("и информатики", xx/2),14);
    wprintf(L"и информатики");

    gotoxy(alignment("Разработчики", xx/2),17);
    wprintf(L"Разработчики");
}

*/

int alignment(wchar_t* slovo, int pol) {
    int otstup, polovinaslova;
    polovinaslova = wcslen(slovo) / 2 - 1;
    otstup = pol - polovinaslova;
    return otstup;
}

void frame(int dlina, int shirina) {
    gotoxy(1,1);
    wprintf(L"┌");
    for ( int i = 2; i < shirina; i++) {
        gotoxy(i,1); wprintf(L"─");
    }
    gotoxy(shirina,1);
    wprintf(L"┐");
    gotoxy(shirina - 8,1); 
    wprintf(L"%ls Exit(Q)%ls", RED , RESET);\
    gotoxy(alignment(L"Wordeng", shirina/2),2); 
    wprintf(L"%ls%lsWordeng%ls", RED, UNDERLINE, RESET);
    gotoxy(alignment(L"Учи английский с радостью!", shirina/2),3); 
    wprintf(L"%lsУчи английский с радостью!%ls", GRAY, RESET);
    for (int i = 2; i < dlina; i++) {
        gotoxy(1,i); wprintf(L"│");
        gotoxy(shirina,i); wprintf(L"│");
    }
    gotoxy(1,4); 
    wprintf(L"├");
    for ( int i = 2; i < shirina; i++) {
        gotoxy(i,4); wprintf(L"─");
    }
    gotoxy(shirina,4); 
    wprintf(L"┤");
    gotoxy(1,dlina);
    wprintf(L"└");
    for ( int i = 2; i < shirina; i++) {
        gotoxy(i,dlina); wprintf(L"─");
    }
    wprintf(L"┘");
}
