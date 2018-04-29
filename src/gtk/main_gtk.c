#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <ctype.h>

#include "../global.h"  // глобальные переменные
#include "gtkwidgets.h"  // Виджеты
#include "widget_build.h"  // билдер

/* GOOD - готовые функции */


//***************билдеры***************
static GtkWidget* create_windowgtk(void) {   //GOOD
    GError* error = NULL;

    builder = gtk_builder_new();
    if (!gtk_builder_add_from_file(builder, "./data/style/style.glade", &error)) {
        g_critical("Не могу загрузить файл: %s", error->message);
        g_error_free(error);
    }
    GFile *file= g_file_new_for_path("./data/style/style.css");
    GtkCssProvider *provider = gtk_css_provider_new();
    if(!gtk_css_provider_load_from_file(provider, file, &error)) {
        g_warning("%s", error->message );
        g_error_free(error);
    }
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_builder_connect_signals(builder, NULL);

    widget_build();

    g_object_unref(builder);

    return windowgtk;
}

static GtkWidget* create_dialoggtk(void) {   //GOOD
    GError* error = NULL;

    builder = gtk_builder_new ();
    if (!gtk_builder_add_from_file (builder, "./data/style/style.glade", &error)) {
        g_critical("Не могу загрузить файл: %s", error->message);
        g_error_free(error);
    }
    GFile *file= g_file_new_for_path("./data/style/style.css");
    GtkCssProvider *provider = gtk_css_provider_new();
    if(!gtk_css_provider_load_from_file(provider, file, &error)) {
        g_warning("%s", error->message );
        g_error_free(error);
    }
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_builder_connect_signals (builder, NULL);
        
    dialoggtk = GTK_WIDGET(gtk_builder_get_object(builder, "dialoggtk"));
    if (!dialoggtk) {
        g_critical("Ошибка при получении виджета dialoggtk");
    }
    g_object_unref(builder);

    return dialoggtk;
}

static GtkWidget* create_profilegtk(void) {   //GOOD
    GError* error = NULL;

    builder = gtk_builder_new ();
    if(!gtk_builder_add_from_file(builder, "./data/style/style.glade", &error)) {
        g_critical("Не могу загрузить файл: %s", error->message);
        g_error_free(error);
    }
    GFile *file= g_file_new_for_path("./data/style/style.css");
    GtkCssProvider *provider = gtk_css_provider_new();
    if(!gtk_css_provider_load_from_file(provider, file, &error)) {
        g_warning("%s", error->message);
        g_error_free(error);
    }
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_builder_connect_signals(builder, NULL);
        
    profilegtk = GTK_WIDGET(gtk_builder_get_object(builder, "profilegtk"));
    if(!profilegtk) {
        g_critical("Ошибка при получении виджета profilegtk");
    }

    widget_build_profilegtk();

    g_object_unref(builder);

    return profilegtk;
}

void main_dialoggtk() {   //GOOD
    dialoggtk = create_dialoggtk();
    gtk_widget_show(dialoggtk);
}

void main_window_profilegtk() {   //GOOD
    profilegtk = create_profilegtk();
    gtk_widget_show(profilegtk);
}

void windowgtk_destroy_cb() {   //GOOD
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
    char str[100];
    sprintf(str, "%d", fail);
    gtk_label_set_text(GTK_LABEL(profile_fail), str);
    gtk_label_set_text(GTK_LABEL(profile_name), name);
    memset(str, 0, 100);
    sprintf(str, "%d", max_learn);
    gtk_label_set_text(GTK_LABEL(profile_words), str);
}
//***************билдеры***************


