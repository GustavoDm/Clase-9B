#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

typedef struct
{
    char nombre[50];
    char descripcion[200];
    float precio;
    int flagCargaProducto;
    int ID;
    int indice;

}EProducto;

int inicializarFlagProductos(EProducto productos[], int cantidad);

int cargaProducto(EProducto productos[], int indice, int size);

int buscadorEspacioVacio(EProducto productos[], int size, int *indexProducto);

int imprimirListaProducto(EProducto productos[], int size);

int buscadorID(EProducto *productos, int ID, int size, int *resultadoIndice);

#endif // PRODUCTO_H_INCLUDED
