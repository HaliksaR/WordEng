#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <ctype.h>

#include "gtkwidgets.h"
#include "widget_build.h"


static GtkWidget* create_windowgtk(void) {
    GError* error = NULL;

    builder = gtk_builder_new();
    if (!gtk_builder_add_from_file(builder, "./src/gtk/style/style.glade", &error)) {
        g_critical("Не могу загрузить файл: %s", error->message);
        g_error_free(error);
    }
    GFile *file= g_file_new_for_path("./src/gtk/style/style.css");
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

static GtkWidget* create_dialoggtk(void) {
    GError* error = NULL;

    builder = gtk_builder_new ();
    if (!gtk_builder_add_from_file (builder, "./src/gtk/style/style.glade", &error)) {
        g_critical("Не могу загрузить файл: %s", error->message);
        g_error_free(error);
    }
    GFile *file= g_file_new_for_path("./src/gtk/style/style.css");
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
    if (!gtk_builder_add_from_file(builder, "./src/gtk/style/style.glade", &error)) {
        g_critical("Не могу загрузить файл: %s", error->message);
        g_error_free(error);
    }
    GFile *file= g_file_new_for_path("./src/gtk/style/style.css");
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

//********ФУНКЦИЯ ЗАПОЛНЕНИЯ LABEL*******
void status_text() {
    int in = 54354;
    char str[7];
    sprintf(str, "%d", in);
    gtk_label_set_text(GTK_LABEL(stats_words_word), str);
}

void menubar_learn_activate_cb() {
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
}

void menubar_retry_activate_cb() {
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
    char *input2, *str2 = "";
    input2 = (char*)gtk_entry_get_text(GTK_ENTRY(name_enty));
    if (strcmp (input2, str2) != 0) {
        g_print("Hostname: %s\n", input2);
        gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
        edit_profile_2();
    }
}

void on_retry_next_clicked() {
    char *input2, *str2 = "", *ansv = "заяц";
    input2 = (char*)gtk_entry_get_text(GTK_ENTRY(retry_enty));
    for (int i = 0; i < sizeof(input2) - 1; i++) {
        input2[i] = tolower(input2[i]);
    }
    if (strcmp (input2, str2) != 0) {
        if (strcmp (input2, ansv) != 0) {
            gtk_widget_set_visible(retry_fails, TRUE);
        } else {
            gtk_widget_set_visible(retry_fails, FALSE);
        }
        printf("Words: %s\n", input2);
        gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
    }
}

void on_retry_stop_clicked() {
    menubar_learn_activate_cb();
    gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
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