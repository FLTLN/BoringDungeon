#ifndef __GOUTPUT_
#define __GOUTPUT_

#include <SFML/Graphics.hpp>
using namespace sf;
#include "mazeGenerator.h"


typedef struct gamespase
{
	RenderWindow * window;
	Sprite sprites[81];

	Texture wall;
	Texture path;
	Texture player;

}GAMESPASE;

typedef struct p_pos
{
	int x, y;
}P_POS;

void prepare_textures(GAMESPASE * gamespase);
void refresh_textures(GAMESPASE * gamespase, char * plase);
void draw_all(GAMESPASE * gamespase);
int check(P_POS pos, char * plase);
void refresh_array(P_POS old_p, P_POS new_p, char * plase);
int check_full(P_POS pos, char * plase, PAR * par);

#endif // !__GOUTPUT_
