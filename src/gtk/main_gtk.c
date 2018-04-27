#include <stdlib.h>
#include <stdio.h> 
#include <gtk/gtk.h>
#include <string.h>
#include <glib.h>

    GtkWidget *dialoggtk;

    GtkWidget *profilegtk;
    GtkWidget *header1;
    GtkWidget *profile_name;
    GtkWidget *profile_level;
    GtkWidget *profile_words;
    GtkWidget *profile_fail;

    GtkWidget *windowgtk;
    /****МЕНЮ****/
    GtkWidget *menubar;
    /*HIDE SHOW!!!
    ****ФОН***/
    GtkWidget *all_hello;
    GtkWidget *all_back;
    /****ОКНО ПРИВЕТСТВИЯ*****/
    GtkWidget *hello_welcome;
    GtkWidget *hello_welcome2;
    GtkWidget *hello_button;
    /****ОКНО ИМЕНИ****/
    GtkWidget *name_label;
    GtkWidget *name_enty;
    GtkWidget *name_button;
    /****ОКНО УРОВНЯ*****/
    GtkWidget *level_label;
    GtkWidget *level_button_easy;
    GtkWidget *level_button_middle;
    GtkWidget *level_button_hight;
    /****ОКНО СЛОВ*****/
    GtkWidget *words_label;
    GtkWidget *number_button_num_1;
    GtkWidget *number_button_num_2;
    GtkWidget *number_button_num_3;
    GtkWidget *number_button_num_4;
    /****СТАТУС****/
    GtkWidget *stats_words;         // СТАТИК
    GtkWidget *stats_learn;         // СТАТИК
    GtkWidget *stats_fail;         // СТАТИК
    /****СТАТУС ПЕРЕМЕННЫЕ****/
    GtkWidget *stats_words_word;
    GtkWidget *stats_words_learn;
    GtkWidget *stats_words_fail;
    GtkWidget *stats_words_num;
    GtkWidget *stats_sl;         // СТАТИК
    GtkWidget *stats_words_num_all;
    GtkWidget *stats_wrd;        //СТАТИК
    /****ОКНО ПОВТОРЕНИЯ*****/
    GtkWidget *retry_english;
    GtkWidget *retry_label;
    GtkWidget *retry_enty;
    GtkWidget *retry_fails;
    GtkWidget *retry_stop;
    GtkWidget *retry_next;
    /****ОКНО УЧИТЬ****/
    GtkWidget *learn_eng;
    GtkWidget *learn_rus;
    GtkWidget *learn_button_next;

    GtkBuilder *builder;


