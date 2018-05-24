#include <string.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "includes/term.h"
#include "includes/logo.h"
#include "../global.h"
#include "../body_main.h"

int print = 0;

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
void hello_console();
void name_console();
void level_console();
void words_console();
// если есть
void learn_console();
void retry_console();
//всплывающие окна
void profile_console(int form);
void about_console(int form);

int alignment(wchar_t* slovo, int pol);
void frame(int dlina, int shirina);


void console_massage(int i) {  //GOOD
    switch (i) {
        case 0:
            save_profile(0);
            max_learn = 0;
            break;
        case 1:
            system("clear");
            gotoxy(2,1);
            wprintf(L"DONE LEARN ENGLISH!\n");
            remove("./data/profile/.profile.txt");
            exit(0);
            break;
    }
}

void retry_rand_up_label_con() {
    if (retry_rand() == -1) {
        save_profile(1);
        exit(0);
    } 
}

void correct_index_console() {
    if (max_index == max_learn) {
        if (level != 3) {
            level++;
            if (load_max_index() == -1) {
                wprintf(L"ERROR OPEN DATA!\n");
                system("clear");
                exit(0);
            }
            console_massage(0);
        } else {
            console_massage(1);
        }
    }
}

int main_console () {
    FILE *pfile;
    pfile = fopen("./data/profile/.profile.txt", "r");
    if (pfile == NULL) {
        hello_console();
    } else {
        if (load_profile() == -1) {
            hello_console();
        } else {
            if (load_max_index() == -1) {
                wprintf(L"ERROR OPEN DATA!\n");
                return 0;       
            }
            i_words = 1;
            if (learn_rand() == -1) {
                system("clear");
                exit(0);
            }
            learn_console();
        }
    }
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
    if ( ansv == L'g' ||  ansv == L'п' ) {
        return 1;
    }
    if ( ansv == L'c'||  ansv == L'с' ) {
        return 2;
    }
    if ( ansv == L'q'||  ansv == L'й' ) {
        system("clear");
        exit(0);
    }
	guestion_console();
    return 0;
}

void hello_console() {
    int xx = 54;
    int yy = 33;
    wchar_t ansv;
    frame(yy,xx);
    logo();
    gotoxy(alignment(L"Добро подаловать!", xx/2),29);
    wprintf(L"Добро подаловать!");
    gotoxy(alignment(L"Для начала вы должны заполнить профиль:)", xx/2),30);
    wprintf(L"%lsДля начала вы должны заполнить профиль:)%ls\n\n", GRAY, RESET);
    gotoxy(alignment(L"Начать!(N)", xx/2),31);
    wprintf(L"%lsНачать!(N)%ls\n", RED, RESET);
    gotoxy(xx/2, 32);
    wscanf(L"%lc", &ansv);
    ansv = towlower(ansv);
    if (ansv == ( L'n' ) || ansv == L'т') {
        name_console();
    } else {
        hello_console();
    }
}



void name_console() {
    int xx = 54;
    int yy = 32;
    name = (wchar_t*)malloc(100);
    system("clear");
    frame(yy,xx);
    gotoxy(alignment(L"Как вас зовут?", xx/2),14);
    wprintf(L"%lsКак вас зовут?", CYAN);
    gotoxy(alignment(L"Enter", xx/2),24);
    wprintf(L"%lsEnter%ls\n\n", RED, RESET);
    gotoxy(18,16);
    wprintf(L"%ls", CYAN);
    wscanf(L"%ls", name);
    name = realloc (name, wcslen(name));
    wprintf(L"%ls", RESET);
    level_console();
}

int level_scan(wchar_t leveli) {
    leveli = towlower(leveli);
    if (leveli == L'e' ||  leveli == L'у' ) {
        level = 1;
        if (load_max_index() == -1) {
            system("clear");
            exit(0);    
        }
        words_console();
        return 0;
    }
    if (leveli == L'n' ||  leveli == L'т' ) {
        level = 2;
        if (load_max_index() == -1) {
            system("clear");
            exit(0);    
        }
        words_console();
        return 0;
    }
    if ( leveli == L'h' ||  leveli == L'р' ) {
        level = 3;
        if (load_max_index() == -1) {
            system("clear");
            exit(0);    
        }
        words_console();
        return 0;
    }
    if ( leveli == L'q' ||  leveli == L'й' ) {
        system("clear");
        exit(0);
    }
    return -1;
}

