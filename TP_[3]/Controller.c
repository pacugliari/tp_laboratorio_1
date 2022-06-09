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

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger,int* pId)
{
	int todoOk =0;
	int contador=0;
	char confirmacion = 's';
	FILE* arch = fopen(path,"r");

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
				ll_clear(pArrayListPassenger);
				contador = parser_PassengerFromText(arch,pArrayListPassenger,pId);
				printf("Cantidad de pasajeros cargados desde el archivo de texto: %s es: %d \n",path,contador);
				todoOk=1;
			}

		}
	}
	fclose(arch);
    return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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
				ll_clear(pArrayListPassenger);
				contador = parser_PassengerFromBinary(arch,pArrayListPassenger,pId);
				printf("Cantidad de pasajeros cargados desde el archivo binario: %s es: %d \n",path,contador);
				todoOk=1;
			}

		}
	}
	fclose(arch);
    return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,int* pId)
{
	int todoOk =0;
    eTipoPasajero tiposP [TAMTP];
    eEstadoVuelo estadosV [TAMEV];

    hardcodearTiposPasajeros(tiposP,TAMTP);
    hardcodearEstadosVuelo(estadosV,TAMEV);

	if(pArrayListPassenger){
		Passenger* nuevoPasajero = Passenger_new();
		pedirDatosAlta (nuevoPasajero,tiposP,TAMTP,estadosV,TAMEV);
		nuevoPasajero->isEmpty = 0;
		nuevoPasajero->id = (*pId);
		ll_add(pArrayListPassenger,nuevoPasajero);
		(*pId)++;
		todoOk = 1;
	}
    return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    int id;
    char respuesta = 'n';
    int respuestaMenu;
    Passenger* pasajeroActual;
    eTipoPasajero tiposP [TAMTP];
    eEstadoVuelo estadosV [TAMEV];

    hardcodearTiposPasajeros(tiposP,TAMTP);
    hardcodearEstadosVuelo(estadosV,TAMEV);

    if(pArrayListPassenger){
    	id = pedirId();
    	for(int i=0;i<ll_len(pArrayListPassenger);i++){
    		pasajeroActual = (Passenger*)ll_get(pArrayListPassenger,i);
    		if(pasajeroActual->id == id){
    		respuesta = pedirConfirmacion (*pasajeroActual,2,tiposP,TAMTP,estadosV,TAMEV);
				if(respuesta == 's'){
					do{
						switch(respuestaMenu = pedirMenuModificar()){
							case 1:
								pedirNombre(pasajeroActual->nombre);
								printf("Se modifico el nombre de manera exitosa \n");
							break;
							case 2:
								pedirApellido(pasajeroActual->apellido);
								printf("Se modifico el apellido de manera exitosa \n");
							break;
							case 3:
								pedirPrecio(&pasajeroActual->precio);
								printf("Se modifico el precio de manera exitosa \n");
							break;
							case 4:
								pedirTipoPasajero(tiposP,TAMTP,&pasajeroActual->idTipoPasajero);
								printf("Se modifico el tipo de pasajero de manera exitosa \n");
							break;
							case 5:
								pedirCodigoVuelo(pasajeroActual->codigoVuelo);
								printf("Se modifico el codigo de vuelo de manera exitosa \n");
							break;
							case 6:
								pedirEstadoVuelo(estadosV,TAMEV,&pasajeroActual->idEstadoVuelo);
								printf("Se modifico el estado de vuelo de manera exitosa \n");
							break;
						}
					}while(respuestaMenu != 7);
				}else
					printf("Modificacion de pasajero canselada \n");

				printf("Modificacion de pasajero con exito \n");
				todoOk = 1;
				break;
    		}
    	}

    }else
    	printf("Error en los parametro de modificar pasajero \n");
    return todoOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    Passenger* pasajeroActual;

    eTipoPasajero tiposP [TAMTP];
    eEstadoVuelo estadosV [TAMEV];

    hardcodearTiposPasajeros(tiposP,TAMTP);
    hardcodearEstadosVuelo(estadosV,TAMEV);

    if(pArrayListPassenger){
		printf("\t\t\t\t\t\t\t***LISTA DE PASAJEROS***\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		 for(int i=0;i<ll_len(pArrayListPassenger);i++){
			 pasajeroActual = ll_get(pArrayListPassenger,i);
			 if(!pasajeroActual->isEmpty)
				 printPassengerData (*pasajeroActual,tiposP,TAMTP,estadosV,TAMEV);
		 }
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printf("Tamanio: %d \n",ll_len(pArrayListPassenger) );
    	todoOk = 1;
    }
    return todoOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */


int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{

    eTipoPasajero tiposP [TAMTP];
    eEstadoVuelo estadosV [TAMEV];

    hardcodearTiposPasajeros(tiposP,TAMTP);
    hardcodearEstadosVuelo(estadosV,TAMEV);

	int todoOk = 0;
	char confirmacion = 's';
	Passenger* pasajeroActual;
	char descripcionTipo[20];
	char descripcionEstado[20];
	FILE* f = fopen(path,"r");
	if(pArrayListPassenger ){
		if(f != NULL){
			printf("El archivo ya existe, desea sobrescribirlo ? s-n");
			fflush(stdin);
			scanf("%c",&confirmacion);
			fflush(stdin);
			confirmacion = tolower(confirmacion);
		}
		if(confirmacion == 's'){
			FILE* f = fopen(path,"w");
			fprintf(f,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
			for(int i=0;i<ll_len(pArrayListPassenger);i++){
				 pasajeroActual = ll_get(pArrayListPassenger,i);
				 cargarDescripcionEstadoVuelo(estadosV,3,pasajeroActual->idEstadoVuelo,descripcionEstado);
				 cargarDescripcionTipoPasajero(tiposP,3,pasajeroActual->idTipoPasajero,descripcionTipo);
				 fprintf(f,"%d,%s,%s,%f,%s,%s,%s\n",pasajeroActual->id,pasajeroActual->nombre,pasajeroActual->apellido,pasajeroActual->precio,
						 pasajeroActual->codigoVuelo,descripcionTipo,descripcionEstado);
			}
			todoOk = 1;
			printf("Pasajeros guardados de manera exitosa en el archivo de texto %s \n",path);
		}
	}
	fclose(f);
    return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	char confirmacion = 's';
	Passenger* pasajeroActual;
	FILE* f = fopen(path,"rb");

	if(pArrayListPassenger ){
		if(f != NULL){
			printf("El archivo ya existe, desea sobrescribirlo ? s-n");
			fflush(stdin);
			scanf("%c",&confirmacion);
			fflush(stdin);
			confirmacion = tolower(confirmacion);
		}
		if(confirmacion == 's'){
			f = fopen(path,"wb");
			for(int i=0;i<ll_len(pArrayListPassenger);i++){
				 pasajeroActual = (Passenger*)ll_get(pArrayListPassenger,i);
				 fwrite(pasajeroActual,sizeof(Passenger),1,f);
			}
			todoOk = 1;
			printf("Pasajeros guardados de manera exitosa en el archivo binario %s \n",path);
		}
	}
	fclose(f);
    return todoOk;
}

