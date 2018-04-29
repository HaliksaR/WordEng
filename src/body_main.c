#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <ctype.h>

#include "global.h" // глобальные переменные
#include "gtk/main_gtk.h" // весь интерфейс GTK
#include "console/console_graphics.h"

/* тут должен быть код андрея, тоесть весь скелет программы (обработчики файлов, информации, ошибок) */

/* На данный момент тут эксперементальные данные*/

int main (int argc, char *argv[] /*<---ВАЖНО! НЕ УДАЛЯТЬ*/) {
    fail = 228;
    max_index = 56765;
    max_learn = 65;
    i_words = 1;
    index = 1;
    english = "Rabbit";
    russian = "Заяц, кролик";
    name = "Alex";
    level = 1;
    words = 4;
    fail = 66;
    main_console();
    //main_gtk(argc, argv); //ВАЖНО ДЛЯ GTK! НЕ УДАЛЯТЬ
    return 0;
}