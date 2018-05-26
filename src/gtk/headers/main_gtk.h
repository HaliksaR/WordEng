#ifndef __MAIN_GTK_H__
#define __MAIN_GTK_H__

#include "../../global.h"

int main_gtk(int argc, char *argv[]);
void main_dialoggtk();
void main_window_profilegtk();
void main_window_massage(int i);
void on_massage_destroy();
void status_text();
int correct_index();
void windowgtk_destroy_cb();
void on_header_destroy();
void menubar_about_activate_cb();
void menubar_profile_activate_cb();
void learn_rand_up_label();
void retry_rand_up_label();

#endif