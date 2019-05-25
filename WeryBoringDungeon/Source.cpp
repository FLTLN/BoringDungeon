#include "mazeGenerator.h"
#include "mazeTestPrinter.h"
#include <stdlib.h>
#include <time.h>
#include "graphicsOutput.h"
#include <SFML/Graphics.hpp>
using namespace sf;


void main()
{
	srand(time(NULL));
	PAR maze_par;

	Clock clock;
	//float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах

	RenderWindow window(sf::VideoMode(900, 900), "Boring Dungeon 0.01");
	GAMESPASE spase;
	spase.window = &window;
	prepare_textures(&spase);

	char example[] = { "#########" 
					   "#    #  #"
					   "#       #"
					   "#    #  #"
					   "#   @   #"
					   "#       #"
					   "#    ####"
					   "#       #" 
					   "#########" };

	P_POS pos;

	pos.x = 5;
	pos.y = 5;

	P_POS pos_new;

	maze_par.W = 40;
	maze_par.H = 55;

	maze_par.max_W = 15;
	maze_par.max_H = 15;


	create_Rooms_List(&maze_par); //Create list with rooms courners

	link_Rooms(&maze_par); //Linking rooms with their neihbourhoods

	char * mazeArray = create_Maze_Array(&maze_par);

	//output_TXT(mazeArray, &maze_par, "maze.txt");

	//char * test_display_output;
	//TESTPAR console_display_par;
	//console_display_par.W = 999;
	//console_display_par.H = 999;
	// char * someFunction(char *, POINT *)
	//test_display_output = some_function(mazeArray,playerPosition)
	//output_test_TXT(test_display_output,console_display_par,"name.txt")

	int can_move = 0;

	clock.restart();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//window.draw(herosprite);//выводим спрайт на экран

		refresh_textures(&spase, example);
		draw_all(&spase);

		//if (clock.getElapsedTime().asSeconds() > 0.2)
		//{
		//	can_move = 1;
		//}

		if (clock.getElapsedTime().asSeconds() > 0.2)
		{
			can_move = 0;
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				pos_new.x = pos.x - 1;
				pos_new.y = pos.y;

				if (check(pos_new, example))
				{
					refresh_array(pos, pos_new, example);
					pos.x = pos_new.x;
					pos.y = pos_new.y;
					//can_move = 0;
					clock.restart();
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				pos_new.x = pos.x + 1;
				pos_new.y = pos.y;

				if (check(pos_new, example))
				{
					refresh_array(pos, pos_new, example);
					pos.x = pos_new.x;
					pos.y = pos_new.y;
					//can_move = 0;
					clock.restart();
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				pos_new.x = pos.x;
				pos_new.y = pos.y - 1;

				if (check(pos_new, example))
				{
					refresh_array(pos, pos_new, example);
					pos.x = pos_new.x;
					pos.y = pos_new.y;
					//can_move = 0;
					clock.restart();
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				pos_new.x = pos.x;
				pos_new.y = pos.y + 1;

				if (check(pos_new, example))
				{
					refresh_array(pos, pos_new, example);
					pos.x = pos_new.x;
					pos.y = pos_new.y;
					//can_move = 0;
					clock.restart();
				}
			}
		}

		window.display();
	}

}