static GtkWidget* create_windowgtk(void) {
    GError* error = NULL;

    builder = gtk_builder_new();
    if (!gtk_builder_add_from_file(builder, "./style/style.glade", &error)) {
        g_critical("Не могу загрузить файл: %s", error->message);
        g_error_free(error);
    }
    GFile *file= g_file_new_for_path("./style/style.css");
    GtkCssProvider *provider = gtk_css_provider_new();
    if(!gtk_css_provider_load_from_file(provider, file, &error)) {
        g_warning("%s", error->message );
        g_error_free(error);
    }
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_builder_connect_signals(builder, NULL);

    windowgtk = GTK_WIDGET(gtk_builder_get_object(builder, "windowgtk"));
    if (!windowgtk) {
        g_critical("Ошибка при получении виджета windowgtk");
    }
    /*********************widgets build for hide and show*********************/
    menubar = GTK_WIDGET(gtk_builder_get_object(builder, "menubar"));
    if (!menubar) {
        g_critical("Ошибка при получении виджета menubar");
    }
    learn_eng = GTK_WIDGET(gtk_builder_get_object(builder, "learn_eng"));
    if (!learn_eng) {
        g_critical("Ошибка при получении виджета learn_eng");
    }
    all_hello = GTK_WIDGET(gtk_builder_get_object(builder, "all_hello"));
    if (!all_hello) {
        g_critical("Ошибка при получении виджета all_hello");
    }
    all_back = GTK_WIDGET(gtk_builder_get_object(builder, "all_back"));
    if (!all_back) {
        g_critical("Ошибка при получении виджета all_back");
    }
    hello_welcome = GTK_WIDGET(gtk_builder_get_object(builder, "hello_welcome"));
    if (!hello_welcome) {
        g_critical("Ошибка при получении виджета hello_welcome");
    }
    hello_button = GTK_WIDGET(gtk_builder_get_object(builder, "hello_button"));
    if (!hello_button) {
        g_critical("Ошибка при получении виджета hello_button");
    }
    name_label = GTK_WIDGET(gtk_builder_get_object(builder, "name_label"));
    if (!name_label) {
        g_critical("Ошибка при получении виджета name_label");
    }
    name_enty = GTK_WIDGET(gtk_builder_get_object(builder, "name_enty"));
    if (!name_enty) {
        g_critical("Ошибка при получении виджета name_enty");
    }
    name_button = GTK_WIDGET(gtk_builder_get_object(builder, "name_button"));
    if (!name_button) {
        g_critical("Ошибка при получении виджета name_button");
    }
    level_label = GTK_WIDGET(gtk_builder_get_object(builder, "level_label"));
    if (!level_label) {
        g_critical("Ошибка при получении виджета level_label");
    }
    level_button_easy = GTK_WIDGET(gtk_builder_get_object(builder, "level_button_easy"));
    if (!level_button_easy) {
        g_critical("Ошибка при получении виджета level_button_easy");
    }
    level_button_middle = GTK_WIDGET(gtk_builder_get_object(builder, "level_button_middle"));
    if (!level_button_middle) {
        g_critical("Ошибка при получении виджета level_button_middle");
    }
    level_button_hight = GTK_WIDGET(gtk_builder_get_object(builder, "level_button_hight"));
    if (!level_button_hight) {
        g_critical("Ошибка при получении виджета level_button_hight");
    }
    number_button_num_1 = GTK_WIDGET(gtk_builder_get_object(builder, "number_button_num_1"));
    if (!number_button_num_1) {
        g_critical("Ошибка при получении виджета number_button_num_1");
    }
    number_button_num_2 = GTK_WIDGET(gtk_builder_get_object(builder, "number_button_num_2"));
    if (!number_button_num_2) {
        g_critical("Ошибка при получении виджета number_button_num_2");
    }
    number_button_num_3 = GTK_WIDGET(gtk_builder_get_object(builder, "number_button_num_3"));
    if (!number_button_num_3) {
        g_critical("Ошибка при получении виджета number_button_num_3");
    }
    number_button_num_4 = GTK_WIDGET(gtk_builder_get_object(builder, "number_button_num_4"));
    if (!number_button_num_4) {
        g_critical("Ошибка при получении виджета number_button_num_4");
    }
    stats_words = GTK_WIDGET(gtk_builder_get_object(builder, "stats_words"));
    if (!stats_words) {
        g_critical("Ошибка при получении виджета stats_words");
    }
    stats_learn = GTK_WIDGET(gtk_builder_get_object(builder, "stats_learn"));
    if (!stats_learn) {
        g_critical("Ошибка при получении виджета stats_learn");
    }
    stats_fail = GTK_WIDGET(gtk_builder_get_object(builder, "stats_fail"));
    if (!stats_fail) {
        g_critical("Ошибка при получении виджета stats_fail");
    }
    stats_words_word = GTK_WIDGET(gtk_builder_get_object(builder, "stats_words_word"));
    if (!stats_words_word) {
        g_critical("Ошибка при получении виджета stats_words_word");
    }
    stats_words_learn = GTK_WIDGET(gtk_builder_get_object(builder, "stats_words_learn"));
    if (!stats_words_learn) {
        g_critical("Ошибка при получении виджета stats_words_learn");
    }
    stats_words_fail = GTK_WIDGET(gtk_builder_get_object(builder, "stats_words_fail"));
    if (!stats_words_fail) {
        g_critical("Ошибка при получении виджета stats_words_fail");
    }
    stats_words_num = GTK_WIDGET(gtk_builder_get_object(builder, "stats_words_num"));
    if (!stats_words_num) {
        g_critical("Ошибка при получении виджета stats_words_num");
    }
    words_label = GTK_WIDGET(gtk_builder_get_object(builder, "words_label"));
    if (!words_label) {
        g_critical("Ошибка при получении виджета words_label");
    }
    stats_wrd = GTK_WIDGET(gtk_builder_get_object(builder, "stats_wrd"));
    if (!stats_wrd) {
        g_critical("Ошибка при получении виджета stats_wrd");
    }
    retry_english = GTK_WIDGET(gtk_builder_get_object(builder, "retry_english"));
    if (!retry_english) {
        g_critical("Ошибка при получении виджета retry_english");
    }
    retry_label = GTK_WIDGET(gtk_builder_get_object(builder, "retry_label"));
    if (!retry_label) {
        g_critical("Ошибка при получении виджета retry_label");
    }
    retry_enty = GTK_WIDGET(gtk_builder_get_object(builder, "retry_enty"));
    if (!retry_enty) {
        g_critical("Ошибка при получении виджета retry_enty");
    }
    retry_fails = GTK_WIDGET(gtk_builder_get_object(builder, "retry_fails"));
    if (!retry_fails) {
        g_critical("Ошибка при получении виджета retry_fails");
    }
    retry_stop = GTK_WIDGET(gtk_builder_get_object(builder, "retry_stop"));
    if (!retry_stop) {
        g_critical("Ошибка при получении виджета retry_stop");
    }
    retry_next = GTK_WIDGET(gtk_builder_get_object(builder, "retry_next"));
    if (!retry_next) {
        g_critical("Ошибка при получении виджета retry_next");
    }
    learn_eng = GTK_WIDGET(gtk_builder_get_object(builder, "learn_eng"));
    if (!learn_eng) {
        g_critical("Ошибка при получении виджета learn_eng");
    }
    learn_rus = GTK_WIDGET(gtk_builder_get_object(builder, "learn_rus"));
    if (!learn_rus) {
        g_critical("Ошибка при получении виджета learn_rus");
    }
    learn_button_next = GTK_WIDGET(gtk_builder_get_object(builder, "learn_button_next"));
    if (!learn_button_next) {
        g_critical("Ошибка при получении виджета learn_button_next");
    }
    profile_name = GTK_WIDGET(gtk_builder_get_object(builder, "profile_name"));
    if (!profile_name) {
        g_critical("Ошибка при получении виджета profile_name");
    }
    header1 = GTK_WIDGET(gtk_builder_get_object(builder, "header1"));
    if (!header1) {
        g_critical("Ошибка при получении виджета header1");
    }
    profile_level = GTK_WIDGET(gtk_builder_get_object(builder, "profile_level"));
    if (!profile_level) {
        g_critical("Ошибка при получении виджета profile_level");
    }
    profile_words = GTK_WIDGET(gtk_builder_get_object(builder, "profile_words"));
    if (!profile_words) {
        g_critical("Ошибка при получении виджета profile_words");
    }
    profile_fail = GTK_WIDGET(gtk_builder_get_object(builder, "profile_fail"));
    if (!profile_fail) {
        g_critical("Ошибка при получении виджета profile_fail");
    }
    hello_welcome2 = GTK_WIDGET(gtk_builder_get_object(builder, "hello_welcome2"));
    if (!hello_welcome2) {
        g_critical("Ошибка при получении виджета hello_welcome2");
    }   

    stats_sl = GTK_WIDGET(gtk_builder_get_object(builder, "stats_sl"));
    if (!stats_sl) {
        g_critical("Ошибка при получении виджета stats_sl");
    } 
    stats_words_num_all = GTK_WIDGET(gtk_builder_get_object(builder, "stats_words_num_all"));
    if (!stats_words_num_all) {
        g_critical("Ошибка при получении виджета stats_words_num_all");
    }
    /*********************widgets build for hide and show*********************/
    g_object_unref(builder);

    return windowgtk;
}