//***************Отрисовка***************
void status_text() {
    char str[100];
    sprintf(str, "%d", max_index);
    gtk_label_set_text(GTK_LABEL(stats_words_word), str);
    memset(str, 0, 100);
    sprintf(str, "%d", max_learn);
    gtk_label_set_text(GTK_LABEL(stats_words_learn), str);
    memset(str, 0, 100);
    sprintf(str, "%d", fail);
    gtk_label_set_text(GTK_LABEL(stats_words_fail), str);
    memset(str, 0, 100);
    sprintf(str, "%d", i_words);
    gtk_label_set_text(GTK_LABEL(stats_words_num), str);
    memset(str, 0, 100);
}

void menubar_learn_activate_cb() {
    gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
    // меню
    status_text();
    gtk_widget_set_visible(menubar, TRUE);
    // фон
    gtk_widget_set_visible(all_hello, FALSE);
    gtk_widget_set_visible(all_back, TRUE);
    // приветствие
    gtk_widget_set_visible(hello_welcome, FALSE);
    gtk_widget_set_visible(hello_welcome2, FALSE);
    gtk_widget_set_visible(hello_button, FALSE);
    // имя
    gtk_widget_set_visible(name_label, FALSE);
    gtk_widget_set_visible(name_enty, FALSE);
    gtk_widget_set_visible(name_button, FALSE);
    // уровень
    gtk_widget_set_visible(level_label, FALSE);
    gtk_widget_set_visible(level_button_easy, FALSE);
    gtk_widget_set_visible(level_button_middle, FALSE);
    gtk_widget_set_visible(level_button_hight, FALSE);
    // слова
    gtk_widget_set_visible(words_label, FALSE);
    gtk_widget_set_visible(number_button_num_1, FALSE);
    gtk_widget_set_visible(number_button_num_2, FALSE);
    gtk_widget_set_visible(number_button_num_3, FALSE);
    gtk_widget_set_visible(number_button_num_4, FALSE);
    // статус
    gtk_widget_set_visible(stats_words, TRUE);
    gtk_widget_set_visible(stats_learn, TRUE);
    gtk_widget_set_visible(stats_fail, TRUE);
    gtk_widget_set_visible(stats_words_word, TRUE);
    gtk_widget_set_visible(stats_words_learn, TRUE);
    gtk_widget_set_visible(stats_words_fail, TRUE);
    gtk_widget_set_visible(stats_words_num, TRUE);
    gtk_widget_set_visible(stats_sl, TRUE);
    gtk_widget_set_visible(stats_words_num_all, TRUE);
    gtk_widget_set_visible(stats_wrd, TRUE);
    // повторение
    gtk_widget_set_visible(retry_english, FALSE);
    gtk_widget_set_visible(retry_label, FALSE);
    gtk_widget_set_visible(retry_enty, FALSE);
    gtk_widget_set_visible(retry_fails, FALSE);
    gtk_widget_set_visible(retry_stop, FALSE);
    gtk_widget_set_visible(retry_next, FALSE);
    // изучение
    gtk_widget_set_visible(learn_eng, TRUE);
    gtk_widget_set_visible(learn_rus, TRUE);
    gtk_widget_set_visible(learn_button_next, TRUE);
    char str[100];
    sprintf(str, "%d", words);
    gtk_label_set_text(GTK_LABEL(stats_words_num_all), str);
    memset(str, 0, 100);
}

