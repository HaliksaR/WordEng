#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include <glib.h>


void on_learn_button_next_clicked();
void on_retry_next_clicked();
void on_retry_stop_clicked();
void on_number_button_num_4_clicked();
void on_number_button_num_3_clicked();
void on_number_button_num_2_clicked();
void on_number_button_num_1_clicked();
void on_level_button_hight_clicked();
void on_level_button_middle_clicked();
void on_level_button_easy_clicked();
void on_name_button_clicked();
void on_hello_button_clicked();
void on_menubar_about_about_activate();
void on_menubar_profile_activate();
void on_menubar_retry_activate();
void on_menubar_learn__activate();


static GtkWidget* create_window(void) {
    GtkWidget *window;
    GtkBuilder *builder;
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

    window = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
    if (!window) {
        g_critical("Ошибка при получении виджета окна");
    }
    g_object_unref(builder);

    return window;
}

static GtkWidget* create_dialog(void) {
    GtkWidget *dialog;
    GtkBuilder *builder;
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
        
    dialog = GTK_WIDGET(gtk_builder_get_object(builder, "dialog"));
    if (!dialog) {
        g_critical("Ошибка при получении виджета окна");
    }
    g_object_unref(builder);

    return dialog;
}

static GtkWidget* create_profile(void) {
    GtkWidget *profile;
    GtkBuilder *builder;
    GError* error = NULL;

    builder = gtk_builder_new ();
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
        
    profile = GTK_WIDGET(gtk_builder_get_object (builder, "profile"));
    if (!profile) {
        g_critical("Ошибка при получении виджета окна");
    }
    g_object_unref(builder);

    return profile;
}

void main_dialog() {
    GtkWidget *dialog;
    dialog = create_dialog();
    gtk_widget_show(dialog);
}

void main_window_profile() {
    GtkWidget *profile;
    profile = create_profile();
    gtk_widget_show(profile);
}

void on_window_header_delete_event() {
    printf("EXIT");
    gtk_main_quit();
}

void on_menubar_about_about_activate() {
    main_dialog();
}
void on_menubar_profile_activate() {
    main_window_profile();
}

int main (int argc, char *argv[]) {
    GtkWidget *window;
    gtk_init(&argc, &argv);
    window = create_window();
    gtk_widget_show(window);
    gtk_main();
    return 0;
}