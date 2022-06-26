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
#include <ctype.h>


int buscarPasajeroLibre (Passenger pasajeros[],int tamP,int* pIndice){
    int todoOk = 0;
    if(pasajeros && tamP && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamP;i++){
            if(pasajeros[i].isEmpty){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int hardcodearPasajeros (Passenger pasajeros[],int tamP,int cantidad,int* pId){
    int todoOk = 0;
    int indiceLibre;
    Passenger pasajerosHard [] = {{1,"Pablo","Cugliari",100,"PC100",0,1,0},
                          {2,"Juan","Perez",200,"JP200",1,0,0},
                          {3,"Donna","Benfenati",300,"DB300",2,1,0},
                          {4,"Sergio","Albanese",400,"SA400",0,2,0},
                          {5,"Antonio","Mena",500,"AM500",1,1,0}};

    if (pasajeros && tamP>0 && pId && cantidad > 0 && cantidad <= 5){
    	buscarPasajeroLibre(pasajeros,tamP,&indiceLibre);
    	if(indiceLibre != -1){
    		for(int i=0;i<cantidad;i++){
    			pasajeros[indiceLibre] = pasajerosHard[i];
    			pasajeros[indiceLibre].id = (*pId);
    			(*pId)++;
    			indiceLibre++;
    		}
    		todoOk = cantidad;
    	}
    }
    return todoOk;
}

void printPassengerData (Passenger p,eTipoPasajero tiposPasajeros[], int tamT){
	char descripcionTipoPasajero [30];
	char descripcionEstado [10] = {"INACTIVO"};
	if(tiposPasajeros && tamT>0){
		if(p.statusFlight == 1)
			strcpy(descripcionEstado,"ACTIVO");
		cargarDescripcionTipoPasajero(tiposPasajeros,tamT,p.typePassenger,descripcionTipoPasajero);
		printf("%04d\t\t%-16s%-24s$%10.2f\t\t%-30s\t%-10s\t\t%-s\n",p.id,
							p.name,p.lastName,p.price,descripcionTipoPasajero,
							p.flycode,descripcionEstado);
	}else
		printf("Error en los parametros de printPassengerData \n");
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

int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger,int statusFlight, char flycode[]){
	int retorno = ERROR;
	Passenger pasajeroNuevo;
	int indice;

	if(list && len >0  && name && lastName && flycode && buscarPasajeroLibre(list,len,&indice)){
		if(indice != ERROR){
			//CARGO LOS DATOS
			strcpy(pasajeroNuevo.name,name);
			strcpy(pasajeroNuevo.lastName,lastName);
			pasajeroNuevo.price = price;
			pasajeroNuevo.typePassenger = typePassenger;
			strcpy(pasajeroNuevo.flycode,flycode);
			pasajeroNuevo.id = id;
			pasajeroNuevo.isEmpty=FALSE;
			pasajeroNuevo.statusFlight = statusFlight;

			list[indice] = pasajeroNuevo;
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


int printPassenger(Passenger* list, int length,eTipoPasajero tiposPasajeros[], int tamT){
	int retorno = ERROR;
	Passenger pasajeroActual;
	int seEjecuto = FALSE;

	if(list && length >0 && tiposPasajeros && tamT>0){
		printf("\t\t\t\t\t\t\t***LISTA DE PASAJEROS***\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		for(int i=0;i<length;i++){
			pasajeroActual = list[i];
			if(!pasajeroActual.isEmpty){
				printPassengerData(pasajeroActual,tiposPasajeros,tamT);
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


int printPassengerActive(Passenger* list, int length,eTipoPasajero tiposPasajeros[],int tamT){
	int retorno = ERROR;
	Passenger pasajeroActual;
	int seEjecuto = FALSE;

	if(list && length >0 && tiposPasajeros && tamT){
		printf("\t\t\t\t\t\t\t***LISTA DE PASAJEROS ACTIVOS***\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		for(int i=0;i<length;i++){
			pasajeroActual = list[i];
			if(!pasajeroActual.isEmpty && pasajeroActual.statusFlight==1){
				printPassengerData(pasajeroActual,tiposPasajeros,tamT);
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


int calculatePricesPassengers(Passenger* list, int len,eTipoPasajero tiposPasajeros[],int tamT){
	int retorno = ERROR ;//CALCULOS ERRONEOS
	float promedio=0;
	int cantidadPasajerosSupPromedio = 0;
	int contadorPasajeros = 0;
	float total=0;
	int indicePasajerosSupProm[len];


	if(list && len >0 && tiposPasajeros && tamT > 0 ){
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
				indicePasajerosSupProm[cantidadPasajerosSupPromedio]=i;
				cantidadPasajerosSupPromedio++;

			}

		}

		retorno = TODO_OK;//CALCULOS CORRECTOS
		printf("Total de los pasajes: $%.2f \n",total);
		printf("Promedio de los pasajes: $%.2f \n",promedio);
		printf("Cantidad de pasajeros que superan el precio promedio: %d \n\n",(int)cantidadPasajerosSupPromedio);
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		for(int i=0;i<cantidadPasajerosSupPromedio;i++){
			printPassengerData(list[indicePasajerosSupProm[i]],tiposPasajeros,tamT);
		}
	}
	return retorno;
}

