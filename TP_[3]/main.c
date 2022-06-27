#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "TipoPasajero.h"
#include "EstadoVuelo.h"
#include "pedirDatos.h"


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
         switch(option=pedirMenu()){
             case 1:
            	 if(pedirPath(path))
            		 controller_loadFromText(path,listaPasajeros,&id,tiposPasajeros,estadosVuelos);
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
            	 controller_sortPassenger(listaPasajeros);
                 break;
             case 8:
            	 if(ll_len(listaPasajeros)>0){
            		 pedirPath(path);
            		 seGuardoArchivo = controller_saveAsText(path,listaPasajeros,tiposPasajeros,estadosVuelos);
            	 }else
            		 printf("No hay ningun pasajero cargado \n");

                 break;
             case 9:
            	 if(ll_len(listaPasajeros)>0){
        		 	 pedirPath(path);
            		 seGuardoArchivo = controller_saveAsBinary(path,listaPasajeros);
            	 }else
            		 printf("No hay ningun pasajero cargado \n");
                 break;
             case 10:
            	 if(seGuardoArchivo){
            		 printf("Saliendo...\n");
            		 option = 10;
            	 }else{
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

	EstadosVuelos_deleteLista(estadosVuelos);
	TiposPasajeros_deleteLista(tiposPasajeros);
	Passenger_deleteLista(listaPasajeros);
    ll_deleteLinkedList(listaPasajeros);

    return 0;
}










