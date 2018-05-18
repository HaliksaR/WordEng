#ifndef __GTKWIDGETS_H__
#define __GTKWIDGETS_H__

#include <gtk/gtk.h>
#include <glib.h>

    GtkWidget *dialoggtk;
    GtkWidget *profilegtk;
    GtkWidget *windowgtk;
    GtkWidget *massage;

    GtkWidget *header1;
    GtkWidget *profile_name;
    GtkWidget *profile_level;
    GtkWidget *profile_words;
    GtkWidget *profile_fail;

    /****МЕНЮ****/
    GtkWidget *menubar;
    /* HIDE / SHOW!!!
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
    GtkWidget *levelup;

    GtkBuilder *builder;
    
#endif