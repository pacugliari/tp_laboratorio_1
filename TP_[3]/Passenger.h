/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int idTipoPasajero;
	char codigoVuelo[50];//TIENEN 7 CARACTERES EN LOS ARCHIVOS
	int idEstadoVuelo;
	int isEmpty;

}Passenger;

Passenger* Passenger_new();

//FALTAN PARAMETROS ?
Passenger* Passenger_newParametros(int id,char* nombre,char* apellido,char* codigoVuelo,int idTipoPasajero,float precio,int idEstadoVuelo);

Passenger* Passenger_newPassenger (Passenger pasajero);

void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setStatusFlight(Passenger* this,int idEstadoVuelo);
int Passenger_getStatusFlight(Passenger* this,int* idEstadoVuelo);

#endif /* PASSENGER_H_ */
