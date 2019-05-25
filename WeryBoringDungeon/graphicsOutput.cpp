#include "graphicsOutput.h"

void prepare_textures(GAMESPASE * gamespase)
{
	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			(*(gamespase->sprites + i * 9 + j)).setPosition(float(i*100),float(j*100));
		}
	}

	(gamespase->wall).loadFromFile("textures/wall.png");
	(gamespase->path).loadFromFile("textures/path.png");
	(gamespase->player).loadFromFile("textures/player.png");
}

void refresh_textures(GAMESPASE * gamespase, char * plase)
{
	int i;
	for (i = 0; i < 9 * 9; i++)
	{
		switch (*(plase + i))
		{
		case '#':
		{
			(*(gamespase->sprites + i)).setTexture(gamespase->wall);
			break;
		}
		case ' ':
		{
			(*(gamespase->sprites + i)).setTexture(gamespase->path);
			break;
		}

		case '@':
		{
			(*(gamespase->sprites + i)).setTexture(gamespase->player);
			break;
		}

		default:
			break;
		}
	}
}

void draw_all(GAMESPASE * gamespase)
{
	int i;
	for (i = 0; i < 9 * 9; i++)
	{
		(*(gamespase->window)).draw(*(gamespase->sprites + i));
	}
}

int check(P_POS pos, char * plase)
{
	if (*(plase + pos.x * 9 + pos.y) == '#') return 0;
	else return 1;
}

void refresh_array(P_POS old_p, P_POS new_p, char * plase)
{
	*(plase + old_p.x * 9 + old_p.y) = ' ';
	*(plase + new_p.x * 9 + new_p.y) = '@';
}