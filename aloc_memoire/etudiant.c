#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "etudiant.h"

char * alphabet_min(){
    char * alphabet = (char *)malloc(26*sizeof(char));
    for(int i = 0; i<26; i++){
        alphabet[i]=i+'a';
    }
    return alphabet;
}

void init_eleves(eleves* mesEleves){
    mesEleves->nb_eleves=0;
    mesEleves->notes=NULL;
    mesEleves->prenoms=NULL;
}


// QUESTION 1
int * notes(int nb_notes){
    int * tableau_notes = malloc(nb_notes * sizeof(int));
    for(int i = 0; i < nb_notes; i++){
        tableau_notes[i] = 0;
    }
    return tableau_notes;
}


// QUESTION 2
char *copie_chaine(char chaine[NAME_LEN]){
    char *copie = malloc((strlen(chaine)) * sizeof(char));
    for(int i=0; i < strlen(chaine) ; i++){
        copie[i] = chaine[i];
    }
    return copie;
}

// QUESTION 3
char ** copie_chaines(int nb_chaines, char les_chaines[][NAME_LEN]){
    char** les_copies = malloc(nb_chaines * sizeof(char*));
    for (int i = 0; i < nb_chaines; i++) {
        les_copies[i] = copie_chaine(les_chaines[i]);
    }
    return les_copies;
}

// QUESTION 4
void entrer_notes(eleves* mesEleves){
    for (int i = 0; i < mesEleves->nb_eleves; i++) {
        mesEleves->notes[i] = rand() % 21;
    }
}

// QUESTION 5
void affiche_notes(eleves mesEleves) {
    if(mesEleves.notes == NULL || mesEleves.prenoms==NULL ){
        printf("Pas d'eleves ou pas de notes\n");
        return;
    }
    for(int i=0; i<mesEleves.nb_eleves;i++){
        printf("%s : %d\n", mesEleves.prenoms[i], mesEleves.notes[i]);
    }
}

// QUESTION 6
void libererClasse(eleves mesEleves){
    if (mesEleves.prenoms != NULL) {
        for (int i = 0; i < mesEleves.nb_eleves; i++) {
            free(mesEleves.prenoms[i]);
        }
        free(mesEleves.prenoms);
    }
    if (mesEleves.notes != NULL) {
        free(mesEleves.notes);
    }
}