/*
* Luke Schaefer
* 18186970
* LESDMG
*/

#include "graph.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

// Creates a graph. 
// Array of GraphNodes 
// Each node represents a floor
GNode * CreateGraph(int * array) {

    int numFloors = array[0];
    int upNum = array[3];
    int downNum = array[4];

    GNode * graph = malloc((numFloors+1) * sizeof(GNode));

    for(int i = 0; i < numFloors+1; i++) {
        (graph+i)->floor = i;
        (graph+i)->color = 1;
        (graph+i)->parent = 0;

        if(i + upNum < numFloors+1) {
            (graph+i)->upFloor = i + upNum;
        }
        else {
            (graph+i)->upFloor = 0;
        }
        if(i - downNum > 0) {
            (graph+i)->downFloor = i - downNum;
        } 
        else {
            (graph+i)->downFloor = 0;
        }  
    }
    return graph;

}

// Finds the shortest path between two floors with the given data using Breadth First Search. 
// Returns the goal floor for tracing backwards for path discovery.
int BFS(GNode * graph, int * array) {

    Queue * queue = initQueue();
    int startFloor = array[1];
    int goalFloor = array[2];

    enqueue(queue, startFloor);
    while(queue->head != NULL) {

        int tester = dequeue(queue);
        
        int currentFloor = (graph + tester)->floor;
        int up = (graph + tester)->upFloor;
        int down = (graph + tester)->downFloor;
        
        if(currentFloor == goalFloor) {
            return currentFloor;
        }
        else {
            if(up && (graph + up)->color) {
                (graph+up)->parent = currentFloor;
                enqueue(queue, up);
            }
            if(down && (graph + down)->color) {
                (graph+down)->parent = currentFloor;
                enqueue(queue, down);
            }
        }
        (graph+tester)->color = 0;
    }
    return 0;
}