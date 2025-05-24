#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Reserva memoria para una matriz cuadrada de tamaño tamano
void reservar_matriz(int ***matriz, int tamano) {
    *matriz = malloc(tamano * sizeof(int *));
    for (int i = 0; i < tamano; i++) {
        (*matriz)[i] = malloc(tamano * sizeof(int));
    }
}

// Llena la matriz con valores aleatorios (0 o 1)
void llenar_matriz(int **matriz, int tamano) {
    srand(time(NULL));
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            matriz[i][j] = rand() % 2;
        }
    }
}

// Imprime la matriz
void imprimir_matriz(int **matriz, int tamano) {
    printf("Matriz %dx%d:\n", tamano, tamano);
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Libera la memoria de la matriz
void liberar_matriz(int **matriz, int tamano) {
    for (int i = 0; i < tamano; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

/*
 * Encuentra la longitud de la secuencia de 1s más larga
 * en cualquier antidiagonal desde la esquina superior derecha hacia abajo.
 */
void encontrar_diagonal_mas_larga(int **matriz, int tamano, int *resultado) {
    int maxcont = 0;

    // Antidiagonales superiores (incluyendo la antidiagonal principal)
    for (int col = tamano - 1; col >= 0; col--) {
        int i = 0, j = col, cont = 0;
        while (i < tamano && j < tamano) {
            if (matriz[i][j] == 1) {
                cont++;
                if (cont > maxcont) maxcont = cont;
            } else {
                cont = 0;
            }
            i++;
            j++;
        }
    }

    // Antidiagonales inferiores 
    for (int fila = 1; fila < tamano; fila++) {
        int i = fila, j = 0, cont = 0;
        while (i < tamano && j < tamano) {
            if (matriz[i][j] == 1) {
                cont++;
                if (cont > maxcont) maxcont = cont;
            } else {
                cont = 0;
            }
            i++;
            j++;
        }
    }

    *resultado = maxcont;
}

//Añade valores aleatorios para aumentar la matriz o elimina valores para reducirla
int **redimensionar_matriz(int **matriz, int viejo_tamano, int nuevo_tamano) {
    int **nueva_matriz;
    nueva_matriz = (int **)malloc(nuevo_tamano * sizeof(int *));
    for (int i = 0; i < nuevo_tamano; i++) {
        nueva_matriz[i] = (int *)malloc(nuevo_tamano * sizeof(int));
    }

    for (int i = 0; i < nuevo_tamano; i++) {
        for (int j = 0; j < nuevo_tamano; j++) {
            if (i < viejo_tamano && j < viejo_tamano) {
                nueva_matriz[i][j] = matriz[i][j];
            } else {
                nueva_matriz[i][j] = rand() % 2; // valores nuevos aleatorios
            }
        }
    }

    liberar_matriz(matriz, viejo_tamano);
    return nueva_matriz;
}

int main() {
    int tamano, diagonal_mas_larga;
    int **matriz = NULL;

    srand(time(NULL));
    printf("Ingrese el tamaño inicial de la matriz: ");
    scanf("%d", &tamano);

    reservar_matriz(&matriz, tamano);
    llenar_matriz(matriz, tamano);

    int opcion;
    do {
        printf("\nMatriz actual:\n");
        imprimir_matriz(matriz, tamano);

        encontrar_diagonal_mas_larga(matriz, tamano, &diagonal_mas_larga);
        printf("La secuencia de 1s más grande es: %d\n", diagonal_mas_larga);

        printf("\n¿Desea cambiar el tamaño de la matriz? (1: Sí, 0: No): ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            int nuevo_tamano;
            printf("Ingrese el nuevo tamaño de la matriz: ");
            scanf("%d", &nuevo_tamano);
            matriz = redimensionar_matriz(matriz, tamano, nuevo_tamano);
            tamano = nuevo_tamano;
        }

    } while (opcion != 0);

    liberar_matriz(matriz, tamano);
    return 0;
}