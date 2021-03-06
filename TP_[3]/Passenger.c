/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "LinkedList.h"
#include "tipoPasajero.h"
#include "estadoVuelo.h"

Passenger* Passenger_new(){
	Passenger* nuevoPasajero = (Passenger*) calloc(1,sizeof(Passenger));
    return nuevoPasajero;
}


Passenger* Passenger_newParametros(int id,char* nombre,char* apellido,float precio,char* codigoVuelo,int idTipoPasajero,int idEstadoVuelo){
	Passenger* nuevoPasajero = Passenger_new();
    if(nuevoPasajero && nombre && apellido && codigoVuelo){
        if(!(Passenger_setId(nuevoPasajero,id) &&
        	 Passenger_setNombre(nuevoPasajero,nombre) &&
			 Passenger_setApellido(nuevoPasajero,apellido) &&
			 Passenger_setCodigoVuelo(nuevoPasajero,codigoVuelo) &&
			 Passenger_setTipoPasajero(nuevoPasajero,idTipoPasajero) &&
			 Passenger_setPrecio(nuevoPasajero,precio) &&
			 Passenger_setStatusFlight(nuevoPasajero,idEstadoVuelo))){

        		Passenger_delete(nuevoPasajero);
                nuevoPasajero = NULL;
           }
    }
    return nuevoPasajero;
}

Passenger* Passenger_newParametrosString(char* id,char* nombre,char* apellido,char* precio,char* codigoVuelo,char* idTipoPasajero,char* idEstadoVuelo){
	return Passenger_newParametros(atoi(id),nombre,apellido,atof(precio),codigoVuelo,atoi(idTipoPasajero),atoi(idEstadoVuelo));
}


Passenger* Passenger_newPassenger (Passenger pasajero){
    return Passenger_newParametros(pasajero.id,pasajero.nombre,pasajero.apellido,pasajero.precio,pasajero.codigoVuelo,pasajero.idTipoPasajero,pasajero.idEstadoVuelo);
}

void Passenger_delete(Passenger* pasajero){
	free(pasajero);
}

void Passenger_deleteLista (LinkedList* listaPasajeros){
	int cursor = 0;
	Passenger* pasajeroActual;
	int tamanioLista = ll_len(listaPasajeros);
	 while( tamanioLista > cursor){
		 pasajeroActual = ll_get(listaPasajeros,cursor);
		 Passenger_delete(pasajeroActual);
		 cursor++;
	 }
	 ll_clear(listaPasajeros);
	printf("Se limpiaron %d pasajeros de un total de %d cargados en la lista \n",cursor,tamanioLista);
}


