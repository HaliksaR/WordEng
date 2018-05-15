#include "global.h" // глобальные переменные
#include <time.h>


// дочерние
int search_index(FILE *dictionaries);// GOOD Законченно
int srav_index(int h);// GOOD
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
        printf("Could not open file");
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
    FILE *profile = fopen("./data/profile/.profile.txt", "a");
    fprintf (profile, "%d\n", index);
    fclose(profile);
    index_arr = (int*) realloc(index_arr, sizeof(int) * max_learn + 1);
    index_arr[max_learn] = index;
    max_learn++;
}

void delete_index_profile() {
    int i = 0;
    for (; index_arr[i] != index; i++);
    for  (int c = i; c < max_learn - 1; c++) {
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
    char *buff = (char*) calloc(1000, sizeof(char));
    for (int i = 0; i < max_index; i++) {
        memset(buff, 0, 1000);
        fgets(str, 1000, dictionaries);
        if (i == index) {
            if (buff == NULL) {
                return -1;
            }
            int k = 0;
            for (int b = 0; str[k] != ';'; k++) {
                buff[b] = str[k];
                b++;
            }
            k++;
            russian_num = atoi(buff);
            for (int b = 0; str[k] != ';'; k++) {
                buff[b] = str[k];
                b++;
            }
            k++;
            english = convert_to_wchar(buff);
            english[0] = towupper(english[0]);
            for (int b = 0; str[k] != '\0'; k++) {
                if (str[k] == ';') {
                    buff[b] = ',';
                    b++;
                    buff[b] = ' ';
                } else {
                    buff[b] = str[k];
                }
                b++;
            }
            russian = convert_to_wchar_rus(buff);      
            fclose(dictionaries);
            return 0;
        }
    }
    
    free(str);
    free(buff);
    fclose(dictionaries);
    return -1;
}

int srav_index(int h) {
    if (index_arr == NULL) {
        return 0;
    } else {
        for (int i = 0; i < max_learn + 1; i++) {
            if (h == 1) {
                if (index_arr[i] == index) {
                    return -1;
                }
            } else if (h == 2) {
                if (index_arr[i] == index) {
                    return 0;
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
        printf("Could not open file");
        return -1;
    }
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
    int err = -1;
    FILE *dictionaries = level_file();
    if (dictionaries == NULL) {
        printf("Could not open file");
        return -1;
    }
    char *ind = malloc(sizeof(char) * 100);
    if (ind  == NULL) {
        return -1;
    }
    fscanf(dictionaries, "%s\n", ind);
    index = atoi(ind);
    free(ind);
    while (err == -1) {
        srand(clock());
        index = 1 + rand() % max_index;
        err = srav_index(2);
    }
    search_index(dictionaries);
    return 0;
}

wchar_t* to_lowercase(const wchar_t *word) {
    wchar_t *res = malloc(sizeof(wchar_t) * (wcslen(word) + 1));
    if (res == NULL) {
        return NULL;
    }
    res[wcslen(word)] = L'\0';
    for(int i = 0; i < wcslen(word); i++) {
        res[i] = towlower(word[i]);
    }
    return res;
}

int retry_rus(wchar_t *ansv) {
    russian = to_lowercase(russian);
    wchar_t *rus = russian;
    wchar_t *pruf = L", \n \0";
    wchar_t *token, *ptr;
	token = wcstok(rus, pruf, &ptr);
	while (token) {
        if (wcsncmp(ansv, token, wcslen(token) -1) == 0) {
            wprintf(L"DONE WORD\n");
            return 0;
        }
		token = wcstok(NULL, pruf, &ptr);
	}
    return -1;
}


void save_profile(int num) {
    FILE *profile;
    switch (num) {
        case 0:
            profile = fopen("./data/profile/.profile.txt", "w");
            fprintf(profile, "name: %ls\n", name);
            fprintf(profile, "level: %d\n", level);
            fprintf(profile, "words: %d\n", words);
            fprintf(profile, "fail: %d\n", fail);
            fprintf(profile, "index:\n");
            fclose(profile);
            break;
        case 1:
            profile = fopen("./data/profile/.profile.txt", "w");
            fprintf(profile, "name: %ls\n", name);
            fprintf(profile, "level: %d\n", level);
            fprintf(profile, "words: %d\n", words);
            fprintf(profile, "fail: %d\n", fail);
            fprintf(profile, "index:\n");
            for(int i = 0; i < max_learn; i++) {
                fprintf(profile, "%d\n", index_arr[i]);
            }
            fclose(profile);
            break;
    }
}

int load_profile() {
    FILE *profile = fopen("./data/profile/.profile.txt", "rb");
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
    name = convert_to_wchar(token);

    fgets(str, 1000, profile);
    token = strtok(str, pruf);
    token = strtok(NULL, pruf);
    level = atoi(token);

    fgets(str, 1000, profile);
    token = strtok(str, pruf);
    token = strtok(NULL, pruf);
    words = atoi(token);

    fgets(str, 1000, profile);
    token = strtok(str, pruf);
    token = strtok(NULL, pruf);
    fail = atoi(token);

    fgets(str, 1000, profile);
    max_learn = 0;
    index_arr = (int*) malloc(sizeof(int) * 10000);
    if (index_arr == NULL) {
        return -1;
    }
    while (fscanf(profile, "%s", str) != EOF) {
        index_arr[max_learn] = atoi(str);
        max_learn++;
    }
    free(str);
    fclose(profile);
    return 0;
}