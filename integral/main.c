#include <stdio.h>

double f(double x){
    return (3-x*x);
}
double integral_rectangle (double a, double b, int n) {
    double h = (b - a) / n;
    double somme = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + i * h;
        somme += f(x) * h;
    }
    return somme;
}

double integral_trapeze (double(*f) (double),double a, double b, int n) {
    double h = (b - a) / n;
    double somme = 0.0;
    for (int i = 0; i < n; i++) {
        somme += h*f(a+h*i);
    }
    return somme;
}

int main() {
    double air = integral_rectangle(0, 2,10);
    double AIR = integral_trapeze(f,0, 2,100000000000);
    printf("%lf %lf",air, AIR);
    return 0;
}