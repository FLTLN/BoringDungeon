#define _CRT_SECURE_NO_WARNINGS
#define SYMBOL_SIZE 40
#include "mazeTestPrinter.h"
#include "mazeGenerator.h"
#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include <zlib.h>

void output_TXT(char * mazeArray, PAR * par, const char * name)
{
	int i, j;
	char newline[] = { "\n" };
	FILE * file = fopen(name, "w");

	if (file)
	{
		for (i = 0; i < par->W; i++)
		{
			for (j = 0; j < par->H; j++)
			{
				fputc(*(mazeArray + (i* par->H) + j), file);
			}
			fputs(newline, file);
		}
	}
}

void output_test_TXT(char * mazeArray, TESTPAR * par, const char * name)
{
	int i, j;
	char newline[] = { "\n" };
	FILE * file = fopen(name, "w");

	if (file)
	{
		for (i = 0; i < par->W; i++)
		{
			for (j = 0; j < par->H; j++)
			{
				fputc(*(mazeArray + (i* par->H) + j), file);
			}
			fputs(newline, file);
		}
	}
}




