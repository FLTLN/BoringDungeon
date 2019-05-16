#include "Output.h"
#include <stdio.h>

char* makeMas(char* par, int w, int h, int x, int y)
{
	static char mas[9][9];
	int XdifTOP, XdifBOT, YdifLEFT,YdifRIGHT;
	XdifTOP = x - 4;
	YdifLEFT = y - 4;
	XdifBOT = x + 4;
	YdifRIGHT = y + 4;
	//if (XdifTOP < 0)
	//{
	//	if (YdifLEFT < 0)
	//	{
	//		//int a = -XdifTOP;
	//		YdifLEFT = -YdifLEFT;
	//		for (int i = 0, a = -XdifTOP; i < a; i++)
	//		{
	//			for (int j = 0; j < YdifLEFT; j++)
	//			{
	//				mas[i][j] = '#';
	//			}
	//		}
	//	}
	//	else if (YdifRIGHT > w)
	//	{
	//		for (int i = 0, a = -XdifTOP; i < a; i++)
	//		{
	//			for (int j = 0; j < YdifLEFT; j++)
	//			{
	//				mas[i][j] = '#';
	//			}
	//		}
	//	}
	//}
	if (x < 4)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < -(x - 4); j++)
			{
				mas[i][j] = '#';
			}
		}
	}
	else if (x + 4 > w)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 9 - (w - x - 1); j < 9; j++)
			{
				mas[i][j] = '#';
			}
		}
	}
	if (y < 4)
	{
		for (int i = 0; i < -(y - 4); i++)
		{
			for (int j = 0; j < 9; j++)
			{
				mas[i][j] = '#';
			}
		}
	}
	else if (y + 4 > h)
	{
		for (int i = 9 - (h - y - 1); i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				mas[i][j] = '#';
			}
		}
	}
	//закончили с исключениями

	mas[4][4] = par[(y * w + x)];		//надо будет про математику побазарить

}