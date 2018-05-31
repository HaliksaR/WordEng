#include "global.h" // глобальные переменные
#include "check_global.h"
#include <time.h>

// дочерние
int search_index(FILE *dictionaries);// GOOD Законченно
int srav_index(int h);// GOOD Законченно
void add_index_profile();// GOOD Законченно
void delete_index_profile();// GOOD Законченно
FILE* level_file(); // GOOD Законченно
// основные
int learn_rand();// GOOD Законченно
int retry_rand();// GOOD Законченно
// работа с файлами
void save_profile(int num);// GOOD Законченно
int load_profile();// GOOD Законченно
int load_max_index();// GOOD Законченно
// служебные
wchar_t* convert_to_wchar_rus(char *input);// GOOD Законченно
wchar_t* convert_to_wchar(char *input);// GOOD Законченно

int load_max_index() {
    FILE *dictionaries = level_file();
    if (dictionaries == NULL) {
        wprintf(L"Could not open file\n");
        return -1;
    }
    char *ind = malloc(sizeof(char) * 100);
    fscanf(dictionaries, "%s\n", ind);
    max_index = atoi(ind);
    free(ind);
    fclose(dictionaries);
    return 0;
}

void add_index_profile() {
    FILE *profile = fopen("./data/profile/profile.txt", "a");
    fprintf (profile, "%d\n", index);
    fclose(profile);
    index_arr = (int*) realloc(index_arr, sizeof(int) * max_learn + 1);
    index_arr[max_learn] = index;
    max_learn++;
}

void delete_index_profile() {
    int i = 0;
    for (; index_arr[i] != index; i++);
    for (int c = i; c < max_learn - 1; c++) {
        index_arr[c] = index_arr[c + 1];

    }
    max_learn = max_learn - 1;
    index_arr = (int*)realloc(index_arr, sizeof(int) * max_learn);
}

FILE* level_file() {
    FILE *dictionaries;
    if (level == 1) {
        dictionaries = fopen("./data/dictionaries/level1.txt", "r");
        return dictionaries;
    }
    if (level == 2) {
        dictionaries = fopen("./data/dictionaries/level2.txt", "r");
        return dictionaries;
    }
    if (level == 3) {
        dictionaries = fopen("./data/dictionaries/level3.txt", "r");
        return dictionaries;
    }
    return NULL;
}

wchar_t* convert_to_wchar_rus(char *input) {
	int len = strlen(input);
	wchar_t *command_w = malloc(sizeof(wchar_t)* len);
    if (command_w == NULL) {
        return NULL;
    }
	swprintf(command_w, len, L"%hs", input);
	return command_w;
}

wchar_t* convert_to_wchar(char *input) { 
	int len = strlen(input) + 1;
	wchar_t *command_w = malloc(sizeof(wchar_t)* len);
    if (command_w == NULL) {
        return NULL;
    }
	swprintf(command_w, len, L"%hs", input);
	return command_w;
}

int search_index(FILE *dictionaries) {
    char *str = (char*) malloc(sizeof(char) * 1000);
    if (str == NULL) {
        return -1;
    }
    for (int i = 0; i < max_index; i++) {
        fgets(str, 1000, dictionaries);
        if (i + 1 == index) {
            char *token = strtok(str, ";");
            if (!token) {
                return -1;
            }
            russian_num = atoi(token);
            token = strtok(NULL, ";");
            if (!token) {
                return -1;
            }
            english = convert_to_wchar(token);
            english[0] = towupper(english[0]);
            token = strtok(NULL, "\0\n ");
            if (!token) {
                return -1;
            }
            russian = convert_to_wchar_rus(token);
            for (int k = 0; k < wcslen(russian) - 1; k++) {
                if (russian[k] == L';') {
                    russian[k] = L',';
                }
            }
            fclose(dictionaries);
            correct_dictionaries();
            return 0;
        }
    }
    free(str);
    fclose(dictionaries);
    return -1;
}

int srav_index(int h) {
    if (index_arr == NULL) {
        return 0;
    } else {
        for (int i = 0; i < max_learn; i++) {
            if (h == 1) {
                if (index_arr[i] == index) {
                    return -1;
                }
            } else if (h == 2) {
                for(int i = 0; i < max_learn; i++) {
                    if (index_arr[i] == index) {
                        return -1;
                    }
                }
            }              
        }
    }
    return 0;
}

int learn_rand() {
    int err = -1;
    FILE *dictionaries = level_file();
    if (dictionaries == NULL) {
        wprintf(L"Could not open file\n");
        return -1;
    }
    char *ind = malloc(sizeof(char) * 10);
    if (ind  == NULL) {
        return -1;
    }
    fscanf(dictionaries, "%s\n", ind);
    free(ind);
    while (err == -1) {
        srand(clock());
        index = 1 + rand() % max_index;
        err = srav_index(1);
    }
    search_index(dictionaries);
    add_index_profile();
    return 0;
}

