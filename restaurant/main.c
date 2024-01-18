#include <stdio.h>
#define N 10

struct s_resto {
    char nom[100];
    int qualite;
    int distance;
    int temps;
};

struct s_resto saisirResto() {
    struct s_resto restaurant;

    printf("Nom du restaurant : ");
    scanf("%s", restaurant.nom);
    printf("Qualite du restaurant (entre 0 et 100) : ");
    scanf("%d", &restaurant.qualite);
    printf("Distance du restaurant : ");
    scanf("%d", &restaurant.distance);
    restaurant.temps = 999;
    return restaurant;
}


void saisirRestos(struct s_resto tableauRestos[N], int* nombreRestos) {
    printf("Combien de restaurants souhaitez-vous saisir ? ");
    scanf("%d", nombreRestos);
    for (int i = 0; i < *nombreRestos; i++) {
        printf("\nSaisie du restaurant %d :\n", i + 1);
        tableauRestos[i] = saisirResto();
    }
}


int main() {
    struct s_resto tableauRestos[N];
    int nombreRestos;
    saisirRestos(tableauRestos, &nombreRestos);

    return 0;
}
