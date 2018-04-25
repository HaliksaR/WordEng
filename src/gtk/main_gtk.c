#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include <glib.h>


void menubar_about_activate_cb();
void menubar_profile_activate_cb();



static GtkWidget* create_windowgtk(void) {
    GtkWidget *windowgtk;
    GtkBuilder *builder;
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
    g_object_unref(builder);

    return windowgtk;
}

static GtkWidget* create_dialoggtk(void) {
    GtkWidget *dialoggtk;
    GtkBuilder *builder;
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
    GtkWidget *profilegtk;
    GtkBuilder *builder;
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
    GtkWidget *dialoggtk;
    dialoggtk = create_dialoggtk();
    gtk_widget_show(dialoggtk);
}

void main_window_profilegtk() {
    GtkWidget *profilegtk;
    profilegtk = create_profilegtk();
    gtk_widget_show(profilegtk);
}

void on_window_header_delete_event() {
    printf("EXIT");
    gtk_main_quit();
}

void menubar_about_activate_cb() {
    main_dialoggtk();
}
void menubar_profile_activate_cb() {
    main_window_profilegtk();
}

int main (int argc, char *argv[]) {
    GtkWidget *windowgtk;
    gtk_init(&argc, &argv);
    windowgtk = create_windowgtk();
    gtk_widget_show(windowgtk);
    gtk_main();
    return 0;
}
