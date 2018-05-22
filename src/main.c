#include "global.h" // глобальные переменные
#include "gtk/headers/main_gtk.h" // весь интерфейс GTK

int main(int argc, char *argv[] /*<---ВАЖНО! НЕ УДАЛЯТЬ*/) {
    setlocale(LC_CTYPE, "");
    int qes = 1;
    if (qes == 1) {
        main_gtk(argc, argv); //ВАЖНО ДЛЯ GTK! НЕ УДАЛЯТЬ
    } else if (qes == 2) {
        //
    } else {
        return -1; 
    }
    return 0; 
}