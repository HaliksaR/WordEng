#ifndef DB_H
#define DB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 512

struct DB_NODE {
	char* raw_str;
	char* english;
	char** russian;
	int rus_size;
	struct DB_NODE* next;
};

struct DB {
	struct DB_NODE* db_node;
	int size;
};


struct DB* read_db_from_file(const char* path);
void free_db(struct DB* db);
void free_node(struct DB_NODE* node);
struct DB_NODE* get_node(struct DB* db, int index);
//Нужно бы сделать сериализацию
void print_node(struct DB* db, int index);
void print_db(struct DB* db);

#endif