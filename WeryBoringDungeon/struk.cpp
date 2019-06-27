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
