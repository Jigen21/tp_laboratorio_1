#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDADPERSONAS 20




int main()
{
    EPersona lista[20];

    EPersona auxPer;

    char AuxNombre[50];
    char AuxiliarDni[50];
    char AuxiliarEdad[50];
    int AuxEstado;
    int AuxEdad;
    int AuxDni;


    int IndLugarLibre;
    int IndBusqueda;

    int i,j;

    inicListaPersonas(lista,CANTIDADPERSONAS,-1);






    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                system("cls");

                IndLugarLibre = obtenerEspacioLibre(lista,CANTIDADPERSONAS,-1);
                if(IndLugarLibre==-1)
                {
                    printf("NO QUEDAN LUGARES\n\n");
                }

                printf ("ALTA\n\n");

                if(!getStringLetras("Ingrese el nombre\n",AuxNombre))
                {
                    printf("El nombre debe estar compuesto solo por letras\n");
                    break;
                }

                if(!getStringNumeros("Ingrese el documento\n",AuxiliarDni))
                {
                   printf("el documento debe estar compuesto solo por numeros\n");
                   break;
                }

                if(!getStringNumeros("Ingrese su edad\n",AuxiliarEdad))
                {

                   printf("la edad debe estar compuesta solo por numeros\n");
                   break;
                }

                AuxDni = atoi(AuxiliarDni);
                AuxEdad =atoi(AuxiliarEdad);

                if(buscarPorDni(lista,CANTIDADPERSONAS,AuxDni) != -1)
                {
                    printf("EL DNI YA EXISTE\n");
                    break;
                }


                strcpy(lista[IndLugarLibre].nombre,AuxNombre);
                lista[IndLugarLibre].edad = AuxEdad;
                lista[IndLugarLibre].dni = AuxDni;
                lista[IndLugarLibre].estado = AuxEstado;




                break;
            case 2:

                system("cls");

                printf ("BAJA\n\n");

                if(!getStringNumeros("Ingrese el documento a dar de baja\n",AuxiliarDni))
                {
                    printf("El Documento tiene que ser numerico\n");
                    break;
                }

                IndBusqueda = buscarPorDni(lista,CANTIDADPERSONAS,atoi(AuxiliarDni));

                if(IndBusqueda==-1)
                {
                    printf("No se encuentra ese documento\n");
                    break;
                }
                lista[IndBusqueda].dni=-1;
                printf("El usuario fue dado de baja con exito\n");
                break;


                break;
            case 3:

                system("cls");



                for(i=0;i<CANTIDADPERSONAS;i++)
                {
                   if(lista[i].dni == -1)
                   {
                       continue;
                   }
                   for(j=i+1; j<CANTIDADPERSONAS;j++)
                   {
                       if(lista[j].dni == -1)
                       {
                           continue;
                       }
                       if(strcmp(lista[i].nombre,lista[j].nombre) > 0)
                       {
                           auxPer = lista[j];
                           lista[j] = lista [i];
                           lista[i] = auxPer;
                       }
                   }
                }


                for(i=0;i<CANTIDADPERSONAS;i++)
                {
                    if(lista[i].dni != -1)
                    {
                       printf("\n%s - %d - %d\n",lista[i].nombre,lista[i].dni,lista[i].edad);
                    }
                }



                printf ("ORDENADO EL LISTADO POR NOMBRES\n\n");

                break;
            case 4:

                system("cls");


                for(i=0;i<CANTIDADPERSONAS;i++)
                {
                    if(lista[i].dni != -1)
                    {
                        if(lista[i].edad<18)
                        {

                            printf(" *\t \t \n ");
                        }
                        if(lista[i].edad>=19 && lista[i].edad<=35)
                        {

                            printf("\t * \t \n ");
                        }

                        if(lista[i].edad>35)
                        {

                            printf("\t \t *\n ");
                        }


                    }


                }
                printf("<18   19-35   >35\n");
                printf("GRAFICO REPRESENTANDO PERSONAS CON ASTERISCO\n\n");





                break;
            case 5:
                seguir = 'n';
                break;
        }
    }


    return 0;
}



