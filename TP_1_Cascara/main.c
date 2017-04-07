/*******************************************************************
*Programa:Tp1-laboratorio 1
*
*Objetivo:
Hacer una Calculadora
*
*Version:0.1 del 7 de abril de 2017
*Autor:Axel Francisco Quinteros
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int NumeroUno;
    int NumeroAFlag=0;
    int NumeroBFlag=0;
    int NumeroDos;
    int ResultadoSuma;
    int ResultadoResta;
    float ResultadoDivision;
    int ResultadoMultiplicacion;
    int ResultadoFactorial;


    while(seguir=='s')
    {
          if(NumeroAFlag==1&&NumeroBFlag==0)
            {

                printf("1- Ingresar 1er operando (%d=x)\n",NumeroUno);
                printf("2- Ingresar 2do operando (B=y)\n",NumeroDos);
                printf("3- Calcular la suma (%d+B)\n",NumeroUno);
                printf("4- Calcular la resta (%d-B)\n",NumeroUno);
                printf("5- Calcular la division (%d/B)\n",NumeroUno);
                printf("6- Calcular la multiplicacion (%d*B)\n",NumeroUno);
                printf("7- Calcular el factorial (%d!)\n",NumeroUno);
                printf("8- Calcular todas las operaciones\n");
                printf("9- Salir\n");


            }

             if(NumeroAFlag==0&&NumeroBFlag==1)
            {
                printf("1- Ingresar 1er operando (A=x)\n",NumeroDos);
                printf("2- Ingresar 2do operando (%d=y)\n",NumeroDos);
                printf("3- Calcular la suma (A+%d)\n",NumeroDos);
                printf("4- Calcular la resta (A-%d)\n",NumeroDos);
                printf("5- Calcular la division (A/%d)\n",NumeroDos);
                printf("6- Calcular la multiplicacion (A*%d)\n",NumeroDos);
                printf("7- Calcular el factorial (A!)\n");
                printf("8- Calcular todas las operaciones\n");
                printf("9- Salir\n");


            }





            if(NumeroAFlag==1&&NumeroBFlag==1)
            {
                printf("1- Ingresar 1er operando (%d=x)\n",NumeroUno);
                printf("2- Ingresar 2do operando (%d=y)\n",NumeroDos);
                printf("3- Calcular la suma (%d+%d)\n",NumeroUno,NumeroDos);
                printf("4- Calcular la resta (%d-%d)\n",NumeroUno,NumeroDos);
                printf("5- Calcular la division (%d/%d)\n",NumeroUno,NumeroDos);
                printf("6- Calcular la multiplicacion (%d*%d)\n",NumeroUno,NumeroDos);
                printf("7- Calcular el factorial (%d!)\n",NumeroUno);
                printf("8- Calcular todas las operaciones\n");
                printf("9- Salir\n");


            }


            if(NumeroAFlag==0&&NumeroBFlag==0)

            {
                printf("1- Ingresar 1er operando (A=x)\n");
                printf("2- Ingresar 2do operando (B=y)\n");
                printf("3- Calcular la suma (A+B)\n");
                printf("4- Calcular la resta (A-B)\n");
                printf("5- Calcular la division (A/B)\n");
                printf("6- Calcular la multiplicacion (A*B)\n");
                printf("7- Calcular el factorial (A!)\n");
                printf("8- Calcular todas las operaciones\n");
                printf("9- Salir\n");



            }


            scanf("%d",&opcion);



        switch(opcion)
        {
            case 1:


                system("cls");
                NumeroUno=PedirNumeroA();
                printf("El Numero A Ingresado es:%d)\n",NumeroUno);
                NumeroAFlag=1;


                break;
            case 2:


                system("cls");
                NumeroDos=PedirNumeroB();
                printf("El Numero B Ingresado es:%d)\n",NumeroDos);
                NumeroBFlag=1;


                break;


            case 3:

                if(NumeroAFlag==1&&NumeroBFlag==1)
                {
                    system("cls");
                    ResultadoSuma=Suma(NumeroUno,NumeroDos);
                    printf("la suma es:%d)\n",ResultadoSuma);

                }
                else
                {
                   system("cls");
                   printf("ERROR,falta ingresar un numero/s");

                }

                break;
            case 4:

                if(NumeroAFlag==1&&NumeroBFlag==1)
                {
                    system("cls");
                    ResultadoResta=Resta(NumeroUno,NumeroDos);
                    printf("La Resta es:%d)\n",ResultadoResta);
                }

                else
                {
                    system("cls");
                    printf("ERROR,falta ingresar un numero/s\n");
                }


                break;
            case 5:

                if(NumeroAFlag==1&&NumeroBFlag==1)
                {
                    if(NumeroDos!=0)
                    {
                        system("cls");
                        ResultadoDivision=Division(NumeroUno,NumeroDos);
                        printf("La Division es:%f)\n",ResultadoDivision);
                        break;
                    }
                    else
                    {
                        system("cls");
                        printf("ERROR,no puede dividir por cero\n");
                    }
                }

                else
                {
                    system("cls");
                    printf("ERROR,falta ingresar un numero\n");
                }






                break;
            case 6:

                if(NumeroAFlag==1&&NumeroBFlag==1)
                {
                    system("cls");
                    ResultadoMultiplicacion=Multiplicacion(NumeroUno,NumeroDos);
                    printf("La Multiplicacion es:%d)\n",ResultadoMultiplicacion);
                }

                else
                {
                    system("cls");
                    printf("ERROR,falta ingresar un numero/s\n");
                }


                break;
            case 7:

                if (NumeroAFlag==1)
                {
                    if(NumeroUno>0)
                    {
                        system("cls");
                        ResultadoFactorial=Factorial(NumeroUno);
                        printf("El factorial es:%d)\n",ResultadoFactorial);
                        break;
                    }
                    else
                    {
                        system("cls");
                        printf("ERROR,el primer numero ingresado tiene que ser positivo\n");
                    }

                }

                else
                {
                    system("cls");
                    printf("ERROR,no ingreso el primer numero\n");
                }



                break;
            case 8:



                if(NumeroAFlag==1&&NumeroBFlag==1)
                {
                    system("cls");
                    ResultadoSuma=Suma(NumeroUno,NumeroDos);
                    ResultadoResta=Resta(NumeroUno,NumeroDos);
                    ResultadoDivision=Division(NumeroUno,NumeroDos);
                    ResultadoMultiplicacion=Multiplicacion(NumeroUno,NumeroDos);
                    ResultadoFactorial=Factorial(NumeroUno);
                    printf("la suma es:%d)\n",ResultadoSuma);
                    printf("la resta es:%d)\n",ResultadoResta);
                    printf("la division es:%f)\n",ResultadoDivision);
                    printf("la multiplicacion es:%d)\n",ResultadoMultiplicacion);
                    printf("el factorial es:%d)\n",ResultadoFactorial);

                }
                else
                {
                    system("cls");
                    printf("ERROR,falta ingresar un numero\n");
                }












                break;
            case 9:
                seguir = 'n';
                break;


            default :
                system("cls");
                printf("Por favor,un numero del 1 al 9\n");
                break;
        }



    }


return 0;


}
