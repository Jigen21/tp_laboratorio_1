#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.,y verifica para ver si quedan lugares o no
 * @param lista el array se pasa como parametro.
 * \param CantElem,la cantidad de personas en la estructura
 * \param val,el valor a ser comparado
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[],int CantElem,int val);

/** \brief verifica si el dni ingresado es el mismo o no,para poder darlo de baja
 * \param ArrayPersonas,se pasa como parametro
 * \param CantElem,la cantidad de personas en la estructura
 * \param val,el valor a ser comparado
 * \return el valor a verificar si es valido o no
 */

int buscarPorDni(EPersona lista[],int CantElem ,int val);

/** \brief Inicia el array de personas,dandole un valor de -1 a cada indice,haciendolos libres.
 *
 * \param ArrayPersonas,se pasa como parametro
 * \param CantElem,la cantidad de personas en la estructura
 * \param val,el valor a ser comparado
 * \return NULL
 *
 */

void inicListaPersonas (EPersona lista[],int CantElem,int val);


/** \brief funcion para simplificar el ingreso de un mensaje
 * \param cadena para mensaje
 * \param cadena para input
 * \return NULL
 *
 */

void getString(char mensaje[],char input[]);

/** \brief funcion para simplificar el ingreso de un mensaje con solo letras
 * \param cadena para mensaje
 * \param cadena para input
 * \return Devuelve el valor correspondiente a si es valido o no
 *
 */

int getStringLetras(char mensaje[],char input[]);

/** \brief funcion para simplificar el ingreso de un mensaje con solo numeros
 * \param cadena para mensaje
 * \param cadena para input
 * \return Devuelve el valor correspondiente a si es valido o no
 *
 */

int getStringNumeros(char mensaje[],char input[]);

/** \brief funcion para verificar si lo ingresado es solo numeros
 * \param cadena para str
 * \return Devuelve el valor correspondiente a si es valido o no
 *
 */

int esNumerico(char str[]);

/** \brief funcion para verificar si lo ingresado son solo letras
 * \param cadena para str
 * \return Devuelve el valor correspondiente a si es valido o no
 *
 */

int esSoloLetras(char str[]);





#endif // FUNCIONES_H_INCLUDED
