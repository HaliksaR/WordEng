#include "global.h"
#include "gtk/headers/main_gtk.h"

int main(int argc, char *argv[]) {
    setlocale(LC_CTYPE, "");
    main_gtk(argc, argv);
    return 0; 
}