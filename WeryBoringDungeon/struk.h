#ifndef _STRUK_

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

#endif // STRUK
