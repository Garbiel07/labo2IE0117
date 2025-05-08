#include <stdio.h>

int SumaDeInferiores(int distancia, int tamano, int matriz[tamano][tamano]){
    int suma = 0;
    for (int i=distancia, j=0; i<tamano; i++, j++){
            suma += matriz[i][j];            
        }
    return suma;
}

int SumaDeSuperiores(int desplazamiento, int tamano, int matriz[tamano][tamano]){
    int suma = 0;
    for (int i=0, j=desplazamiento; i<tamano; i++, j++){
            suma += matriz[i][j];            
        }
    return suma;
}

void ObtenerEspejo(int tamano, int matriz[tamano][tamano]){
    for (int i=0; i<tamano;i++){
        for (int j=0; j<tamano/2; j++){
            int temp = matriz[i][j];
            matriz[i][j] = matriz [i][tamano-1-j];
            matriz[i][tamano-1-j]=temp;
        }
    }
}

void SumaTotal(int tamano, int matriz[tamano][tamano]){
    for (int distancia = tamano-1; distancia>0; distancia--){
        int suma = SumaDeInferiores(distancia, tamano, matriz);
        printf("la suma de la diagonal %d: %d\n", tamano-distancia, suma);
    }

    int sumaPrincipal = SumaDeInferiores(0, tamano, matriz);
    printf("Suma de diagonal principal: %d\n", sumaPrincipal);

    for (int desplazamiento = 1; desplazamiento<tamano; desplazamiento++){
        int suma = SumaDeSuperiores(desplazamiento, tamano, matriz);
        printf("la suma de la diagonal %d: %d\n", desplazamiento+tamano, suma);
    }

    ObtenerEspejo(tamano, matriz);

    for (int distancia = tamano-1; distancia>0; distancia--){
        int suma = SumaDeInferiores(distancia, tamano, matriz);
        printf("la suma de la diagonal %d: %d\n", tamano-distancia+9, suma);
    }

    sumaPrincipal = SumaDeInferiores(0, tamano, matriz);
    printf("Suma de diagonal principal: %d\n", sumaPrincipal);

    for (int desplazamiento = 1; desplazamiento<tamano; desplazamiento++){
        int suma = SumaDeSuperiores(desplazamiento, tamano, matriz);
        printf("la suma de la diagonal %d: %d\n", desplazamiento+tamano+9, suma);
    }
}


int main() {
    int matrizA[5][5] = {
        {5, 7, 8, 1, 3},
        {4, 6, 7, 5, 7},
        {2, 3, 4, 7, 3},
        {5, 7, 8, 3, 5},
        {1, 3, 2, 4, 9},
    };

    int matrizB[6][6] = {
        {5, 7, 8, 1, 3, 6},
        {4, 6, 7, 5, 7, 3},
        {2, 3, 4, 7, 3, 7},
        {5, 7, 8, 3, 5, 9},
        {1, 3, 2, 4, 9, 3},
        {4, 3, 1, 2, 5, 3},
    };

    int matrizC[7][7] = {
        {5, 7, 8, 1, 3, 5, 8},
        {4, 6, 7, 5, 7, 4, 2},
        {2, 3, 4, 7, 3, 1, 3},
        {5, 7, 8, 3, 5, 5, 9},
        {1, 3, 2, 4, 9, 6, 5},
        {3, 7, 5, 1, 8, 5, 8},
        {5, 2, 8, 7, 3, 4, 8},
    };

    int opcion;
    printf("Para elegir una matriz, digite: \n");
    printf("1 (Matriz 5x5)\n");
    printf("2 (Matriz 6x6)\n");
    printf("3 (Matriz 7x7)\n");
    scanf("%d", &opcion);

    int sumaPrincipal;
    switch (opcion) {

        case 1: {
            int tamano=sizeof(matrizA) / sizeof(matrizA[0]);
            SumaTotal(tamano, matrizA);
            break;
        }
        case 2:{
            int tamano=sizeof(matrizB) / sizeof(matrizB[0]);
            SumaTotal(tamano, matrizB);
            break;
        }
        case 3:{
            int tamano=sizeof(matrizC) / sizeof(matrizC[0]);
            SumaTotal(tamano, matrizC);
            break;
        }
        default:
            printf("opcion invalida.\n");
            break;
    }
    return 0;
}