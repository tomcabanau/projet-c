#ifndef QUEUE_H
#define QUEUE_H

#include "element.h"

typedef struct _queue {
    element* last;
    element* head;
} queue;

int testFile();
queue emptyQueue();
void enqueue(queue* file, int value);
int dequeue(queue* file);
void printqueue(queue* file);


#endif