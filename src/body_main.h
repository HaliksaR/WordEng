#ifndef __BODY_MAIN_H__
#define __BODY_MAIN_H__

int learn_rand();
int retry_rand();
int retry_rus(wchar_t *ansv);
void save_profile(int num);
int load_profile();
int load_max_index();
wchar_t * to_lowercase(wchar_t *word);
void delete_index_profile();

#endif