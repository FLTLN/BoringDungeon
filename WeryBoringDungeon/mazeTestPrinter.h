#include "mazeGenerator.h"

#ifndef __MAZETESTPRINTER_
#define __MAZETESTPRINTER_

typedef struct testpar
{
	int W;
	int H;

}TESTPAR;

void output_TXT(char * mazeArray, PAR * par, const char * name);
void output_test_TXT(char * mazeArray, TESTPAR * par, const char * name);


#endif // !__MAZETESTPRINTER_


