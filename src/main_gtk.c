#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include <glib.h>


// signals
// overlays
void overlay_get_child_position_cb();
void main_get_child_position_cb();
void profile_get_child_position_cb();

// overlay hello
void start_button_clicked_cb();

// overlay name
void button_name_clicked_cb();

// overlay numder
void button_num_4_clicked_cb();
void button_num_3_clicked_cb();
void button_num_2_clicked_cb();
void button_num_1_clicked_cb();

// overlay level
void button_hight_clicked_cb();
void button_middle_clicked_cb();
void button_easy_clicked_cb();

// overlay learn
void learn_button_next_clicked_cb();
// learn menu
void menubar_learn_about_about_clicked_activate_cb();
void menubar_learn_profile_activate_cb();
void menubar_learn_retry_activate_cb();
void menubar_learn_learn_activate_cb();

// overlay retry
void retry_next_clicked_cb();
void retry_stop_clicked_cb();
// retry menu
void menubar_retry_about_about_clicked_activate_cb();
void menubar_retry_profile_activate_cb();
void menubar_retry_retry_activate_cb();
void menubar_retry_learn_activate_cb();
// signals


static GtkWidget* create_window (void) {
    GtkWidget *window;
    GtkBuilder *builder;
    GError* error = NULL;

    builder = gtk_builder_new ();
    if (!gtk_builder_add_from_file (builder, "./data/style/style.glade", &error)) {
        g_critical ("Не могу загрузить файл: %s", error->message);
        g_error_free (error);
    }
    GFile *file= g_file_new_for_path("./data/style/style.css");
    GtkCssProvider *provider = gtk_css_provider_new();
    if(!gtk_css_provider_load_from_file(provider, file, &error)) {
        g_warning( "%s", error->message );
        g_error_free( error );
    }
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_builder_connect_signals (builder, NULL);

    window = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
    if (!window) {
        g_critical ("Ошибка при получении виджета окна");
    }
    g_object_unref (builder);

    return window;
}

static GtkWidget* create_dialog(void) {
    GtkWidget *dialog;
    GtkBuilder *builder;
    GError* error = NULL;

    builder = gtk_builder_new ();
    if (!gtk_builder_add_from_file (builder, "./data/style/style.glade", &error)) {
        g_critical ("Не могу загрузить файл: %s", error->message);
        g_error_free (error);
    }
    GFile *file= g_file_new_for_path("./data/style/style.css");
    GtkCssProvider *provider = gtk_css_provider_new();
    if(!gtk_css_provider_load_from_file(provider, file, &error)) {
        g_warning( "%s", error->message );
        g_error_free( error );
    }
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_builder_connect_signals (builder, NULL);
        
    dialog = GTK_WIDGET (gtk_builder_get_object (builder, "dialog"));
    if (!dialog) {
         g_critical ("Ошибка при получении виджета окна");
    }
    g_object_unref (builder);

    return dialog;
}

void main_dialog() {
    GtkWidget *dialog;
    dialog = create_dialog ();
    gtk_widget_show (dialog);
}

void on_window_header_delete_event() {
    printf("EXIT");
    gtk_main_quit();
}

int main (int argc, char *argv[]) {
    GtkWidget *window;
    gtk_init (&argc, &argv);
    window = create_window ();
    gtk_widget_show (window);
    main_dialog();
    gtk_main ();
    return 0;
}
