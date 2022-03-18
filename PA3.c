/*
* Luke Schaefer
* 18186970
* LESDMG
*/

#include "PA3.h"
#include <stdlib.h>
#include <stdio.h>

// Reads in the input from cmdline and stores the parameters in an integer array. Returns the integer array.
int * ReadInput() {
    int * array = malloc(5 * sizeof(int));
    puts("Please enter integers to represent f s g u d in that order then press enter.");
    scanf("%d %d %d %d %d", array, array+1, array+2, array+3, array+4);

    int numFloors = array[0];
    int startFloor = array[1];
    int goalFloor = array[2];

    if(numFloors <= 0 || startFloor <= 0 || startFloor > numFloors || goalFloor <= 0 || goalFloor > numFloors) {
        puts("Invalid input. Goodbye.");
        return NULL;
    }
    
    return array;
}


// Processes the input from the input array.
Queue * ProcessInput(int * input) {
    /*
    * Create a graph (list representation)
    * BFS on the graph to find the lowest floor path
    * Return path
    */
   
    GNode * graph = CreateGraph(input);
    Queue * path = FindPath(graph, input);
    return path;
   
}

//Finds the shortest path between the two floors with the given parameters using the Breadth First Search algorithm. 
Queue * FindPath(GNode * graph, int * array) {

    Queue * path = initQueue();
    int tree = BFS(graph, array);

    
    while(tree) {
        insertAtIndex(path, tree, 0);
        tree = (graph + tree)->parent;
    }
    return path;

}

// Outputs the path of the floors that will be visted.
void OutputPath(Queue * path) {
    if(path->head == NULL) {
        puts("Take the stairs.");
    }
    else {
        int num;
        num = dequeue(path);
        printf("%d", num);
        while(path->size) {
            num = dequeue(path);
            printf("->%d", num);
        }
        puts("");
    }
    freeQueue(path);
    puts("Thank you. Goodbye.");
}

