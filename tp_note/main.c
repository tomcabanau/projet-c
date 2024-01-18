// TOM CABANAU CIR1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTENCE_SIZE 100
#define MAX_PLAYER 3

void printSentence(const char* sentence, const int* revealed){
    //la fonction parcourt chaque caractère de sentence grâce a la boucle for qui va de 0 a la fin
    //avec le strlen et qui test pour chaque caractere si la valeur qui lui est associé dans le revealed
    //est 1 ou 0
    for(int i=0; i<strlen(sentence); i++){
        if(revealed[i] == 1 || sentence[i] == ' '){
            printf("%c", sentence[i]);
        } else {
            printf("_");
        }
    }
    printf("\n");
}

void initRevealed(const char* sentence, int * revealed){
    // la focntion parcourt chaque caractere comme dans la question 1 et regarde si le carctere est
    // une majuscule ou une minuscule et si c'est le cas met l'indice du carctere dans le revealed a 0
    // si ce n'est pas le cas et que ce n'est pas une lettre, la fonction met l'indice du caractere
    // dans le revealded a 1
    for(int i=0; i<strlen(sentence); i++){
        if(sentence[i] >= 'A' && sentence[i] <= 'z'){ // Si la lettre est une majuscule ou une minuscule
            revealed[i] = 0;
        } else {
            revealed[i] = 1;
        }
    }
}

int chooseAction(){
    // dans une boucle while, tant que le choix n'est pas correct la fonction affiche les choix
    int choix;
    printf("Faites un choix : ");
    scanf("%d", &choix);
    return choix;
}

int nextPlayer(int player){
    // la fonction permet de passer au joueur suivant car:
    // joueur = 0 et (0+1) modulo 3 = 1
    // joueur = 1 et (1+1) modulo 3 = 2
    // joueur = 2 et (2+1) modulo 3 = 0
    return (player + 1) % MAX_PLAYER;
}

char chooseLetter(int vowel){
    // la fonction test si vowel est 1 donc une voyelle ou 0 une consonne et demande l'une ou l'autre
    // avant de la renvoyer
    char lettre;
    if(vowel == 0){
        printf("Entre une consonne en majuscule : ");
    } else {
        printf("Entre une voyelle en majuscule : ");
    }
    scanf(" %c", &lettre);
    return lettre;
}


int proposeConsonant(const char* sentence, int * revealed, int *gains, int player){
    int nbconsonnes = 0;
    printf("Le joueur %d, ", player);
    char lettre = chooseLetter(0);
    for(int i=0; i<strlen(sentence); i++){
        if(sentence[i] == lettre && revealed[i] == 0){    //pour chaque caractere regarde si il corresopnd a
            revealed[i] = 1;                              // la lettre entrée et sa valeur dans le revealed
        } else if(revealed[i] == 1){                      // n'est pas égale a 0. Si oui une consonne est trouvé et l'on ajoute 1 au gain du joueur l'ayant trouvé
            revealed[i] = 1;
        } else {
            revealed[i] = 0;
        }
    }
    return nbconsonnes;
}

// Fonction pour acheter une voyelle
int buyVowel(const char* sentence, int * revealed, int * gains, int player){
    int nbvoyelle = 0;
    printf("Le joueur %d, ", player);
    char lettre = chooseLetter(1);
    for(int i=0; i<strlen(sentence); i++){
        if(sentence[i] == lettre && revealed[i] == 0){      // même fonctionnement que dans proposeConsonant mais
            nbvoyelle++;                                    // on enleve 1 au gain
            revealed[i] = 1;
            (*gains)--;
        } else if(revealed[i] == 1){
            revealed[i] = 1;
        } else {
            revealed[i] = 0;
        }
    }
    return nbvoyelle;
}

// Fonction pour proposer une phrase
int proposeSentence(const char* sentence){
    char phrase[SENTENCE_SIZE];
    char caractere;
    int index = 0;
    printf("Entrez une phrase : ");
    while (scanf(" %c", &caractere) == 1 && caractere != '\n') {
        phrase[index] = caractere;
        index++;
        if (index >= SENTENCE_SIZE - 1) {
            break;
        }
    }
    phrase[index] = '\0';
    return strcmp(phrase, sentence) == 0;
}

// Fonction principale du jeu
void game(const char* sentence, int * revealed){
    int player = 0;
    int result = 0;
    int gains[3] = {0};
    printf("J0 : %d, J1 : %d, J2 : %d\n", gains[0], gains[1], gains[2]);
    initRevealed(sentence, revealed);
    printSentence(sentence, revealed);
    while (result != 1) {
        int choice;
        do {
            printf("Joueur %d, faites un choix :\n"
                   "0. Quitter\n"
                   "1. Proposer une consonne\n"
                   "2. Acheter une voyelle\n"
                   "3. Acheter une phrase\n", player);
            choice = chooseAction();
        } while (choice < 0 || choice > 3);
        switch (choice) {
            case 0:
                result = 1;
                break;
            case 1:
                gains[player] += proposeConsonant(sentence, revealed, &gains[player], player);
                break;
            case 2:
                gains[player] -= buyVowel(sentence, revealed, &gains[player], player);
                break;
            case 3:
                result = proposeSentence(sentence);
                break;
        }
        printSentence(sentence, revealed);
        int nb=0;
        for(int i=0;i<strlen(sentence);i++){
            if(sentence[i] == '_'){
                nb++;
            }
            if (nb == 0) {
                printf("La phrase a été découverte !\n");
                result = 1;
            }
        }
        player = nextPlayer(player);
    }
    printf("Fin du jeu!\nScores:\nJ0 : %d\nJ1 : %d\nJ2 : %d\n", gains[0], gains[1], gains[2]);
}


// Fonction principale du programme
int main() {
    char sentence[SENTENCE_SIZE] = "VIVE LE VENT D'HIVER!";
    int revealed[SENTENCE_SIZE] = {1,1,1,1};

    //printSentence(sentence,revealed);  test de la fonction de la question 1

    //initRevealded(sentence,revealed);  test de la fonction de la question 2
    //printSentence(sentence,revealed);

    //printf("%d", chooseAction());  test de la fonction de la question 3

    game(sentence, revealed);

    return 0;
}
