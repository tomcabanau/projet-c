//
// Created by ISEN on 07/12/2020.
//

#ifndef MEMOIREDYNAMIQUE_ETUDIANT_H
#define MEMOIREDYNAMIQUE_ETUDIANT_H

#define NB_ELEVES 15
#define NAME_LEN 30

typedef struct s_eleves{
    int nb_eleves;
    char ** prenoms;
    int * notes;

}eleves;

char * alphabet_min(); // fonction exemple

void init_eleves(eleves* mesEleves);

int * notes(int nb_notes);

char *copie_chaine(char chaine[NAME_LEN]);

char ** copie_chaines(int nb_chaines, char chaines[][NAME_LEN]);

void affiche_notes(eleves mesEleves);

void entrer_notes(eleves* mesEleves);



void libererClasse(eleves mesEleves);

#endif //MEMOIREDYNAMIQUE_ETUDIANT_H
