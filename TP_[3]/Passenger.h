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

#endif /* PASSENGER_H_ */


//Constructores
Passenger* Passenger_new();
Passenger* Passenger_newParametros(int id,char* nombre,char* apellido,float precio,char* codigoVuelo,int idTipoPasajero,int idEstadoVuelo);
Passenger* Passenger_newPassenger (Passenger pasajero);
Passenger* Passenger_newParametrosString(char* id,char* nombre,char* apellido,char* precio,char* codigoVuelo,char* idTipoPasajero,char* idEstadoVuelo);

//Destructores
void Passenger_delete();


//Setters
int Passenger_setId(Passenger* this,int id);
int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_setStatusFlight(Passenger* this,int idEstadoVuelo);

//Getters
int Passenger_getId(Passenger* this,int* id);
int Passenger_getNombre(Passenger* this,char* nombre);
int Passenger_getApellido(Passenger* this,char* apellido);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
int Passenger_getPrecio(Passenger* this,float* precio);
int Passenger_getStatusFlight(Passenger* this,int* idEstadoVuelo);