void menubar_retry_activate_cb() {
    gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
    // меню
    status_text();
    gtk_widget_set_visible(menubar, TRUE);
    // фон
    gtk_widget_set_visible(all_hello, FALSE);
    gtk_widget_set_visible(all_back, TRUE);
    // приветствие
    gtk_widget_set_visible(hello_welcome, FALSE);
    gtk_widget_set_visible(hello_welcome2, FALSE);
    gtk_widget_set_visible(hello_button, FALSE);
    // имя
    gtk_widget_set_visible(name_label, FALSE);
    gtk_widget_set_visible(name_enty, FALSE);
    gtk_widget_set_visible(name_button, FALSE);
    // уровень
    gtk_widget_set_visible(level_label, FALSE);
    gtk_widget_set_visible(level_button_easy, FALSE);
    gtk_widget_set_visible(level_button_middle, FALSE);
    gtk_widget_set_visible(level_button_hight, FALSE);
    // слова
    gtk_widget_set_visible(words_label, FALSE);
    gtk_widget_set_visible(number_button_num_1, FALSE);
    gtk_widget_set_visible(number_button_num_2, FALSE);
    gtk_widget_set_visible(number_button_num_3, FALSE);
    gtk_widget_set_visible(number_button_num_4, FALSE);
    // статус
    gtk_widget_set_visible(stats_words, TRUE);
    gtk_widget_set_visible(stats_learn, TRUE);
    gtk_widget_set_visible(stats_fail, TRUE);
    gtk_widget_set_visible(stats_words_word, TRUE);
    gtk_widget_set_visible(stats_words_learn, TRUE);
    gtk_widget_set_visible(stats_words_fail, TRUE);
    gtk_widget_set_visible(stats_words_num, TRUE);
    gtk_widget_set_visible(stats_sl, TRUE);
    gtk_widget_set_visible(stats_words_num_all, TRUE);
    gtk_widget_set_visible(stats_wrd, FALSE);
    // повторение
    gtk_widget_set_visible(retry_english, TRUE);
    gtk_widget_set_visible(retry_label, TRUE);
    gtk_widget_set_visible(retry_enty, TRUE);
    gtk_widget_set_visible(retry_fails, FALSE);
    gtk_widget_set_visible(retry_stop, TRUE);
    gtk_widget_set_visible(retry_next, TRUE);
    // изучение
    gtk_widget_set_visible(learn_eng, FALSE);
    gtk_widget_set_visible(learn_rus, FALSE);
    gtk_widget_set_visible(learn_button_next, FALSE);
    char str[100];
    sprintf(str, "%d", max_learn);
    gtk_label_set_text(GTK_LABEL(stats_words_num_all), str);
    memset(str, 0, 100);
}

void hello_button_clicked_cb () {
    // меню
    gtk_widget_set_visible(menubar, FALSE);
    // фон
    gtk_widget_set_visible(all_hello, FALSE);
    gtk_widget_set_visible(all_back, TRUE);
    // приветствие
    gtk_widget_set_visible(hello_welcome, FALSE);
    gtk_widget_set_visible(hello_welcome2, FALSE);
    gtk_widget_set_visible(hello_button, FALSE);
    // имя
    gtk_widget_set_visible(name_label, TRUE);
    gtk_widget_set_visible(name_enty, TRUE);
    gtk_widget_set_visible(name_button, TRUE);
    // уровень
    gtk_widget_set_visible(level_label, FALSE);
    gtk_widget_set_visible(level_button_easy, FALSE);
    gtk_widget_set_visible(level_button_middle, FALSE);
    gtk_widget_set_visible(level_button_hight, FALSE);
    // слова
    gtk_widget_set_visible(words_label, FALSE);
    gtk_widget_set_visible(number_button_num_1, FALSE);
    gtk_widget_set_visible(number_button_num_2, FALSE);
    gtk_widget_set_visible(number_button_num_3, FALSE);
    gtk_widget_set_visible(number_button_num_4, FALSE);
    // статус
    gtk_widget_set_visible(stats_words, FALSE);
    gtk_widget_set_visible(stats_learn, FALSE);
    gtk_widget_set_visible(stats_fail, FALSE);
    gtk_widget_set_visible(stats_words_word, FALSE);
    gtk_widget_set_visible(stats_words_learn, FALSE);
    gtk_widget_set_visible(stats_words_fail, FALSE);
    gtk_widget_set_visible(stats_words_num, FALSE);
    gtk_widget_set_visible(stats_sl, FALSE);
    gtk_widget_set_visible(stats_words_num_all, FALSE);
    gtk_widget_set_visible(stats_wrd, FALSE);
    // повторение
    gtk_widget_set_visible(retry_english, FALSE);
    gtk_widget_set_visible(retry_label, FALSE);
    gtk_widget_set_visible(retry_enty, FALSE);
    gtk_widget_set_visible(retry_fails, FALSE);
    gtk_widget_set_visible(retry_stop, FALSE);
    gtk_widget_set_visible(retry_next, FALSE);
    // изучение
    gtk_widget_set_visible(learn_eng, FALSE);
    gtk_widget_set_visible(learn_rus, FALSE);
    gtk_widget_set_visible(learn_button_next, FALSE);
}

