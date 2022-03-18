/*
* Luke Schaefer
* 18186970
* LESDMG
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "graph.h"



int * ReadInput();
Queue * ProcessInput(int * input);
Queue * FindPath(GNode * graph, int * array);
void OutputPath(Queue * path);
