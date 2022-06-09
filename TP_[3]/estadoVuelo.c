/*
 * estadoVuelo.c
 *
 *  Created on: 5 jun. 2022
 *      Author: PACugliari
 */

#include "estadoVuelo.h"
#include "stdlib.h"
#include "stdio.h"
#include <string.h>


eEstadoVuelo* EstadoVuelo_new(){
	eEstadoVuelo* nuevoEstado = (eEstadoVuelo*) calloc(1,sizeof(eEstadoVuelo));
    return nuevoEstado;
}


eEstadoVuelo* EstadoVuelo_newParametros(int id,char* descripcion){
	eEstadoVuelo* nuevoEstado = EstadoVuelo_new();
    if(nuevoEstado && descripcion ){
        if(!(EstadoVuelo_setId(nuevoEstado,id) && EstadoVuelo_setDescripcion(nuevoEstado,descripcion))){
        	EstadoVuelo_delete(nuevoEstado);
        	nuevoEstado = NULL;
           }
    }
    return nuevoEstado;
}

LinkedList* EstadosVuelos_newLista (){
	LinkedList* todoOk = ll_newLinkedList();
	eEstadoVuelo* estadoActual;

	if(todoOk){
		estadoActual = EstadoVuelo_newParametros(20000,"Aterrizado");
		if(estadoActual)
			ll_add(todoOk,estadoActual);
		estadoActual = EstadoVuelo_newParametros(20001,"En Horario");
		if(estadoActual)
			ll_add(todoOk,estadoActual);
		estadoActual = EstadoVuelo_newParametros(20002,"Demorado");
		if(estadoActual)
			ll_add(todoOk,estadoActual);
	}

	return todoOk;
}

int EstadosVuelos_deleteLista(LinkedList* lista){
	int todoOk = 0;
	eEstadoVuelo* estadoActual;
	if(lista){
		for(int i=0;i<ll_len(lista);i++){
			estadoActual = (eEstadoVuelo*) ll_get(lista,i);
			EstadoVuelo_delete(estadoActual);
		}
		ll_deleteLinkedList(lista);
		todoOk = 1;
	}
	return todoOk;
}

void EstadoVuelo_delete(eEstadoVuelo* estadoVuelo){
	free(estadoVuelo);
}

int EstadoVuelo_setId(eEstadoVuelo* this,int id){
    int todoOk = 0;
    if(this && id >= 20000 && id <= 29999 ){ //VALIDACION DE ID
    	this->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int EstadoVuelo_getId(eEstadoVuelo* this,int* id){
    int todoOk = 0;
    if(this && id){
        (*id) = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int EstadoVuelo_setDescripcion(eEstadoVuelo* this,char* descripcion){
    int todoOk = 0;
    if(this && descripcion && strlen(descripcion) > 0 && strlen(descripcion) < 25){
        strcpy(this->descripcion,descripcion);
        todoOk = 1;
    }
    return todoOk;
}

int EstadoVuelo_getDescripcion(eEstadoVuelo* this,char* descripcion){
    int todoOk = 0;
    if(this && descripcion){
        strcpy(descripcion,this->descripcion);
        todoOk = 1;
    }
    return todoOk;
}


int buscarEstadoVueloPorDescripcion (LinkedList* lista,char* descripcion,int* indice){
    int todoOk = 0;
    eEstadoVuelo* estadoActual;

    if(lista && indice){
    	(*indice)= -1;
        for(int i=0;i<ll_len(lista);i++){
        	estadoActual = (eEstadoVuelo*) ll_get(lista,i);
            if(!strcmp(estadoActual->descripcion,descripcion)){
                (*indice) = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarEstadoVueloPorId (LinkedList* lista,int id,int* indice){
    int todoOk = 0;
    eEstadoVuelo* estadoActual;

    if(lista && indice){
    	(*indice) = -1;
        for(int i=0;i<ll_len(lista);i++){
        	estadoActual = (eEstadoVuelo*) ll_get(lista,i);
            if(estadoActual->id == id){
                (*indice) = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionEstadoVuelo (LinkedList* lista,int id,char descripcion[]){
    int todoOk = 0;
    int indice;
    eEstadoVuelo* estadoActual;

    if(lista && descripcion && buscarEstadoVueloPorId(lista,id,&indice)){
    	estadoActual = (eEstadoVuelo*) ll_get(lista,indice);
        strcpy(descripcion,estadoActual->descripcion);
        todoOk = 1;
    }
    return todoOk;
}


int listarEstadosVuelos (LinkedList* lista){
    int todoOk = 0;
    eEstadoVuelo* estadoActual;

    if(lista){
        system("cls");
        printf("  ***LISTADO DE ESTADOS DE VUELOS***\n");
        printf("-------------------------------\n");
        printf("ID\tEstado de vuelo\n");
        printf("-------------------------------\n");
        for(int i=0;i<ll_len(lista);i++){
        	estadoActual = (eEstadoVuelo*) ll_get(lista,i);
            printf("%d\t%-10s\n",estadoActual->id,estadoActual->descripcion);
        }
        printf("-------------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}


int validarEstadoVuelo (LinkedList* lista,int id){
    int todoOk = 0;
    int indice;
    if(lista){
    	buscarEstadoVueloPorId (lista,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}


int pedirEstadoVuelo (LinkedList* lista,int* id){
    int todoOk=0;
    if(lista && id){
    	listarEstadosVuelos(lista);
        printf("Ingrese el ID del estado de vuelo \n");
        scanf("%d",id);
        fflush(stdin);

        while(!validarEstadoVuelo(lista,*id)){
            printf("Error en la ID del estado de vuelo.Vuelva a ingresar \n");
            scanf("%d",id);
            fflush(stdin);
        }
        todoOk = 1;
    }
    return todoOk;

}
