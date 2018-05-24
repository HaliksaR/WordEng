#include "global.h" // глобальные переменные
#include "gtk/headers/main_gtk.h" // весь интерфейс GTK
#include "console/main_console.h"

int main(int argc, char *argv[] /*<---ВАЖНО! НЕ УДАЛЯТЬ*/) {
    setlocale(LC_CTYPE, "");
    int qes = guestion_console();
    if (qes == 1) {
        system("clear");
        main_gtk(argc, argv); //ВАЖНО ДЛЯ GTK! НЕ УДАЛЯТЬ
    } else if (qes == 2) {
        system("clear");
        main_console();
    } else {
        return -1; 
    }
    return 0; 
}