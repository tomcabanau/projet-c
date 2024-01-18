#include <stdio.h>
#include <stdlib.h>

void writeMultiplication(char* filename, int integer);
void readOperations(char* filename);

int main() {

    writeMultiplication("table10.txt", 10);
    readOperations("operation.txt");

    return 0;
}

void writeMultiplication(char* filename, int integer){
    FILE * monFichier;
    monFichier = fopen(filename, "w");
    if ( monFichier != NULL ) {
        fprintf(monFichier, "%d\n", integer);

        for(int i = 0; i < integer+1; i++) {
            for (int j = 0; j < integer+1; ++j) {
                fprintf(monFichier, "%4d", i*j);
            }
            fprintf(monFichier, "\n");
        }
    } else {
        fprintf(stderr, "Cannot open file\n");
    }
    fclose(monFichier);
}

void readOperations(char* filename) {
    FILE* file;
    file = fopen(filename, "r");
    if(file != NULL) {
        while(!feof(file)) {
            int a = 0;
            int b = 0;
            char * line = NULL;
            size_t length = 0;

            getline(&line, &length, file);
            sscanf(line, "%d %d", &a, &b);

            printf("%d x %d = %d\n", a, b, a*b);
            free(line);
        }
    } else {
        fprintf(stderr, "Error\n");
    }
    fclose(file);
}