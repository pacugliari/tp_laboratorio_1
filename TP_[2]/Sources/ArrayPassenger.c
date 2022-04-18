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
lastName[],float price,int typePassenger, char flycode[]){
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


	strcpy(pasajero1->flycode,pasajero2->flycode);
	pasajero1->id = pasajero2->id;
	pasajero1->isEmpty = pasajero2->isEmpty;
	strcpy(pasajero1->lastName,pasajero2->lastName);
	strcpy(pasajero1->name,pasajero2->name);
	pasajero1->price = pasajero2->price;
	pasajero1->typePassenger = pasajero2->typePassenger;

	strcpy(pasajero2->flycode,aux.flycode);
	pasajero2->id = aux.id;
	pasajero2->isEmpty = aux.isEmpty;
	strcpy(pasajero2->lastName,aux.lastName);
	strcpy(pasajero2->name,aux.name);
	pasajero2->price = aux.price;
	pasajero2->typePassenger = aux.typePassenger;
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


