#include "../global.h"  // глобальные переменные
#include "headers/gtkwidgets.h"  // Виджеты
#include "headers/widget_build.h"  // билдер
#include "headers/build_window.h"
#include "../body_main.h"
#include "headers/rendering.h"
#include "headers/signals.h"
/* GOOD - готовые функции */

void main_dialoggtk() {   //GOOD
    dialoggtk = create_dialoggtk();
    gtk_widget_show(dialoggtk);
}

void main_window_profilegtk() {   //GOOD
    profilegtk = create_profilegtk();
    gtk_widget_show(profilegtk);
}

int mass_age;

void main_window_massage(int i) {  //GOOD
    massage = create_massage();
    switch (i) {
        case 0:
            save_profile(0);
            max_learn = 0;
            mass_age = 0;
            break;
        case 1:
            mass_age = 1;
            gtk_label_set_text(GTK_LABEL(levelup), "DONE LEARN ENGLISH!");
            clear_window();
            break;
    }
    gtk_widget_show(massage);
}

void on_massage_destroy() {
    if (mass_age == 1) {
        remove("./data/profile/.profile.txt");
        gtk_main_quit();
    }
}

void status_text() {
    char *str = (char*) malloc(100);
    sprintf(str, "%d", max_index);
    gtk_label_set_text(GTK_LABEL(stats_words_word), str);
    sprintf(str, "%d", max_learn);
    gtk_label_set_text(GTK_LABEL(stats_words_learn), str);
    sprintf(str, "%d", fail);
    gtk_label_set_text(GTK_LABEL(stats_words_fail), str);
    sprintf(str, "%d", i_words);
    gtk_label_set_text(GTK_LABEL(stats_words_num), str);
    free(str);
}

void correct_index() {
    if (max_index == max_learn) {
        if (level != 3) {
            level++;
            if (load_max_index() == -1) {
                wprintf(L"ERROR OPEN DATA!\n");
                gtk_main_quit();
            }
            status_text();
            main_window_massage(0);
        } else {
            main_window_massage(1);
        }
    }
}

void windowgtk_destroy_cb() {   //GOOD
    save_profile(1);
    gtk_main_quit();
}

void on_header_destroy() {   //GOOD
    gtk_main_quit();
}

void menubar_about_activate_cb() {   //GOOD
    main_dialoggtk();
}

void menubar_profile_activate_cb() {  //GOOD
    main_window_profilegtk();

    if (level == 1) {
        gtk_label_set_text(GTK_LABEL(profile_level), "Низкий");
    }
    if (level == 2) {
        gtk_label_set_text(GTK_LABEL(profile_level), "Средний");
    }
    if (level == 3) {
        gtk_label_set_text(GTK_LABEL(profile_level), "Высокий");
    }
    char *str = (char*) malloc(sizeof(char) * 100);
    wcstombs(str, name, sizeof(wchar_t) * wcslen(name) + 1);
    gtk_label_set_text(GTK_LABEL(profile_name), str);
    sprintf(str, "%d", fail);
    gtk_label_set_text(GTK_LABEL(profile_fail), str);
    sprintf(str, "%d", max_learn);
    gtk_label_set_text(GTK_LABEL(profile_words), str);
    free(str);
}
//***************билдеры***************

//***************Отрисовка***************

void learn_rand_up_label() {
    char *str = (char*) malloc(sizeof(char) * 1000);
    if (learn_rand() == -1) {
        windowgtk_destroy_cb();
    }
    wcstombs(str, english, sizeof(wchar_t) * wcslen(english) + 1);
    gtk_label_set_text(GTK_LABEL(learn_eng), str);
    wcstombs(str, russian, sizeof(wchar_t) * wcslen(russian) + 1);
    gtk_label_set_text(GTK_LABEL(learn_rus), str);
    free(str);
}

void retry_rand_up_label() {
    char *str = (char*) malloc(sizeof(char) * 1000);
    if (retry_rand() == -1) {
        windowgtk_destroy_cb();
    }  
    wcstombs(str, english, sizeof(wchar_t) * wcslen(english) + 1);
    gtk_label_set_text(GTK_LABEL(retry_english), str);
    free(str);
}

int main_gtk(int argc, char *argv[]) {
    FILE *pfile;
    pfile = fopen("./data/profile/.profile.txt", "r");
    gtk_init(&argc, &argv);
    windowgtk = create_windowgtk();
    gtk_widget_show(windowgtk);
    if (pfile == NULL) {
        edit_profile_1();
    } else {
        if (load_profile() == -1) {
            edit_profile_1();
        } else {
            if (load_max_index() == -1) {
                wprintf(L"ERROR OPEN DATA!\n");
                gtk_main_quit();        
            }
            menubar_learn_activate_cb();
        }
    }
    gtk_main();
    return 0;
}