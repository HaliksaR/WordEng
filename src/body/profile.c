#include "profile.h"

struct Profile* create_new_profile(const char* path) {
	if(path == NULL) {
		return NULL;
	}

	size_t path_len = strlen(path);

	if(path_len == 0) {
		return NULL;
	}

	struct Profile* profile = (struct Profile*) malloc(sizeof(struct Profile));

	if(profile == NULL) {
		return NULL;
	}

	profile->level = 1;
	profile->cur_level = 1;
	profile->count_a = 0;
	profile->count_ar = 0;
	profile->count_t = 0;


	if(save_profile(profile, path) != 0){
		free(profile);
		return NULL;
	}
	return profile;
}


struct Profile* load_profile(const char* path) {
	if(path == NULL) {
		return NULL;
	}

	size_t path_len = strlen(path);

	if(path_len == 0) {
		return NULL;
	}

	FILE* pFile = fopen(path, "rb");

	if(pFile == NULL) {
		return NULL;
	}

	struct Profile* profile = (struct Profile*) malloc(sizeof(struct Profile));

	if(profile == NULL) {
		fclose(pFile);
		return NULL;
	}


	if(!fread(profile, sizeof(struct Profile), 1, pFile)) {
		free(profile);
		fclose(pFile);
		return NULL;
	}

	fclose(pFile);
	return profile;
}

int save_profile(struct Profile* profile, const char* path) {
	if((profile == NULL) || (path == NULL)) {
		return -1;
	}

	if(strlen(path) == 0) {
		return -2;
	}

	FILE* pFile = fopen(path, "wb");

	if(pFile == NULL) {
		return -3;
	}

	if(fwrite(profile, sizeof(struct Profile), 1, pFile) == 0) {
		fclose(pFile);
		return -4;
	}
	fclose(pFile);

	return 0;
}

void show_profile(struct Profile* profile) {
	printf("level = %d\ncurrent level = %d\ncount answer = %d\ncount answer in a raw = %d\ncount try = %d\n",
		profile->level, profile->cur_level, profile->count_a, profile->count_ar, profile->count_t);
}