void edit_profile_1() {
    // меню
    gtk_widget_set_visible(menubar, FALSE);
    // фон
    gtk_widget_set_visible(all_hello, TRUE);
    gtk_widget_set_visible(all_back, FALSE);
    // приветствие
    gtk_widget_set_visible(hello_welcome, TRUE);
    gtk_widget_set_visible(hello_welcome2, TRUE);
    gtk_widget_set_visible(hello_button, TRUE);
    // имя
    gtk_widget_set_visible(name_label, FALSE);
    gtk_widget_set_visible(name_enty, FALSE);
    gtk_widget_set_visible(name_button, FALSE);
    // уровень
    gtk_widget_set_visible(level_label, FALSE);
    gtk_widget_set_visible(level_button_easy, FALSE);
    gtk_widget_set_visible(level_button_middle, FALSE);
    gtk_widget_set_visible(level_button_hight, FALSE);
    // слова
    gtk_widget_set_visible(words_label, FALSE);
    gtk_widget_set_visible(number_button_num_1, FALSE);
    gtk_widget_set_visible(number_button_num_2, FALSE);
    gtk_widget_set_visible(number_button_num_3, FALSE);
    gtk_widget_set_visible(number_button_num_4, FALSE);
    // статус
    gtk_widget_set_visible(stats_words, FALSE);
    gtk_widget_set_visible(stats_learn, FALSE);
    gtk_widget_set_visible(stats_fail, FALSE);
    gtk_widget_set_visible(stats_words_word, FALSE);
    gtk_widget_set_visible(stats_words_learn, FALSE);
    gtk_widget_set_visible(stats_words_fail, FALSE);
    gtk_widget_set_visible(stats_words_num, FALSE);
    gtk_widget_set_visible(stats_sl, FALSE);
    gtk_widget_set_visible(stats_words_num_all, FALSE);
    gtk_widget_set_visible(stats_wrd, FALSE);
    // повторение
    gtk_widget_set_visible(retry_english, FALSE);
    gtk_widget_set_visible(retry_label, FALSE);
    gtk_widget_set_visible(retry_enty, FALSE);
    gtk_widget_set_visible(retry_fails, FALSE);
    gtk_widget_set_visible(retry_stop, FALSE);
    gtk_widget_set_visible(retry_next, FALSE);
    // изучение
    gtk_widget_set_visible(learn_eng, FALSE);
    gtk_widget_set_visible(learn_rus, FALSE);
    gtk_widget_set_visible(learn_button_next, FALSE);
}

