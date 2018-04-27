#ifndef __GLOBAL_H__
#define __GLOBAL_H__

/* !!!нужно будет воспользоваться массивом структур для вызова структур на экране изучения и повторения!!! */
typedef struct {
    int index;  // индекс нужного слова
    char *english; // само слово
    char *russian; // переводы
} database; // структура данных о слове

typedef struct {
    char *name; // имя 
    int level; // уровень 1-3
    int words; // количество слов 1-4
    int fail; // количество ошибок за весь период
    int *index; // индексы выученных слов
} profile_data; // структура профиля

int max_index; // количество строк в базе слов
int max_learn; // количество выученных слов (подсчет индексов)
   
#endif