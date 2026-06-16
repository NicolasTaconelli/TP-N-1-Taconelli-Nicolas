#ifndef FUNCIONES_H
#define FUNCIONES_H

#define CANT_ARTICULOS 60

#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2

typedef struct
{
    char descripcion[90];
    int cantidad_sucursal[3];
    int total;
} articulos_t;

void carArt(articulos_t *articulos);
void mostArt(articulos_t *articulos);
void ordArt(articulos_t *articulos);

int buscArt(articulos_t *articulos, char *descripcion);
void calcT(articulos_t *articulo);
void intercambiarArticulos(articulos_t *a, articulos_t *b);

#endif
