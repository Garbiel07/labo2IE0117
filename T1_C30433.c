#include <stdio.h>
#include <stdlib.h>

#define MAX_TAMANO 50

int leerPrimeraMatriz(const char* nombreArchivo, int matriz[MAX_TAMANO][MAX_TAMANO]) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 0;
    }

    char linea[512];
    int fila = 0;

    while (fila < MAX_TAMANO && fgets(linea, sizeof(linea), archivo) != NULL) {
        if (linea[0] == '\n' || linea[0] == '\r') break;

        int col = 0;
        int valor;
        char* ptr = linea;

        while (sscanf(ptr, "%d", &valor) == 1) {
            matriz[fila][col] = valor;
            col++;

            while (*ptr != ' ' && *ptr != '\0') ptr++;
            while (*ptr == ' ') ptr++;
        }
        fila++;
    }

    fclose(archivo);
    return fila;  // Assuming square matrix, so filas = columnas
}

void imprimirMatriz(int tamano, int matriz[MAX_TAMANO][MAX_TAMANO]) {
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int encontrarUnosAntidiagonal(int tamano, int matriz[MAX_TAMANO][MAX_TAMANO]) {
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
    int matriz[MAX_TAMANO][MAX_TAMANO];
    int tamano = leerPrimeraMatriz("Matrices.txt", matriz);

    if (tamano == 0) {
        return 1;
    }

    printf("Matriz leída:\n");
    imprimirMatriz(tamano, matriz);

    int diagonal_mas_larga = encontrarUnosAntidiagonal(tamano, matriz);
    printf("La secuencia de 1s mas grande en las antidiagonales es: %d\n", diagonal_mas_larga);

    return 0;
}