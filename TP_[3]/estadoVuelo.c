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

int buscarEstadoVuelo (eEstadoVuelo estadoV[],int tamEstadoV,char* descripcion,int* pIndice){
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