int retry_rand() {
    int err = 0;
    FILE *dictionaries = level_file();
    if (dictionaries == NULL) {
        wprintf(L"Could not open file\n");
        return -1;
    }
    char *ind = malloc(sizeof(char) * 100);
    if (ind  == NULL) {
        return -1;
    }
    fscanf(dictionaries, "%s\n", ind);
    index = atoi(ind);
    free(ind);
    while (err == 0) {
        srand(clock());
        index = (1 + rand() % max_index);
        err = srav_index(2);
    }
    search_index(dictionaries);
    return 0;
}

wchar_t* to_lowercase( wchar_t *word) {
    wchar_t *res = malloc(sizeof(wchar_t) * (wcslen(word) + 1));
    if (res == NULL) {
        return NULL;
    }
    res[wcslen(word)] = L'\0';
    for(int i = 0; i < wcslen(word); i++) {
        if (towlower(word[i]) == L'ё') {
            word[i] = L'e';
        }
        res[i] = towlower(word[i]);
    }
    return res;
}

int retry_rus(wchar_t *ansv) {
    wprintf(L"%ls", russian);
    russian = to_lowercase(russian);
    wchar_t *rus = (wchar_t*) malloc(sizeof(wchar_t) * (wcslen(russian)) + 1);
    wcscpy(rus, russian);
    wchar_t *pruf = L", \n";
    wchar_t *token, *ptr;
	token = wcstok(russian, pruf, &ptr);
	while (token) {
        if (wcsncmp(ansv, token, wcslen(token) - 1) == 0) {
            wprintf(L"DONE WORD\n");
            wcscpy(russian, rus);
            free(rus);
            return 0;
        }
		token = wcstok(NULL, pruf, &ptr);
	}
    wcscpy(russian, rus);
    free(rus);
    return -1;
}

void save_profile(int num) {
    correct_profile();
    FILE *profile;
    switch (num) {
        case 0:
            profile = fopen("./data/profile/profile.txt", "w");
            if (profile == NULL){
                system("mkdir ./data/profile/");
                return save_profile(0);
            }
            fprintf(profile, "name: %ls\n", name);
            fprintf(profile, "level: %d\n", level);
            fprintf(profile, "words: %d\n", words);
            fprintf(profile, "fail: %d\n", fail);
            fprintf(profile, "index:\n");
            fclose(profile);
            break;
        case 1:
            profile = fopen("./data/profile/profile.txt", "w");
            if (profile == NULL){
                system("mkdir ./data/profile/");
                return save_profile(1);
            }
            fprintf(profile, "name: %ls\n", name);
            fprintf(profile, "level: %d\n", level);
            fprintf(profile, "words: %d\n", words);
            fprintf(profile, "fail: %d\n", fail);
            fprintf(profile, "index:\n");
            load_max_index();

            for(int i = 0; i <= max_learn; i++) {
                if (index_arr[i] > 0 && index_arr[i] <= max_index){
                    fprintf(profile, "%d\n", index_arr[i]);
                }
            }
            fclose(profile);
            break;
    }
}

int load_profile() {
    FILE *profile = fopen("./data/profile/profile.txt", "rb");
    if (profile == NULL){
        return -1;
    }
    if (getc(profile) == EOF) {
        fclose(profile);
        return -1;
    }
    char *str = (char*) calloc(1000, sizeof(char));
    char *pruf = ": \n \0";

    fgets(str, 1000, profile);
    char *token = strtok(str, pruf);
    if (strcmp(token, "ame")) {
        fclose(profile);
        return -1;
    }
    token = strtok(NULL, pruf);
    if (!token) {
        return -1;
    }
    name = convert_to_wchar(token);

    fgets(str, 1000, profile);
    token = strtok(str, pruf);
    token = strtok(NULL, pruf);
    level = atoi(token);
    load_max_index();

    fgets(str, 1000, profile);
    token = strtok(str, pruf);
    token = strtok(NULL, pruf);
    words = atoi(token);

    fgets(str, 1000, profile);
    token = strtok(str, pruf);
    token = strtok(NULL, pruf);
    fail = atoi(token);

    fgets(str, 1000, profile);
    index_arr = (int*) malloc(sizeof(int) * 10000);
    if (index_arr == NULL) {
        return -1;
    }
    max_learn = 0;
    while (fscanf(profile, "%s", str) != EOF) {
        if (atoi(str) > 0 && atoi(str) <= max_index) {
            index_arr[max_learn] = atoi(str);
            max_learn++;
        }
    }
    free(str);
    fclose(profile);
    correct_profile();
    return 0;
}