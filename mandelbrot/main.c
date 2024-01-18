#include <stdio.h>

#define LARGEUR_IMAGE 800
#define HAUTEUR_IMAGE 600
#define ZOOM_VALUE 0.05

int valeur_pixel(double a, double b) {
    double x = 0.0, y = 0.0;
    int m = 2;
    for (int n = 1; n <= 1000; n++) {
        double X = x*x-y*y+a;
        y = 2*x*y+b;
        x = X;
        if (x*x+y*y >= m*m) {
            return n % 255;
        } else if (n == 1000) {
            return 0;
        }
    }
    return 0;
}

void calculer_fractale_mandelbrot(double xmin, double xmax, double ymin, double ymax, int tab[LARGEUR_IMAGE][HAUTEUR_IMAGE]) {
    double X = (xmax - xmin) / LARGEUR_IMAGE;
    double Y = (ymax - ymin) / HAUTEUR_IMAGE;
    for (int i = 0; i < LARGEUR_IMAGE; i++) {
        for (int j = 0; j < HAUTEUR_IMAGE; j++) {
            double a = xmin + i * X;
            double b = ymin + j * Y;
            tab[i][j] = valeur_pixel(a, b);
        }
    }
}

void ecrire_fichier_ppm(int tab[LARGEUR_IMAGE][HAUTEUR_IMAGE], int image) {
    char path[50];
    sprintf(path,"images/image%d.ppm",image+1000);
    FILE *fichier = fopen(path, "w");
    fprintf(fichier,"P3\n");
    fprintf(fichier,"%d %d\n", LARGEUR_IMAGE, HAUTEUR_IMAGE);
    fprintf(fichier,"255\n");
    for (int j = 0; j < HAUTEUR_IMAGE; j++) {
        for (int i = 0; i < LARGEUR_IMAGE; i++) {
            int n = tab[i][j];
            int R = (n+300)%255;
            int G = (n+100)%255;
            int B = (n+200)%255;
            fprintf(fichier,"%d %d %d ", R, G, B);
        }
        fprintf(fichier,"\n");
    }
    fclose(fichier);
}

int main() {
    double xmin, xmax, ymin, ymax;
    int tab[LARGEUR_IMAGE][HAUTEUR_IMAGE];
    int num_image;

    printf("Fractale de Mandelbrot\n"
           "----------------------\n"
           "Entrez les valeurs de xMin, xMax, yMin, yMax et le numéro de l'image N:\n");
    scanf("%lf %lf %lf %lf %d", &xmin, &xmax, &ymin, &ymax, &num_image);

    for (int image = 1; image <= num_image; image++) {
        xmin = xmin - (xmax - xmin) * ZOOM_VALUE;
        xmax = xmax + (xmax - xmin) * ZOOM_VALUE;
        ymin = ymin - (ymax - ymin) * ZOOM_VALUE;
        ymax = ymax + (ymax - ymin) * ZOOM_VALUE;

        calculer_fractale_mandelbrot(xmin, xmax, ymin, ymax, tab);
        ecrire_fichier_ppm(tab, image);
    }
    return 0;
}
