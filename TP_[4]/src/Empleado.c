#include <stdio.h>
#include <stdlib.h>
#include "../inc/Empleado.h"
#include <ctype.h>
#include <string.h>



eEmpleado* new_Empleado(){
    eEmpleado* nuevoEmpleado = (eEmpleado*) calloc(1,sizeof(eEmpleado));
    return nuevoEmpleado;
}

eEmpleado* new_EmpleadoParam(int legajo,char* nombre,char* apellido,char sexo,float sueldo){
    eEmpleado* nuevoEmpleado = new_Empleado();
    if(nuevoEmpleado){
        if(!(empleadoSetLegajo(nuevoEmpleado,legajo) &&
           empleadoSetNombre(nuevoEmpleado,nombre) &&
           empleadoSetApellido(nuevoEmpleado,apellido) &&
           empleadoSetSexo(nuevoEmpleado,sexo) &&
           empleadoSetSueldo(nuevoEmpleado,sueldo))){
               destroy_Empleado(nuevoEmpleado);
               nuevoEmpleado = NULL;
           }
    }
    return nuevoEmpleado;
}

eEmpleado* new_EmpleadoString(char* legajo,char* nombre,char* apellido,char* sexo,char* sueldo){
    eEmpleado* nuevoEmpleado = new_Empleado();
    if(nuevoEmpleado && legajo && nombre && apellido && sexo && sueldo){
        if(!(empleadoSetLegajo(nuevoEmpleado,atoi(legajo)) &&
           empleadoSetNombre(nuevoEmpleado,nombre) &&
           empleadoSetApellido(nuevoEmpleado,apellido) &&
           empleadoSetSexo(nuevoEmpleado,sexo[0]) &&
           empleadoSetSueldo(nuevoEmpleado,atof(sueldo)))){
               destroy_Empleado(nuevoEmpleado);
               nuevoEmpleado = NULL;
           }
    }
    return nuevoEmpleado;
}

void destroy_Empleado(eEmpleado* e){
    free(e);
}

int empleadoSetLegajo(eEmpleado* e,int legajo){
    int todoOk = 0;
    if(e && legajo >= 20000){
        e->legajo = legajo;
        todoOk = 1;
    }
    return todoOk;
}

int empleadoSetNombre (eEmpleado* e,char* nombre){
    int todoOk = 0;
    if(e && nombre && strlen(nombre)<20 && strlen(nombre)>2){
        //PARA EVITAR EL ERROR SI EL USUARIO ME PASA UN LITERAL DE CADENA
        //POR PARAMETRO, LO ALMACENO  EN LA ESTRUCTURA, AL PASAR POR LITERAL SE PASA "ONTHEFLY" QUE SE PIERDE
        //Y EL STRLWR NO RECIBE NADA Y POR LO TANTO CRASHEA EL PROGRAMA
        strcpy(e->nombre,nombre);
        strlwr(e->nombre);
        e->nombre[0] = toupper(e->nombre[0]);
        todoOk = 1;
    }
    return todoOk;
}

int empleadoSetApellido (eEmpleado* e,char* apellido){
    int todoOk = 0;
    if(e && apellido && strlen(apellido)<20 && strlen(apellido)>1){
        strcpy(e->apellido,apellido);
        strlwr(e->apellido);
        e->apellido[0] = toupper(e->apellido[0]);
        todoOk = 1;
    }
    return todoOk;
}

int empleadoSetSexo (eEmpleado* e,char sexo){
    int todoOk = 0;
    sexo = tolower(sexo);
    if(e && (sexo == 'm' || sexo== 'f')){
        e->sexo = sexo;
        todoOk = 1;
    }
    return todoOk;
}

