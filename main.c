#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Producto.h"
#define CANTIDAD 4

int main ()
{
    EProducto productos[CANTIDAD];

    int indice;
    int retornoBuscadorIndice;
    int resultadoBuscadorID;
    char opcionMenu;
    char opcionCarga='s';
    char seguir= 's';
    int ID;
    char confirmacion;

    inicializarFlagProductos(productos, CANTIDAD);

    do
    {
        printf("Elija una opcion: \n\nA:Cargar un Producto\nB:Imprimir lista de productos\nC:Buscar espacio libre en el indice\nD:Buscar indice por ID\nE:Modificar producto\nF:Borrar producto: \n");
        scanf("%c",&opcionMenu);
        opcionMenu=toupper(opcionMenu);
        fflush(stdin);

        switch(opcionMenu)
        {


        case 'A':
            do{
            system("cls");
            printf("\nIngrese el indice del producto a cargar: ");
            scanf("%d", &indice);
            indice=indice-1;
            fflush(stdin);
            cargaProducto(productos, indice, CANTIDAD);
            printf("\nDesea cargar otro? ");
            scanf("%c", &opcionCarga);
            fflush(stdin);
            }while(opcionCarga=='s');
            break;

        case 'B':
            system("cls");
            imprimirListaProducto(productos, CANTIDAD);
            printf("\nDesea volver al menu? ");
            scanf("%c", &seguir);
            fflush(stdin);
            break;

        case 'C':
            system("cls");
            if(buscadorEspacioVacio(productos, CANTIDAD, &retornoBuscadorIndice)==0){
            printf("Tiene un espacio libre en el slot n:%d", retornoBuscadorIndice);
            printf("\nDesea volver al menu? ");
            scanf("%c", &seguir);
            fflush(stdin);
            }
            else{
                printf("\nNo hay espacio disponible.");
            }
            break;

        case 'D':
            system("cls");
            printf("\nIngrese el ID que quiera buscar: ");
            scanf("%d", &ID);
            fflush(stdin);
           if(buscadorID(productos, ID, CANTIDAD, &resultadoBuscadorID)==0){
           printf("El ID %d pertenece al item %d del indice", ID, resultadoBuscadorID);
           }
           else
           {
               printf("\nEl ID ingresado no corresponde a ningun producto");
           }
            printf("\nDesea volver al menu? ");
            scanf("%c", &seguir);
            fflush(stdin);
          break;

        case 'E':
            system("cls");
            printf("\nIngrese el ID del producto que quiere modificar: ");
            scanf("%d", &ID);
            fflush(stdin);
            modificarProducto(productos, CANTIDAD, ID);
            if(modificarProducto(productos, CANTIDAD, ID)==-1){
                printf("El ID ingresado no corresponde a ningun producto");
            }
            break;

        case 'F':
             system("cls");
             printf("\nIngrese el ID del producto que quiere borrar: ");
             scanf("%d", &ID);
             printf("Desea borrar el producto?");
             scanf("%c", &confirmacion);
             confirmacion=toupper(confirmacion);
             if(confirmacion=='S'){
             borrarProducto(productos, CANTIDAD, ID);
             if(borrarProducto(productos, CANTIDAD, ID)==0){
                printf("\nEl producto ha sido borrado");
             }
             else{
                printf("\nEl ID ingresado no corresponde a ningun producto");
             }
             }
             printf("\nDesea volver al menu? ");
             scanf("%c", &seguir);
             fflush(stdin);
             break;
        }



    }while(seguir=='s');
    return 0;

}
