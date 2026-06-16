#include <stdio.h>
#include <string.h>
#include "funciones.h"

void carArt(articulos_t *articulos)
{
    int opcion = 1;
    int sucursal, cantidad, pos;
    char descripcion[90];
    articulos_t *articulo_actual;

    while (opcion == 1)
    {
        printf("Ingrese descripcion del articulo: ");
        scanf("%89s", descripcion);

        pos = buscArt(articulos, descripcion);

        if (pos == -1)
        {
            printf("No queda lugar para cargar mas articulos.\n");
            return;
        }

        articulo_actual = articulos + pos;

        if (*(articulo_actual->descripcion) == '\0')
        {
            strcpy(articulo_actual->descripcion, descripcion);
        }

        printf("Ingrese sucursal (1, 2 o 3): ");
        scanf("%d", &sucursal);

        if (sucursal < 1 || sucursal > 3)
        {
            printf("Sucursal incorrecta, se toma sucursal 1.\n");
            sucursal = 1;
        }

        printf("Ingrese cantidad: ");
        scanf("%d", &cantidad);

        *(articulo_actual->cantidad_sucursal + sucursal - 1) = cantidad;
        calcT(articulo_actual);

        printf("Desea cargar otro articulo? 1-Si 2-No: ");
        scanf("%d", &opcion);
    }
}

void mostArt(articulos_t *articulos)
{
    articulos_t *actual = articulos;
    articulos_t *fin = articulos + CANT_ARTICULOS;

    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");

    while (actual < fin && *(actual->descripcion) != '\0')
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n",
               actual->descripcion,
               *(actual->cantidad_sucursal + SUCURSAL_1),
               *(actual->cantidad_sucursal + SUCURSAL_2),
               *(actual->cantidad_sucursal + SUCURSAL_3),
               actual->total);
        actual++;
    }
}

void ordArt(articulos_t *articulos)
{
    int i, j;
    articulos_t *actual;
    articulos_t *siguiente;

    for (i = 0; i < CANT_ARTICULOS - 1; i++)
    {
        for (j = 0; j < CANT_ARTICULOS - 1 - i; j++)
        {
            actual = articulos + j;
            siguiente = actual + 1;

            if (actual->total < siguiente->total)
            {
                intercambiarArticulos(actual, siguiente);
            }
        }
    }
}

int buscArt(articulos_t *articulos, char *descripcion)
{
    int i;
    articulos_t *actual;
    articulos_t *libre = NULL;

    for (i = 0; i < CANT_ARTICULOS; i++)
    {
        actual = articulos + i;

        if (*(actual->descripcion) == '\0')
        {
            if (libre == NULL)
            {
                libre = actual;
            }
        }
        else if (strcmp(actual->descripcion, descripcion) == 0)
        {
            return i;
        }
    }

    if (libre == NULL)
    {
        return -1;
    }

    return libre - articulos;
}

void calcT(articulos_t *articulo)
{
    int i;

    articulo->total = 0;

    for (i = 0; i < 3; i++)
    {
        articulo->total += *(articulo->cantidad_sucursal + i);
    }
}

void intercambiarArticulos(articulos_t *a, articulos_t *b)
{
    articulos_t aux;

    aux = *a;
    *a = *b;
    *b = aux;
}
