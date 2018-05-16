#include "../global.h"  // глобальные переменные
#include "gtkwidgets.h"  // Виджеты
#include "widget_build.h"  // билдер
#include "../body_main.h"

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
        g_warning("%s", error->message);
        g_error_free(error);
    }
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_builder_connect_signals(builder, NULL);

    widget_build();

    g_object_unref(builder);

    return windowgtk;
}
static GtkWidget* create_massage(void) {   //GOOD
    GError* error = NULL;

    builder = gtk_builder_new();
    if (!gtk_builder_add_from_file(builder, "./data/style/style.glade", &error)) {
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

    massage = GTK_WIDGET(gtk_builder_get_object(builder, "massage"));
    if (!massage) {
        g_critical("Ошибка при получении виджета massage");
    }
    levelup = GTK_WIDGET(gtk_builder_get_object(builder, "levelup"));
    if (!levelup) {
        g_critical("Ошибка при получении виджета levelup");
    }
    g_object_unref(builder);

    return massage;
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
        g_warning("%s", error->message);
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

void clear_window() {
    // меню
    gtk_widget_set_visible(menubar, FALSE);
    // фон
    gtk_widget_set_visible(all_hello, TRUE);
    gtk_widget_set_visible(all_back, FALSE);
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
    gtk_widget_set_visible(stats_words, FALSE);
    gtk_widget_set_visible(stats_learn, FALSE);
    gtk_widget_set_visible(stats_fail, FALSE);
    gtk_widget_set_visible(stats_words_word, FALSE);
    gtk_widget_set_visible(stats_words_learn, FALSE);
    gtk_widget_set_visible(stats_words_fail, FALSE);
    gtk_widget_set_visible(stats_words_num, FALSE);
    gtk_widget_set_visible(stats_sl, FALSE);
    gtk_widget_set_visible(stats_words_num_all, FALSE);
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

void correct_index() {
    if (max_index == max_learn) {
        if (level != 3) {
            level++;
            if (load_max_index() == -1) {
                wprintf(L"ERROR OPEN DATA!\n");
                gtk_main_quit();
            }
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

void menubar_learn_activate_cb() {
    correct_index();
    i_words = 1;
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
    char *str = (char*) malloc(100);
    sprintf(str, "%d", words);
    gtk_label_set_text(GTK_LABEL(stats_words_num_all), str);
    free(str);
    learn_rand_up_label();
}

void menubar_retry_activate_cb() {
    correct_index();
    i_words = 1;
    chanse = 0;
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
    char *str = (char*) malloc(100);
    sprintf(str, "%d", max_learn);
    gtk_label_set_text(GTK_LABEL(stats_words_num_all), str);
    free(str);
    retry_rand_up_label();
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
    if (load_max_index() == -1) {
        wprintf(L"ERROR OPEN DATA!\n");
        gtk_main_quit();
    }
    edit_profile_3();
}

void level_button_middle_clicked_cb() {  //GOOD
    level = 2;
    if (load_max_index() == -1) {
        wprintf(L"ERROR OPEN DATA!\n");
        gtk_main_quit();        
    }
    edit_profile_3();
}

void level_button_easy_clicked_cb() {  //GOOD
    level = 1;
    if (load_max_index() == -1) {
        wprintf(L"ERROR OPEN DATA!\n");
        gtk_main_quit();        
    }
    edit_profile_3();
}

void name_button_clicked_cb() {  //GOOD
    char *str2 = "";
    char *ansv = (char*) gtk_entry_get_text(GTK_ENTRY(name_enty));
    name = to_lowercase((wchar_t*)g_utf8_to_ucs4_fast(ansv, -1, NULL));
    if (strcmp(ansv, str2) != 0) {
        gtk_entry_set_text(GTK_ENTRY(name_enty), "");
        edit_profile_2();
    }
}


void on_learn_button_next_clicked() {
    correct_index();
    status_text();
    char *str = (char*) malloc(sizeof(char) * 1000);
    sprintf(str, "%d", words);
    gtk_label_set_text(GTK_LABEL(stats_words_num_all), str);
    memset(str, 0, 1000);
    if (i_words != words) {
        i_words++;
        learn_rand_up_label();
    } else {
        i_words = 1;
        menubar_retry_activate_cb();
    }
    free(str);
}

int on_retry_next_clicked() {
    correct_index();
    wprintf(L"%ls\n", russian);
    char *str = (char*) malloc(sizeof(char) * 1000);
    wcstombs(str, english, sizeof(wchar_t) * wcslen(english) + 1);
    gtk_label_set_text(GTK_LABEL(retry_english), str);
    char *str2 = "";
    char *ansv = (char*) gtk_entry_get_text(GTK_ENTRY(retry_enty));
    wchar_t *wword = to_lowercase((wchar_t*)g_utf8_to_ucs4_fast(ansv, -1, NULL));
    if (strcmp(ansv, str2) != 0) {
        if (retry_rus(wword) == -1) {
            gtk_widget_set_visible(retry_fails, TRUE);
            fail++;
            chanse++;
            status_text();
            if (chanse == 5) {
                delete_index_profile();
            }
        } else {
            retry_rand_up_label();
            gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
            gtk_widget_set_visible(retry_fails, FALSE);
            i_words++;
            status_text();
        }
        sprintf(str, "%d", max_learn);
        gtk_label_set_text(GTK_LABEL(stats_words_num_all), str);
    } else {
        return 0;
    }
    if (i_words == max_learn) {
        i_words = 1;
        menubar_learn_activate_cb();
        gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
    }
    free(str);
    return 0;
}

void on_retry_stop_clicked() {  //GOOD
    max_learn++;
    status_text();
    menubar_learn_activate_cb();
    gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
}

void number_button_num_4_clicked_cb () {  //GOOD
    words = 4;
    save_profile(0);
    menubar_learn_activate_cb();
}

void number_button_num_3_clicked_cb () {  //GOOD
    words = 3;
    save_profile(0);
    menubar_learn_activate_cb();
}

void number_button_num_2_clicked_cb () {  //GOOD
    words = 2;
    save_profile(0);
    menubar_learn_activate_cb();
}

void number_button_num_1_clicked_cb () {  //GOOD
    words = 1;
    save_profile(0);
    menubar_learn_activate_cb();
}
//***************Сигналы***************

void egg_clicked_cb () {

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