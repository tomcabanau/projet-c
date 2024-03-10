#ifndef ELEMENT_H
#define ELEMENT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _element {
    int value;
    struct _element *next;
} element;

typedef struct _interval {
    int max;
    int min;
} interval;

element* newEmptyElement();
element* pushElement(element* first_element, int value);
void pushElementWithPointeur(element** first_element, int value);
void printlisterec(element* list);
void printliste(element* list);
void takeFirstElement(element** list);
void reversePrint(element* list);
element* pushElementAtEnd(element* first_element, int value);
element* pushElementAtPos(element* first_element, int value, int* pos);
element* removeElementAtPos(element* first_element, int* pos);
int lengthOfElement(element* list);
int sommeOfElements(element* list);
int multipleOfElements(element* list);
int maxOfElement(element* list);
int minOfElement(element* list);
interval intervalOfElements(element* list);
void freeElement(element* element);

#endif