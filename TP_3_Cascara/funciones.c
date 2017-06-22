#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int agregarPelicula(EMovie movie)
{

    FILE *binario;

    int auxPuntaje;
    int auxDuracion;

    printf("Ingrese el titulo de la pelicula\n");
    fflush(stdin);
    gets(movie.titulo);
    printf("Ingrese el genero de la pelicula\n");
    fflush(stdin);
    gets(movie.genero);
    auxDuracion=getValidInt("ingrese la duracion en minutos de la pelicula\n","ERROR,solo numeros del 1 al 320,Reingrese",1,320);
    fflush(stdin);
    printf("Ingrese la descripcion de la pelicula\n");
    fflush(stdin);
    gets(movie.descripcion);
    auxPuntaje=getValidInt("ingrese el puntaje de la pelicula\n","ERROR,solo numeros del 1 al 99,Reingrese",1,99);
    fflush(stdin);
    printf("Ingrese el link de la pelicula\n");
    fflush(stdin);
    gets(movie.linkImagen);

    movie.duracion=auxDuracion;
    movie.puntaje=auxPuntaje;

    if((binario=fopen("binario.bin","ab+"))!=NULL)
    {
        fwrite(&movie,sizeof(movie),1,binario);
        fclose(binario);
        return 1;
    }
    else
    {
        fclose(binario);
        return 0;
    }

}

int borrarPelicula(EMovie movie)
{
    FILE *binario;

    char auxTitulo[20];

    binario=fopen("binario.bin","rb+");
    rewind(binario);

    printf("Por favor ponga el titulo de la pelicula a borrar\n");
    fflush(stdin);
    gets(auxTitulo);



    while(!feof(binario))
    {
        fread(&movie,sizeof(EMovie),1,binario);
        if(strcmpi(auxTitulo,movie.titulo)==0)
        {
            printf("coincidencia encontrada");
            strcpy(movie.titulo,"NULL");

            fseek(binario,(-1)*sizeof(EMovie),SEEK_CUR);
            fwrite(&movie,sizeof(EMovie),1,binario);
            fclose(binario);
            return 1;



        }
    }





    fclose(binario);
    return 0;



}


void generarPagina(EMovie movie)
{
    FILE* binario;
    FILE* html;
    if((binario=fopen("binario.bin","rb"))!=NULL)
    {
     if((html=fopen("index.html","wb"))!=NULL)
     {
       while((fread(&movie,sizeof(EMovie),1,binario))!=0)
       {
        if(strcmpi(movie.titulo,"NULL")!=0)
        {
                    fprintf(html,
                            "<article class='col-md-4 article-intro'>"
                                    "<a href='#'>"
                                    "<img class='img-responsive img-rounded' src=%s alt=''>"
                                     "</a>"
                                     "<h3>"
                                     "<a href='#'>%s</a>"
                                     "</h3>"
                                    "<ul>"
                                    "<li>Género:%s</li>"
                                    "<li>Puntaje:%d</li>"
                                    "<li>Duración:%d</li>"
                                    "</ul>"
                                     "<p>%s</p>"
                                    "</article>",movie.linkImagen,movie.titulo,movie.genero,movie.puntaje,movie.duracion,movie.descripcion);
                }


            }
        }
        else
        {

            return 0;
        }
    }
    else
    {

        return 0;
    }
    printf("Pagina creada");
    fclose(binario);
    fclose(html);
    return 1;
}

int modificarPelicula(EMovie movie)
{
    FILE *binario;

    char auxTitulo[20];
    char auxGenero[20];
    int auxDuracion;
    char auxDescripcion[50];
    int auxPuntaje;
    char auxLinkImagen[50];

    binario=fopen("binario.bin","rb+");

    printf("Por favor ponga el titulo de la pelicula a modificar\n");
    fflush(stdin);
    gets(auxTitulo);

    rewind(binario);

    while(!feof(binario))
    {
        fread(&movie,sizeof(EMovie),1,binario);
        if(strcmpi(auxTitulo,movie.titulo)==0)
        {
            printf("coincidencia encontrada");


            printf("Ingrese el nuevo titulo de la pelicula\n");
            fflush(stdin);
            gets(auxTitulo);
            strcpy(movie.titulo,auxTitulo);
            printf("Ingrese el nuevo genero de la pelicula\n");
            fflush(stdin);
            gets(auxGenero);
            strcpy(movie.genero,auxGenero);
            auxDuracion=getValidInt("ingrese la duracion en minutos de la pelicula\n","ERROR,solo numeros del 1 al 320,Reingrese",1,320);
            fflush(stdin);
            movie.duracion=auxDuracion;
            printf("Ingrese la nueva descripcion de la pelicula\n");
            fflush(stdin);
            gets(auxDescripcion);
            strcpy(movie.descripcion,auxDescripcion);
            auxPuntaje=getValidInt("ingrese el puntaje de la pelicula\n","ERROR,solo numeros del 1 al 99,Reingrese",1,99);
            fflush(stdin);
            movie.puntaje=auxPuntaje;
            printf("Ingrese el nuevo link de la pelicula\n");
            fflush(stdin);
            gets(auxLinkImagen);
            strcpy(movie.linkImagen,auxLinkImagen);
            fseek(binario,(-1)*sizeof(EMovie),SEEK_CUR);
            fwrite(&movie,sizeof(EMovie),1,binario);
            fclose(binario);
            return 1;


        }
    }





    fclose(binario);
    return 0;





}

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}





