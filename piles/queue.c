#include "queue.h"
#include "stack.h"

int testFile() {
    queue file;
    file = emptyQueue();

    for(int i=0; i <10;i++) {
        enqueue(&file, rand()%20);
    }
    printqueue(&file);
    int n = dequeue(&file);
    printf("L'élément supprimé est %d\n", n);
    printqueue(&file);

    freeElement(file.head);
    return 0;
}

queue emptyQueue() {
    queue q;
    q.last = NULL;
    q.head = NULL;
    return q;
}

void enqueue(queue *q, int value) {
    element *e;
    e = (element *) malloc(sizeof(element));
    e->value = value;
    e->next = NULL;
    if (q->head == NULL) {
        q->head = e;
        q->last = e;
    } else {
        q->last->next = e;
        q->last = e;
    }
}

int dequeue(queue* file){
    return pop(&(file->head));
}

void printqueue(queue* file) {
    printliste(file->head);
    printf("\n");
}