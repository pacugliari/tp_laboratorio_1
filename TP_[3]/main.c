#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir

		Las funciones del LinkedList que deben utilizarse como mínimo son las siguientes:

	LinkedList* ll_newLinkedList(void) -> Crea y retorna un nuevo LinkedList. Es el constructor, ya
	que en él crearemos la struct y daremos valores iniciales a los campos.

	void ll_deleteLinkedList(LinkedList* self) -> Elimina el LinkedList
	void ll_add(LinkedList* self , void* element) ->Agrega un elemento al final de LinkedList..
	void ll_remove(LinkedList* self , int index) ->Elimina un elemento en LinkedList, en el índice
	especificado.
	void* ll_get(LinkedList* self , int index) ->Retorna un puntero al elemento que se encuentra en el
	índice especificado.
	int ll_len(LinkedList* self ) ->Retorna el tamaño del LinkedList.


	             case 1:
            	 //controller_loadFromText("data.csv",listaPasajeros);
            	 for(int i=0;i<10;i++)
            		 ll_add(listaPasajeros,i*i);
            	 printf("%d \n",ll_len(listaPasajeros));

                 break;
             case 2:
            	 while(ll_len(listaPasajeros) > cursor){
            		 printf("Index: %d - Dato: %d \n",cursor,ll_get(listaPasajeros,cursor));
            		 cursor++;
            	 }
*****************************************************/

int menu();

int main()
{

	//ID INICIAL ES 1
	//DEBE HABER POR LOMENOS UN ELEMENTO CARGADO PARA SALIR
	//PEDIDO DE DATOS NO PUEDE ESTAR EN LA MISMA QUE PASAJEROS

	setvbuf(stdout, NULL, _IONBF, 0);//AGREGADO PARA EVITAR BUG CONSOLA ECLIPSE
    int option = 0;

    LinkedList* listaPasajeros =  ll_newLinkedList();
    //int cursor = 0;
    do{
    	//cursor=0;
         switch(option=menu()){
             case 1:
            	 //controller_loadFromText("data.csv",listaPasajeros);

                 break;
             case 2:

                 break;
             case 3:

                 break;
             case 4:

                 break;
             case 5:

                 break;
             case 6:

                 break;
             case 7:

                 break;
             case 8:

                 break;
             case 9:

                 break;
             case 10:
            	 option = 10;
                 break;
             default:
                 system("cls");
                 printf("Opcion de menu incorrecta \n\n");
             break;
         }

         system("pause");
         system("cls");
     }while (option != 10 );

    ll_deleteLinkedList(listaPasajeros);

    return 0;
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

/*
 *
 APERTURA ARCHIVO

FILE *parch;
if((parch=fopen("banco.dat","rb"))==NULL)
{
printf("\nEl archivo no puede ser abierto");
exit (1);
}
fclose(parch);

APERTURA EN MODO W
void main (void)
{
FILE *parch;
//Se abre en modo lectura
if((parch=fopen("banco.dat","rb"))==NULL)
{
//Si el modo anterior dio error el archivo
if((parch=fopen("banco.dat","wb"))==NULL)
{
printf("\nEl archivo no puede ser abierto");
exit (1);
}
//no existe, por lo tanto se crea
fclose(parch);
}
}


//LECTURA
struct a{
char nombre[10];
int edad;
};
void main (void)
{
FILE *bin;
struct a pers;
int cant;
if ((bin=fopen("bin.dat","rb"))==NULL)
{
printf("No se pudo abrir el archivo");
exit(1);
}
while(!feof(bin))
{
cant=fread(&pers,sizeof(pers),1,bin);
if(cant!=1)
{
if(feof(bin))
break;
else
{
error("No leyo el ultimo registro");
break;
}
}
printf("\n%s\t%d",pers.nombre,pers.edad);
}
fclose(bin);
getch();
}



 * */

