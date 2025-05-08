#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generadoDeMatriz(int tamano, int matriz[tamano][tamano]) {
    srand(time(NULL));

    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            matriz[i][j] = rand() % 2;
        }
    }
}

void imprimirMatriz(int tamano, int matriz[tamano][tamano]) {
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int encontrarUnosAntidiagonal(int tamano, int matriz[tamano][tamano]) {
    int maxcont = 0;
    int cont = 0;

    for (int col = tamano - 1; col >= 0; col--) {
        int i = 0;
        int j = col;
        while (i < tamano && j >= 0) {
            if (matriz[i][j] == 1) {
                cont++;
                if (cont > maxcont) maxcont = cont;
            } else {
                cont = 0;
            }
            i++;
            j--;
        }
    }

    for (int row = 1; row < tamano; row++) {
        int i = row;
        int j = tamano - 1;
        while (i < tamano && j >= 0) {
            if (matriz[i][j] == 1) {
                cont++;
                if (cont > maxcont) maxcont = cont;
            } else {
                cont = 0;
            }
            i++;
            j--;
        }
    }

    return maxcont;
}

int main() {
    int tamano;
    printf("ingrese el tamano para columna o fila de la matriz");
    scanf("%d", &tamano);
    int matrizA[tamano][tamano];
    
    generadoDeMatriz(tamano,matrizA);
    imprimirMatriz(tamano, matrizA);

    int diagonal_mas_larga = encontrarUnosAntidiagonal(tamano, matrizA);
    printf("La secuencia de 1s mas grande es: %d\n", diagonal_mas_larga);

    return 0;
}


    
