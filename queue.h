/*
* Luke Schaefer
* 18186970
* LESDMG
*/

#include <stdio.h>

typedef struct QueueNode {
	struct QueueNode * next;
	int data;
} QNode;

typedef struct {
	QNode * head;
	int size;
} Queue;

int isValidIndex(Queue * queue, int index);
QNode * makeQNode(int data, QNode * next);
int freeQNode(QNode * node);
QNode * nodeAtIndex(Queue * queue, int index);
void clearQueue(Queue * queue);
QNode * setHead(Queue * queue, QNode * newHead);
int insertAtIndex(Queue * queue, int data, int index);
int enqueue(Queue * queue, int data);
int removeAtIndex(Queue * queue, int index);
int dequeue(Queue * queue);
Queue * initQueue();
void freeQueue(Queue * queue);