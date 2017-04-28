#include "funciones.h"
#define CANTIDADPERSONAS 20

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if (str[i] < '0'  ||  str[i] > '9')
        return 0;
        i++;
   }
   return 1;
}

int esSoloLetras(char str[])
{
     int i=0;
   while(str[i] != '\0')
   {
       if ((str[i] != ' ')  &&  (str[i] < 'a' || str[i] > 'z') &&  (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
   }
   return 1;
}



void getString(char mensaje[],char input[])
{
    printf(mensaje);
    scanf("%s",input);
}

int getStringLetras(char mensaje[],char input[])
{
   char aux[256];
   getString(mensaje,aux);
   if(esSoloLetras(aux))
   {
       strcpy(input,aux);
       return 1;
   }
   return 0;
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





int obtenerEspacioLibre(EPersona lista[],int CantElem,int val)
{
    int i=0;

    for(i=0;i<CantElem;i++)
    {
        if(lista[i].estado==val)
        {
            return i;
        }
    }
    return -1;
}

  int buscarPorDni(EPersona lista[],int CantElem,int val)
  {
    int i=0;

    for(i=0;i<CantElem;i++)
    {
        if(lista[i].dni==val)
        {
            return i;
        }
    }
    return -1;
}


         void inicListaPersonas (EPersona lista[],int CantElem,int val)
        {
            int i;

            for(i=0;i<CantElem;i++)
                {
                    lista[i].dni = val;
                    lista[i].estado = val;

                }

        }


