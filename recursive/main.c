//void affiche(int n, int fin)
//  if (){
//      return ;
//  }
//

#include <stdio.h>

int factorielle(int n) {
    if (n == 0) {
        return 1;
    }
    int resultat = n * factorielle(n - 1);
    return resultat;
}

void inverse(int n) {
    if (n >= 0) {
        printf("%d ", n);
        inverse(n - 1);
    }
}

void bonordre(int n) {
    if (n >= 0) {
        bonordre(n - 1);
        printf("%d ", n);
    }
}

double exp_simple(double x, int n) {
    if (n==0){
        return 1;
    }
    return x * exp_simple(x, n - 1);
}

double exp_rapide(double x, int n) {
    double result = 0;
    if (n == 0) {
        return 1;
    }
    if ((n % 2) == 0) {
        result = exp_rapide(x, n / 2);
        return result * result;
    } else {
        result = exp_rapide(x, (n - 1) / 2);
        return x * result * result;
    }
}

int pgcd (int p , int q ){
    if (p==0){
        return q;
    }
    if (q==0){
        return p;
    }
    if (p<=q){
        return pgcd(p,q-p);
    }
    return pgcd(p-q,q);
}

int fiboreclineaire(int n, int fib_2, int fib_1) {
    if (n<=1) return fib_1;
    else {
        fiboreclineaire(n - 1, fib_1, fib_2 + fib_1);
    }
}

int fibolineaire(int n) { /* fonction interface = pour avoir un appel plus "propre"*/
    return fiboreclineaire(n, 1, 1);
}

int main() {
    printf("%d! = %d\n", 5, factorielle(5));

    inverse(5);
    printf("\n");

    bonordre(5);
    printf("\n");

    printf("%f\n",exp_simple(5.0,4));

    printf("%f\n",exp_rapide(5.0,4));

    printf("%d\n",pgcd(5,4));

    int a = fibolineaire(5);
    return 0;
}
