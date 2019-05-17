#include "Output.h"
#include <stdio.h>

char* makeMas(char* par, int w, int h, int x, int y)
{
	static char mas[9][9];
	int a = 0, b = 0;
	int T = 0, B = 0, L = 0, R = 0;
	if (x < 4)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < -(x - 4); j++)
			{
				mas[i][j] = '#';
				a--;
				L++;
			}
		}

		if (y < 4)
		{
			for (int i = 0; i < -(y - 4); i++)
			{
				for (int j = 0; j < 9; j++)
					mas[i][j] = '#';
				b--;
				T++;
			}
			for (int i = T, d = -40; i < 9; i++, d += 9 + L)		
				for (int j = L; j < 9; j++)
					mas[i][j] = par[((y * w + x) + d + j)];
		}
		else if (y + 4 > h - 1)
		{
			for (int i = 9 - (h - y - 1); i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
					mas[i][j] = '#';
				b++;
				B++;
			}
			for (int i = 0, d = -40; i < 9 - B; i++, d += 9 + L)
				for (int j = L; j < 9; j++)
					mas[i][j] = par[((y * w + x) + d + j)];
		}	
	}
	else if (x + 4 > w - 1)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 9 - (w - x - 1); j < 9; j++)
			{
				mas[i][j] = '#';
				a++;
				R++;
			}
		}

		if (y < 4)
		{
			for (int i = 0; i < -(y - 4); i++)
			{
				for (int j = 0; j < 9; j++)
					mas[i][j] = '#';
				b--;
				T++;
			}
			for (int i = T, d = -40; i < 9; i++, d += 9 + L)
				for (int j = 0; j < 9 - R; j++)
					mas[i][j] = par[((y * w + x) + d + j)];
		}
		else if (y + 4 > h)
		{
			for (int i = 9 - (h - y - 1); i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
					mas[i][j] = '#';
				b++;
				B++;
			}
			for (int i = 0, d = -40; i < 9 - B; i++, d += 9 + L)
				for (int j = 0; j < 9 - R; j++)
					mas[i][j] = par[((y * w + x) + d + j)];
		}
	}
	else
	{
		if (y < 4)
		{
			for (int i = 0; i < -(y - 4); i++)
			{
				for (int j = 0; j < 9; j++)
					mas[i][j] = '#';
				b--;
			}
			for (int i = T, d = -40; i < 9; i++, d += 9 + L)
				for (int j = 0; j < 9; j++)
					mas[i][j] = par[((y * w + x) + d + j)];
		}
		else if (y + 4 > h)
		{
			for (int i = 9 - (h - y - 1); i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
					mas[i][j] = '#';
				b++;
			}
			for (int i = 0, d = -40; i < 9 - B; i++, d += 9 + L)
				for (int j = 0; j < 9; j++)
					mas[i][j] = par[((y * w + x) + d + j)];
		}
		else
		{
			for (int i = 0, d = -40; i < 9; i++, d += 9)			//запись лабиринта в массив в общем случае
				for (int j = 0; j < 9; j++)
					mas[i][j] = par[((y * w + x) + d + j)];
		}
	}
	//надо будет про математику побазарить

}