static GtkWidget* create_dialoggtk(void) {
    GError* error = NULL;

    builder = gtk_builder_new ();
    if (!gtk_builder_add_from_file (builder, "./style/style.glade", &error)) {
        g_critical("Не могу загрузить файл: %s", error->message);
        g_error_free(error);
    }
    GFile *file= g_file_new_for_path("./style/style.css");
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

static GtkWidget* create_profilegtk(void) {
    GError* error = NULL;

    builder = gtk_builder_new ();
    if (!gtk_builder_add_from_file(builder, "./style/style.glade", &error)) {
        g_critical("Не могу загрузить файл: %s", error->message);
        g_error_free(error);
    }
    GFile *file= g_file_new_for_path("./style/style.css");
    GtkCssProvider *provider = gtk_css_provider_new();
    if(!gtk_css_provider_load_from_file(provider, file, &error)) {
        g_warning("%s", error->message);
        g_error_free(error);
    }
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_builder_connect_signals(builder, NULL);
        
    profilegtk = GTK_WIDGET(gtk_builder_get_object(builder, "profilegtk"));
    if (!profilegtk) {
        g_critical("Ошибка при получении виджета profilegtk");
    }
    g_object_unref(builder);

    return profilegtk;
}

void main_dialoggtk() {
    dialoggtk = create_dialoggtk();
    gtk_widget_show(dialoggtk);
}

void main_window_profilegtk() {
    profilegtk = create_profilegtk();
    gtk_widget_show(profilegtk);
}

void windowgtk_destroy_cb() {
    gtk_main_quit();
}

void on_header_destroy() {
    gtk_main_quit();
}

void menubar_about_activate_cb() {
    main_dialoggtk();
}

void menubar_profile_activate_cb() {
    main_window_profilegtk();
}

void on_retry_next_clicked () { 
}

void on_retry_stop_clicked () { 
}

void menubar_learn_activate_cb () {
    // меню
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
}

void menubar_retry_activate_cb () {
    // меню
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
    gtk_widget_set_visible(retry_english, TRUE);
    gtk_widget_set_visible(retry_label, TRUE);
    gtk_widget_set_visible(retry_enty, TRUE);
    gtk_widget_set_visible(retry_fails, TRUE);
    gtk_widget_set_visible(retry_stop, TRUE);
    gtk_widget_set_visible(retry_next, TRUE);
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


void level_button_hight_clicked_cb() {
    edit_profile_3();
}
void level_button_middle_clicked_cb() {
    edit_profile_3();
}
void level_button_easy_clicked_cb() {
    edit_profile_3();
}


void name_button_clicked_cb() {
    edit_profile_2();
}


void number_button_num_4_clicked_cb () {
    menubar_learn_activate_cb();
}
void number_button_num_3_clicked_cb () {
    menubar_learn_activate_cb();
}
void number_button_num_2_clicked_cb () {
    menubar_learn_activate_cb();
}
void number_button_num_1_clicked_cb () {
    menubar_learn_activate_cb();
}

int main (int argc, char *argv[]) {
    int i = 0;
    gtk_init(&argc, &argv);
    windowgtk = create_windowgtk();
    gtk_widget_show(windowgtk);
    if (i == 0) {
        edit_profile_1();
    }
    if (i == 1) {
        menubar_learn_activate_cb();
    }
    gtk_main();
    return 0;
}