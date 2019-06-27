#ifndef __STRUK_
#define __STRUK_

typedef struct coordinates
{
	int x;
	int y;
}COORDINATES;

typedef struct boring
{
	int value;
	int change;
	int max_val;
}BORING;


typedef struct character
{
	COORDINATES* koord_char;
	BORING* boring_par;
}CHARACTER;

typedef struct event
{
	COORDINATES koord_event;
	int effect;
	char message[1000];
}EVENT;

void right(CHARACTER* current_location);
void left(CHARACTER* current_location);
void down(CHARACTER* current_location);
void up(CHARACTER* current_location);
void boring_change(CHARACTER* boring_val);
void boring_change_event(CHARACTER* boring_val, int change);
CHARACTER * character_init();
int is_bored(CHARACTER * character);

#endif // STRUK
