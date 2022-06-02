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
    return nuevoPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr){
	Passenger* nuevoPasajero = Passenger_new();
    if(nuevoPasajero && nombreStr && tipoPasajeroStr && idStr){
        if(!(Passenger_setId(nuevoPasajero,atoi(idStr)) &&
        	 Passenger_setNombre(nuevoPasajero,nombreStr) &&
			 Passenger_setTipoPasajero(nuevoPasajero,atoi(tipoPasajeroStr)))){

        		Passenger_delete(nuevoPasajero);
                nuevoPasajero = NULL;
           }
    }
    return nuevoPasajero;
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
    if(this && nombre && strlen(nombre)<50 && strlen(nombre)>2){
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
    if(this && codigoVuelo && strlen(codigoVuelo) != 4){
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
    	this->tipoPasajero = tipoPasajero;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
    int todoOk = 0;
    if(this && tipoPasajero){
        (*tipoPasajero) = this->tipoPasajero;
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
