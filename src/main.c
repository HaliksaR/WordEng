#include "global.h"
#include "gtk/headers/main_gtk.h"
#include "console/main_console.h"

int main(int argc, char *argv[]) {
    setlocale(LC_CTYPE, "");
    int qes = guestion_console();
    if (qes == 1) {
        system("clear");
        main_gtk(argc, argv);
    } else if (qes == 2) {
        system("clear");
        main_console();
    } else {
        return -1; 
    }
    return 0; 
}