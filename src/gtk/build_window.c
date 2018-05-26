#include "headers/build_window.h"


GtkWidget* create_windowgtk(void) {
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

GtkWidget* create_massage(void) {
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

GtkWidget* create_dialoggtk(void) {
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

GtkWidget* create_profilegtk(void) {
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