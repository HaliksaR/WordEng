#include "db.h"


struct DB* read_db_from_file(const char* path){
	FILE* pFile = fopen(path, "r");

	if(pFile == NULL) {
		return NULL;
	}

	struct DB* db = (struct DB*) malloc(sizeof(struct DB));
	if(db == NULL) {
		fclose(pFile);
		return NULL;
	}

	fwscanf(pFile, L"%d\n", &(db->size));
	if(db->size <= 0) {
		fclose(pFile);
		free(db);
		return NULL;
	}
	struct DB_NODE* p = NULL;
	struct DB_NODE* pt;
	db->db_node = NULL;

	char buf[BUF_SIZE];
	char* pch;
	
	//Парсер строк файла (уродство, по хорошему бы переделать, strtok с кириллицей не работает, но это рабоает)
	for(int i = 0; i < (db->size); ++i) {
		if(p == NULL) {
			p = (struct DB_NODE*) malloc(sizeof(struct DB_NODE));
			db->db_node = p;
		}
		else {
			p->next = (struct DB_NODE*) malloc(sizeof(struct DB_NODE));
			p = p->next;
		}
		
		p->next = NULL;
		fgets(buf, BUF_SIZE, pFile);
		pch = buf;
		int j;
		for(j = 0; (j < BUF_SIZE) || (buf[j] != '\n') || (buf[j] != '\0'); ++j) {
			if(buf[j] == ';') {
				buf[j] = '\0';
				break;
			}
		}

		sscanf(pch, "%d",&(p->rus_size));

		++j;
		pch = &buf[j];
		for(; (j < BUF_SIZE) || (buf[j] != '\n') || (buf[j] != '\0'); ++j) {
			if(buf[j] == ';') {
				buf[j] = '\0';
				break;
			}
		}

		p->english = (char*) malloc(sizeof(char) * (strlen(pch) + 1));
		memcpy(p->english, pch, strlen(pch) + 1);

		p->russian = (char**)malloc(sizeof(char*) * p->rus_size);
		for(int k = 0; k < p->rus_size; ++k) {
			++j;
			pch = &buf[j];
			for(; (j < BUF_SIZE) || (buf[j] != '\0'); ++j) {
				if((buf[j] == ';') || (buf[j] == '\n')) {
					buf[j] = '\0';
					break;
				}
			}

			
			p->russian[k] = (char*) malloc(sizeof(char) * (strlen(pch) + 1));
			memcpy(p->russian[k], pch, strlen(pch) + 1);
		}

	}

	fclose(pFile);
	return db;
}

void print_node(struct DB* db, int index){
	printf("%s - ", get_node(db, index)->english);
	for(int j = 0; j < get_node(db, index)->rus_size - 1; ++j) {
		printf("%s, ", get_node(db, index)->russian[j]);
	}
	printf("%s\n", get_node(db, index)->russian[get_node(db, index)->rus_size - 1]);
}

void print_db(struct DB* db) {
	for(int i = 0; i < db->size; ++i) {
		print_node(db, i);
	}
}

void free_db(struct DB* db) {
	struct DB_NODE* p = db->db_node;
	struct DB_NODE* tmp = p->next;

	while(p != NULL) {
		tmp = p->next;
		free_node(p);
		free(p);
		p = tmp;
	}
	free(db);
}

struct DB_NODE* get_node(struct DB* db, int index){
	if(index >= db->size) {
		return NULL;
	}
	struct DB_NODE* tmp = db->db_node;
	for(int i = 0; i < index; ++i) {
		tmp = tmp->next;
	}

	return tmp;
}

void free_node(struct DB_NODE* node) {
	free(node->english);
	for(int j = 0; j < node->rus_size; ++j){
		free(node->russian[j]);
	}
	free(node->russian);
}