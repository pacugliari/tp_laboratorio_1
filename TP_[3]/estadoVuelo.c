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

int hardcodearEstadosVuelo(eEstadoVuelo* vector,int tam){
	int todoOk = 0;
	if(vector && tam >0 && tam <= 3){
		eEstadoVuelo estadosV [3] = {{20000,"Aterrizado"},
		                                  {20001,"En Horario"},
		                                  {20002,"Demorado"}};
		for(int i=0;i<tam;i++){
			vector[i].id = estadosV[i].id;
			strcpy(vector[i].descripcion,estadosV[i].descripcion);
		}
		todoOk = 1;
	}
	return todoOk;

}

int buscarEstadoVueloPorDescripcion (eEstadoVuelo estadoV[],int tamEstadoV,char* descripcion,int* pIndice){
    int todoOk = 0;
    if(estadoV && tamEstadoV >0 && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamEstadoV;i++){
            if(!strcmp(estadoV[i].descripcion,descripcion)){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarEstadoVueloPorId (eEstadoVuelo estadoV[],int tamEstadoV,int id,int* pIndice){
    int todoOk = 0;
    if(estadoV && tamEstadoV >0 && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamEstadoV;i++){
            if(estadoV[i].id == id){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionEstadoVuelo (eEstadoVuelo estadoV[],int tamE,int id,char descripcion[]){
    int todoOk = 0;
    int indice;
    if(estadoV && tamE >0 && descripcion && buscarEstadoVueloPorId(estadoV,tamE,id,&indice)){
        strcpy(descripcion,estadoV[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}


int listarEstadosVuelos (eEstadoVuelo estadosV[],int tamE){
    int todoOk = 0;

    if(estadosV && tamE>0){
        system("cls");
        printf("  ***LISTADO DE ESTADOS DE VUELOS***\n");
        printf("-------------------------------\n");
        printf("ID\tEstado de vuelo\n");
        printf("-------------------------------\n");
        for(int i=0;i<tamE;i++){
            printf("%d\t%-10s\n",estadosV[i].id,estadosV[i].descripcion);
        }
        printf("-------------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}





int validarEstadoVuelo (eEstadoVuelo estadosV[],int tamE,int id){
    int todoOk = 0;
    int indice;
    if(estadosV && tamE > 0){
    	buscarEstadoVueloPorId (estadosV,tamE,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}


int pedirEstadoVuelo (eEstadoVuelo estadosV[],int tamE,int* idEstadoV){
    int todoOk=0;
    if(estadosV && tamE >0 && idEstadoV){
    	listarEstadosVuelos(estadosV,tamE);
        printf("Ingrese el ID del estado de vuelo \n");
        scanf("%d",idEstadoV);
        fflush(stdin);

        while(!validarEstadoVuelo(estadosV,tamE,*idEstadoV)){
            printf("Error en la ID del estado de vuelo.Vuelva a ingresar \n");
            scanf("%d",idEstadoV);
            fflush(stdin);
        }
        todoOk = 1;
    }
    return todoOk;

}
