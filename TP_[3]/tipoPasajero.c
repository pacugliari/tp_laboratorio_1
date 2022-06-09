/*
 * tipoPasajero.c
 *
 *  Created on: 5 jun. 2022
 *      Author: PACugliari
 */


#include "tipoPasajero.h"
#include "stdlib.h"
#include "stdio.h"
#include <string.h>



int hardcodearTiposPasajeros (eTipoPasajero* vector,int tam){
	int todoOk = 0;
	if(vector && tam >0 && tam <= 3){
	    eTipoPasajero tiposP [3] = {{10000,"FirstClass"},
	                                  {10001,"ExecutiveClass"},
	                                  {10002,"EconomyClass"}};

		for(int i=0;i<tam;i++){
			vector[i].id = tiposP[i].id;
			strcpy(vector[i].descripcion,tiposP[i].descripcion);
		}
		todoOk = 1;
	}
	return todoOk;

}


int buscarTipoPasajeroPorDescripcion (eTipoPasajero tiposP[],int tamP,char* descripcion,int* pIndice){
    int todoOk = 0;
    if(tiposP && tamP >0 && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamP;i++){
            if(!strcmp(tiposP[i].descripcion,descripcion)){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarTipoPasajeroPorId (eTipoPasajero tiposP[],int tamP,int id,int* pIndice){
    int todoOk = 0;
    if(tiposP && tamP >0 && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamP;i++){
            if(tiposP[i].id == id){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarTiposPasajeros (eTipoPasajero tiposP[],int tamP){
    int todoOk = 0;

    if(tiposP && tamP>0){
        system("cls");
        printf("  ***LISTADO DE TIPOS DE PASAJEROS***\n");
        printf("-------------------------------\n");
        printf("ID\tTipo de pasajero\n");
        printf("-------------------------------\n");
        for(int i=0;i<tamP;i++){
            printf("%d\t%-10s\n",tiposP[i].id,tiposP[i].descripcion);
        }
        printf("-------------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}





int validarTipoPasajero (eTipoPasajero tiposP[],int tamP,int id){
    int todoOk = 0;
    int indice;
    if(tiposP && tamP > 0){
    	buscarTipoPasajeroPorId (tiposP,tamP,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}


int pedirTipoPasajero(eTipoPasajero tiposP[],int tamP,int* idTiposP){
    int todoOk=0;
    if(tiposP && tamP >0 && idTiposP){
    	listarTiposPasajeros(tiposP,tamP);
        printf("Ingrese el ID del tipo de pasajero \n");
        scanf("%d",idTiposP);
        fflush(stdin);

        while(!validarTipoPasajero(tiposP,tamP,*idTiposP)){
            printf("Error en la ID del tipo de pasajero.Vuelva a ingresar \n");
            scanf("%d",idTiposP);
            fflush(stdin);
        }
        todoOk = 1;
    }
    return todoOk;

}

int cargarDescripcionTipoPasajero (eTipoPasajero tiposP[],int tamP,int id,char descripcion[]){
    int todoOk = 0;
    int indice;
    if(tiposP && tamP >0 && descripcion && buscarTipoPasajeroPorId(tiposP,tamP,id,&indice)){
        strcpy(descripcion,tiposP[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}

