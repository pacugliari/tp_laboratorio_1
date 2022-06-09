#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "TipoPasajero.h"
#include "EstadoVuelo.h"
#include <string.h>

int menu();
void limpiarLista(LinkedList* listaPasajeros);
int pedirPath(char* path);

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);//AGREGADO PARA EVITAR BUG CONSOLA ECLIPSE
    int option = 0;
    LinkedList* listaPasajeros =  ll_newLinkedList();
    LinkedList* tiposPasajeros = TiposPasajeros_newLista();
    LinkedList* estadosVuelos = EstadosVuelos_newLista();

	char path[50];
    int id= 1;
    int seGuardoArchivo = 0;

    do{
         switch(option=menu()){
             case 1:
            	 if(pedirPath(path))
            		 controller_loadFromText(path,listaPasajeros,&id);
                 break;
             case 2:
            	 if(pedirPath(path))
            		 controller_loadFromBinary(path,listaPasajeros,&id);
                 break;
             case 3:
            	 controller_addPassenger(listaPasajeros,&id,tiposPasajeros,estadosVuelos);
                 break;
             case 4:
            	 controller_editPassenger(listaPasajeros,tiposPasajeros,estadosVuelos);
                 break;
             case 5:
            	 controller_removePassenger(listaPasajeros,tiposPasajeros,estadosVuelos);
                 break;
             case 6:
            	 controller_ListPassenger(listaPasajeros,tiposPasajeros,estadosVuelos);
                 break;
             case 7:

                 break;
             case 8:
            	 if(pedirPath(path))
            		 seGuardoArchivo = controller_saveAsText(path,listaPasajeros,tiposPasajeros,estadosVuelos);
                 break;
             case 9:
            	 if(pedirPath(path))
            		 seGuardoArchivo = controller_saveAsBinary(path,listaPasajeros);
                 break;
             case 10:
            	 if(seGuardoArchivo)
            		 option = 10;
            	 else{
            		 printf("No se guardo ningun archivo \n");
            		 option=-1;
            	 }

                 break;
             default:
                 system("cls");
                 printf("Opcion de menu incorrecta \n\n");
             break;
         }
         system("pause");
         system("cls");
     }while (option != 10 );

    limpiarLista(listaPasajeros);
    ll_deleteLinkedList(listaPasajeros);
	EstadosVuelos_deleteLista(estadosVuelos);
	TiposPasajeros_deleteLista(tiposPasajeros);

    return 0;
}


void limpiarLista (LinkedList* listaPasajeros){
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


int menu(){
    int respuesta;

	printf("-------------------------------------------------------------------------------------------------------------------------------"
			"------------------------\n");
    printf("Menu: \n");
    printf("\t1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
    printf("\t2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
    printf("\t3. Alta de pasajero\n");
    printf("\t4. Modificar datos de pasajero\n");
    printf("\t5. Baja de pasajero\n");
    printf("\t6. Listar pasajeros\n");
    printf("\t7. Ordenar pasajeros\n");
    printf("\t8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
    printf("\t9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
    printf("\t10. Salir \n\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------"
			"------------------------\n");
	printf("Ingrese opcion: ");

    scanf("%d",&respuesta);
    fflush(stdin);


    return respuesta;

}

int pedirPath(char* path){
	int todoOk = 0;
	char pathAux [30];
	if(path){
		 path[0]='\0';
		 strcat(path,"TP_[3]/");
		 printf("Ingrese el Path: ");
		 fflush(stdin);
		 gets(pathAux);
		 fflush(stdin);
		 while(strlen(pathAux) <= 0 || strlen(pathAux) >= 20){
			 printf("Ingrese un Path mas corto/largo: ");
			 fflush(stdin);
			 gets(pathAux);
			 fflush(stdin);
		 }
		 strcat(path,pathAux);
		 todoOk = 1;
	}

	 return todoOk;
}



