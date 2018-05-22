#include "../global.h"
#include "headers/gtkwidgets.h"
#include "../body_main.h"
#include "headers/main_gtk.h"
#include "headers/signals.h"

void clear_window() {
    // меню
    gtk_widget_set_visible(menubar, FALSE);
    // фон
    gtk_widget_set_visible(all_hello, TRUE);
    gtk_widget_set_visible(all_back, FALSE);
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
    gtk_widget_set_visible(stats_words, FALSE);
    gtk_widget_set_visible(stats_learn, FALSE);
    gtk_widget_set_visible(stats_fail, FALSE);
    gtk_widget_set_visible(stats_words_word, FALSE);
    gtk_widget_set_visible(stats_words_learn, FALSE);
    gtk_widget_set_visible(stats_words_fail, FALSE);
    gtk_widget_set_visible(stats_words_num, FALSE);
    gtk_widget_set_visible(stats_sl, FALSE);
    gtk_widget_set_visible(stats_words_num_all, FALSE);
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

void menubar_learn_activate_cb() {
    if (correct_index() != 0) {
        return;
    }
    learn_rand_up_label();
    gtk_widget_set_sensitive(menubar_retry, TRUE);
    gtk_widget_set_sensitive(menubar_learn, FALSE);
    i_words = 1;
    status_text();
    gtk_entry_set_text(GTK_ENTRY(retry_enty), "");
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
    char *str = (char *)malloc(100);
    sprintf(str, "%d", words);
    gtk_label_set_text(GTK_LABEL(stats_words_num_all), str);
    free(str);
}

void menubar_retry_activate_cb() {
    retry_rand_up_label();
    gtk_widget_set_sensitive(menubar_retry, FALSE);
    gtk_widget_set_sensitive(menubar_learn, TRUE);
    i_words = 1;
    chanse = 0;
    gtk_entry_set_text(GTK_ENTRY(retry_enty), "");
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
    char *str = (char *)malloc(100);
    sprintf(str, "%d", max_learn);
    gtk_label_set_text(GTK_LABEL(stats_words_num_all), str);
    free(str);
}

void hello_button_clicked_cb() {
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