int Passenger_setId(Passenger* this,int id){
    int todoOk = 0;
    if(this && id >= 1 && id <= 9999 ){ //VALIDACION DE ID
    	this->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int Passenger_getId(Passenger* this,int* id){
    int todoOk = 0;
    if(this && id){
        (*id) = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre){
    int todoOk = 0;
    if(this && nombre && strlen(nombre) > 1 && strlen(nombre) < 50){ //VALIDAR NOMBRE
        strcpy(this->nombre,nombre);
        strlwr(this->nombre);
        this->nombre[0] = toupper(this->nombre[0]);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre){
    int todoOk = 0;
    if(this && nombre){
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido){
    int todoOk = 0;
    if(this && apellido && strlen(apellido)<50 && strlen(apellido)>1){
        strcpy(this->apellido,apellido);
        strlwr(this->apellido);
        this->apellido[0] = toupper(this->apellido[0]);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido){
    int todoOk = 0;
    if(this && apellido){
        strcpy(apellido,this->apellido);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
    int todoOk = 0;
    if(this && codigoVuelo && strlen(codigoVuelo)<8 && strlen(codigoVuelo)>0 ){ //VALIDAR CODIGO DE VUELO
        strcpy(this->codigoVuelo,codigoVuelo);
        strupr(this->codigoVuelo);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
    int todoOk = 0;
    if(this && codigoVuelo){
        strcpy(codigoVuelo,this->codigoVuelo);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
    int todoOk = 0;
    if(this ){ //VALIDACION DE TIPO DE PASAJERO
    	this->idTipoPasajero = tipoPasajero;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
    int todoOk = 0;
    if(this && tipoPasajero){
        (*tipoPasajero) = this->idTipoPasajero;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio){
    int todoOk = 0;
    if(this && precio >= 0 ){ //VALIDACION DE PRECIO
    	this->precio = precio;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio){
    int todoOk = 0;
    if(this && precio){
        (*precio) = this->precio;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setStatusFlight(Passenger* this,int idEstadoVuelo){
    int todoOk = 0;
    if(this ){ //VALIDACION DE ESTADO DE VUELO
    	this->idEstadoVuelo = idEstadoVuelo;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getStatusFlight(Passenger* this,int* idEstadoVuelo){
    int todoOk = 0;
    if(this && idEstadoVuelo){
        (*idEstadoVuelo) = this->idEstadoVuelo;
        todoOk = 1;
    }
    return todoOk;
}

int pasajeroComparaId (void* a,void* b){
    int retorno = 0;
    Passenger* x;
    Passenger* y;

    if(a && b){
        x = (Passenger*)a;
        y = (Passenger*)b;

        if(x->id > y->id){
            retorno = 1;
        }else if (x->id < y->id){
            retorno = -1;
        }
    }
    return retorno;
}

int pasajeroComparaNombre (void* a,void* b){
    int retorno = 0;
    Passenger* x;
    Passenger* y;

    if(a && b){
        x = (Passenger*)a;
        y = (Passenger*)b;

        retorno = strcmp(x->nombre,y->nombre);
    }
    return retorno;
}

int pasajeroComparaApellido (void* a,void* b){
    int retorno = 0;
    Passenger* x;
    Passenger* y;

    if(a && b){
        x = (Passenger*)a;
        y = (Passenger*)b;

        retorno = strcmp(x->apellido,y->apellido);
    }
    return retorno;
}

int pasajeroComparaPrecio (void* a,void* b){
    int retorno = 0;
    Passenger* x;
    Passenger* y;

    if(a && b){
        x = (Passenger*)a;
        y = (Passenger*)b;

        if(x->precio > y->precio){
            retorno = 1;
        }else if (x->precio < y->precio){
            retorno = -1;
        }
    }
    return retorno;
}


int pasajeroComparaCodigoVuelo (void* a,void* b){
    int retorno = 0;
    Passenger* x;
    Passenger* y;

    if(a && b){
        x = (Passenger*)a;
        y = (Passenger*)b;

        retorno = strcmp(x->codigoVuelo,y->codigoVuelo);
    }
    return retorno;
}

int pasajeroComparaTipoPasajero (void* a,void* b){
    int retorno = 0;
    Passenger* x;
    Passenger* y;
    char descripcionTipo1 [20];
    char descripcionTipo2 [20];
    LinkedList* tiposPasajeros = TiposPasajeros_newLista();


    if(a && b && tiposPasajeros){
        x = (Passenger*)a;
        y = (Passenger*)b;

        cargarDescripcionTipoPasajero (tiposPasajeros,x->idTipoPasajero,descripcionTipo1);
        cargarDescripcionTipoPasajero (tiposPasajeros,y->idTipoPasajero,descripcionTipo2);

        retorno = strcmp(descripcionTipo1,descripcionTipo2);
        TiposPasajeros_deleteLista(tiposPasajeros);
    }

    return retorno;
}

int pasajeroComparaEstadoVuelo (void* a,void* b){
    int retorno = 0;
    Passenger* x;
    Passenger* y;
    char descripcionEstado1 [20];
    char descripcionEstado2 [20];
    LinkedList* estadosVuelos = EstadosVuelos_newLista();

    if(a && b && estadosVuelos){
        x = (Passenger*)a;
        y = (Passenger*)b;
        cargarDescripcionEstadoVuelo (estadosVuelos,x->idEstadoVuelo,descripcionEstado1);
        cargarDescripcionEstadoVuelo (estadosVuelos,y->idEstadoVuelo,descripcionEstado2);
        retorno = strcmp(descripcionEstado1,descripcionEstado2);
        EstadosVuelos_deleteLista(estadosVuelos);
    }
    return retorno;
}


int buscarPasajeroPorId(LinkedList* pArrayListPassenger,int* pIndice,int id){
	int todoOk = 0;
	Passenger* pasajeroActual;
	if(pArrayListPassenger && pIndice ){
		(*pIndice) = -1;
		for(int i=0;i<ll_len(pArrayListPassenger);i++){
			pasajeroActual = ll_get(pArrayListPassenger,i);
			if(pasajeroActual->id == id){
				(*pIndice) = i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}


void printPassengerData (Passenger p,LinkedList* listaTiposPasajeros,LinkedList* listaEstadosVuelos){
	char descripcionTipoPasajero [30];
	char descripcionEstado [30];
	if(listaTiposPasajeros && listaEstadosVuelos){
		cargarDescripcionTipoPasajero(listaTiposPasajeros,p.idTipoPasajero,descripcionTipoPasajero);
		cargarDescripcionEstadoVuelo(listaEstadosVuelos,p.idEstadoVuelo,descripcionEstado);
		printf("%04d\t\t%-16s%-24s$%10.2f\t\t%-30s\t%-10s\t\t%-s\n",p.id,
									p.nombre,p.apellido,p.precio,descripcionTipoPasajero,
									p.codigoVuelo,descripcionEstado);
	}else
		printf("Error en los parametros de printPassengerData \n");
}


