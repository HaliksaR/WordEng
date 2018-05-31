#include "global.h"

#define RESET L"\033[0m"
#define RED   L"\033[1;31m"

int start_program() {
    if (max_index < max_learn) {
        return -1;
    }
    return 0;
}

void correct_start_program() {
    int error = 0;
    if (start_program() == -1) {
        wprintf(L"%lsmax_index < max_learn!!\n%ls", RED, RESET);
        error++;
    }
    if (error != 0) {
        remove("./data/profile/profile.txt");
        exit(-5);
    }
}