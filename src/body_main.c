#include "global.h" // глобальные переменные
#include <time.h>

void add_index_profile() { // GOOD
    FILE *profile = fopen("./data/profile/profile.txt", "a");
    fprintf (profile, "%d\n", index);
    fclose(profile);
}

FILE* level_file() { // GOOD
    FILE *dictionaries;
    if (level == 1) {
        dictionaries = fopen("./data/dictionaries/level1.txt", "r");
    }
    if (level == 2) {
        dictionaries = fopen("./data/dictionaries/level2.txt", "r");
    }
    if (level == 3) {
        dictionaries = fopen("./data/dictionaries/level3.txt", "r");
    }
    return dictionaries;
}

int search_index(FILE *dictionaries) {
    wchar_t *str = malloc(sizeof(wchar_t) * 1000);

    for (int i = 0; i < max_index; i++) {
        fgetws(str, 1000, dictionaries);
        if (i == index - 1) {
            // ЗАПОЛНИТЬ ГЛОБАЛКИ ENGLISH RUSSIAN!!!!!!!
            fclose(dictionaries);
            free(str);
            return 0;
        }
    }
    free(str);
    return -1;
}

int srav_index(int h) { // GOOD
    if (index_arr == NULL) {
        return 0;
    } else {
        for (int i = 0; i < sizeof(index_arr); i++) {
            if (h == 1) {
                if (index_arr[i] == index) {
                    return -1;
                }
            } else if (h == 2) {
                if (index_arr[i] != index) {
                    return -1;
                }  
            }              
        }
    }
    return 0;
}

// где-то тут проблема make: *** [gtk] Floating point exception (core dumped)
int learn_rand() { // рандом учить
    int err = -1;
    FILE *dictionaries = level_file();
    if (dictionaries == NULL) {
        printf("Could not open file");
        return -1;
    }
    char *ind = malloc(sizeof(char) * 100);
    fscanf(dictionaries, "%s\n", ind);
    index = atoi(ind);
    free(ind);
    while (err == -1) {
        srand(time(NULL));
        index = 3 + rand() %max_index;
        err = srav_index(1);
    }
//------------------------------------------------------------------------------------
    search_index(dictionaries);
    add_index_profile(); // функция для переноса индекса в конец профиля 
    return 0;
}

// где-то тут проблема make: *** [gtk] Floating point exception (core dumped)
int retry_rand() { // рандом повторять
    int err = -1;
    FILE *dictionaries = level_file();
    if (dictionaries == NULL) {
        printf("Could not open file");
        return -1;
    }
    char *ind = malloc(sizeof(char) * 100);
    fscanf(dictionaries, "%s\n", ind);
    index = atoi(ind);
    free(ind);
    while (err == -1) {
        srand(time(NULL));
        index = 3 + rand() %max_index;
        err = srav_index(2);
    }
//------------------------------------------------------------------------------------
    search_index(dictionaries);
    add_index_profile(); // функция для переноса индекса в конец профиля 
    return 0;
}

int retry_rus(wchar_t *ansv) { // Сравнение ввода // GOOD
    for (int i = 0; i < russian_num; i++) {
        if (wcscmp(ansv, russian[i])== 0) {
            return 0;
        }
    }
    return -1;
}

void save_profile() { // GOOD
    FILE *profile = fopen("./data/profile/profile.txt", "w");
    fwprintf (profile, L"name: %ls\n", name);
    fprintf (profile, "level: %d\n", level);
    fprintf (profile, "words: %d\n", words);
    fprintf (profile, "fail: %d\n", fail);
    fprintf (profile, "index:\n");
    for (int i = 0; i < sizeof(index_arr); i++) {
        fprintf (profile, "%d\n", index_arr[i]);
    }
    fclose(profile);
}

void load_profile() {
    FILE *profile = fopen("./data/profile/profile.txt", "r");
    // считывание и заполнение !!!!!

    //test
    index = 4;
    russian_num = 0;
    english = L"Door";
    russian = malloc(sizeof(wchar_t) * 1000 * russian_num);
    russian[russian_num] = L"Дверь";

    name = L"Matt";
    level = 1;
    words = 4;
    fail = 546;
    index_arr = malloc(sizeof(int) * 40);
    index_arr[0] = 56;
    index_arr[1] = 43;
    index_arr[2] = 54;

    max_index = 456;
    max_learn = 56;
    //test

    fclose(profile);
}