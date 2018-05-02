#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <ctype.h>

#include "global.h" // глобальные переменные
#include "gtk/main_gtk.h" // весь интерфейс GTK

void learn_rand() {
    int err = -1;
    index_arr = malloc((int)* 30);
    index_arr = {56, 57, 58, 59, 60, 61}; // diapazon rand
    fscanf(pFile, "%d\n", max_index);
    while (err == -1) {
        int index = 1 + rand() &max_index; // srand
        err = srav_index();// сравнене  в0озврат укк если все гуд то 0 если нет то -1ж
    }
    // обращение по индексу функция эта функкия заполняет глоб
    // функция для переноса индекса в конец профиля 
}

/* тут должен быть код андрея, тоесть весь скелет программы (обработчики файлов, информации, ошибок) */

/* На данный момент тут эксперементальные данные*/

int main (int argc, char *argv[] /*<---ВАЖНО! НЕ УДАЛЯТЬ*/) {
    fail = 228;
    max_index = 56765;
    max_learn = 65;
    i_words = 1;
    main_gtk(argc, argv); //ВАЖНО ДЛЯ GTK! НЕ УДАЛЯТЬ
    return 0;
}

void search_index() {
    setlocale(LC_CTYPE, "");
    FILE *fp;
    wchar_t str[MAXCHAR];
    char* filename = "level1.txt";

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    for(int i = 0; i < max_index; i++) {
        fgetws(str, MAXCHAR, fp);
        if (i == index - 1) {
            wprintf(L"%ls", str);
            fclose(fp);
        }
    }
}

int srav_index() {
    if (index_arr == NULL) {
        return 0;
    } else {
        err != -1;
    }
}

#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>


#define MAXCHAR 1000

int main() {
setlocale(LC_CTYPE, "");
FILE *fp;
wchar_t str[MAXCHAR];
char* filename = "level1.txt";

fp = fopen(filename, "r");
if (fp == NULL){
printf("Could not open file %s",filename);
return 1;
}
for(int i = 0; i < 485; i++) {
fgetws(str, MAXCHAR, fp);
if (i == 50 - 1) {
wprintf(L"%ls", str);
fclose(fp);
}
}
return 0;
}