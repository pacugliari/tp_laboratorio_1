/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Passenger* Passenger_new(){
	Passenger* nuevoPasajero = (Passenger*) calloc(1,sizeof(Passenger));
	nuevoPasajero->isEmpty = 0;
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

int Passenger_setId(Passenger* this,int id){
    int todoOk = 0;
    if(this ){ //VALIDACION DE ID
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
    if(this && nombre){ //VALIDAR NOMBRE
        strcpy(this->nombre,nombre);
        strlwr(this->nombre);
        this->nombre[0] = toupper(this->nombre[0]);
        todoOk = 1;
    }else
    	printf("Error en nombre \n");
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
    if(this && apellido && strlen(apellido)<50 && strlen(apellido)>2){
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
    if(this && codigoVuelo){ //VALIDAR CODIGO DE VUELO
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
    if(this ){ //VALIDACION DE PRECIO
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
    if(this ){ //VALIDACION DE TIPO DE PASAJERO
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
