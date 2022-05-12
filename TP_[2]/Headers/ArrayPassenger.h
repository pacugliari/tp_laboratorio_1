/*
 * ArrayPassenger.h
 *
 *  Created on: 18 abr. 2022
 *      Author: PACugliari
 */

#include "../Headers/tipoPasajero.h"

#ifndef TP__2__HEADERS_ARRAYPASSENGER_H_
#define TP__2__HEADERS_ARRAYPASSENGER_H_

#define ASC 1
#define DESC 0
#define ERROR -1
#define FALSE 0
#define TRUE 1
#define TODO_OK 0


struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}typedef Passenger;


#endif /* TP__2__HEADERS_ARRAYPASSENGER_H_ */


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);


/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger,int statusFlight, char flycode[]);


/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id);


/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);


/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length,eTipoPasajero tiposPasajeros[], int tamT);


/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
Programación I – Laboratorio I
UTN FRA – Tecnicatura Superior en Programación. http://www.sistemas-utnfra.com.ar 7
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order);



/// @fn int modifyPassenger(Passenger*, int, int, char[], char[], float, int, char[])
/// @brief Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
///	o Precio o Tipo de pasajero o Código de vuelo
///
/// @param list Passenger*, puntero a vector de pasajeros
/// @param len int, entero con el tamanio del vector de pasajeros
/// @param id int, id validada previamente del usuario a modificar
/// @param name char*, puntero a cadena de caracteres con el nombre de usuario validado
/// @param lastName char*, puntero a cadena de caracteres con el apellido de usuario validado
/// @param price float, flotante con el valor del precio validado previamente
/// @param typePassenger int, entero con el valor del tipo de pasajero validado
/// @param flycode char*, puntero a cadena de caracteres con el codigo de vuelo  del usuario validado
/// @return int, retorna un valor de -1 en caso de ERROR o un valor de 0 en caso de que se pudo hacer la modificacion
int modifyPassenger(Passenger* list, int len, int id, char name[],char
		lastName[],float price,int typePassenger, char flycode[]);

/// @fn int printPassengerActive(Passenger*, int)
/// @brief muestra del vector de pasajeros aquellas posiciones que no estan vacias y el tipo de pasajero
/// es ACTIVO = 1
///
/// @param list Passenger*, puntero a vector de pasajeros
/// @param length int, tamanio del vector
/// @param eTipoPasajero tiposPasajeros[], vector de tipos de pasajeros
/// @param int tamT, tamanio del vector de tipos de pasajeros
/// @return int, retorna un valor de -1 en caso de ERROR o un valor de 0 en caso de que se pudo hacer la muestra de datos
int printPassengerActive(Passenger* list, int length,eTipoPasajero tiposPasajeros[],int tamT);

/// @fn int calculatePricesPassengers(Passenger*, int, float*)
/// @brief calcula los precios del total , promedio y cantidad de pasajeros que superan dicho promedio
///
/// @param list Passenger* , puntero a vector de pasajeros
/// @param len int, tamanio del vector de pasajeros
/// @param resultados float*, puntero a vector de flotantes donde se almacenan los 3 resultados
/// @return int, retorna un valor de -1 en caso de ERROR o un valor de 0 en caso de que se pudo hacer el calculo
int calculatePricesPassengers(Passenger* list, int len);


/// @fn void printPassengerData(Passenger)
/// @brief realiza una muestra de datos de un pasajero en particular, funcion usada en printPassengerActive() y
///  printPassenger()
///
///
/// @param p Passenger, tipo de dato Pasenger , donde los campos contiene la informacion a mostrar
/// @param eTipoPasajero tiposPasajeros[], vector de tipos de pasajeros
/// @param int tamT, tamanio del vector de tipos de pasajeros
void printPassengerData (Passenger p,eTipoPasajero tiposPasajeros[], int tamT);


/// @fn int hardcodearPasajeros(Passenger[], int, int, int*)
/// @brief carga en el vector de pasajeros informacion cargada previamente para probar el codigo
///
/// @param Passenger pasajeros[],vector de pasajeros
/// @param int tamP, tamanio del vector de pasajeros
/// @param int cantidad, cantidad de pasajeros con informacion falsa a cargar (MAX = 5)
/// @param int* pId, puntero a entero que apunta a la variable que lleva el control de la id de pasajeros
/// @return si los parametros son correctos retorna 1, si los parametros son incorrectos retorna 0
int hardcodearPasajeros (Passenger pasajeros[],int tamP,int cantidad,int* pId);

/// @fn int buscarPasajeroLibre(Passenger[], int, int*)
/// @brief busca en el vector de pasajeros la primer posicion donde se encuentre uno libre, es decir con el campo isEmpty = 1
///
/// @param Passenger pasajeros [],vector de pasajeros
/// @param int tamP, tamanio del vector de pasasjeros
/// @param int* pIndice, puntero a entero que apunta a la variable donde se va almacenar el indice de la posicion vacia, si no hay almacena -1
/// @return si los parametros son correctos retorna 1, si los parametros son incorrectos retorna 0
int buscarPasajeroLibre (Passenger pasajeros[],int tamP,int* pIndice);

/// @fn int swapPasajeros(Passenger*, Passenger*)
/// @brief copia la informacion de los campos del pasajero2 a la estructura pasajero1
///
/// @param Passenger* pasajero1,puntero al tipo de dato Passenger que recibe la informacion copiada
/// @param Passenger* pasajero2,puntero al tipo de dato Passenger que cede la informacion copiada
/// @return si los parametros son correctos retorna 1, si los parametros son incorrectos retorna 0
int swapPasajeros(Passenger* pasajero1,Passenger* pasajero2);
