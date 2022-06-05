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


int buscarTipoPasajero (eTipoPasajero tiposP[],int tamP,char* descripcion,int* pIndice){
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
/*
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
        buscarDestino (tiposP,tamP,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}


int pedirTipoPasajero(eTipoPasajero tiposP[],int tamP,int* idTiposP){
    int todoOk=0;
    if(tiposP && tamP >0 && idTiposP){
        listarDestinos(tiposP,tamP);
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
    if(tiposP && tamP >0 && descripcion && buscarTipoPasajero(tiposP,tamP,id,&indice)){
        strcpy(descripcion,tiposP[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}*/

