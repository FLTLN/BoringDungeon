#include "struk.h"
#include <stdio.h>


void right(CHARACTER* current_location) {
	current_location->koord_char->x++;
}

void left(CHARACTER* current_location) {
	current_location->koord_char->x=current_location->koord_char->x - 1;
}

void down(CHARACTER* current_location) {
	current_location->koord_char->y++;
}

void up(CHARACTER* current_location) {
	current_location->koord_char->y = current_location->koord_char->y-1;
}

void boring_change(CHARACTER* boring_val){															//изменение скуки в течение игры
	boring_val->boring_par->value = boring_val->boring_par->value+ boring_val->boring_par->change;
}

void boring_change_event(CHARACTER* boring_val, int change) {									   //изменение скуки при событии
	boring_val->boring_par->value = boring_val->boring_par->value+change;
}
