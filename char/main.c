#include<stdio.h>
#include<string.h>
#include <ctype.h>

int voyelles(char chaine[]) {
    int nbvoyelle = 0;
    for (int i = 0; i < strlen(chaine); i++) {
        if (chaine[i] == 'a' || chaine[i] == 'e' || chaine[i] == 'i' || chaine[i] == 'o' || chaine[i] == 'u' ||chaine[i] == 'y') {
            nbvoyelle++;
        }
    }
    return nbvoyelle;
}

void majuscule(char* chaine) {
    int decalage = 'A' - 'a';
    int l = strlen(chaine);
    for(int i = 0; i < l; i++){
        if (chaine[i] >= 'a' && chaine[i] <= 'z'){
            chaine[i] += 'A' - 'a';
        }
    }
}

int estPalindrome(char chaine[]) {
    int debut = 0;
    int fin = strlen(chaine) - 1;
    while (debut < fin) {
        if (chaine[debut] != chaine[fin]) {
            return 0;
        }
        debut++;
        fin--;
    }
    return 1;
}

int anagramme(char mot1[], char mot2[]) {
    int occurrences[26] = {0};
    for (int i = 0; mot1[i] != '\0'; i++) {
        occurrences[mot1[i]]++;
    }
    for (int i = 0; mot2[i] != '\0'; i++) {
        occurrences[mot2[i]]--;
        if (occurrences[mot2[i]] < 0) {
            return 0;
        }
    }
    for (int i = 0; i < 128; i++) {
        if (occurrences[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {

    char chaine[32];
    printf("Entrer un mot : ");
    fgets(chaine, 32, stdin);
    chaine[strlen(chaine) - 1] = '\0';
    int nombre_voyelles = voyelles(chaine);
    printf("Nombre de voyelles dans le mot '%s' : %d\n", chaine, nombre_voyelles);


    majuscule(chaine);
    printf("votre chaine en majuscule est : %s\n", chaine);


    if (estPalindrome(chaine)) {
        printf("\"%s\" est un palindrome.\n", chaine);
    } else {
        printf("\"%s\" n'est pas un palindrome.\n", chaine);
    }

    char mot1[32];
    printf("Entrer un premier mot : ");
    fgets(mot1, 32, stdin);
    char mot2[32];
    printf("Entrer un deuxième mot : ");
    fgets(mot2, 32, stdin);
    if (anagramme(mot1, mot2)){
        printf("%s et %s sont un anagramme. \n",mot1, mot2);
    } else {
        printf("%s et %s ne sont pas un anagramme. \n",mot1, mot2);
    }

    return 0;
}
