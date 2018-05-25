#include "global.h" // глобальные переменные

int correct_level() {
    if (level > 3 || level < 0) {
        return -1;
    }
    return 0;
}

int correct_words() {
    if (words > 4 || words < 0) {
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
    if (!name) {
        return -1;
    }
    return 0;
}

void correct_profile() {
    if (correct_level() == -1) {
        wprintf(L"Incorrect level!!\n");
        remove("./data/profile/.profile.txt");
        exit(1);
    }
    if (correct_words() == -1) {
        wprintf(L"Incorrect level!!\n");
        remove("./data/profile/.profile.txt");
        exit(2);
    }
    if (correct_fail() == -1) {
        wprintf(L"Incorrect fail!!\n");
        remove("./data/profile/.profile.txt");
        exit(3);
    }
    if (correct_name() == -1) {
        wprintf(L"Incorrect name!!\n");
        remove("./data/profile/.profile.txt");
        exit(4);
    }
}

int correct_max_index() {
    if (max_index < 1) {
        return -1;
    }
    return 0;
}

int correct_index_global() {
    if (index < 0 || index > max_index) {
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

void correct_dictionaries() {
    if (correct_max_index() == -1) {
        wprintf(L"Incorrect max_index!!\n");
        remove("./data/profile/.profile.txt");
        exit(5);
    }
    if (correct_index_global() == -1) {
        wprintf(L"Incorrect index!!\n");
        remove("./data/profile/.profile.txt");
        exit(6);
    }
    if (correct_russian_num() == -1) {
        wprintf(L"Incorrect russian_num!!\n");
        remove("./data/profile/.profile.txt");
        exit(7);
    }
}