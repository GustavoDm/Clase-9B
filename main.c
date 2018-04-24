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

    inicializarFlagProductos(productos, CANTIDAD);

    do
    {
        printf("Elija una opcion: \n\nA:Cargar un Producto\nB:Imprimir lista de productos\nC:Buscar espacio libre en el indice\nD:Buscar indice por ID");
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
            imprimirListaProducto(productos, CANTIDAD);
            printf("\nDesea volver al menu? ");
            scanf("%c", &seguir);
            fflush(stdin);
            break;

        case 'C':
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
            printf("\nIngrese el ID que quiera buscar: ");
            scanf("%d", &ID);
           if(buscadorID(productos, ID, CANTIDAD, &resultadoBuscadorID)==0){
           printf("El ID %d pertenece al item %d del indice", ID, resultadoBuscadorID);
           }
           else
           {
               printf("\nEl ID ingresado no corresponde a ningun producto");
           }
          break;
        }



    }while(seguir=='s');
    return 0;

}