void level_console() {
    int xx = 54;
    int yy = 32;
    system("clear");
    frame(yy,xx);
    wchar_t leveli;
    gotoxy(alignment(L"Каковы твои знания английского языка?",xx/2),6);
    wprintf(L"%lsКаковы твои знания английского языка?%ls", WHITE, RESET);
    gotoxy(alignment(L"Низкий(E)",xx/2),8);
    wprintf(L"%lsНизкий(E)%ls", WHITE, RESET);
    gotoxy(alignment(L"Средний(N)",xx/2),10);
    wprintf(L"%lsСредний(N)%ls", WHITE, RESET);
    gotoxy(alignment(L"Высокий(H)",xx/2),12);
    wprintf(L"%lsВысокий(H)%ls", WHITE, RESET);
    gotoxy(xx/2,14);
    wscanf(L"%lc", &leveli);
    if (level_scan(leveli) == 0) {
        words_console();
    } else {
        level_console();
    }
}

int words_scan(int wwords) {
    if (wwords == 1 || wwords == 2 || wwords == 3 || wwords == 4 ) {
        words = wwords;
        return 0;
    } else {
       return -1;
    }
}

void words_console() {
    int xx = 54;
    int yy = 32;
    int wwords;
    system("clear");
    frame(yy,xx);
    gotoxy(alignment(L"Сколько слов вы хотите учить за раз?", xx/2),15);
    wprintf(L"%lsСколько слов вы хотите учить за раз?%ls", WHITE, RESET);
    gotoxy(2,17);
    wprintf(L"\t\t1\t2\t3\t4");
    gotoxy(26,18);
    wscanf(L"%ld", &wwords);
    if (words_scan(wwords) == 0) {
        save_profile(0);
        i_words = 1;
        if (learn_rand() == -1) {
            system("clear");
            exit(0);
        }
        learn_console();
    } else {
        words_console();
    }
}

int learn_scan(wchar_t next) {
    correct_index_console();
    next = towlower(next);
    if ( next == L'r' ||  next == L'к' ) {
        return -1;
    }
    if ( next == L'p' ||  next == L'з' ) {
        profile_console(1);
    }
    if ( next == L'a' ||  next == L'ф' ) {
        about_console(1);
    }
    if ( next == L'n' ||  next == L'т' ) {
        if (i_words != words) {
            i_words++;
            if (learn_rand() == -1) {
                system("clear");
                exit(0);
            }
            return 0;
        } else {
            i_words = 1;
            return -1;
        }
    }
    if (next == L'q' ||  next == L'й' ) {
        system("clear");
        exit(0);
    }
    return 0;
}

void learn_console() {
    int xx = 54;
    int yy = 32;
    wchar_t next;
    system("clear");
    frame(yy,xx);
    gotoxy(2,5);
    wprintf(L" Учить(L) Повторение(R) Профиль(P) Справка(A)");
    gotoxy(2,7);
    wprintf(L"%ls Слов: %ld\t\t\t\t%ld/%ld слов", GRAY, max_index, i_words, words);
    gotoxy(2,8);
    wprintf(L" Выученных: %ld", max_learn);
    gotoxy(2,9);
    wprintf(L" Ошибок: %ld%ls", fail, RESET);
    gotoxy(alignment(english, xx/2),11);
    wprintf(L"%ls%ls%ls%ls", UNDERLINE, CYAN, english, RESET);
    gotoxy(alignment(russian, xx/2),14);
    wprintf(L"%ls", russian);
    gotoxy(alignment(L"Далее(N)", xx/2),20);
    wprintf(L"%lsДалее(N)%ls", RED, RESET);
    wscanf(L"%lc", &next);
    gotoxy(xx/2,22);
    int pruf = learn_scan(next);
    if (pruf == 0) {
        learn_console();
    } else if (pruf == -1) {
        retry_console();
    }
}

int retry_scan(wchar_t *russ) {
    correct_index_console();
    russ = to_lowercase(russ);
    if (wcscmp(russ, L"q") == 0 || wcscmp(russ, L"й") == 0) {
        system("clear");
        exit(0);
    }
    if (wcscmp(russ, L"p") == 0 || wcscmp(russ, L"з") == 0) {
        profile_console(2);
    }
    if (wcscmp(russ, L"a" ) == 0 || wcscmp(russ, L"ф") == 0) {
        about_console(2);
    }
    if (wcscmp(russ, L"l" ) == 0 || wcscmp(russ, L"д") == 0) {
        if (print == 1) {
            print = 0;
            return 1;
        } else {
            return -1;
        }
    }
    if (i_words == max_learn) {
        print = 0;
        return 1;
    }
    if (i_words > (max_learn / 4) || (i_words == 1 && chanse == 0)) {
            print = 1;
        } else {
            print = 0;
        }
    if (wcscmp(russ, L"") != 0) {
        if (retry_rus(russ) == -1) {
            chanse++;
            if (chanse == 5) {
                fail++;
                chanse = 0;
                delete_index_profile();
                retry_rand_up_label_con();
            }
            gotoxy(alignment(L"НЕВЕРНО!",27),22);
            wprintf(L"%lsНЕВЕРНО!%ls", RED, RESET);
            return -1;
        } else {
            if (retry_rand() == -1) {
                system("clear");
                exit(0);
            }  
            i_words++;
            return 0;
        }
    } else {
        return 0;
    }
    return 0;
}

