
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS

#include "mazeGenerator.h"
#include "mazeTestPrinter.h"
#include "AnimatedSprite.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>
#include "Output.h"
#include "graphicsOutput.h"
//#include <SFML/Graphics.hpp>
using namespace sf;


void main()
{
	srand(time(NULL));
	PAR maze_par;

	Clock clock;
	//float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах

	Image playerImage;
	playerImage.loadFromFile("textures/player.png");
	Player* player;
	player = new Player(playerImage, 400, 400);
	std::string direction = "stay";

	RenderWindow window(sf::VideoMode(900, 900), "Boring Dungeon 0.01");
	GAMESPASE spase;
	spase.window = &window;
	prepare_textures(&spase);

	window.setFramerateLimit(15);

	char example[82];

	P_POS pos;

	pos.x = 5;
	pos.y = 5;

	P_POS pos_new;

	int repeat_pos_generation = 1;



	maze_par.W = 400;
	maze_par.H = 400;

	maze_par.max_W = 15;
	maze_par.max_H = 15;


	create_Rooms_List(&maze_par); //Create list with rooms courners

	link_Rooms(&maze_par); //Linking rooms with their neihbourhoods

	char * mazeArray = create_Maze_Array(&maze_par);

	do
	{
		pos.x = rand() % maze_par.H;
		pos.y = rand() % maze_par.W;

	} while (!check_full(pos, mazeArray, &maze_par));

	printf_s("%d\n", pos.x);
	printf_s("%d\n", pos.y);

	//pos.x = 9;
	//pos.y = 9;

	//char * around = (char *)(malloc((9 * 9 + 10)* sizeof(char)));
	char around[82];
	//char * local_arround = makeMas(mazeArray, maze_par.W, maze_par.H, pos.y, pos.x, around);

	get_Plase(&maze_par,&pos,mazeArray,around);

	output_TXT(mazeArray, &maze_par, "maze.txt");

	//char * test_display_output;
	//TESTPAR console_display_par;
	//console_display_par.W = 999;
	//console_display_par.H = 999;
	// char * someFunction(char *, POINT *)
	//test_display_output = some_function(mazeArray,playerPosition)
	//output_test_TXT(test_display_output,console_display_par,"name.txt")

	int can_move = 0;

	//////////////////////////////
	sf::Shader shader;
	if (!shader.loadFromFile("vert_shader.vert", "frag_shader.frag")) {
		std::cout << "Unable to load the shaders" << std::endl;
	}

	shader.setUniform("texture", sf::Shader::CurrentTexture);
	shader.setUniform("resolution", Glsl::Vec2(window.getSize().x, window.getSize().y));
	shader.setUniform("ambientData", Glsl::Vec4(0.3, 0.3, 0.8, 0.3));
	shader.setUniform("lightData", Glsl::Vec4(1.0, 0.8, 0.2, 2));
	shader.setUniform("lightSize", Glsl::Vec2(0.3, 0));
	//////////////////////////////

	char ex[] =
	{
		"#########"
		"#     # #"
		"#       #"
		"#   @   #"
		"#       #"
		"###     #"
		"#       #"
		"#       #"
		"#########"
	};
	sf::Clock fpsClock;

	clock.restart();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//float elapsedTime = 1.f / fpsClock.getElapsedTime().asMilliseconds();

		float elapsedTime = fpsClock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		
		//elapsedTime = elapsedTime / 300; //скорость игры

		player->playAnimation(direction);

		player->update(elapsedTime);

		shader.setUniform("mouse", Glsl::Vec2(window.getSize().x / 2, window.getSize().y / 2));
		shader.setUniform("time", Glsl::Vec2(elapsedTime, 0));

		window.clear();
		refresh_textures(&spase, around);
		draw_all(&spase, &shader);

		window.draw(*player, &shader);

		if (clock.getElapsedTime().asSeconds() > 0.2)
		{
			can_move = 1;

		}

		if (can_move == 1)
		{
			direction = "stay";
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				pos_new.x = pos.x - 1;
				pos_new.y = pos.y;
				direction = "moveLeft";


				//pos_new.x = pos.x;
				//pos_new.y = pos.y - 1;

				if (check_full(pos_new, mazeArray, &maze_par))
				{
					//refresh_array(pos, pos_new, example);
					//get_Plase(&maze_par, &pos, mazeArray, &around);
					//around = makeMas(mazeArray, maze_par.W, maze_par.H, pos_new.x, pos_new.y, around);
					get_Plase(&maze_par, &pos_new, mazeArray, around);
					pos.x = pos_new.x;
					pos.y = pos_new.y;
					can_move = 0;
					mazeArray[pos.x * maze_par.W + pos.y] = 'l';


					clock.restart();

					
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				pos_new.x = pos.x + 1;
				pos_new.y = pos.y;
				direction = "moveRight";

				//pos_new.x = pos.x;
				//pos_new.y = pos.y + 1;

				if (check_full(pos_new, mazeArray, &maze_par))
				{
					//refresh_array(pos, pos_new, example);
					//get_Plase(&maze_par, &pos, mazeArray, &around);
					//around = makeMas(mazeArray, maze_par.W, maze_par.H, pos_new.x, pos_new.y, around);
					get_Plase(&maze_par, &pos_new, mazeArray, around);
					pos.x = pos_new.x;
					pos.y = pos_new.y;
					can_move = 0;
					mazeArray[pos.x * maze_par.W + pos.y] = 'r';
					clock.restart();
					
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				pos_new.x = pos.x;
				pos_new.y = pos.y - 1;
				direction = "moveUp";

				//pos_new.x = pos.x - 1;
				//pos_new.y = pos.y;

				if (check_full(pos_new, mazeArray, &maze_par))
				{
					//refresh_array(pos, pos_new, example);
					//get_Plase(&maze_par, &pos, mazeArray, &around);
					//around = makeMas(mazeArray, maze_par.W, maze_par.H, pos_new.x, pos_new.y, around);
					get_Plase(&maze_par, &pos_new, mazeArray, around);
					pos.x = pos_new.x;
					pos.y = pos_new.y;
					mazeArray[pos.x * maze_par.W + pos.y] = 'u';
					//can_move = 0;
					clock.restart();
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				pos_new.x = pos.x;
				pos_new.y = pos.y + 1;

				direction = "moveDown";

				//pos_new.x = pos.x + 1;
				//pos_new.y = pos.y;


				//footSteps.emplace_back(new Steps(2, pos.x * 81, pos.y * 81));
				
				//refresh_array(pos, pos_new, mazeArray, '#');
				if (check_full(pos_new, mazeArray, &maze_par))
				{

					//get_Plase(&maze_par, &pos, mazeArray, &around);
					//around = makeMas(mazeArray, maze_par.W, maze_par.H, pos_new.x, pos_new.y, around);
					get_Plase(&maze_par, &pos_new, mazeArray, around);
					pos.x = pos_new.x;
					pos.y = pos_new.y;
					mazeArray[pos.x * maze_par.W + pos.y] = 'd';
					//can_move = 0;


					clock.restart();
				}
				//refresh_array(pos, pos_new, mazeArray);
			}
		}
		fpsClock.restart(); //перезагружает время
		window.display();
	}


	//free(around);
}
