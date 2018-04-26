#include <stdio.h>
#include "logic.h"


void menu_first() {
	int m = -1;
	while((m < 1) || (m > 5)) {
		printf("1 - View profile\n2 - Next card\n3 - Set level\n4 - Show level\n5 - Exit\n");
		scanf("%d",&m);
	}
	char buf[128];
	char a = 'r';
	int lvl;
	switch(m) {
		case 1:
		view_profile();
		break;

		case 2:
		get_next_raund();
		printf("%s\n", get_eng());
		scanf("%s",buf);

		if(check_answer(buf) == 0) {
			printf("Верно!\n");
			count_answer_up();
			count_answer_row_up();
			show_answer();

			if(check_next_lvl() == 0) {
				while((a != 'y') && (a != 'n')) {
					printf("To the next level? [y/n]\n");
					scanf("%c",&a);
				}
				if(a == 'y') {
					if(lvl_up() == 0) {
						reset_count_answer_row();
						load_level();
						printf("123\n");
					}
				}
			}
		}
		else {
			printf("Неверно!\n");
			show_answer();
			reset_count_answer_row();
		}
		count_try_up();
		break;

		case 3:
		printf("Enter new level:\n");
		scanf("%d", &lvl);
		set_current_level(lvl);
		load_level();
		reset_count_answer_row();
		break;

		case 4:
		show_lvl();
		break;

		case 5:
		save_progress();
		exit(0);
		break;

		//case 6:
		//save_progress();
		///help();
		//break;

		default:
		break;
	}
}


int main (int argc, char** argv) {
	load_progress();
	load_level();
	for(;;) {
		menu_first();
	}
	return 0;
}