#include "struk.h"
#include <stdio.h>
#include <malloc.h>


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
	boring_val->boring_par->value += boring_val->boring_par->change;
}

void boring_change_event(CHARACTER* boring_val, int change) {									   //изменение скуки при событии
	boring_val->boring_par->value += change;
}

CHARACTER * character_init()
{
	CHARACTER * new_character = (CHARACTER *)malloc(sizeof(CHARACTER));
	new_character->boring_par = (BORING *)malloc(sizeof(BORING));
	new_character->koord_char = (COORDINATES *)malloc(sizeof(COORDINATES));

	return new_character;
};

int is_bored(CHARACTER * character)
{
	if (character->boring_par->value <= 0) return 0;
	else return 1;
};