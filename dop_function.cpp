#include "struk.h"
#include <stdio.h>

void change_koord_for_teleport(CHARACTER* current_location, KOORDINATS new_x_y) {
	current_location->koord_char->x = new_x_y.x;
	current_location->koord_char->y = new_x_y.y;
}

void for_file_effects(EVENT_LIST* list_event) {
	char *ptr = new char[1000];
	int i = 0;
	FILE * f = fopen("data.txt", "r");
	while (!feof(f))
	{
		if (fgets(ptr+i, 80, f)) {
			i++;
			list_event->current_event.effect = 1;
		}


	}

}