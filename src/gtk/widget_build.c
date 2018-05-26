#include "headers/gtkwidgets.h"

void widget_build() {
    windowgtk = GTK_WIDGET(gtk_builder_get_object(builder, "windowgtk"));
    if (!windowgtk) {
        g_critical("Ошибка при получении виджета windowgtk");
    }
    menubar = GTK_WIDGET(gtk_builder_get_object(builder, "menubar"));
    if (!menubar) {
        g_critical("Ошибка при получении виджета menubar");
    }
    menubar = GTK_WIDGET(gtk_builder_get_object(builder, "menubar"));
    if (!menubar) {
        g_critical("Ошибка при получении виджета menubar");
    }
    menubar_learn = GTK_WIDGET(gtk_builder_get_object(builder, "menubar_learn"));
    if (!menubar_learn) {
        g_critical("Ошибка при получении виджета menubar_learn");
    }
    menubar_retry = GTK_WIDGET(gtk_builder_get_object(builder, "menubar_retry"));
    if (!menubar_retry) {
        g_critical("Ошибка при получении виджета menubar_retry");
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
}

void widget_build_profilegtk() {
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
}