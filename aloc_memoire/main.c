#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "etudiant.h"


// NE PAS MODIFIER LE MAIN

int main() {
    char * alph = alphabet_min();
    printf("l'alphabet %s\n", alph);
    free(alph);
    char lesPrenoms[NB_ELEVES][NAME_LEN]={"Thomas",
                                          "Gustave",
                                          "Quentin",
                                          "Maxime",
                                          "Cyriac",
                                          "Liam",
                                          "Jack",
                                          "Tom",
                                          "Mathis",
                                          "Thierry",
                                          "Eliotte",
                                          "Antoine",
                                          "Edouard",
                                          "Mathis",
                                          "Etienne",
                                          };
    int* lesNotes=notes(NB_ELEVES);
    if (lesNotes != NULL){
        printf("voici les notes avant modification : \n");
        for(int i=0;i<NB_ELEVES;i++){
            printf("%d : %d, ", i+1, lesNotes[i] );
        }
        printf("\n");
    }else{
        printf("Le tableau de notes n'est pas initialisé\n");
    }
    char * professeur = copie_chaine("Simon Le Gloannec");
    printf("Professeur : %s\n", professeur);
    free(professeur);

    eleves mesEleves;
    init_eleves(&mesEleves);

    mesEleves.prenoms = copie_chaines(NB_ELEVES, lesPrenoms);
    mesEleves.notes = lesNotes;
    mesEleves.nb_eleves = NB_ELEVES;

    if (mesEleves.prenoms != NULL && mesEleves.notes != NULL){
        entrer_notes(&mesEleves);
        printf("Voici les notes finales \n");
        affiche_notes(mesEleves);
    }
    else{
        printf("Un element de mesEleves est mal initialisé : \n");
        printf("eleves %d\n", mesEleves.prenoms);
        printf("notes %d\n", mesEleves.notes); ;

    }

    libererClasse(mesEleves);

    return 0;

}

