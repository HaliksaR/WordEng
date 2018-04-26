#include "logic.h"

int load_level() {
	if(db != NULL) {
		free_db(db);
	}

	char buf[128];
	sprintf(buf, "%slevel%d.txt", lvl_path, profile->cur_level);
	//printf("%s\n", buf);
	db = read_db_from_file(buf);
	if(db == NULL) {
		return -1;
	}

	return 0;
}
int save_progress() {
	char buf[128];
	char log[128];
	getlogin_r(log,128);
	sprintf(buf, "%s.%s", profile_path, log);
	return save_profile(profile, buf);
}

int load_progress() {
	char buf[128];
	/*char login[128];
	getlogin_r(login,128);*/
	char* login = getenv("LOGNAME");
	printf("%s\n",login);
	sprintf(buf, "%s.%s", profile_path, login);
	printf("%s\n",buf);

	if(profile != NULL) {
		free(profile);
	}

	profile = load_profile(buf);

	if(profile == NULL) {
		profile = create_new_profile(buf);
	}

	if(profile == NULL) {
		return -1;
	}

	return 0;
}

int get_next_raund() {
	if(db == NULL) {
		return -1;
	}
	node_num = rand() % db->size;
	return 0;

}

int set_current_level(unsigned int lvl){
	if(profile == NULL) {
		return -1;
	}
	if(profile->level < lvl) {
		return -2;
	}
	profile->cur_level = lvl;
	return 0;
}

int check_answer(const char* answer) {
	if(node_num < 0) {
		return -1;
	}

	if(db == NULL) {
		return -2;
	}

	for(int i = 0; i  < get_node(db, node_num)->rus_size; ++i) {
		if(memcmp(answer, get_node(db, node_num)->russian[i],
			(strlen(answer) > strlen(get_node(db, node_num)->russian[i])) ? strlen(get_node(db, node_num)->russian[i]) : strlen(answer)) == 0) {
			return 0;
		}
	}
	return -3;
}

int lvl_up() {
	if(profile->cur_level > MAX_LEVEL) {
		return -1;
	}
	profile->cur_level++;
	if(profile->cur_level > profile->level) {
		profile->level = profile->cur_level;
	}
	return 0;
}

void count_try_up() {
	profile->count_t++;
}

void count_answer_up() {
	profile->count_a++;	
}

void count_answer_row_up() {
	profile->count_ar++;
}
void reset_count_answer_row() {
	profile->count_ar = 0;
}


int view_profile() {
	if(profile == NULL) {
		return -1;
	}
	show_profile(profile);
	return 0;
}

char* get_eng() {
	return get_node(db, node_num)->english;
}

int check_next_lvl() {
	if(profile->count_ar > 10) {
		return 0;
	}
	return -1;
}

void show_answer(){
	print_node(db, node_num);
}

void show_lvl(){
	print_db(db);
}