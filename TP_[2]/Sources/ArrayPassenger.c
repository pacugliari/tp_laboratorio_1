/*
 * ArrayPassenger.c
 *
 *  Created on: 18 abr. 2022
 *      Author: PACugliari
 */

#include "../Headers/ArrayPassenger.h"



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
	if(list && len >0 && id >=0 && id<=CANT_PASAJEROS-1){
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

	if(list && len > 0 && id >=0 && id <= CANT_PASAJEROS-1 ){
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

void swapPasajeros(Passenger* pasajero1,Passenger* pasajero2){
	Passenger aux;

	strcpy(aux.flycode,pasajero1->flycode);
	aux.id = pasajero1->id;
	aux.isEmpty = pasajero1->isEmpty;
	strcpy(aux.lastName,pasajero1->lastName);
	strcpy(aux.name,pasajero1->name);
	aux.price = pasajero1->price;
	aux.typePassenger = pasajero1->typePassenger;
	aux.statusFlight = pasajero1->statusFlight;


	strcpy(pasajero1->flycode,pasajero2->flycode);
	pasajero1->id = pasajero2->id;
	pasajero1->isEmpty = pasajero2->isEmpty;
	strcpy(pasajero1->lastName,pasajero2->lastName);
	strcpy(pasajero1->name,pasajero2->name);
	pasajero1->price = pasajero2->price;
	pasajero1->typePassenger = pasajero2->typePassenger;
	pasajero1->statusFlight = pasajero2->statusFlight;

	strcpy(pasajero2->flycode,aux.flycode);
	pasajero2->id = aux.id;
	pasajero2->isEmpty = aux.isEmpty;
	strcpy(pasajero2->lastName,aux.lastName);
	strcpy(pasajero2->name,aux.name);
	pasajero2->price = aux.price;
	pasajero2->typePassenger = aux.typePassenger;
	pasajero2->statusFlight = aux.statusFlight;
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
		for(int i=0;i<CANT_PASAJEROS;i++){
			pasajeroActual = list[i];
			if(!pasajeroActual.isEmpty)
				printf("%04d\t\t%-16s%-24s%10.2f\t\t%d\t\t\t\t%-10s\t\t%d\n",pasajeroActual.id,
					pasajeroActual.name,pasajeroActual.lastName,pasajeroActual.price,pasajeroActual.typePassenger,
					pasajeroActual.flycode,pasajeroActual.statusFlight);
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

	if(list && len >0 && id != -1 && name && lastName && flycode && -1 != findPassengerById(list,CANT_PASAJEROS,id)){

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
		for(int i=0;i<CANT_PASAJEROS;i++){
			pasajeroActual = list[i];
			if(!pasajeroActual.isEmpty && pasajeroActual.statusFlight)
				printf("%04d\t\t%-16s%-24s%10.2f\t\t%d\t\t\t\t%-10s\t\t%d\n",pasajeroActual.id,
					pasajeroActual.name,pasajeroActual.lastName,pasajeroActual.price,pasajeroActual.typePassenger,
					pasajeroActual.flycode,pasajeroActual.statusFlight);
		}
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n\n");

		retorno =0;
	}

	return retorno;
}

int calculatePricesPassengers(Passenger* list, int len,float* resultados){
	int retorno =0 ;//CALCULOS ERRONEOS
	float promedio;
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