void retry_console() { // нилаботаит
    int xx = 54;
    int yy = 32;
    wchar_t *russ = (wchar_t*) malloc(sizeof(wchar_t) * 100);
    system("clear");
    frame(yy,xx);
    gotoxy(2,5);
    if (print == 1) {
        wprintf(L" Учить(L) Профиль(P) Справка(A)");
    } else {
        wprintf(L" Профиль(P) Справка(A)");
    }
    gotoxy(2,7);
    wprintf(L"%ls Слов: %ld\t\t\t\t%ld/%ld слов", GRAY, max_index, i_words, max_learn);
    gotoxy(2,8);
    wprintf(L" Выученных: %ld", max_learn);
    gotoxy(2,9);
    wprintf(L" Ошибок: %ld%ls", fail, RESET);
    gotoxy(alignment(english,xx/2),12);
    wprintf(L"%ls%ls%ls%ls", UNDERLINE, CYAN, english, RESET);
    gotoxy(12,18);
    wprintf(L"Ответ:");
    wscanf(L"%ls", russ);
    int pruf = retry_scan(russ);
    if (pruf == -1) {
        retry_console();
    } else if (pruf == 1){
        i_words = 1;
        if (learn_rand() == -1) {
            system("clear");
            exit(0);
        }
        learn_console();
    } else {
        retry_console();
    }
    free(russ);
}

void profile_console(int form) {
    int xx = 54;
    int yy = 16;
    int yyk = yy + 10;
    wchar_t exi;
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
    wprintf(L"%ls Exit(Q)%ls", RED , RESET);
    yy++;
    gotoxy(alignment(L"Wordeng", xx/2),yy); 
    wprintf(L"%ls%lsWordeng%ls", RED, UNDERLINE, RESET);
    yy++;
    gotoxy(alignment(L"Учи английский с радостью!", xx/2),yy); 
    wprintf(L"%lsУчи английский с радостью!%ls", GRAY, RESET);
    yy++;
    gotoxy(alignment( name, xx/2),yy);
    wprintf(L"%ls", name);
    yy = yy + 2;
    gotoxy(alignment(L"Выученных:", xx/2),yy);
    wprintf(L"Выученных: %ld", max_learn);
    yy++;
    gotoxy(alignment(L"Ошибок: ", xx/2),yy);
    wprintf(L"Ошибок: %ld", fail);
    yy++;
    gotoxy(xx,yyk); 
    wprintf(L"┤");
    gotoxy(1,yyk); 
    wprintf(L"├");
    for ( int i = 2; i < xx; i++) {
        gotoxy(i,yyk); wprintf(L"─");
    }
    yy++;
    gotoxy(xx/2,yy);
    wscanf(L"%lc", &exi);
    exi = towlower(exi);
    if (exi == L'q' || exi == L'й') {
        if (form == 1) {
            learn_console();
        } else {
            retry_console();
        }
    } else {
        profile_console(form);
    }

}

void about_console(int form) {
    int xx = 54;
    int yy = 18;
    wchar_t exi;
    system("clear");
    frame(yy,xx);

    gotoxy(alignment(L"WordEnd", xx/2),5);
    wprintf(L"WordEnd");

    gotoxy(alignment(L"1.0 Beta", xx/2),7);
    wprintf(L"1.0 Beta");

    gotoxy(alignment(L"Программа для заучивания слов иностранного языка", xx/2),9);
    wprintf(L"Программа для заучивания слов иностранного языка");

    gotoxy(alignment(L"(английского)", xx/2),10);
    wprintf(L"(английского)");

    gotoxy(alignment(L"Курсовая работа студентов Сибирского", xx/2),12);
    wprintf(L"Курсовая работа студентов Сибирского");

    gotoxy(alignment(L"государственного университета телекоммуникации", xx/2),13);
    wprintf(L"государственного университета телекоммуникации");

    gotoxy(alignment(L"и информатики", xx/2),14);
    wprintf(L"и информатики");

    gotoxy(alignment(L"Разработчики", xx/2),17);
    wprintf(L"Разработчики");
    wscanf(L"%lc", &exi);
    exi = towlower(exi);
    if (exi == L'q' || exi == L'й') {
        if (form == 1) {
            learn_console();
        } else {
            retry_console();
        }
    } else {
        about_console(form);
    }
}



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
