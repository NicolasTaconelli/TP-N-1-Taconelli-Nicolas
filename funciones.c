#include <stdio.h>
#include <string.h>
#include "funciones.h"

void carArt(articulos_t articulos[])
{
    int opcion = 1;
    int sucursal, cantidad, pos;
    char descripcion[90];

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

        if (articulos[pos].descripcion[0] == '\0')
        {
            strcpy(articulos[pos].descripcion, descripcion);
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

        articulos[pos].cantidad_sucursal[sucursal - 1] = cantidad;
        calcT(&articulos[pos]);

        printf("Desea cargar otro articulo? 1-Si 2-No: ");
        scanf("%d", &opcion);
    }
}

void mostArt(articulos_t articulos[])
{
    int i = 0;

    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");

    while (i < CANT_ARTICULOS && articulos[i].descripcion[0] != '\0')
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n",
               articulos[i].descripcion,
               articulos[i].cantidad_sucursal[SUCURSAL_1],
               articulos[i].cantidad_sucursal[SUCURSAL_2],
               articulos[i].cantidad_sucursal[SUCURSAL_3],
               articulos[i].total);
        i++;
    }
}

void ordArt(articulos_t articulos[])
{
    int i, j;

    for (i = 0; i < CANT_ARTICULOS - 1; i++)
    {
        for (j = 0; j < CANT_ARTICULOS - 1 - i; j++)
        {
            if (articulos[j].total < articulos[j + 1].total)
            {
                intercambiarArticulos(&articulos[j], &articulos[j + 1]);
            }
        }
    }
}

int buscArt(articulos_t articulos[], char descripcion[])
{
    int i;
    int libre = -1;

    for (i = 0; i < CANT_ARTICULOS; i++)
    {
        if (articulos[i].descripcion[0] == '\0')
        {
            if (libre == -1)
            {
                libre = i;
            }
        }
        else if (strcmp(articulos[i].descripcion, descripcion) == 0)
        {
            return i;
        }
    }

    return libre;
}

void calcT(articulos_t *articulo)
{
    int i;

    articulo->total = 0;

    for (i = 0; i < 3; i++)
    {
        articulo->total += articulo->cantidad_sucursal[i];
    }
}

void intercambiarArticulos(articulos_t *a, articulos_t *b)
{
    articulos_t aux;

    aux = *a;
    *a = *b;
    *b = aux;
}
