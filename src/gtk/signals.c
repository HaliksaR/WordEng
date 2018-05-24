#include "../global.h"
#include "headers/gtkwidgets.h"
#include "../body_main.h"
#include "headers/main_gtk.h"
#include "headers/rendering.h"

//***************Сигналы***************
void level_button_hight_clicked_cb() {  //GOOD
    level = 3;
    if (load_max_index() == -1) {
        wprintf(L"ERROR OPEN DATA!\n");
        gtk_main_quit();
    }
    edit_profile_3();
}

void level_button_middle_clicked_cb() {  //GOOD
    level = 2;
    if (load_max_index() == -1) {
        wprintf(L"ERROR OPEN DATA!\n");
        gtk_main_quit();        
    }
    edit_profile_3();
}

void level_button_easy_clicked_cb() {  //GOOD
    level = 1;
    if (load_max_index() == -1) {
        wprintf(L"ERROR OPEN DATA!\n");
        gtk_main_quit();        
    }
    edit_profile_3();
}

void name_button_clicked_cb() {  //GOOD
    char *str2 = "";
    char *ansv = (char*) gtk_entry_get_text(GTK_ENTRY(name_enty));
    name = to_lowercase((wchar_t*)g_utf8_to_ucs4_fast(ansv, -1, NULL));
    name[0] = towupper(name[0]);
    if (strcmp(ansv, str2) != 0) {
        gtk_entry_set_text(GTK_ENTRY(name_enty), "");
        edit_profile_2();
    }
}

int del = 4;

void on_learn_button_next_clicked() {
    if (max_learn == max_index) {
        save_profile(1);
        load_profile();
        menubar_retry_activate_cb();
        gtk_widget_set_sensitive(menubar_learn, FALSE);
        gtk_widget_set_visible(menubar_learn, FALSE);
        gtk_widget_set_visible(retry_stop, FALSE);
        del = 1;
        return;
    }
    if (max_learn < words) {
        gtk_widget_set_visible(menubar_retry, FALSE);
    } else {
        gtk_widget_set_sensitive(menubar_retry, TRUE);
        gtk_widget_set_visible(menubar_retry, TRUE);
    }
    if (correct_index() != 0) {
        return;
    }
    char *str = (char*) malloc(sizeof(char) * 1000);
    sprintf(str, "%d", words);
    gtk_label_set_text(GTK_LABEL(stats_words_num_all), str);
    memset(str, 0, 1000);
    if (i_words != words) {
        i_words++;
        learn_rand_up_label();
    } else {
        i_words = 1;
        menubar_retry_activate_cb();
    }
    status_text();
    free(str);
}

int on_retry_next_clicked() {
    if (i_words == max_learn && del != 1) {
        i_words = 1;
        menubar_learn_activate_cb();
        gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
        return 0;
    }
    if (i_words == (max_learn / 2) && max_index == max_learn) {
        menubar_learn_activate_cb();
        correct_index();
        del = 4;
        return 0;
    }
    //wprintf(L"%d --", max_learn);
    char *str = (char*) malloc(sizeof(char) * 1000);
    wcstombs(str, english, sizeof(wchar_t) * wcslen(english) + 1);
    gtk_label_set_text(GTK_LABEL(retry_english), str);
    char *str2 = "";
    char *ansv = (char*) gtk_entry_get_text(GTK_ENTRY(retry_enty));
    wchar_t *wword = to_lowercase((wchar_t*)g_utf8_to_ucs4_fast(ansv, -1, NULL));
    if (strcmp(ansv, str2) != 0) {
        if (retry_rus(wword) == -1) {
            gtk_widget_set_visible(retry_fails, TRUE);
            chanse++;
            if (chanse == 5) {
                fail++;
                chanse = 0;
                delete_index_profile();
                retry_rand_up_label();
            }
        } else {
            chanse = 0;
            retry_rand_up_label();
            gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
            gtk_widget_set_visible(retry_fails, FALSE);
            i_words++;
        }
        sprintf(str, "%d", max_learn);
        gtk_label_set_text(GTK_LABEL(stats_words_num_all), str);
    } else {
        return 0;
    }
    if (i_words > max_learn) {
        i_words = 1;
        menubar_learn_activate_cb();
        gtk_entry_set_text(GTK_ENTRY(retry_enty),"");
        return 0;
    }
    free(str);
    status_text();
    if (i_words > (max_learn / del) && (i_words <= 1 && chanse == 0)) {
        gtk_widget_set_visible(menubar_learn, TRUE); 
        gtk_widget_set_visible(retry_stop, TRUE);
    } else {
        gtk_widget_set_sensitive(menubar_learn, FALSE);
        gtk_widget_set_visible(menubar_learn, FALSE);
        gtk_widget_set_visible(retry_stop, FALSE);        
    }
    return 0;
}

void on_retry_stop_clicked() {  //GOOD
    if (i_words > (max_learn / del) || (i_words == 1 && chanse == 0)) {
        menubar_learn_activate_cb();
    }
}

void number_button_num_4_clicked_cb () {  //GOOD
    words = 4;
    save_profile(0);
    menubar_learn_activate_cb();
}

void number_button_num_3_clicked_cb () {  //GOOD
    words = 3;
    save_profile(0);
    menubar_learn_activate_cb();
}

void number_button_num_2_clicked_cb () {  //GOOD
    words = 2;
    save_profile(0);
    menubar_learn_activate_cb();
}

void number_button_num_1_clicked_cb () {  //GOOD
    words = 1;
    save_profile(0);
    menubar_learn_activate_cb();
}

void egg_clicked_cb () {

}