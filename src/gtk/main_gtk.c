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

    windowgtk = GTK_WIDGET (gtk_builder_get_object (builder, "windowgtk"));
    if (!windowgtk) {
        g_critical("Ошибка при получении виджета окна");
    }
    learn_eng = GTK_WIDGET (gtk_builder_get_object (builder, "learn_eng"));
    if (!learn_eng) {
        g_critical("Ошибка при получении виджета окна");
    }
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
        g_critical("Ошибка при получении виджета окна");
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
        
    profilegtk = GTK_WIDGET(gtk_builder_get_object (builder, "profilegtk"));
    if (!profilegtk) {
        g_critical("Ошибка при получении виджета окна");
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
    gtk_widget_set_visible(learn_eng, FALSE);
}

void on_retry_stop_clicked () { 
    gtk_widget_set_visible(learn_eng, TRUE);
}
int main (int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    windowgtk = create_windowgtk();
    gtk_widget_show(windowgtk);
    gtk_main();
    return 0;
}
