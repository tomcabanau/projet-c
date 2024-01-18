#include <stdio.h>


int sudoku[9][9]={{7,0,3,0,0,4,6,0,0},
                  {0,0,9,1,0,0,3,0,0},
                  {0,4,0,0,9,0,0,0,7},
                  {6,0,0,2,4,0,5,0,3},
                  {4,0,0,3,0,1,0,0,0},
                  {3,0,0,0,6,7,0,0,1},
                  {1,0,4,0,0,0,0,9,0},
                  {0,5,0,0,0,0,8,0,2},
                  {0,0,6,7,0,9,1,0,5},
                  };

int l(int n) {
    return n - n % 3;
}

int c(int n) {
    return (n % 3) * 3;
}

void afficherLigne(int i) {
    for (int j = 0; j < 9; j++) {
        printf("%d ", sudoku[i][j]);
    }
    printf("\n");
}


void afficherColonne(int i) {
    for (int j = 0; j < 9; j++) {
        printf("%d ", sudoku[j][i]);
    }
    printf("\n");
}


void afficherCarre(int i) {
    int ligneDebut = l(i);
    int colonneDebut = c(i);
    for (int j = ligneDebut; j < ligneDebut + 3; j++) {
        for (int k = colonneDebut; k < colonneDebut + 3; k++) {
            printf("%d ", sudoku[j][k] == 0);
        }
        printf("\n");
    }
}


void afficherSudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j] == 0);
        }
        printf("\n");
    }
}


int ligneValide(int ligne) {
    int occurences[10] = {0};
    for (int j = 0; j < 9; j++) {
        int chiffre = sudoku[ligne][j];
        if (chiffre != 0) {
            if (occurences[chiffre] == 1) {
                return 0;
            }
            occurences[chiffre]++;
        }
    }
    return 1;
}


int colonneValide(int colonne) {
    int occurences[10] = {0};
    for (int i = 0; i < 9; i++) {
        int chiffre = sudoku[i][colonne];
        if (chiffre != 0) {
            if (occurences[chiffre] == 1) {
                return 0;
            }
            occurences[chiffre]++;
        }
    }
    return 1;
}


int carreValide(int carre) {
    int ligneDebut = l(carre);
    int colonneDebut = c(carre);
    int occurences[10] = {0};
    for (int i = ligneDebut; i < ligneDebut + 3; i++) {
        for (int j = colonneDebut; j < colonneDebut + 3; j++) {
            int chiffre = sudoku[i][j];
            if (chiffre != 0) {
                if (occurences[chiffre] == 1) {
                    return 0;
                }
                occurences[chiffre]++;
            }
        }
    }
    return 1;
}



int sudokuValide() {
    for (int i = 0; i < 9; i++) {
        if (!ligneValide(i) || !colonneValide(i) || !carreValide(i)) {
            return 0;
        }
    }
    return 1;
}

int ligne_remplie(int b) {
    for (int i = 0; i < 9; i++) {
        int valeur = sudoku[b][i];
        if (valeur == 0) {
            return 0;
        }
    }
    return 1;
}


int colonne_remplie(int b){
    for (int i = 0; i < 9; i++){
        int valeur = sudoku[i][b];
        if (valeur == 0){
            return 0;
        }
    }
    return 1;
}

int carre_remplie(int b){
    int ligneDebut = l(b);
    int colonneDebut = c(b);
    for (int i = ligneDebut; i < ligneDebut + 3; i++) {
        for (int j = colonneDebut; j < colonneDebut + 3; j++) {
            if (sudoku[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int ligne_terminee(int b){
    if (!ligneValide(b) || !ligne_remplie(b)) {
        return 0;
    }
    return 1;
}

int colonne_terminee(int b){
    if (!colonneValide(b) || !colonne_remplie(b)){
        return 0;
    }
    return 1;
}

int carre_termine(int b){
    if (!carreValide(b) || !carre_remplie(b)){
        return 0;
    }
    return 1;
}

void propose(int x, int y) {
    int ligneCarre = l(x);
    int colonneCarre = c(y);
    int chiffresPossibles[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    for (int i = 0; i < 9; i++) {
        chiffresPossibles[sudoku[x][i]] = 0;
        chiffresPossibles[sudoku[i][y]] = 0;
    }

    for (int i = ligneCarre; i < ligneCarre + 3; i++) {
        for (int j = colonneCarre; j < colonneCarre + 3; j++) {
            printf("%d",sudoku[i][j]);
            chiffresPossibles[sudoku[i][j]] = 0;
        }
    }
    printf("\n");
    for(int i = 0;i < 9;i++){
        printf("%d",chiffresPossibles[i]);
    }
    printf("\n");
    printf("Chiffres proposés à la position (%d, %d) : ", x, y);
    for (int i = 1; i <= 9; i++) {
        if (chiffresPossibles[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}



int main() {
    afficherLigne(0);
    printf("\n");
    afficherColonne(0);
    printf("\n");
    afficherCarre(0);
    printf("\n");
    afficherSudoku();
    printf("\n");

    if (sudokuValide()) {
        printf("Le sudoku est valide.\n");
    } else {
        printf("Le sudoku n'est pas valide.\n");
    }

    printf("\n");

    if (ligne_remplie(0)) {
        printf("La ligne est remplie.\n");
    } else {
        printf("La ligne n'est pas remplie.\n");
    }

    if (colonne_remplie(0)) {
        printf("La colonne est remplie.\n");
    } else {
        printf("La colonne n'est pas remplie.\n");
    }

    if (carre_remplie(0)) {
        printf("Le carré est remplie.\n");
    } else {
        printf("Le carré n'est pas remplie.\n");
    }

    printf("\n");

    if (ligne_terminee(0)) {
        printf("La ligne est terminé.\n");
    } else {
        printf("La ligne n'est pas terminé.\n");
    }

    if (colonne_terminee(0)) {
        printf("La colonne est terminé.\n");
    } else {
        printf("La colonne n'est pas terminé.\n");
    }

    if (carre_termine(0)) {
        printf("Le carré est terminé.\n");
    } else {
        printf("Le carré n'est pas terminé.\n");
    }

    propose(1,1);

    return 0;
}
