#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include <string.h>


#define ARCH_DIR "TP_[3]/data.csv"
/****************************************************

	Las funciones del LinkedList que deben utilizarse como mínimo son las siguientes:
	LinkedList* ll_newLinkedList(void) -USADA
	void ll_deleteLinkedList(LinkedList* self) ->USADA
	void ll_add(LinkedList* self , void* element) USADA
	void ll_remove(LinkedList* self , int index) -FALTA
	void* ll_get(LinkedList* self , int index) USADA
	int ll_len(LinkedList* self ) USADA

*****************************************************/

int menu();
void limpiarLista(LinkedList* listaPasajeros);

int pedirPath(char* path){
	int todoOk = 0;
	char pathAux [20];
	if(path){
		 path[0]='\0';
		 strcat(path,"TP_[3]/");
		 printf("Ingrese el Path: ");
		 fflush(stdin);
		 gets(pathAux);
		 fflush(stdin);
		 strcat(path,pathAux);
		 todoOk = 1;
	}

	 return todoOk;
}

int main()
{

	//DEBE HABER POR LOMENOS UN ELEMENTO CARGADO PARA SALIR
	//PEDIDO DE DATOS NO PUEDE ESTAR EN LA MISMA QUE PASAJEROS

	setvbuf(stdout, NULL, _IONBF, 0);//AGREGADO PARA EVITAR BUG CONSOLA ECLIPSE
    int option = 0;
    LinkedList* listaPasajeros =  ll_newLinkedList();
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
            	 if(controller_addPassenger(listaPasajeros,&id));
                 break;
             case 4:
            	 controller_editPassenger(listaPasajeros);
                 break;
             case 5:

                 break;
             case 6:
            	 controller_ListPassenger(listaPasajeros);
                 break;
             case 7:

                 break;
             case 8:
            	 if(pedirPath(path))
            		 seGuardoArchivo = controller_saveAsText(path,listaPasajeros);
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

    printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de pasajero\n");
    printf("4. Modificar datos de pasajero\n");
    printf("5. Baja de pasajero\n");
    printf("6. Listar pasajeros\n");
    printf("7. Ordenar pasajeros\n");
    printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
    printf("10. Salir \n\n");

    scanf("%d",&respuesta);
    fflush(stdin);


    return respuesta;

}


