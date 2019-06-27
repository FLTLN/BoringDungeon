#include "Output.h"



char* makeMas(const char* par, int w, int h, int x, int y, char* mas)
{
	int len = 81;
	printf("x = %d\n",x);
	scanf_s("%d", &x);
	printf("y = %d\n",y);
	scanf_s("%d", &y);
	int T = 0, B = 0, L = 0, R = 0;
	if (x < 4)
	{
		for (int i = 0; i < len; i += 9)
		{
			for (int j = 0; j < 4 - x; j++)
				mas[i + j] = '#';
			L++;
		}

		if (y < 4)
		{
			for (int i = 0; i < 9*y - 1; i += 9)
			{
				for (int j = 0; j < 9; j++)
					mas[i + j] = '#';
				T++;
			}

			for (int i = 0 + T * 9, a = 0; i < len; i += 9, a++)
				for (int j = 0 + L; j < 9; j++)
					mas[i + j] = par[(y * w + x) + (a - 4) * w + (j - 4)];
		}
		else if (y + 4 > h - 1)
		{
			for (int i = 45 + (h - y - 1) * w; i < len; i += 9)
			{
				for (int j = 0; j < 9; j++)
					mas[i + j] = '#';
				B++;
			}
				
			for (int i = 81 - B * 9, a = 0; i < len; i += 9, a++)
				for (int j = 0 + L; j < 9; j++)
					mas[i + j] = par[(y * w + x) + (a - 4) * w + (j - 4)];
		}
		else
		{
			for (int i = 0, a = 0; i < len; i += 9, a++)
				for (int j = 0 + L; j < 9; j++)
					mas[i + j] = par[(y * w + x) + (a - 4) * w + (j - 4)];
		}

		
	}
	else if (x + 4 > w - 1)
	{
		for (int i = 0; i < len; i += 9)
		{
			for (int j = 9 - (w - x - 1); j < 9; j++)
				mas[i + j] = '#';
			R++;
		}

		if (y < 4)
		{
			for (int i = 0; i < 9*y - 1; i += 9)
			{
				for (int j = 0; j < 9; j++)
					mas[i + j] = '#';
				T++;
			}
			
			for (int i = 0 + T * 9, a = 0; i < len; i += 9, a++)
				for (int j = 9 - R; j < 9; j++)
					mas[i + j] = par[(y * w + x) + (a - 4) * w + (j - 4)];
		}
		else if (y + 4 > h - 1)
		{
			for (int i = 45 + (h - y - 1) * w; i < len; i += 9)
			{
				for (int j = 0; j < 9; j++)
					mas[i + j] = '#';
				B++;
			}
				
			for (int i = 81 - B * 9, a = 0; i < len; i += 9, a++)
				for (int j = 9 - R; j < 9; j++)
					mas[i + j] = par[(y * w + x) + (a - 4) * w + (j - 4)];
		}
		else
		{
			for (int i = 0, a = 0; i < len; i += 9, a++)
				for (int j = 9 - R; j < 9; j++)
					mas[i + j] = par[(y * w + x) + (a - 4) * w + (j - 4)];
		}
	}
	else
	{
		if (y < 4)
		{
			for (int i = 0; i < 9*y - 1; i+=9)
				for (int j = 0; j < 9; j++)
					mas[i + j] = '#';

			for (int i = 4 - y, a = 0; i < len; i += 9, a++)
				for (int j = 0; j < 9; j++)
					mas[i + j] = par[(y * w + x) + (a - 4) * w + (j - 4)];
		}
		else if (y + 4 > h - 1)
		{
			for (int i = 45 + (h - y - 1) * w; i < len; i += 9)
				for (int j = 0; j < 9; j++)
					mas[i + j] = '#';

			for (int i = 0, a = 0; i < 45 + (h - y - 1); i += 9, a++)
				for (int j = 0; j < 9; j++)
					mas[i + j] = par[(y * w + x) + (a - 4) * w + (j - 4)];
		}
		else
		{
			for (int i = 0, a = 0; i < len; i+=9, a++)
				for (int j = 0; j < 9; j++)
					mas[i+j] = par[(y * w + x) + (a - 4) * w + (j - 4)];
		}
	}
	for (int i = 0; i < 81; i += 9)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%c", mas[i + j]);
		}
		printf("\n");
	}
	return mas;
}

void get_Plase(PAR * par, P_POS * position, char * maze,char * plase)
{
	int i, j,k;
	//printf_s("\n");

	k = 0;
	for (i = position->x - 4; i <= position->x + 4; i++)
	{
		for (j = position->y - 4; j <= position->y + 4; j++)
		{

			if ((i*par->H + j < 0) || (i*par->H + j > par->H*par->W))
			{
				*(plase + k) = '#';
				//printf_s("%c", *(plase + k));
			}
			else
			{
				*(plase + k) = *(maze + i * par->H + j);
				//printf_s("%c", *(plase + k));
			}

			k++;
		}
		//printf_s("\n");
	}
}