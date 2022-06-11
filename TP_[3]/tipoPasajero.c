/*
 * tipoPasajero.c
 *
 *  Created on: 5 jun. 2022
 *      Author: PACugliari
 */

#include "stdlib.h"
#include "stdio.h"
#include <string.h>
#include "tipoPasajero.h"

eTipoPasajero* TipoPasajero_new(){
	eTipoPasajero* nuevoTipo = (eTipoPasajero*) calloc(1,sizeof(eTipoPasajero));
    return nuevoTipo;
}


eTipoPasajero* TipoPasajero_newParametros(int id,char* descripcion){
	eTipoPasajero* nuevoTipo = TipoPasajero_new();
    if(nuevoTipo && descripcion ){
        if(!(TipoPasajero_setId(nuevoTipo,id) && TipoPasajero_setDescripcion(nuevoTipo,descripcion))){
        	TipoPasajero_delete(nuevoTipo);
        	nuevoTipo = NULL;
           }
    }
    return nuevoTipo;
}

LinkedList* TiposPasajeros_newLista (){
	LinkedList* todoOk = ll_newLinkedList();
	eTipoPasajero* tipoActual;

	if(todoOk){
		tipoActual = TipoPasajero_newParametros(10000,"FirstClass");
		if(tipoActual)
			ll_add(todoOk,tipoActual);
		tipoActual = TipoPasajero_newParametros(10001,"ExecutiveClass");
		if(tipoActual)
			ll_add(todoOk,tipoActual);
		tipoActual = TipoPasajero_newParametros(10002,"EconomyClass");
		if(tipoActual)
			ll_add(todoOk,tipoActual);
	}

	return todoOk;
}

int TiposPasajeros_deleteLista(LinkedList* lista){
	int todoOk = 0;
	eTipoPasajero* tipoActual;
	if(lista){
		for(int i=0;i<ll_len(lista);i++){
			tipoActual = (eTipoPasajero*) ll_get(lista,i);
			TipoPasajero_delete(tipoActual);
		}
		ll_deleteLinkedList(lista);
		todoOk = 1;
	}
	return todoOk;
}

void TipoPasajero_delete(eTipoPasajero* tipoPasajero){
	free(tipoPasajero);
}

int TipoPasajero_setId(eTipoPasajero* this,int id){
    int todoOk = 0;
    if(this && id >= 10000 && id <= 19999 ){ //VALIDACION DE ID
    	this->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int TipoPasajero_getId(eTipoPasajero* this,int* id){
    int todoOk = 0;
    if(this && id){
        (*id) = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int TipoPasajero_setDescripcion(eTipoPasajero* this,char* descripcion){
    int todoOk = 0;
    if(this && descripcion && strlen(descripcion) > 0 && strlen(descripcion) < 25){
        strcpy(this->descripcion,descripcion);
        todoOk = 1;
    }
    return todoOk;
}

int TipoPasajero_getDescripcion(eTipoPasajero* this,char* descripcion){
    int todoOk = 0;
    if(this && descripcion){
        strcpy(descripcion,this->descripcion);
        todoOk = 1;
    }
    return todoOk;
}


int buscarTipoPasajeroPorDescripcion (LinkedList* lista,char* descripcion,int* pIndice){
    int todoOk = 0;
    eTipoPasajero* tipoActual;

    if(lista&& pIndice){
        *pIndice = -1;
        for(int i=0;i<ll_len(lista);i++){
        	tipoActual = (eTipoPasajero*) ll_get(lista,i);
            if(!strcmp(tipoActual->descripcion,descripcion)){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarTipoPasajeroPorId (LinkedList* lista,int id,int* pIndice){
    int todoOk = 0;
    eTipoPasajero* tipoActual;

    if(lista && pIndice){
    	(*pIndice) = -1;
        for(int i=0;i<ll_len(lista);i++){
        	tipoActual = (eTipoPasajero*) ll_get(lista,i);
            if(tipoActual->id == id){
                (*pIndice) = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarTiposPasajeros (LinkedList* lista){
    int todoOk = 0;
    eTipoPasajero* tipoActual;

    if(lista){
        system("cls");
        printf("\n-------------------------------\n");
        printf("  ***LISTADO DE TIPOS DE PASAJEROS***\n");
        printf("-------------------------------\n");
        printf("ID\tTipo de pasajero\n");
        printf("-------------------------------\n");
        for(int i=0;i<ll_len(lista);i++){
        	tipoActual = (eTipoPasajero*) ll_get(lista,i);
            printf("%d\t%-10s\n",tipoActual->id,tipoActual->descripcion);
        }
        printf("-------------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}





int validarTipoPasajero (LinkedList* lista,int id){
    int todoOk = 0;
    int indice;
    if(lista){
    	buscarTipoPasajeroPorId (lista,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}


int pedirTipoPasajero(LinkedList* lista,int* id){
    int todoOk=0;
    if(lista && id){
    	listarTiposPasajeros(lista);
        printf("Ingrese el ID del tipo de pasajero \n");
        scanf("%d",id);
        fflush(stdin);

        while(!validarTipoPasajero(lista,*id)){
            printf("Error en la ID del tipo de pasajero.Vuelva a ingresar \n");
            scanf("%d",id);
            fflush(stdin);
        }
        todoOk = 1;
    }
    return todoOk;

}

int cargarDescripcionTipoPasajero (LinkedList* lista,int id,char descripcion[]){
    int todoOk = 0;
    int indice;
    eTipoPasajero* tipoActual;

    if(lista && descripcion && buscarTipoPasajeroPorId(lista,id,&indice)){
    	tipoActual = (eTipoPasajero*) ll_get(lista,indice);
        strcpy(descripcion,tipoActual->descripcion);
        todoOk = 1;
    }
    return todoOk;
}

