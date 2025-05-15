#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//Genera un arreglo con numeros aleatorios entre 0 y 99 del tamano que el usuario seleccione
void generadoDeArreglo(int tamano, int arreglo[tamano]) {
    srand(time(NULL));
    for (int i = 0; i < tamano; i++) {
        arreglo[i] = rand() % 100;
    }
}

//Desplega el arreglo iterando cada posicion
void imprimirArreglo(int tamano, int arreglo[tamano]) {
    for (int i = 0; i < tamano; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

//Utiliza una version optimizada del algoritmo bubble sort para ordenar el arreglo de menor a mayor
void bubbleSortOpt(int tamano, int arreglo[tamano]) {
    bool cambiados;
    int i = 0;
    do {
        cambiados = false;
        for (int j = 0; j < tamano - 1 - i; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
                cambiados = true;
            }
        }
        i++;
    } while (cambiados);
}

//Utiliza una version basica del algoritmo bubble sort para ordenar el arreglo de menor a mayor
void bubbleSortBasico(int tamano, int arreglo[tamano]) {
    for (int j = 0; j < tamano; j++) {
        for (int i = 0; i < tamano - 1; i++) {
            if (arreglo[i] > arreglo[i + 1]) {
                int temp = arreglo[i];
                arreglo[i] = arreglo[i + 1];
                arreglo[i + 1] = temp;
            }
        }
    }
}

//Utiliza el algoritmo selection sort para ordenar el arreglo de menor a mayor
void selectionSort(int tamano, int arreglo[tamano]) {
    for (int i = 0; i < tamano - 1; i++) {
        int posmin = i;
        for (int j = i + 1; j < tamano; j++) {
            if (arreglo[j] < arreglo[posmin]) {
                posmin = j;
            }
        }
        if (posmin != i) {
            int temp = arreglo[i];
            arreglo[i] = arreglo[posmin];
            arreglo[posmin] = temp;
        }
    }
}

//Pide al usuario ingresar el valor de tamano para generar la matriz. 
//Guarda 3 copias del arreglo para probarlo con cada algoritmo
//Utiliza la funcion clock() antes y despues de correr cada funcion para medir el tiempo que dura en correr
int main() {
    int tamano;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &tamano);

    int arreglo[tamano];
    generadoDeArreglo(tamano, arreglo);

    int copia1[tamano];
    int copia2[tamano];

    for (int i = 0; i < tamano; i++) {
        copia1[i] = arreglo[i];
        copia2[i] = arreglo[i];
    }

    printf("\nArreglo original:\n");
    imprimirArreglo(tamano, arreglo);

    clock_t start, end;
    double tiempo;

    start = clock();
    bubbleSortOpt(tamano, arreglo);
    end = clock();
    tiempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nBubble Sort Optimizado:\n");
    imprimirArreglo(tamano, arreglo);
    printf("Tiempo: %.6f segundos\n", tiempo);

    start = clock();
    bubbleSortBasico(tamano, copia1);
    end = clock();
    tiempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nBubble Sort Basico:\n");
    imprimirArreglo(tamano, copia1);
    printf("Tiempo: %.6f segundos\n", tiempo);

    start = clock();
    selectionSort(tamano, copia2);
    end = clock();
    tiempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nSelection Sort:\n");
    imprimirArreglo(tamano, copia2);
    printf("Tiempo: %.6f segundos\n", tiempo);

    return 0;
}