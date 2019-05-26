#ifndef _OUTPUT_H
#define _OUTPUT_H
#include <stdio.h>
#include <string.h>
#include "graphicsOutput.h"
#include "mazeGenerator.h"


char* makeMas(const char* par, int w, int h, int x, int y, char* mas);
void get_Plase(PAR * par, P_POS * position, char * maze, char * plase);

#endif // !_OUTPUT_H

