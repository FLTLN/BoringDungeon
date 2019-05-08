#include "mazeGenerator.h"
#include "mazeTestPrinter.h"
#include <stdlib.h>
#include <time.h>


void main()
{
	srand(time(NULL));
	PAR maze_par;

	maze_par.W = 40;
	maze_par.H = 55;

	maze_par.max_W = 15;
	maze_par.max_H = 15;


	create_Rooms_List(&maze_par); //Create list with rooms courners

	link_Rooms(&maze_par); //Linking rooms with their neihbourhoods

	char * mazeArray = create_Maze_Array(&maze_par);

	output_TXT(mazeArray, &maze_par, "maze.txt");

	//char * test_display_output;
	//TESTPAR console_display_par;
	//console_display_par.W = 999;
	//console_display_par.H = 999;
	// char * someFunction(char *, POINT *)
	//test_display_output = some_function(mazeArray,playerPosition)
	//output_test_TXT(test_display_output,console_display_par,"name.txt")

}