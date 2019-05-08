#define _CRT_SECURE_NO_WARNINGS
#include "mazeGenerator.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

char * create_Maze_Array(PAR * par)
{
	char * mazeArray = (char *)malloc(par->H*par->W * sizeof(char));
	char newline[] = { "\n" };

	if (mazeArray)
	{
		unsigned int i, j;
		for (i = 0; i < (par->H*par->W); i++)
		{
			*(mazeArray + i) = '#';
		}

		ROOM * rooms = par->rooms_courners_list;

		while (rooms)
		{

			for (i = 0; i < rooms->down_courner.y - rooms->up_courner.y; i++)
			{
				for (j = 0; j < rooms->down_courner.x - rooms->up_courner.x; j++)
				{
					*(mazeArray + (i + rooms->up_courner.y)* par->H + j + rooms->up_courner.x) = ' ';
				}

			}

			rooms = rooms->next_room;
		}

		rooms = par->rooms_courners_list;

		int not_differrent;
		POINT from;
		POINT to;
		int rand_num;
		ROOM * from_room, *to_room;
		int roomsWitsRoadsQuantity = 0;
		to_room = NULL;

		from_room = findRoom(par->rooms_courners_list, rand() % par->rooms_quantity + 1);

		if (from_room)
		{
			printf_s("FROM ROOM %d\n", from_room->number);
		}


		do
		{
			switch (rand() % 4 + 1)
			{
			case 1:
				to_room = findRoom(par->rooms_courners_list, from_room->UN_N);
				break;
			case 2:
				to_room = findRoom(par->rooms_courners_list, from_room->BN_N);
				break;
			case 3:
				to_room = findRoom(par->rooms_courners_list, from_room->LN_N);
				break;
			case 4:
				to_room = findRoom(par->rooms_courners_list, from_room->RN_N);
				break;

			default:
				break;
			}
		} while (!to_room);

		if (to_room)
		{
			printf_s("TO ROOM %d\n", to_room->number);
		}

		createRoads(&from, &to, from_room, to_room);
		digRoads(par, mazeArray, from, to);
		roomsWitsRoadsQuantity = 2;

		while (roomsWitsRoadsQuantity < par->rooms_quantity)
		{
			do
			{
				from_room = findRoom(par->rooms_courners_list, rand() % par->rooms_quantity + 1);

				do
				{

					switch (rand() % 4 + 1)
					{
					case 1:
						to_room = findRoom(par->rooms_courners_list, from_room->UN_N);
						break;
					case 2:
						to_room = findRoom(par->rooms_courners_list, from_room->BN_N);
						break;
					case 3:
						to_room = findRoom(par->rooms_courners_list, from_room->LN_N);
						break;
					case 4:
						to_room = findRoom(par->rooms_courners_list, from_room->RN_N);
						break;

					default:
						break;
					}
				} while (!to_room);



			} while (!((to_room->with_road) && (!from_room->with_road)));

			if (from_room)
			{
				printf_s("FROM ROOM %d\n", from_room->number);
			}

			if (to_room)
			{
				printf_s("TO ROOM %d\n", to_room->number);
			}

			createRoads(&from, &to, from_room, to_room);
			digRoads(par, mazeArray, from, to);

			roomsWitsRoadsQuantity++;
		}

	}

	return mazeArray;
}

void add(ROOM ** rooms, ROOM * room)
{
	if (room)
	{
		room->next_room = *rooms;
		*rooms = room;
	}
}


