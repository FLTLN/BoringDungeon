#include "graphicsOutput.h"

void prepare_textures(GAMESPASE * gamespase)
{
	int i, j;
	
	gamespase->path = new Texture();
	gamespase->wall = new Texture();
	gamespase->step_d = new Texture();
	gamespase->step_u = new Texture();
	gamespase->step_l = new Texture();
	gamespase->step_r = new Texture();
	if (!(gamespase->wall)->loadFromFile("textures/wall.png"))
	{
		printf("unable to load texture!");
	}
	(gamespase->path)->loadFromFile("textures/path.png");
	(gamespase->step_d)->loadFromFile("textures/step_d.png");
	(gamespase->step_l)->loadFromFile("textures/step_l.png");
	(gamespase->step_r)->loadFromFile("textures/step_r.png");
	(gamespase->step_u)->loadFromFile("textures/step_u.png");
	

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			(*(gamespase->sprites + i * 9 + j)).setPosition(float(i*100),float(j*100));
		}
	}
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
			(*(gamespase->sprites + i)).setTexture(*gamespase->wall);
			break;
		}
		case ' ':
		{
			(*(gamespase->sprites + i)).setTexture(*gamespase->path);
			break;
		}
		case 'd':
		{
			(*(gamespase->sprites + i)).setTexture(*gamespase->step_d);
			break;
		}
		case 'u':
		{
			(*(gamespase->sprites + i)).setTexture(*gamespase->step_u);
			break;
		}
		case 'r':
		{
			(*(gamespase->sprites + i)).setTexture(*gamespase->step_r);
			break;
		}
		case 'l':
		{
			(*(gamespase->sprites + i)).setTexture(*gamespase->step_l);
			break;
		}

		default:
			break;
		}
	}

	(*(gamespase->sprites + 4*9+4)).setTexture(gamespase->player);
}

void draw_all(GAMESPASE * gamespase, sf::Shader* shader)
{
	int i;
	for (i = 0; i < 9 * 9; i++)
	{
		(*(gamespase->window)).draw(*(gamespase->sprites + i), shader);
	}
}

int check(P_POS pos, char * plase)
{
	if (*(plase + pos.x * 9 + pos.y) == '#') return 0;
	else return 1;
}

int check_full(P_POS pos, char * plase,PAR * par)
{
	if (pos.x * par->H + pos.y > par->H*par->W) return 0;
	if (pos.x * par->H + pos.y < 0) return 0;
	if (*(plase + pos.x * par->H + pos.y) == '#') return 0;
	else return 1;
}

void refresh_array(P_POS old_p, P_POS new_p, char * plase)
{
	*(plase + old_p.x * 9 + old_p.y) = ' ';
	*(plase + new_p.x * 9 + new_p.y) = '@';
}
