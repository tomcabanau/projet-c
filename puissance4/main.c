#include <stdio.h>
#define SIZE 7
#define VIDE 0
#define JOUEUR1 1
#define JOUEUR2 2

void initialise_grille(int grille[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            grille[i][j] = VIDE;
        }
    }
}

void ligne_horizontale() {
    printf("+---+---+---+---+---+---+---+\n");
}

void numerotation() {
    printf("  0   1   2   3   4   5   6\n");
}

void affiche_grille(int grille[SIZE][SIZE]){
    printf("---------------\n"
                  "| Puissance 4 |\n"
                  "---------------\n");
    numerotation();
    ligne_horizontale();
    for(int i = 0; i < SIZE; i++) {
        printf("|");
        for(int j = 0; j < SIZE; j++) {
            if (grille[i][j] == VIDE) {
                printf("   |");
            } else if (grille[i][j] == JOUEUR1) {
                printf(" O |");
            } else if (grille[i][j] == JOUEUR2) {
                printf(" X |");
            }
        }
        printf("\n");
        ligne_horizontale();
    }
    numerotation();
}

int remplissage(int grille[SIZE][SIZE], int colonne){
    int element=0;
    for(int i=0;i < 7;i++){
        if(grille[i][colonne] != VIDE){
            element += 1;
        }
    }
    return element;
}

void poser_pion(int grille[SIZE][SIZE], int colonne, int joueur){
    if (remplissage(grille,colonne) >= SIZE){
        printf("la colonne est remplie");
    } else {
        grille[SIZE-1-remplissage(grille,colonne)][colonne]=joueur;
    }
}

int demander_colonne(int grille[SIZE][SIZE],int *colonne){
    do {
        printf("Entrez une colonne (entre 0 et 6) : ");
        scanf("%d", colonne);
        if (*colonne < 0 || *colonne >= SIZE) {
            printf("La colonne n'est pas valide. Veuillez entrer une colonne entre 0 et %d.\n", SIZE - 1);
        } else if (grille[0][*colonne] != 0) {
            printf("La colonne est pleine. Veuillez choisir une autre colonne.\n");
        } else {
            return 1;
        }
    } while (1);

}

int verifie_horizontal(int grille[SIZE][SIZE], int joueur) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <= SIZE - 4; j++) {
            if (grille[i][j] == joueur && grille[i][j + 1] == joueur && grille[i][j + 2] == joueur && grille[i][j + 3] == joueur) {
                return joueur;
            }
        }
    }
    return 0;
}

int verifie_vertical(int grille[SIZE][SIZE], int joueur) {
    for (int i = 0; i <= SIZE - 4; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grille[i][j] == joueur && grille[i + 1][j] == joueur && grille[i + 2][j] == joueur && grille[i + 3][j] == joueur) {
                return joueur;
            }
        }
    }
    return 0;
}

int verifie_diagonale(int grille[SIZE][SIZE], int joueur) {
    for (int i = 0; i <= SIZE - 4; i++) {
        for (int j = 0; j <= SIZE - 4; j++) {
            if (grille[i][j] == joueur &&
                grille[i + 1][j + 1] == joueur &&
                grille[i + 2][j + 2] == joueur &&
                grille[i + 3][j + 3] == joueur) {
                return joueur;
            }
        }
    }
    return 0;
}

int gagner(int grille[SIZE][SIZE], int joueur) {
    if (verifie_horizontal(grille, joueur) || verifie_vertical(grille, joueur) || verifie_diagonale(grille, joueur)) {
        return joueur;
    }

    return 0;
}

int main() {
    int grille[SIZE][SIZE];
    int colonne = -1;
    int a=1;
    int joueur;
    initialise_grille(grille);
    int casee = 0;
    for(int i=0; i< SIZE;i++){
        for(int j=0; j< SIZE;j++){
            if(grille[i][j] == VIDE){
                casee +=1;
            }
        }
    }
    printf("%d", remplissage(grille,colonne));
    while(casee>0){
        affiche_grille(grille);
        if(a%2 != 0){
            joueur= JOUEUR1;
        } else {
            joueur = JOUEUR2;
        }
        if(demander_colonne(grille,&colonne)){
            poser_pion(grille,colonne,joueur);
            casee--;
            a++;
            int resultat = gagner(grille, joueur);
            if (resultat) {
                affiche_grille(grille);
                printf("Le joueur %d a gagné !\n", resultat);
                return 0;
            }
        }
    }
    affiche_grille(grille);
    printf("Match nul !\n");
    return 0;
}
