#include <stdio.h>
#include <stdlib.h>

1) Definir un tipo de dato que represente
un producto. El producto tiene un nombre,
 una descripcion y un precio.
2) Definir un array de 200 productos,
indicar de alguna manera que la info de
cada item no esta cargada.
3) Realizar una funcion que reciba el
array, un indice, y le permita al usuario
cargar los datos en el item de la
posicion especificada por el indice.

4) Realizar una funcion que reciba el
array y un indice e imprima los datos
del item de la posicion especificada
por el indice.

5) Realizar una funcion que me devuelva
el indice de un item vacio (sin cargar).

6) Realizar un programa con un menu de
dos opciones:
    a) Cargar un producto
    b) Imprimir lista productos

7) Agregar al tipo de dato el campo ID
que represente un identificador unico.
 Modificar el codigo anterior para que
 el ID se genere automaticamente.
 Se debera cargar el ID automaticamente
 al cargar un producto, y se debera
 imprimir al imprimir la lista.

8) Realizar una funcion que reciba el array y un ID, y me devuelva el indice del item con dicho ID.

9) Realizar una funcion que reciba el array, un indice, y le permita al usuario modificar los campos nombre y precio del item del array en la posicion especificada por el indice.


10) Agregar una opcion en el menu. "Editar producto" que pida al usuario el ID del mismo y le permita cambiar el nombre y el precio.

11) Agregar una opcion en el menu "Borrar producto" que pida al usuario el ID del mismo.







typedef struct {
    char nombre[50];
    char descripcion[200];
    float precio;
    int flagVacio;
}Producto;



int cargarProducto(Producto productos[],
                   int index,int size)
{
    char auxNombre[50];
    char auxDescripcion[200];
    char auxPrecio[8];
    float auxPrecioF;
    printf("nombre:");

    fflush(stdin);
    fgets(auxNombre,sizeof(auxNombre),stdin);
    auxNombre[strlen(auxNombre)-1]=0;
    // validar
    //TODO
    fflush(stdin);
    fgets(auxPrecio,sizeof(auxPrecio),stdin);
    auxPrecio[strlen(auxPrecio)-1]=0;
    // validar
    auxPrecioF = atof(auxPrecio);


    productos[index].precio = auxPrecioF;
    //productos[index].nombre = auxNombre;
    strcpy(productos[index].nombre,auxNombre);
    productos[index].flagVacio=0;
}

int imprimirProducto(Producto productos[],
                   int index,int size)
{
    printf("nombre:%s",productos[index].nombre);
    printf("dessc:%s",productos[index].descripcion);
    printf("precio:%f",productos[index].precio);

}


int main()
{
    Producto productos[200];

    int i;
    for(i=0; i<200;i++)
        productos[i].flagVacio=1;






    return 0;
}




