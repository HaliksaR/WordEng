#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "db.h"
#include "profile.h"

#define MAX_LEVEL 3

//Пути прописаны в программе, что плохо для тру прогеров, можно придумать какой нибудь конфиг, хотя и так сойдет
static const char* lvl_path = "levels/";
static const char* profile_path = ".cards/";

static struct Profile* profile = NULL;
static struct DB* db = NULL;
static int node_num = -1;

int load_level();
int save_progress();
int get_next_raund();
int set_current_level(unsigned int lvl);
int load_progress();
int check_answer(const char* answer);
int lvl_up();
void count_try_up();
void count_answer_up();
void count_answer_row_up();
void reset_count_answer_row();
int view_profile();
char* get_eng();
int check_next_lvl();

//Нужно сделать сериализацию
void show_answer();
void show_lvl();

#endif