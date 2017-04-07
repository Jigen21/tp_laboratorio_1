#include "funciones.h"

/** \brief Ingresa el primer numero a la calculadora
 * \param void
 * \return El primer numero ingresado
 */

int PedirNumeroA()
{
    int NumeroUno;
    scanf("%d",&NumeroUno);
    return NumeroUno;
}

/** \brief Ingresa el segundo numero a la calculadora
 * \param void
 * \return El segundo numero ingresado
 */

int PedirNumeroB()
{
    int NumeroDos;
    scanf("%d",&NumeroDos);
    return NumeroDos;

}

/** \brief La suma total del primer y segundo numero
 * \param El primer numero ingresado,y el segundo numero ingresado
 * \return La suma resultante
 */

int Suma(NumeroUno,NumeroDos)
{
    int ResultadoSuma;
    ResultadoSuma=NumeroUno+NumeroDos;
    return ResultadoSuma;

}

/** \brief La resta del segundo numero al primero
 * \param El primer numero ingresado,y el segundo numero ingresado
 * \return La resta resultante
 */

int Resta(NumeroUno,NumeroDos)
{
    int ResultadoResta;
    ResultadoResta=NumeroUno-NumeroDos;
    return ResultadoResta;

}

/** \brief La division del segundo numero al primero
 * \param El primer numero ingresado,y el segundo numero ingresado
 * \return La division resultante
 */

float Division(NumeroUno,NumeroDos)
{
    float ResultadoDivision;
    ResultadoDivision=(float)NumeroUno/NumeroDos;
    return ResultadoDivision;
}

/** \brief La multiplicacion de los 2 numeros
 * \param El primer numero ingresado,y el segundo numero ingresado
 * \return La multiplicacion resultante
 */

int Multiplicacion(NumeroUno,NumeroDos)
{
    float ResultadoMultiplicacion;
    ResultadoMultiplicacion=NumeroUno*NumeroDos;
    return ResultadoMultiplicacion;
}

/** \brief El factorial del primer numero,la multiplicacion por sus antecesores
 * \param El primer numero ingresado
 * \return El factorial resultante del primer numero
 */


int Factorial(NumeroUno)
{
    int ResultadoFactorial=1;
    int i;


    for(i = NumeroUno;i > 1 ; i-- )
    {
       ResultadoFactorial = ResultadoFactorial * i;
    }

    return ResultadoFactorial;


}
