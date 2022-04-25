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
	int retorno = -1;

	if(list && len>0 ){
		for(int i=0;i<len;i++){
			list[i].isEmpty = 1;//1-TRUE
		}
		retorno =0;
	}
	return retorno;
}

int posicionVacia(Passenger* list,int len){
	int retorno = -1;
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
	int retorno = -1;


	if(list && len >0 && id != -1 && name && lastName && flycode){
		//CARGO LOS DATOS
		strcpy(list[id].name,name);
		strcpy(list[id].lastName,lastName);
		list[id].price = price;
		list[id].typePassenger = typePassenger;
		strcpy(list[id].flycode,flycode);
		list[id].id = id;
		list[id].isEmpty=0;
		list[id].statusFlight = statusFlight;
		retorno = 0;

	}
	return retorno;
}

int findPassengerById(Passenger* list, int len,int id){
	int retorno = -1;

	//ID VA DE 0 A 1999
	if(list && len >0 && id >=0 && id<=len-1){
		for(int i=0;i<len;i++){
			if(id == list[i].id && !list[i].isEmpty){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


int removePassenger(Passenger* list, int len, int id){
	int retorno = -1;

	if(list && len > 0 && id >=0 && id <= len-1 && -1 != findPassengerById(list,len,id)){
		for(int i=0;i<len;i++){
			if(id == list[i].id && !list[i].isEmpty){
				list[i].isEmpty = 1;
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}

int swapPasajeros(Passenger* pasajero1,Passenger* pasajero2){
	Passenger aux;
	int todoOk = 0;

	if(pasajero1 && pasajero2){
		aux = *pasajero1;
		*pasajero1 = *pasajero2;
		*pasajero2 = aux;

		todoOk = 1;
	}

	return todoOk;

}


int sortPassengers(Passenger* list, int len, int order){
	int retorno = -1;

	if(list && len > 0 && (order==1 || order == 0)){
		//ORDENO APELLIDOS
		for(int i=0;i<len-1;i++){
			for(int j=i+1;j<len;j++){
					if((order && 0 < strcmp(list[i].lastName,list[j].lastName) ) || (!order && 0 > strcmp(list[i].lastName,list[j].lastName))){
						swapPasajeros(&list[i],&list[j]);
					}
			}
		}
		//ORDENO TIPO DE PASAJERO
		for(int i=0;i<len-1;i++){
			for(int j=i+1;j<len;j++){
					if((order && 0 == strcmp(list[i].lastName,list[j].lastName) && list[i].typePassenger > list[j].typePassenger ) || (
							!order && 0 == strcmp(list[i].lastName,list[j].lastName)  && list[i].typePassenger < list[j].typePassenger)){
						swapPasajeros(&list[i],&list[j]);
					}
			}
		}
		retorno = 0;
	}
	return retorno;
}


int printPassenger(Passenger* list, int length){
	int retorno = -1;
	Passenger pasajeroActual;

	if(list && length >0){
		printf("\t\t\t\t\t\t\t***LISTA DE PASAJEROS***\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		for(int i=0;i<length;i++){
			pasajeroActual = list[i];
			if(!pasajeroActual.isEmpty)
				printPassengerData(pasajeroActual);
		}
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n\n");

		retorno =0;
	}

	return retorno;
}


int sortPassengersByCode(Passenger* list, int len, int order){
	int retorno =-1;
	if(list && len > 0 && (order==1 || order == 0)){
			//ORDENO POR CODIGO DE VUELO
			for(int i=0;i<len-1;i++){
				for(int j=i+1;j<len;j++){
						if((order && 0 < strcmp(list[i].flycode,list[j].flycode) ) || (!order && 0 > strcmp(list[i].flycode,list[j].flycode))){
							swapPasajeros(&list[i],&list[j]);
						}
				}
			}
			//ORDENO POR ESTADO DE VUELO
			for(int i=0;i<len-1;i++){
				for(int j=i+1;j<len;j++){
						if((order && 0 == strcmp(list[i].flycode,list[j].flycode) && list[i].statusFlight > list[j].statusFlight ) || (
								!order && 0 == strcmp(list[i].flycode,list[j].flycode)  && list[i].statusFlight < list[j].statusFlight)){
							swapPasajeros(&list[i],&list[j]);
						}
				}
			}
			retorno = 0;
		}

	return retorno;
}

int modifyPassenger(Passenger* list, int len, int id, char name[],char
		lastName[],float price,int typePassenger, char flycode[]){
	int retorno = -1;
	if(list && len >0 && id != -1 && name && lastName && flycode && -1 != findPassengerById(list,len,id)){
		//CARGO LOS DATOS
		strcpy(list[id].name,name);
		strcpy(list[id].lastName,lastName);
		list[id].price = price;
		list[id].typePassenger = typePassenger;
		strcpy(list[id].flycode,flycode);
		list[id].id = id;
		list[id].isEmpty=0;
		retorno = 0;


	}
	return retorno;

}

int printPassengerActive(Passenger* list, int length){
	int retorno = -1;
	Passenger pasajeroActual;

	if(list && length >0){
		printf("\t\t\t\t\t\t\t***LISTA DE PASAJEROS ACTIVOS***\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		for(int i=0;i<length;i++){
			pasajeroActual = list[i];
			if(!pasajeroActual.isEmpty && pasajeroActual.statusFlight)
				printPassengerData(pasajeroActual);
		}
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n\n");

		retorno =0;
	}

	return retorno;
}

int calculatePricesPassengers(Passenger* list, int len,float* resultados){
	int retorno =0 ;//CALCULOS ERRONEOS
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

		retorno =1;//CALCULOS CORRECTOS
		resultados[0] = total;
		resultados[1] = promedio;
		resultados[2] = cantidadPasajerosSupPromedio;
	}
	return retorno;
}