int empleadoSetSueldo (eEmpleado* e,float sueldo){
    int todoOk = 0;
    if(e && sueldo > 0 && sueldo <= 1000000){
        e->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetLegajo(eEmpleado* e,int* pLegajo){
    int todoOk = 0;
    if(e && pLegajo){
        (*pLegajo) = e->legajo;
        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetNombre(eEmpleado* e,char* nombre){
    int todoOk = 0;
    if(e && nombre){
        strcpy(nombre,e->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetApellido(eEmpleado* e,char* apellido){
    int todoOk = 0;
    if(e && apellido){
        strcpy(apellido,e->apellido);
        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetNombreCompleto(eEmpleado* e,char* nombreCompleto){
    int todoOk = 0;
    if(e && nombreCompleto){
        strcpy(nombreCompleto,e->nombre);
        strcat(nombreCompleto," ");
        strcat(nombreCompleto,e->apellido);
        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetSexo (eEmpleado* e,char* pSexo){
    int todoOk = 0;
    if(e && pSexo){
        (*pSexo) = e->sexo;
        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetSexoString (eEmpleado* e,char* sexo){
    int todoOk = 0;
    if(e && sexo){
        if(e->sexo == 'm'){
           strcpy(sexo,"Masculino");
        }else
            strcpy(sexo,"Femenino");

        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetSueldo(eEmpleado* e,float* pSueldo){
    int todoOk = 0;
    if(e && pSueldo){
        (*pSueldo) = e->sueldo;
        todoOk = 1;
    }
    return todoOk;
}


int mostrarEmpleado(eEmpleado* e){
    int todoOk = 0;
    if(e){
       printf("%d\t%-10s\t%-10s\t%c\t$%.2f\n",e->legajo,e->nombre,e->apellido,e->sexo,e->sueldo);

       todoOk = 1;
    }
    return todoOk;
}


int empleadoComparaNombre(void* a,void* b){
    int retorno = 0;
    eEmpleado* x;
    eEmpleado* y;

    if(a && b){
        //COMO LOS TENGO EN VOID LOS CASTEO A EMPLEADOS
        x = (eEmpleado*)a;
        y = (eEmpleado*)b;

        retorno = strcmp(x->nombre,y->nombre);
    }
    return retorno;
}

int empleadoComparaSexo(void* a,void* b){
    int retorno = 0;
    eEmpleado* x;
    eEmpleado* y;

    if(a && b){
        //COMO LOS TENGO EN VOID LOS CASTEO A EMPLEADOS
        x = (eEmpleado*)a;
        y = (eEmpleado*)b;

        if(x->sexo > y->sexo){
            retorno = 1;
        }else if (x->sexo < y->sexo){
            retorno = -1;
        }
    }
    return retorno;
}



int empleadoComparaSueldo(void* a,void* b){
    int retorno = 0;
    eEmpleado* x;
    eEmpleado* y;

    if(a && b){
        //COMO LOS TENGO EN VOID LOS CASTEO A EMPLEADOS
        x = (eEmpleado*)a;
        y = (eEmpleado*)b;

        if(x->sueldo > y->sueldo){
            retorno = 1;
        }else if (x->sueldo < y->sueldo){
            retorno = -1;
        }
    }
    return retorno;
}

int empleadoComparaLegajo (void* a,void* b){
    int retorno = 0;
    eEmpleado* x;
    eEmpleado* y;

    if(a && b){
        //COMO LOS TENGO EN VOID LOS CASTEO A EMPLEADOS
        x = (eEmpleado*)a;
        y = (eEmpleado*)b;

        if(x->legajo > y->legajo){
            retorno = 1;
        }else if (x->legajo < y->legajo){
            retorno = -1;
        }
    }
    return retorno;
}

void mostrarEncabezadoEmpleado(){
        printf("-------------------------------------------------------------  \n");
        printf("             ****LISTA DE EMPLEADOS****                 \n");
        printf("-------------------------------------------------------------  \n");
        printf("ID\tNOMBRE\t\tAPELLIDO\tSEXO\tSUELDO\n");
        printf("-------------------------------------------------------------  \n");
}

int destroy_ListaEmpleados(LinkedList* lista){
    int todoOk = 0;
    int tam;
    eEmpleado* empleado;
    if(lista){
        tam = ll_len(lista);
        for(int i=0;i<tam;i++){
            empleado = ll_get(lista,i);
            destroy_Empleado(empleado);
        }
    }
    return todoOk;
}


LinkedList* cargarArchivoEmpleados(){
    LinkedList* retorno = NULL;
    char buffer[5][20];
    char path[] = {"TP_[4]/src/empleados.csv"};
    FILE* arch = fopen(path,"r");
    eEmpleado* empleado;
    int datos = 0;

    if(arch){
        retorno = ll_newLinkedList();
        fscanf(arch,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
        if(retorno){
            while(!feof(arch)){
                datos =  fscanf(arch,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
                if(datos == 5){
                    empleado = new_EmpleadoString(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
                    ll_add(retorno,empleado);
                }
            }
        }
    }else{
    	printf("No se pudo iniciar el archivo de prueba '%s' \n",path);
    }
    fclose(arch);
    return retorno;
}
