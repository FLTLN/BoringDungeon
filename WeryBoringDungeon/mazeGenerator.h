#ifndef __MAZEGENERATOR_
#define __MAZEGENERATOR_

typedef struct point
{
	unsigned int x;
	unsigned int y;
}POINT;

typedef struct room
{
	POINT up_courner;
	POINT down_courner;

	unsigned int number = 0;

	unsigned int UN_N = 0;
	unsigned int BN_N = 0;
	unsigned int LN_N = 0;
	unsigned int RN_N = 0;

	unsigned int with_road;


	room * next_room;

}ROOM;

typedef struct par
{
	unsigned int H;
	unsigned int W;

	unsigned int max_H;
	unsigned int max_W;

	unsigned int rooms_quantity = 0;

	unsigned int max_quantity_on_x;

	ROOM * rooms_courners_list;

}PAR;

//void add(ROOM ** rooms, ROOM * room);
void link_Rooms(PAR * par);
void digRoads(PAR * par, char * mazeArray, POINT from, POINT to);
ROOM * findRoom(ROOM * rooms, unsigned int number);
void createRoads(POINT * from, POINT * to, ROOM * rooms, ROOM * next_room);

//Refactored Functions:

void create_Rooms_List(PAR * par);
char * create_Maze_Array(PAR * par);

#endif // !__MAZEGENERATOR_


