#ifndef __GLOBAL_H__
#define __GLOBAL_H__

    int index;  // индекс нужного слова
    char *english; // само слово
    char *russian; // переводы

    char *name; // имя 
    int level; // уровень 1-3
    int words; // количество слов 1-4
    int fail; // количество ошибок за весь период
    int *indexx; // индексы выученных слов
    int i_words; // для подсчета слов


int max_index; // количество строк в базе слов
int max_learn; // количество выученных слов (подсчет индексов)

#endif