void create_Rooms_List(PAR * par)
{
	int i, j, zone_courner_x, zone_courner_y;
	ROOM * rooms = NULL;
	ROOM * room;
	int rooms_quantity = 1;


	for (i = 0; i < (par->H / par->max_H); i++)
	{
		for (j = 0; j < (par->W / par->max_W); j++)
		{

			zone_courner_x = i * par->max_H;
			zone_courner_y = j * par->max_W;

			room = (ROOM *)malloc(sizeof(ROOM));

			room->up_courner.x = zone_courner_x + rand() % (par->max_H / 2 - 2) + 2;
			room->up_courner.y = zone_courner_y + rand() % (par->max_W / 2 - 2) + 2;

			unsigned int uncorrect;

			do
			{
				uncorrect = 0;
				room->down_courner.x = zone_courner_x + rand() % (par->max_H - 4) + 4;
				if (room->down_courner.x <= room->up_courner.x) uncorrect = 1;
				if (room->down_courner.x - room->up_courner.x <= 2) uncorrect = 1;

			} while (uncorrect);

			do
			{
				uncorrect = 0;
				room->down_courner.y = zone_courner_y + rand() % (par->max_W - 4) + 4;
				if (room->down_courner.y <= room->up_courner.y) uncorrect = 1;
				if (room->down_courner.y - room->up_courner.y <= 2) uncorrect = 1;

			} while (uncorrect);

			room->number = rooms_quantity;
			rooms_quantity++;

			add(&rooms, room);
		}

		par->rooms_quantity = rooms_quantity - 1;
		par->rooms_courners_list = rooms;
		par->max_quantity_on_x = par->W / par->max_W;
		printf_s("CREATE ROOMS DONE\n");

	}
}

void link_Rooms(PAR * par)
{
	ROOM * room = par->rooms_courners_list;

	printf_s(">>start link rooms\n\n");

	while (room)
	{
		printf_s("link room %d \n\n", room->number);

		if (room->number % par->max_quantity_on_x != 0)
		{
			room->RN_N = room->number + 1;
		}
		else room->RN_N = 0;

		if ((room->number - 1) % par->max_quantity_on_x != 0)
		{
			room->LN_N = room->number - 1;
		}
		else room->LN_N = 0;

		if (room->number + par->max_quantity_on_x <= par->rooms_quantity)
		{
			room->BN_N = room->number + par->max_quantity_on_x;
		}
		else room->BN_N = 0;

		if (((int)room->number - (int)par->max_quantity_on_x) > 0)
		{
			room->UN_N = room->number - par->max_quantity_on_x;
		}
		else room->UN_N = 0;

		room->with_road = 0;

		printf_s("room %d linked with:\n", room->number);
		printf_s("room %d as a right neihbour\n", room->LN_N);
		printf_s("room %d as a left neihbour\n", room->RN_N);
		printf_s("room %d as a bot neihbour\n", room->UN_N);
		printf_s("room %d as a up neihbour\n\n", room->BN_N);

		room = room->next_room;
	}
}

void digRoads(PAR * par, char * mazeArray, POINT from, POINT to)
{

	if (from.x < to.x)
	{
		while (from.x < to.x)
		{
			*(mazeArray + from.y*par->H + from.x) = ' ';
			from.x++;
		}
	}
	else
	{
		while (from.x > to.x)
		{
			*(mazeArray + from.y*par->H + from.x) = ' ';
			from.x--;
		}
	}

	if (from.y < to.y)
	{
		while (from.y < to.y)
		{
			*(mazeArray + from.y*par->H + from.x) = ' ';
			from.y++;
		}
	}
	else
	{
		while (from.y > to.y)
		{
			*(mazeArray + from.y*par->H + from.x) = ' ';
			from.y--;
		}
	}
}

ROOM * findRoom(ROOM * rooms, unsigned int number)
{
	if (number == 0) return NULL;
	while (number != rooms->number)
	{
		rooms = rooms->next_room;
	}
	return rooms;
}

void createRoads(POINT * from, POINT * to, ROOM * rooms, ROOM * next_room)
{
	from->x = rooms->up_courner.x + rand() % (rooms->down_courner.x - rooms->up_courner.x);
	from->y = rooms->up_courner.y + rand() % (rooms->down_courner.y - rooms->up_courner.y);

	to->x = next_room->up_courner.x + rand() % (next_room->down_courner.x - next_room->up_courner.x);
	to->y = next_room->up_courner.y + rand() % (next_room->down_courner.y - next_room->up_courner.y);

	rooms->with_road = 1;
	next_room->with_road = 1;

	if (rooms->UN_N == next_room->number)
	{
		rooms->UN_R = 1;
		next_room->BN_R = 1;
	}
	if (rooms->BN_N == next_room->number)
	{
		rooms->BN_R = 1;
		next_room->UN_R = 1;
	}
	if (rooms->LN_N == next_room->number)
	{
		rooms->LN_R = 1;
		next_room->RN_R = 1;
	}
	if (rooms->RN_N == next_room->number)
	{
		rooms->RN_R = 1;
		next_room->LN_R = 1;
	}
}


