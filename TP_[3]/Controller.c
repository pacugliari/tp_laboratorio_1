#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "tipoPasajero.h"
#include "estadoVuelo.h"
#include "pedirDatos.h"
#include "Controller.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPassenger,int* pId,LinkedList* tiposPasajeros,LinkedList* estadosVuelos)
{
	int todoOk =0;
	int contador=0;
	char confirmacion = 's';
	FILE* arch = fopen(path,"r");

	if(pArrayListPassenger && tiposPasajeros && estadosVuelos){
		if(arch == NULL){
			printf("No se pudo abrir el archivo %s \n",path);

		}else{
			if(ll_len(pArrayListPassenger) > 0){
				printf("Hay pasajeros cargados, desea sobrescribirlos ? s-n \n");
				fflush(stdin);
				scanf("%c",&confirmacion);
				fflush(stdin);
				confirmacion = tolower(confirmacion);
			}
			if(confirmacion == 's'){
				Passenger_deleteLista(pArrayListPassenger);
				contador = parser_PassengerFromText(arch,pArrayListPassenger,pId,tiposPasajeros,estadosVuelos);
				printf("Cantidad de pasajeros cargados desde el archivo de texto: %s es: %d \n",path,contador);
				todoOk=1;
			}else
				printf("Se canselo la carga de datos desde el archivo de texto \n");

		}
	}
	fclose(arch);
    return todoOk;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger,int* pId)
{
	int todoOk =0;
	int contador=0;
	FILE* arch = fopen(path,"rb");
	char confirmacion = 's';

	if(pArrayListPassenger){
		if(arch == NULL){
			printf("No se pudo abrir el archivo %s \n",path);

		}else{
			if(ll_len(pArrayListPassenger) > 0){
				printf("Hay pasajeros cargados, desea sobrescribirlos ? s-n \n");
				fflush(stdin);
				scanf("%c",&confirmacion);
				fflush(stdin);
				confirmacion = tolower(confirmacion);
			}
			if(confirmacion == 's'){
				Passenger_deleteLista(pArrayListPassenger);
				contador = parser_PassengerFromBinary(arch,pArrayListPassenger,pId);
				printf("Cantidad de pasajeros cargados desde el archivo binario: %s es: %d \n",path,contador);
				todoOk=1;
			}else
				printf("Se canselo la carga de datos desde el archivo binario \n");

		}
	}
	fclose(arch);
    return todoOk;
}


int controller_addPassenger(LinkedList* pArrayListPassenger,int* pId,LinkedList* tiposPasajeros,LinkedList* estadosVuelos)
{
	int todoOk =0;
    Passenger pasajeroAux;

	if(pArrayListPassenger){
		pedirDatosAlta (&pasajeroAux,tiposPasajeros,estadosVuelos);
		pasajeroAux.id = (*pId);

		Passenger* nuevoPasajero = Passenger_newPassenger(pasajeroAux);
		if(nuevoPasajero){
			ll_add(pArrayListPassenger,nuevoPasajero);
			(*pId)++;
			todoOk = 1;
			printf("Pasajero dado de alta de manera exitosa \n");
		}else
			printf("Error en en alta del pasajero \n");
	}else
		printf("Error en los parametros de controller_addPassenger \n");

    return todoOk;
}

