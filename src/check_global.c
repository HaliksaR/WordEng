#include "global.h"

#define RESET L"\033[0m"
#define RED   L"\033[1;31m"

int correct_level() {
    if (level > 3 || level <= 0) {
        return -1;
    }
    return 0;
}
int correct_words() {
    if (words > 4 || words <= 0) {
        return -1;
    }
    return 0;
}

int correct_fail() {
    if (fail < 0) {
        return -1;
    }
    return 0;
}

int correct_name() {
    if (wcslen(name) == 0) {
        return -1;
    }
    for (int i = 0; i < wcslen(name); i++) {
        if (!iswprint(name[i])) {
            return -1;
        }
    }
    return 0;
}

void correct_profile() {
    int error = 0;
    if (correct_level() == -1) {
        wprintf(L"%lsIncorrect level!!\n%ls", RED, RESET);
        error++;
    }
    if (correct_words() == -1) {
        wprintf(L"%lsIncorrect level!!\n%ls", RED, RESET);
        error++;
    }
    if (correct_fail() == -1) {
        wprintf(L"%lsIncorrect fail!!\n%ls", RED, RESET);
        error++;
    }
    if (correct_name() == -1) {
        wprintf(L"%lsIncorrect name!!\n%ls", RED, RESET);
        error++;
    }
    if (error != 0) {
        remove("./data/profile/profile.txt");
        exit(-1);
    }
}

int correct_max_index() {
    if (max_index <= 1) {
        return -1;
    }
    return 0;
}

int correct_index_global() {
    if (index <= 0 || index > max_index) {
        return -1;
    }
    return 0;
}

int correct_russian_num() {
    if (russian_num < 1) {
        return -1;
    }
    return 0;
}

int correct_english() {
    if (wcslen(english) == 0) {
        return -1;
    }
    for (int i = 0; i < wcslen(english); i++) {
        if ((0x41 > english[i] && 0x7A < english[i]) && !iswpunct(english[i])) {
            return -1;
        }
    }
    return 0;
}

int correct_russian() {
    if (wcslen(russian) == 0) {
        return -1;
    }
    for (int i = 0; i < wcslen(russian); i++) {
        if ((0x0410 > russian[i] && 0x044F < russian[i]) && !iswpunct(russian[i])) {
            return -1;
        }
    }
    return 0;
}

void correct_dictionaries() {
    int error = 0;
    if (correct_max_index() == -1) {
        wprintf(L"%lsIncorrect max_index!!\n%ls", RED, RESET);
        error++;
    }
    if (correct_index_global() == -1) {
        wprintf(L"%lsIncorrect index!!\n%ls", RED, RESET);
        error++;
    }
    if (correct_russian_num() == -1) {
        wprintf(L"%lsIncorrect russian_num!!\n%ls", RED, RESET);
        error++;
    }
    if (correct_english() == -1) {
        wprintf(L"%lsIncorrect english!!\n%ls", RED, RESET);
        error++;
    }
    if (correct_russian() == -1) {
        wprintf(L"%lsIncorrect russian!!\n%ls", RED, RESET);
        error++;
    }
    if (error != 0) {
        remove("./data/profile/profile.txt");
        exit(-2);
    }
}
