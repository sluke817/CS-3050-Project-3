/*
* Luke Schaefer
* 18186970
* LESDMG
*/

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

// Returns if the provided index is valid for the given queue
int isValidIndex(Queue * queue, int index) {
	return index >= 0 && index < queue->size;
}

// Creates and returns a Queue node. Returns NULL if malloc fails
QNode * makeQNode(int data, QNode * next) {
	QNode * node = malloc(sizeof(QNode));
	if(node != NULL) {
		node->next = next;
        node->data = data;
	}
	return node;
}

// Frees the given QNode and returns the number that was stored
int freeQNode(QNode * node) {
	int temp = node->data;
	free(node);
	return temp;
}

// Returns the QNode at the requested index, or NULL if the given index is not valid
QNode * nodeAtIndex(Queue * queue, int index) {

	if(!isValidIndex(queue, index)) {
		return NULL;
	}

	QNode * tracer = queue->head;
	while(index) {
		tracer = tracer->next;
		index--;
	}

	return tracer;
}

// Frees all nodes in a queue and "clears" the given Queue
void clearQueue(Queue * queue) {
	QNode * tracer = queue->head;
	while(tracer != NULL) {
		QNode * temp = tracer;
		tracer = tracer->next;
		free(temp);
	}
	queue->head = NULL;
	queue->size = 0;
}

// Sets the head of the queue to the given QNode and returns the old head
QNode * setHead(Queue * queue, QNode * newHead) {
	QNode * oldHead = queue->head;
	queue->head = newHead;
	return oldHead;
}

// Inserts the given object on the queue at the given index. Returns 1 on success and -1 on failure
int insertAtIndex(Queue * queue, int num, int index) {

	if(!isValidIndex(queue, index) && (index != queue->size)) {
		return -1;
	} 
    else if(index == 0) {
		QNode * new = makeQNode(num, NULL);
		if(new == NULL) {
			return -1;
		}
		else {
			new->next = setHead(queue, new);
		}
		
	} 
    else {
		QNode * previous = nodeAtIndex(queue, index - 1);
		QNode * new = makeQNode(num, previous->next);
		if(new == NULL) {
			return -1;
		}
		else {
			previous->next = new;
		}
		
	}
	queue->size++;
	return 1;
}

// Enqueues the number in the queue. Returns 1 on success, -1 on failure
int enqueue(Queue * queue, int num) {
    return insertAtIndex(queue, num, queue->size);
}

// Removes and returns the number at the given index. Index must be a valid index
int removeAtIndex(Queue *queue, int index) {
	
	int num;
	if(!index) {
		num = freeQNode(setHead(queue, queue->head->next));
	} 
    else {
		QNode *previous = nodeAtIndex(queue, index - 1);
		QNode *temp = previous->next;
		previous->next = temp->next;
		num = freeQNode(temp);
	}
	queue->size--;
	return num;
}

// Dequeues the queue and returns the dequeued number
int dequeue(Queue * queue) {
    return removeAtIndex(queue, 0);
}

// Initializes a Queue. Returns a pointer to the queue or NULL on failure
Queue* initQueue() {
	Queue * queue = malloc(sizeof(Queue));
	if(queue != NULL) {
		queue->head = NULL;
		queue->size = 0;
	}
	return queue;
}

// Frees all memory allocated to the queue
void freeQueue(Queue *queue) {
	clearQueue(queue);
	free(queue);
}
