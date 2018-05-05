#ifndef __GLOBAL_H__
#define __GLOBAL_H__

<<<<<<< HEAD
    #include <stdlib.h>
    #include <stdio.h> 
    #include <string.h>
    
=======
>>>>>>> Andrey
    #include <wchar.h>
    #include <wctype.h>
    #include <locale.h>

    int index;  // индекс нужного слова
<<<<<<< HEAD
    int russian_num;
    wchar_t *english; // само слово
    wchar_t **russian; // переводы
=======
    wchar_t *english; // само слово
    wchar_t *russian; // переводы
>>>>>>> Andrey

    wchar_t *name; // имя 
    int level; // уровень 1-3
    int words; // количество слов 1-4
    int fail; // количество ошибок за весь период
    int *index_arr; // индексы выученных слов
    int i_words; // для подсчета слов


int max_index; // количество строк в базе слов
int max_learn; // количество выученных слов (подсчет индексов)

#endif