int controller_editPassenger(LinkedList* pArrayListPassenger,LinkedList* tiposPasajeros,LinkedList* estadosVuelos)
{
    int todoOk = 0;
    int id;
    char respuesta = 'n';
    int respuestaMenu;
    int indice;
    Passenger* pasajeroActual;
    Passenger aux;

    if(pArrayListPassenger){
    	if(ll_len(pArrayListPassenger) > 0){
    		id = pedirId();
			buscarPasajeroPorId(pArrayListPassenger,&indice,id);
			if(indice != -1){
				pasajeroActual = (Passenger*)ll_get(pArrayListPassenger,indice);
				respuesta = pedirConfirmacion (*pasajeroActual,MODIFICAR,tiposPasajeros,estadosVuelos);
				if(respuesta == 's'){
					do{
						switch(respuestaMenu = pedirMenuModificar()){
							case 1:
								pedirNombre(aux.nombre);
								Passenger_setNombre(pasajeroActual,aux.nombre);
								printf("Se modifico el nombre de manera exitosa \n");
							break;
							case 2:
								pedirApellido(aux.apellido);
								Passenger_setApellido(pasajeroActual,aux.apellido);
								printf("Se modifico el apellido de manera exitosa \n");
							break;
							case 3:
								pedirPrecio(&aux.precio);
								Passenger_setPrecio(pasajeroActual,aux.precio);
								printf("Se modifico el precio de manera exitosa \n");
							break;
							case 4:
								pedirTipoPasajero(tiposPasajeros,&aux.idTipoPasajero);
								Passenger_setTipoPasajero(pasajeroActual,aux.idTipoPasajero);
								printf("Se modifico el tipo de pasajero de manera exitosa \n");
							break;
							case 5:
								pedirCodigoVuelo(aux.codigoVuelo);
								Passenger_setCodigoVuelo(pasajeroActual,aux.codigoVuelo);
								printf("Se modifico el codigo de vuelo de manera exitosa \n");
							break;
							case 6:
								pedirEstadoVuelo(estadosVuelos,&aux.idEstadoVuelo);
								Passenger_setStatusFlight(pasajeroActual,aux.idEstadoVuelo);
								printf("Se modifico el estado de vuelo de manera exitosa \n");
							break;
						}
					}while(respuestaMenu != 7);
					todoOk = 1;
				}else
					printf("Modificacion de pasajero canselada \n");
			}else
				printf("ID no encontrada \n");
    	}else
    		printf("No hay pasajeros cargados \n");
    }else
    	printf("Error en los parametro de modificar pasajero \n");

    return todoOk;
}


int controller_removePassenger(LinkedList* pArrayListPassenger,LinkedList* tiposPasajeros,LinkedList* estadosVuelos)
{
    int todoOk = 0;
    int id;
    char respuesta = 'n';
    int indice;
    Passenger* pasajeroActual;

    if(pArrayListPassenger){
    	if(ll_len(pArrayListPassenger) >0 ){
    		id = pedirId();
			buscarPasajeroPorId(pArrayListPassenger,&indice,id);
			if(indice != -1){
				pasajeroActual = (Passenger*)ll_get(pArrayListPassenger,indice);
				respuesta = pedirConfirmacion (*pasajeroActual,BAJA,tiposPasajeros,estadosVuelos);
				if(respuesta == 's'){
					ll_remove(pArrayListPassenger,indice);
					printf("Pasajero dado de baja de manera exitosa \n");
					todoOk = 1;
				}else
					printf("Baja de pasajero canselada \n");
			}else
				printf("ID no encontrada \n");
    	}else
    		printf("No hay pasajeros cargados \n");
    }else
    	printf("Error en los parametro de baja pasajero \n");

    return todoOk;
}


int controller_ListPassenger(LinkedList* pArrayListPassenger,LinkedList* tiposPasajeros,LinkedList* estadosVuelos)
{
    int todoOk = 0;
    Passenger* pasajeroActual;


    if(pArrayListPassenger){
    	if(ll_len(pArrayListPassenger) >  0){
    		printf("-------------------------------------------------------------------------------------------------------------------------------"
					"------------------------\n");
			printf("\t\t\t\t\t\t\t***LISTA DE PASAJEROS***\n");
			printf("-------------------------------------------------------------------------------------------------------------------------------"
					"------------------------\n");
			printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
			printf("-------------------------------------------------------------------------------------------------------------------------------"
					"------------------------\n");
			 for(int i=0;i<ll_len(pArrayListPassenger);i++){
				 pasajeroActual = ll_get(pArrayListPassenger,i);
				 printPassengerData (*pasajeroActual,tiposPasajeros,estadosVuelos);
			 }
			printf("-------------------------------------------------------------------------------------------------------------------------------"
					"------------------------\n");
			printf("Tamanio: %d \n",ll_len(pArrayListPassenger) );
			todoOk = 1;
    	}else
    		printf("No hay pasajeros cargados \n");
    }
    return todoOk;
}