void edit_profile_2() {
    // меню
    gtk_widget_set_visible(menubar, FALSE);
    // фон
    gtk_widget_set_visible(all_hello, FALSE);
    gtk_widget_set_visible(all_back, TRUE);
    // приветствие
    gtk_widget_set_visible(hello_welcome, FALSE);
    gtk_widget_set_visible(hello_welcome2, FALSE);
    gtk_widget_set_visible(hello_button, FALSE);
    // имя
    gtk_widget_set_visible(name_label, FALSE);
    gtk_widget_set_visible(name_enty, FALSE);
    gtk_widget_set_visible(name_button, FALSE);
    // уровень
    gtk_widget_set_visible(level_label, TRUE);
    gtk_widget_set_visible(level_button_easy, TRUE);
    gtk_widget_set_visible(level_button_middle, TRUE);
    gtk_widget_set_visible(level_button_hight, TRUE);
    // слова
    gtk_widget_set_visible(words_label, FALSE);
    gtk_widget_set_visible(number_button_num_1, FALSE);
    gtk_widget_set_visible(number_button_num_2, FALSE);
    gtk_widget_set_visible(number_button_num_3, FALSE);
    gtk_widget_set_visible(number_button_num_4, FALSE);
    // статус
    gtk_widget_set_visible(stats_words, FALSE);
    gtk_widget_set_visible(stats_learn, FALSE);
    gtk_widget_set_visible(stats_fail, FALSE);
    gtk_widget_set_visible(stats_words_word, FALSE);
    gtk_widget_set_visible(stats_words_learn, FALSE);
    gtk_widget_set_visible(stats_words_fail, FALSE);
    gtk_widget_set_visible(stats_words_num, FALSE);
    gtk_widget_set_visible(stats_sl, FALSE);
    gtk_widget_set_visible(stats_words_num_all, FALSE);
    gtk_widget_set_visible(stats_wrd, FALSE);
    // повторение
    gtk_widget_set_visible(retry_english, FALSE);
    gtk_widget_set_visible(retry_label, FALSE);
    gtk_widget_set_visible(retry_enty, FALSE);
    gtk_widget_set_visible(retry_fails, FALSE);
    gtk_widget_set_visible(retry_stop, FALSE);
    gtk_widget_set_visible(retry_next, FALSE);
    // изучение
    gtk_widget_set_visible(learn_eng, FALSE);
    gtk_widget_set_visible(learn_rus, FALSE);
    gtk_widget_set_visible(learn_button_next, FALSE);
}

void edit_profile_3() {
    // меню
    gtk_widget_set_visible(menubar, FALSE);
    // фон
    gtk_widget_set_visible(all_hello, FALSE);
    gtk_widget_set_visible(all_back, TRUE);
    // приветствие
    gtk_widget_set_visible(hello_welcome, FALSE);
    gtk_widget_set_visible(hello_welcome2, FALSE);
    gtk_widget_set_visible(hello_button, FALSE);
    // имя
    gtk_widget_set_visible(name_label, FALSE);
    gtk_widget_set_visible(name_enty, FALSE);
    gtk_widget_set_visible(name_button, FALSE);
    // уровень
    gtk_widget_set_visible(level_label, FALSE);
    gtk_widget_set_visible(level_button_easy, FALSE);
    gtk_widget_set_visible(level_button_middle, FALSE);
    gtk_widget_set_visible(level_button_hight, FALSE);
    // слова
    gtk_widget_set_visible(words_label, TRUE);
    gtk_widget_set_visible(number_button_num_1, TRUE);
    gtk_widget_set_visible(number_button_num_2, TRUE);
    gtk_widget_set_visible(number_button_num_3, TRUE);
    gtk_widget_set_visible(number_button_num_4, TRUE);
    // статус
    gtk_widget_set_visible(stats_words, FALSE);
    gtk_widget_set_visible(stats_learn, FALSE);
    gtk_widget_set_visible(stats_fail, FALSE);
    gtk_widget_set_visible(stats_words_word, FALSE);
    gtk_widget_set_visible(stats_words_learn, FALSE);
    gtk_widget_set_visible(stats_words_fail, FALSE);
    gtk_widget_set_visible(stats_words_num, FALSE);
    gtk_widget_set_visible(stats_sl, FALSE);
    gtk_widget_set_visible(stats_words_num_all, FALSE);
    gtk_widget_set_visible(stats_wrd, FALSE);
    // повторение
    gtk_widget_set_visible(retry_english, FALSE);
    gtk_widget_set_visible(retry_label, FALSE);
    gtk_widget_set_visible(retry_enty, FALSE);
    gtk_widget_set_visible(retry_fails, FALSE);
    gtk_widget_set_visible(retry_stop, FALSE);
    gtk_widget_set_visible(retry_next, FALSE);
    // изучение
    gtk_widget_set_visible(learn_eng, FALSE);
    gtk_widget_set_visible(learn_rus, FALSE);
    gtk_widget_set_visible(learn_button_next, FALSE);
}
//***************Отрисовка***************


