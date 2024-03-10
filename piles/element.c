#include "element.h"

int minOfElement(element* list) {
    if(list == NULL) {
        return 0;
    } else if(list->next == NULL) {
        return list->value;
    } else {
        return list->value > minOfElement(list->next) ? minOfElement(list->next) : list->value;
    }
}

int maxOfElement(element* list) {
    if(list == NULL) {
        return 0;
    } else if(list->next == NULL) {
        return list->value;
    } else {
        return list->value > maxOfElement(list->next) ? list->value : maxOfElement(list->next);
    }
}

interval intervalOfElements(element* list) {
    interval inter;
    inter.min = minOfElement(list);
    inter.max = maxOfElement(list);
    return inter;
}

int sommeOfElements(element* list) {
    if(list == NULL) {
        return 0;
    } else {
        return list->value + sommeOfElements(list->next);
    }
}

int multipleOfElements(element* list) {
    if(list == NULL) {
        return 1;
    } else {
        return list->value * multipleOfElements(list->next);
    }
}

int lengthOfElement(element* list) {
    if(list == NULL) {
        return 0;
    } else {
        return 1 + lengthOfElement(list->next);
    }
}

void reversePrint(element* list) {
    if(list == NULL) {
        return;
    } else {
        reversePrint(list->next);
        printf("%d ", list->value);
    }
}

element* pushElementAtEnd(element* first_element, int value) {
    if(first_element == NULL) {
        pushElement(first_element, value);
    } else if(first_element->next == NULL) {
        element* new = malloc(sizeof(element));
        new->value = value;
        new->next = NULL;
        first_element->next = new;
    } else {
        pushElementAtEnd(first_element->next, value);
        return first_element;
    }
}

/*element* pushElementAtPos(element* first_element, int value, int* pos) {
    if(*pos > lengthOfElement(first_element)) {
        pushElementAtEnd(first_element, value);
    } else if(*pos <= 2) {
        element* new = malloc(sizeof(element));
        new->next = first_element->next;
        new->value = value;
        first_element->next = new;
    } else {
        *pos = *pos - 1;
        pushElementAtPos(first_element->next, value, pos);
        return first_element;
    }
}

element* removeElementAtPos(element* first_element, int* pos) {
    if(*pos > lengthOfElement(first_element)) {
        return first_element;
    } else if(*pos <= 2) {
        element* list = first_element->next->next;
        free(first_element->next);
        first_element->next = list;
    } else {
        *pos = *pos - 1;
        removeElementAtPos(first_element->next, pos);
        return first_element;
    }
}*/

element* newEmptyElement() {
    return NULL;
}

element* pushElement(element* first_element, int value) {
    element* new = malloc(sizeof(element));
    new->value = value;
    new->next = first_element;
    return new;
}

void pushElementWithPointeur(element** first_element, int value) {
    element* new = malloc(sizeof(element));
    new->value = value;
    new->next = *first_element;
    *first_element = new;
}

void printlisterec(element* list) {
    if(list == NULL) {
        return;
    } else {
        printf("%d ", list->value);
        printliste(list->next);
    }
}

void printliste(element* list) {
    while(list != NULL) {
        printf("%d ", list->value);
        list = list->next;
    }
}

void takeFirstElement(element** list) {
    element* liste = *list;
    printf("Element supprimé : %d ", liste->value);
    *list = liste->next;
    free(liste);
}

void freeElement(element* element) {
    if(element == NULL) {
        return;
    } else {
        freeElement(element->next);
        free(element);
    }
}