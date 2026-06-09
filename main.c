#include <stdio.h>
#include "funciones.h"

int main()
{
    articulos_t articulos[CANT_ARTICULOS] = {0};

    printf("Bienvenido al TP\n\n");

    carArt(articulos);// carga los articulos

    printf("\nARTICULOS CARGADOS\n");
    mostArt(articulos); // muestra los articulos cargados

    ordArt(articulos); // ordena los articulos por cantidad total de mayor a menor

    printf("\nARTICULOS ORDENADOS\n");
    mostArt(articulos);// muestra los articulos ordenados

    return 0;
}