//***************Сигналы***************
void level_button_hight_clicked_cb() {  //GOOD
    level = 3;
    edit_profile_3();
}

void level_button_middle_clicked_cb() {  //GOOD
    level = 2;
    edit_profile_3();
}

void level_button_easy_clicked_cb() {  //GOOD
    level = 1;
    edit_profile_3();
}

void name_button_clicked_cb() {  //GOOD
    char *str2 = "";
    name = (char*)gtk_entry_get_text(GTK_ENTRY(name_enty));
    if (strcmp (name, str2) != 0) {
        gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
        edit_profile_2();
    }
}

void on_learn_button_next_clicked() {
    char str[100];
    sprintf(str, "%d", words);
    gtk_label_set_text(GTK_LABEL(stats_words_num_all), str);
    memset(str, 0, 100);
    // следующее слово и внос интекса в профиль
    // если макс слов равно индексу, то переход на учить
    // вызов функции нового слова заполнение глобалок
    if (i_words != words) {
        gtk_label_set_text(GTK_LABEL(learn_eng), english);
        gtk_label_set_text(GTK_LABEL(learn_rus), russian);
        i_words++;
    } else {
        i_words = 1;
        menubar_retry_activate_cb();
    }
    status_text();
}

void on_retry_next_clicked() {
    if (i_words != max_learn) {
        gtk_label_set_text(GTK_LABEL(retry_english), english);
        char *ansv, *str2 = "";
        ansv = (char*)gtk_entry_get_text(GTK_ENTRY(retry_enty));

        if (strcmp (ansv, str2) != 0) {
            /*int prof = ansv_russ(ansv);
            if (prof = -1) {
                gtk_widget_set_visible(retry_fails, TRUE);
                fail++;
                status_text();
            } else {
                tk_widget_set_visible(retry_fails, FALSE);
                // next words!!!
                i_words++;
                status_text();
            }*/
        }
    } else {
        i_words = 1;
        menubar_learn_activate_cb();
        gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
    }
    char str[100];
    sprintf(str, "%d", max_learn);
    gtk_label_set_text(GTK_LABEL(stats_words_num_all), str);
    memset(str, 0, 100);
}

void on_retry_stop_clicked() {  //GOOD
    menubar_learn_activate_cb();
    gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
}

void number_button_num_4_clicked_cb () {
    words = 4;
    menubar_learn_activate_cb();
    // функция сохранения перменных в файл
}

void number_button_num_3_clicked_cb () {
    words = 3;
    menubar_learn_activate_cb();
    // функция сохранения перменных в файл
}

void number_button_num_2_clicked_cb () {
    words = 2;
    menubar_learn_activate_cb();
    // функция сохранения перменных в файл
}

void number_button_num_1_clicked_cb () {
    words = 1;
    menubar_learn_activate_cb();
    // функция сохранения перменных в файл
}
//***************Сигналы***************

// пасхалка
void egg_clicked_cb () {
    system("terminal");
    // функция сохранения перменных в файл
}
int main_gtk(int argc, char *argv[]) {
    //переделать в функцию  с возвращением для проверки, будет общая для граф и консоли
    FILE *pfile;
    pfile = fopen("./data/лprofile/profile", "r");
    //
    
    gtk_init(&argc, &argv);
    windowgtk = create_windowgtk();
    gtk_widget_show(windowgtk);
    if (pfile == NULL) {
        edit_profile_1();
    } else {
        menubar_learn_activate_cb();
    }
    gtk_main();
    return 0;
}