int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int tipo;
	int order;
	if(pArrayListPassenger){
		if(ll_len(pArrayListPassenger) > 0 ){
			tipo = pedirMenuOrdenar();
			if(tipo >=1 && tipo<=7){
				order = pedirMenuOrdenarTipo();
				if(order == 1 || order == 0){
					printf("Ordenando la lista...\n");
					switch(tipo){
						case 1:
							ll_sort(pArrayListPassenger,pasajeroComparaId,order);
						break;
						case 2:
							ll_sort(pArrayListPassenger,pasajeroComparaNombre,order);
						break;
						case 3:
							ll_sort(pArrayListPassenger,pasajeroComparaApellido,order);
						break;
						case 4:
							ll_sort(pArrayListPassenger,pasajeroComparaPrecio,order);
						break;
						case 5:
							ll_sort(pArrayListPassenger,pasajeroComparaTipoPasajero,order);
						break;
						case 6:
							ll_sort(pArrayListPassenger,pasajeroComparaCodigoVuelo,order);
						break;
						case 7:
							ll_sort(pArrayListPassenger,pasajeroComparaEstadoVuelo,order);
						break;

					}
					todoOk=1;
				}
			}
			if(todoOk)
				printf("Se realizo el ordenamiento de forma correcta \n");
			else
				printf("Ordenamiento canselado \n");
		}else
			printf("No hay pasajeros cargados \n");
	}else
		printf("Error en los parametros de controller_sortPassenger \n");
	return todoOk;
}




int controller_saveAsText(char* path , LinkedList* pArrayListPassenger,LinkedList* tiposPasajeros,LinkedList* estadosVuelos)
{
	int todoOk = 0;
	char confirmacion = 's';
	Passenger* pasajeroActual;
	char descripcionTipo[20];
	char descripcionEstado[20];
	FILE* f = fopen(path,"r");
	if(pArrayListPassenger){
		if(ll_len(pArrayListPassenger) > 0){
			if(f != NULL){
				printf("El archivo ya existe, desea sobrescribirlo ? s-n: ");
				fflush(stdin);
				scanf("%c",&confirmacion);
				fflush(stdin);
				confirmacion = tolower(confirmacion);
			}
			if(confirmacion == 's'){
				fclose(f);
				FILE* f = fopen(path,"w");
				fprintf(f,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
				for(int i=0;i<ll_len(pArrayListPassenger);i++){
					 pasajeroActual = ll_get(pArrayListPassenger,i);
					 cargarDescripcionEstadoVuelo(estadosVuelos,pasajeroActual->idEstadoVuelo,descripcionEstado);
					 cargarDescripcionTipoPasajero(tiposPasajeros,pasajeroActual->idTipoPasajero,descripcionTipo);
					 fprintf(f,"%d,%s,%s,%f,%s,%s,%s\n",pasajeroActual->id,pasajeroActual->nombre,pasajeroActual->apellido,pasajeroActual->precio,
							 pasajeroActual->codigoVuelo,descripcionTipo,descripcionEstado);
				}
				todoOk = 1;
				printf("Pasajeros guardados de manera exitosa en el archivo de texto %s \n",path);
			}else
				printf("Se canselo el guardado en archivo texto \n");
		}else
			printf("No hay pasajeros cargados \n");
	}else
		printf("Error en los parametros de controller_saveAsText \n");

	fclose(f);
    return todoOk;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	char confirmacion = 's';
	Passenger* pasajeroActual;
	FILE* f = fopen(path,"rb");

	if(pArrayListPassenger){
		if(ll_len(pArrayListPassenger) > 0){
			if(f != NULL){
				printf("El archivo ya existe, desea sobrescribirlo ? s-n: ");
				fflush(stdin);
				scanf("%c",&confirmacion);
				fflush(stdin);
				confirmacion = tolower(confirmacion);
			}
			if(confirmacion == 's'){
				fclose(f);
				f = fopen(path,"wb");
				for(int i=0;i<ll_len(pArrayListPassenger);i++){
					 pasajeroActual = (Passenger*)ll_get(pArrayListPassenger,i);
					 fwrite(pasajeroActual,sizeof(Passenger),1,f);
				}
				todoOk = 1;
				printf("Pasajeros guardados de manera exitosa en el archivo binario %s \n",path);
			}else
				printf("Se canselo el guardado en archivo binario \n");
		}else
			printf("No hay pasajeros cargados \n");
	}else
		printf("Error en los parametros de controller_saveAsBinary \n");
	fclose(f);
    return todoOk;
}



