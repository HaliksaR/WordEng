#ifndef PROFILE_H
#define PROFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Профиль пользователя
struct Profile {
	unsigned int level; //Максимальный уровень level 
	unsigned int cur_level; //Текущий уровень current level 
	unsigned int count_a; //Количество правильных ответов cout answer
	unsigned int count_t; //Количество попыток cout try
	unsigned int count_ar; //Количество правильных ответов подряд cout answer in a raw
};
 

int save_profile(struct Profile* profile, const char* path);
struct Profile* create_new_profile(const char* path);
struct Profile* load_profile(const char* path);
//Нужно бы сделать сериализацию
void show_profile(struct Profile* profile);
#endif