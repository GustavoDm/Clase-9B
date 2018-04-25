#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Producto.h"



int inicializarFlagProductos(EProducto productos[], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        productos[i].flagCargaProducto=-1;
    }
    return 0;
}

int cargaProducto(EProducto productos[], int indice, int size)
{
   char auxNombre[50];
   char auxDescripcion[200];
   char auxPrecio[50];
   float auxPrecioF;

   printf("\nIngrese el nombre del producto: ");             //VALIDAR
   fgets(auxNombre, sizeof(auxNombre), stdin);             //VALIDAR
   fflush(stdin);                                          //VALIDAR
   auxNombre[strlen(auxNombre)-1]=0;                       //VALIDAR
   printf("\nIngrese una descripcion del producto: ");     //VALIDAR
   fgets(auxDescripcion, sizeof(auxDescripcion), stdin);   //VALIDAR
   fflush(stdin);                                          //VALIDAR
   auxDescripcion[strlen(auxDescripcion)-1]=0;             //VALIDAR
   printf("\nIngrese el precio del producto: ");           //VALIDAR
   fgets(auxPrecio, sizeof(auxNombre), stdin);             //VALIDAR
   fflush(stdin);                                          //VALIDAR
   auxPrecio[strlen(auxPrecio)-1]=0;                       //VALIDAR
   auxPrecioF= atof(auxPrecio);                            //VALIDAR

   strcpy(productos[indice].nombre, auxNombre);
   strcpy(productos[indice].descripcion, auxDescripcion);
   productos[indice].precio=auxPrecioF;
   productos[indice].flagCargaProducto=0;
   productos[indice].ID=indice;
   productos[indice].indice=indice+1;

   printf("%d", productos[indice].indice);



   return 0;

}

int buscadorEspacioVacio(EProducto productos[], int size, int *indexProducto)
{
    int i;
    int retorno=-1;
 for(i=0;i<size;i++)
 {
     if(productos[i].flagCargaProducto==-1)
     {
        *indexProducto=i+1;
        retorno=0;
        break;
     }

 }

 return retorno;
}

int imprimirListaProducto(EProducto productos[], int size)
{
    int i;
     printf("Indice de productos:\n");
    for(i=0;i<size;i++)
    {
        if(productos[i].flagCargaProducto==0)
        {
        printf("%d: %s ID:%d\n", i+1, productos[i].nombre, productos[i].ID);
        }
        else
        {
        printf("%d: Vacio\n", i+1);
        }
    }
    return 0;
}

int buscadorID(EProducto *productos, int ID, int size, int *resultadoIndice)
{

    int i;
    int retorno=-1;
    for(i=0;i<size;i++){
    if(ID==productos[i].ID){
       *resultadoIndice=productos[i+1].indice;
        retorno=0;
    }

    }
    return retorno;
}

int modificarProducto(EProducto *productos, int size, int ID){

int i;
int retorno=-1;
for(i=0;i<size;i++){
if(productos[i].flagCargaProducto==0&&productos[i].ID==ID){

   char auxNombre[50];
   char auxDescripcion[200];
   char auxPrecio[50];
   float auxPrecioF;

   printf("\nIngrese el nombre del producto: ");             //VALIDAR
   fgets(auxNombre, sizeof(auxNombre), stdin);             //VALIDAR
   fflush(stdin);                                          //VALIDAR
   auxNombre[strlen(auxNombre)-1]=0;                       //VALIDAR
   printf("\nIngrese una descripcion del producto: ");     //VALIDAR
   fgets(auxDescripcion, sizeof(auxDescripcion), stdin);   //VALIDAR
   fflush(stdin);                                          //VALIDAR
   auxDescripcion[strlen(auxDescripcion)-1]=0;             //VALIDAR
   printf("\nIngrese el precio del producto: ");           //VALIDAR
   fgets(auxPrecio, sizeof(auxNombre), stdin);             //VALIDAR
   fflush(stdin);                                          //VALIDAR
   auxPrecio[strlen(auxPrecio)-1]=0;                       //VALIDAR
   auxPrecioF= atof(auxPrecio);                            //VALIDAR

   strcpy(productos[i].nombre, auxNombre);
   strcpy(productos[i].descripcion, auxDescripcion);
   productos[i].precio=auxPrecioF;
   retorno=0;
}
}
return retorno;
}

int borrarProducto(EProducto *productos, int size, int ID){

int i;
int retorno=-1;

for(i=0;i<size;){
if(productos[i].flagCargaProducto==0&&productos[i].ID==ID){
    productos[i].flagCargaProducto=-1;
    retorno=0;
}
}

return retorno;
}
