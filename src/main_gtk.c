#include <gtk/gtk.h>
#include <string.h>

/* создание окна в этот раз мы вынесли в отдельную функцию */
static GtkWidget* create_window (void) {
        /* это виджет окна */
        GtkWidget *window;
        /* это тот волшебный объект, который сделает за нас окошко */
        GtkBuilder *builder;
        /* сюда будем складывать ошибки */
        GError* error = NULL;

        /* тут загружаем файл с интерфейсом */
        builder = gtk_builder_new ();
        if (!gtk_builder_add_from_file (builder, "style.glade", &error))
        {
                /* загрузить файл не удалось */
                g_critical ("Не могу загрузить файл: %s", error->message);
                g_error_free (error);
        }
        GFile *file= g_file_new_for_path("style.css");
        GtkCssProvider *provider = gtk_css_provider_new();
        if(!gtk_css_provider_load_from_file(provider, file, &error))
        {
            g_warning( "%s", error->message );
            g_error_free( error );
        }
        gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
        /* помните, мы подключали сигналы вручную? теперь это происходит автоматически! */
        gtk_builder_connect_signals (builder, NULL);

        /* получаем виджет окна, чтобы его показать */
        window = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
        if (!window)
        {
                /* что-то не так, наверное, ошиблись в имени */
                g_critical ("Ошибка при получении виджета окна");
        }
        g_object_unref (builder);

        return window;
}
static GtkWidget* create_dialog(void) {
        /* это виджет окна */
        GtkWidget *dialog;
        /* это тот волшебный объект, который сделает за нас окошко */
        GtkBuilder *builder;
        /* сюда будем складывать ошибки */
        GError* error = NULL;

        /* тут загружаем файл с интерфейсом */
        builder = gtk_builder_new ();
        if (!gtk_builder_add_from_file (builder, "style.glade", &error))
        {
                /* загрузить файл не удалось */
                g_critical ("Не могу загрузить файл: %s", error->message);
                g_error_free (error);
        }
        GFile *file= g_file_new_for_path("style.css");
        GtkCssProvider *provider = gtk_css_provider_new();
        if(!gtk_css_provider_load_from_file(provider, file, &error))
        {
            g_warning( "%s", error->message );
            g_error_free( error );
        }
        gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
        /* помните, мы подключали сигналы вручную? теперь это происходит автоматически! */
        gtk_builder_connect_signals (builder, NULL);

        /* получаем виджет окна, чтобы его показать */
        dialog = GTK_WIDGET (gtk_builder_get_object (builder, "dialog"));
        if (!dialog)
        {
                /* что-то не так, наверное, ошиблись в имени */
                g_critical ("Ошибка при получении виджета окна");
        }
        g_object_unref (builder);

        return dialog;
}
int main_dialog() {
        GtkWidget *dialog;
        dialog = create_dialog ();
        gtk_widget_show (dialog);
}
/* это главная функция нашего приложения, которая будет выполнена первой */
int main (int argc, char *argv[]) {
        /* виджет окна */
        GtkWidget *window;
        /* запускаем GTK+ */
        gtk_init (&argc, &argv);
        /* вызываем нашу функцию для создания окна */
        window = create_window ();
        gtk_widget_show (window);
        main_dialog();
        /* передаём управление GTK+ */
        gtk_main ();
        return 0;
}
