/*
 * ArrayPassenger.c
 *
 *  Created on: 18 abr. 2022
 *      Author: PACugliari
 */
#include "../Headers/ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printPassengerData (Passenger p){

	printf("%04d\t\t%-16s%-24s%10.2f\t\t%d\t\t\t\t%-10s\t\t%d\n",p.id,
						p.name,p.lastName,p.price,p.typePassenger,
						p.flycode,p.statusFlight);

}

int initPassengers(Passenger* list, int len){
	int retorno = ERROR;

	if(list && len>0 ){
		for(int i=0;i<len;i++){
			list[i].isEmpty = TRUE;
		}
		retorno = TODO_OK;
	}
	return retorno;
}

int posicionVacia(Passenger* list,int len){
	int retorno = ERROR;
	if(list && len >0 ){
		for(int i=0;i<len;i++){
			if(list[i].isEmpty){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger,int statusFlight, char flycode[]){
	int retorno = ERROR;
	Passenger pasajeroNuevo;
	int unaPosicionVacia;

	if(list && len >0  && name && lastName && flycode){
		unaPosicionVacia = posicionVacia(list,len);
		if(unaPosicionVacia != ERROR){
			//CARGO LOS DATOS
			strcpy(pasajeroNuevo.name,name);
			strcpy(pasajeroNuevo.lastName,lastName);
			pasajeroNuevo.price = price;
			pasajeroNuevo.typePassenger = typePassenger;
			strcpy(pasajeroNuevo.flycode,flycode);
			pasajeroNuevo.id = id+1;
			pasajeroNuevo.isEmpty=FALSE;
			pasajeroNuevo.statusFlight = statusFlight;

			list[unaPosicionVacia] = pasajeroNuevo;
			retorno = TODO_OK;
		}

	}
	return retorno;
}

int findPassengerById(Passenger* list, int len,int id){
	int retorno = ERROR;

	if(list && len >0 ){
		for(int i=0;i<len;i++){
			if(!list[i].isEmpty && id == list[i].id ){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


int removePassenger(Passenger* list, int len, int id){
	int retorno = ERROR;

	if(list && len > 0 ){
		for(int i=0;i<len;i++){
			if(id == list[i].id && !list[i].isEmpty){
				list[i].isEmpty = TRUE;
				retorno = TODO_OK;
				break;
			}

		}
	}
	return retorno;
}

int swapPasajeros(Passenger* pasajero1,Passenger* pasajero2){
	Passenger aux;
	int retorno = ERROR;

	if(pasajero1 && pasajero2){
		aux = *pasajero1;
		*pasajero1 = *pasajero2;
		*pasajero2 = aux;

		retorno = TODO_OK;
	}

	return retorno;

}


int sortPassengers(Passenger* list, int len, int order){
	int retorno = ERROR;

	if(list && len > 0 && (order==1 || order == 0)){
		//ORDENO POR APELLIDO Y TIPO DE PASAJERO
		for(int i=0;i<len-1;i++){
			for(int j=i+1;j<len;j++){
				if ((order && ((0 == strcmp(list[i].lastName,list[j].lastName) && list[i].typePassenger > list[j].typePassenger) || 0 < strcmp(list[i].lastName,list[j].lastName) )) ||
						(!order && ((0 == strcmp(list[i].lastName,list[j].lastName) && list[i].typePassenger < list[j].typePassenger) || 0 > strcmp(list[i].lastName,list[j].lastName)))){
					swapPasajeros(&list[i],&list[j]);
				}
			}
		}

		retorno = TODO_OK;
	}
	return retorno;
}


int printPassenger(Passenger* list, int length){
	int retorno = ERROR;
	Passenger pasajeroActual;
	int seEjecuto = FALSE;

	if(list && length >0){
		printf("\t\t\t\t\t\t\t***LISTA DE PASAJEROS***\n");
		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		for(int i=0;i<length;i++){
			pasajeroActual = list[i];
			if(!pasajeroActual.isEmpty){
				printPassengerData(pasajeroActual);
				seEjecuto = TRUE;
			}
		}
		if(!seEjecuto)
			printf("No hay ningun pasajero para mostrar \n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n\n");
		retorno =TODO_OK;
	}

	return retorno;
}


int printPassengerActive(Passenger* list, int length){
	int retorno = ERROR;
	Passenger pasajeroActual;
	int seEjecuto = FALSE;

	if(list && length >0){
		printf("\t\t\t\t\t\t\t***LISTA DE PASAJEROS ACTIVOS***\n");
		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		for(int i=0;i<length;i++){
			pasajeroActual = list[i];
			if(!pasajeroActual.isEmpty && pasajeroActual.statusFlight){
				printPassengerData(pasajeroActual);
				seEjecuto = TRUE;
			}

		}
		if(!seEjecuto)
			printf("No hay ningun pasajero para mostrar \n");

		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n\n");
		retorno =TODO_OK;
	}

	return retorno;
}


int sortPassengersByCode(Passenger* list, int len, int order){
	int retorno =ERROR;
	if(list && len > 0 && (order==1 || order == 0)){
			//ORDENO POR CODIGO DE VUELO Y ESTADO DE VUELO
			for(int i=0;i<len-1;i++){
				for(int j=i+1;j<len;j++){
						if ((order && ((0 == strcmp(list[i].flycode,list[j].flycode) && list[i].statusFlight > list[j].statusFlight) || 0 < strcmp(list[i].flycode,list[j].flycode) )) ||
								(!order && ((0 == strcmp(list[i].flycode,list[j].flycode) && list[i].statusFlight < list[j].statusFlight) || 0 > strcmp(list[i].flycode,list[j].flycode)))){
							swapPasajeros(&list[i],&list[j]);
						}
				}
			}
			retorno = TODO_OK;
		}

	return retorno;
}

int modifyPassenger(Passenger* list, int len, int id, char name[],char
		lastName[],float price,int typePassenger, char flycode[]){
	int retorno = ERROR;
	int posicion;
	if(list && len >0 && name && lastName && flycode ){
		//CARGO LOS DATOS
		posicion = findPassengerById(list,len,id);
		if(posicion != ERROR){
			strcpy(list[posicion].name,name);
			strcpy(list[posicion].lastName,lastName);
			list[posicion].price = price;
			list[posicion].typePassenger = typePassenger;
			strcpy(list[posicion].flycode,flycode);
			list[posicion].isEmpty=FALSE;
			retorno = TODO_OK;
		}

	}
	return retorno;

}


int calculatePricesPassengers(Passenger* list, int len,float* resultados){
	int retorno = ERROR ;//CALCULOS ERRONEOS
	float promedio=0;
	int cantidadPasajerosSupPromedio = 0;
	int contadorPasajeros = 0;
	float total=0;


	if(list && len >0 && resultados){
		for(int i=0;i<len;i++){
			if(!list[i].isEmpty){
				total += list[i].price;
				contadorPasajeros++;
			}

		}
		if(contadorPasajeros)
			promedio = total/contadorPasajeros;
		for(int i=0;i<len;i++){
			if(!list[i].isEmpty && list[i].price > promedio){
				cantidadPasajerosSupPromedio++;
			}

		}

		retorno = TODO_OK;//CALCULOS CORRECTOS
		resultados[0] = total;
		resultados[1] = promedio;
		resultados[2] = cantidadPasajerosSupPromedio;
	}
	return retorno;
}

