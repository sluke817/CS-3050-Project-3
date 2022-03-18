/*
* Luke Schaefer
* 18186970
* LESDMG
*/

#include <stdlib.h>
#include <stdio.h>

/*
* 1 = white
* 0 = black
*/
typedef struct GraphNodeStruct {
    int floor;
    int color;
    int upFloor;
    int downFloor;
    int parent;
} GNode;

int BFS(GNode * graph, int * array);
GNode * CreateGraph(int * array);