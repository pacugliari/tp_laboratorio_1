/*
 * ArrayPassenger.h
 *
 *  Created on: 18 abr. 2022
 *      Author: PACugliari
 */

#ifndef TP__2__HEADERS_ARRAYPASSENGER_H_
#define TP__2__HEADERS_ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT_PASAJEROS 2000

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

void saludar();
int posicionVacia(Passenger* list,int len);

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
int printPassenger(Passenger* list, int length);


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


/*
MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo
 * */
int modifyPassenger(Passenger* list, int len, int id, char name[],char
		lastName[],float price,int typePassenger, char flycode[]);


int printPassengerActive(Passenger* list, int length);


int calculatePricesPassengers(Passenger* list, int len,float* resultados);

#endif /* TP__2__HEADERS_ARRAYPASSENGER_H_ */
