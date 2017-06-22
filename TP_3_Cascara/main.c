#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    EMovie movie;
    int flag;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                system("cls");

                flag=agregarPelicula(movie);

                if(flag==1)
                {
                    printf("Se pudo agregar la pelicula\n");
                }
                if(flag==0)
                {
                  printf("ERROR,No se pudo agregar la pelicula\n");
                }
                break;
            case 2:

                system("cls");

                flag=borrarPelicula(movie);

                if(flag==1)
                {
                    printf("Se borro la pelicula con exito\n");
                }
                if(flag==0)
                {
                    printf("Error,No se pudo borrar la pelicula\n");
                }
                break;
            case 3:

                system("cls");

                flag=modificarPelicula(movie);

                if(flag==1)
                {
                    printf("Se pudo modificar la pelicula con exito\n");
                }
                if(flag==0)
                {
                   printf("Error,no se pudo modificar la pelicula\n");
                }
               break;
            case 4:

                system("cls");

                generarPagina(movie);


               break;
            case 5:
                seguir ='n';
                break;
        }
    }

    return 0;
}
