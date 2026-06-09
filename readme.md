# Trabajo Practico N1 - Informatica I

## Alumno
Nicolas Taconelli

## Se realizo:

- Separacion del programa en multiples archivos.
- Creacion del archivo de cabecera `funciones.h`.
- Implementacion de funciones en `funciones.c`.
- Uso de estructuras para almacenar la informacion de los articulos.
- Ordenamiento de articulos segun la cantidad total registrada.

## Estructura del proyecto

```
TP1_Informatica

* main.c
* funciones.c
* funciones.h
* README.md
```

## Compilacion

Compilar desde terminal con:

```bash
gcc main.c funciones.c -o tp1
```

## Ejecucion

Windows:

```bash
tp1.exe
```

Linux:

```bash
./tp1
```

## Funcionalidades

- Carga de articulos.
- Registro de cantidades por sucursal.
- Calculo del total por articulo.
- Visualizacion de los datos cargados.
- Ordenamiento de articulos por cantidad total.