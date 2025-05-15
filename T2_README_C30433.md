# Tarea 2

## Función generadoDeArreglo
Toma como parámteros el arreglo y su tamaño. Utiliza la linea srand(time(NULL)) 
para inicializar el generador aleatorio usando un valor de semilla generado con la medición 
del tiempo al correr el programa. Luego, usa un ciclo for para iterar a través del arreglo
y asigna un valor a cada posicón con la función rand() % 100 para asignar un valor aleatorio
entre 0 y 100.

## Función imprimirArreglo
Usa un ciclo for para iterar a través del arreglo e imprimir el valor de la posición en la
que se encuentra.

## Función bubbleSortBasico
Utiliza dos ciclos for anidados para recorrer el arreglo el número de veces que corresponda
al tamaño del arreglo - 1. Luego, utiliza el condicional if y una variable temporal 
para sustituir el valor de la posición i por el valor de i+1 si el valor en i es mayor a valor i+1. 

## Función bubbleSortOpt
Realiza lo mismo que la función bubbleSortBasico pero en vez de recorrer el arreglo 
completamente todas las veces, cada recorrido se recorta en i posiciones ya que las últimas
i posiciones siempre van a estar ordenadas porque este algoritmo tiene la característica de que
coloca el valor máximo de último en cada recorrido. Además, se define la variable booleana
"cambiados", la cuál en conjunto con un ciclo do while revisan si cada para revisado 
está ordenado o no. Esto se hace ya que en el caso de que se recorra el arreglo y 
todos los pares estén ordenados, no es necesrio recorrerlo más veces así que permite terminar
el programa más temprano.

## Función selectionSort
Esta función usa dos ciclos anidados igual que antes, pero en vez de comparar las posiciones 
i e i+1, compara la posición correspondiente al número de recorrido con cada valor a la derecha.
Es decir, de la posición i a la izquierda el array está ordenado y de la i a la derecha está desordenado.

## Función main
Primero pide al usuario un tamaño para el array. Luego, genera 3 copias para poder correr cada una 
en un algoritmo distinto. Al correr cada algoritmo, se utiliza la función clock() así como una linea
que calcula la diferencia de tiempo entre antes y después de que corriera el algoritmo, y se imprimen
los resultados así como el array generado. 

## Resultados
Es sabido que el algoritmo selection sort es más eficiente que el bubble sort, ya que el primero
requiere realizar una menor cantidad de cambios. Sin embargo, como se demuestra a continuación, el bubble
sort optimizado logra obtener mejores resultados que su versión básica, aunque siguen siendo más lentos
que selection sort. Esta diferencia se nota más mientras más grande se hace el arreglo.

Arreglo de 10 
![Screenshot from 2025-05-14 14-10-29](https://github.com/user-attachments/assets/4b382866-c5f1-429a-bfb4-8c0d899d700a)
Arreglo de 100
![Screenshot from 2025-05-14 14-11-43](https://github.com/user-attachments/assets/340d144a-76a3-4950-b4eb-faa407e4d9f8)
Arreglo de 1000
![Screenshot from 2025-05-14 14-13-13](https://github.com/user-attachments/assets/f9981b78-fb7e-4543-88e0-9baff20b6165)
Arreglo de 10000
![Screenshot from 2025-05-14 14-15-06](https://github.com/user-attachments/assets/fb20164e-5a67-45cf-b323-6328eb6324df)
![Screenshot from 2025-05-14 14-14-24](https://github.com/user-attachments/assets/c925ad5b-3cbc-4b34-b720-447419731a4d)
![Screenshot from 2025-05-14 14-14-39](https://github.com/user-attachments/assets/ca0fa18d-9176-41f3-a8d6-c01771873d0c)
![Screenshot from 2025-05-14 14-14-04](https://github.com/user-attachments/assets/907534e6-c837-4004-bd57-b934d7bbce94)


