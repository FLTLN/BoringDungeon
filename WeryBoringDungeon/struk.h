#ifndef _STRUK_

typedef struct koordinats
{
	int x;
	int y;
}KOORDINATS;

typedef struct boring
{
	int value;
	int change;
	int max_val;
}BORING;


typedef struct character
{
	KOORDINATS* koord_char;
	BORING* boring_par;
}CHARACTER;

typedef struct event
{
	KOORDINATS koord_event;
	int effect;
	char message[1000];
}EVENT;

#endif // STRUK
