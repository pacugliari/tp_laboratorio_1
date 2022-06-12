#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Controller.h"
#include "Passenger.h"
#include "pedirDatos.h"

int pedirMenuModificar(){
	int respuesta;
	printf("\n1) Nombre \n");
	printf("2) Apellido \n");
	printf("3) Precio \n");
	printf("4) Tipo de pasajero \n");
	printf("5) Codigo de vuelo \n");
	printf("6) Estado de vuelo \n");
	printf("7) Salir \n");
	printf("Ingrese opcion: ");
	scanf("%d",&respuesta);
	fflush(stdin);
	printf("\n");
	return respuesta;
}

int pedirMenuOrdenar(){
	int respuesta;
	printf("\n1) Ordenar por Id \n");
	printf("2) Ordenar por Nombre \n");
	printf("3) Ordenar por Apellido \n");
	printf("4) Ordenar por Precio \n");
	printf("5) Ordenar por Tipo de pasajero \n");
	printf("6) Ordenar por Codigo de vuelo \n");
	printf("7) Ordenar por Estado de vuelo \n");
	printf("8) Salir \n");
	printf("Ingrese opcion: ");
	scanf("%d",&respuesta);
	fflush(stdin);
	return respuesta;
}

int pedirMenuOrdenarTipo(){
	int respuesta;
	printf("0) Ordenar Descendente \n");
	printf("1) Ordenar Ascendente \n");
	printf("2) Salir \n");
	printf("Ingrese opcion: ");
	scanf("%d",&respuesta);
	fflush(stdin);
	return respuesta;
}

char pedirConfirmacion (Passenger pasajero,int tipo,LinkedList* listaTiposPasajeros,LinkedList* listaEstadosVuelos){
	char respuesta = 'n';
	if(listaTiposPasajeros && listaEstadosVuelos){
		printf("\nID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printPassengerData(pasajero,listaTiposPasajeros,listaEstadosVuelos);
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		if(tipo==MODIFICAR){
			printf("Desea modificar el pasajero mostrado? s-n: ");
		}else
			printf("Desea borrar el pasajero mostrado? s-n: ");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta = tolower(respuesta);
		fflush(stdin);
	}
	return respuesta;

}

int esValidoNombreOApellido (char* cadena){
	int todoOk = 1;

	if(cadena){
		char cadenaAux[strlen(cadena)+1];
		strcpy(cadenaAux,cadena);
		strlwr(cadenaAux);
		for(int i=0;i<strlen(cadenaAux);i++){
			if(cadenaAux [i] < 97 || cadenaAux [i] > 122){
				printf("Solo se permite digitos a-z o A-Z para nombre/apellido \n");
				todoOk = 0;
				break;
			}
		}
	}
	return todoOk;
}

void pedirNombre(char nombre[]){
	if(nombre){
		printf("Ingrese el nombre del pasajero: ");
		gets(nombre);
		fflush(stdin);
		while((strlen(nombre) >50  || strlen(nombre)<=1) || !esValidoNombreOApellido(nombre)){
			printf("Ingrese un nombre mas corto/largo: ");
			gets(nombre);
			fflush(stdin);
		}
	}else
		printf("Error en parametro pedirNombre \n");
}

void pedirApellido (char apellido[]){
	if(apellido){
		printf("Ingrese el apellido del pasajero: ");
		gets(apellido);
		fflush(stdin);
		while((strlen(apellido) >50 || strlen(apellido)<=1) || !esValidoNombreOApellido(apellido)){
			printf("Ingrese un apellido mas corto/largo: ");
			gets(apellido);
			fflush(stdin);
		}
	}else
		printf("Error en parametro pedirApellido \n");
}

int esPrecioValido (char *cadena) {
	int longitud = strlen(cadena);
	int i;
	int haEncontradoElPunto = 0;
	int todoOk = 0;
	if(cadena){
		todoOk = 1;
		for (i = 0; i < longitud; i++) {
			if (cadena[i] == '.') {
				if (haEncontradoElPunto) {
					todoOk=  0;
				} else {
					haEncontradoElPunto = 1;
				}
			}
			if (!isdigit(cadena[i]) && cadena[i] != '.')
				todoOk=  0;
		}
			if(!todoOk){
				printf("Solo se permite digitos 0-9 o '.' para el precio \n");
			}
	}
	return todoOk;
}

void pedirPrecio (float* precio){
	if(precio){
		char precioAux[10];
		printf("Ingrese el precio del vuelo $: ");
		gets(precioAux);
		fflush(stdin);
		while((atof(precioAux) < 0 || atof (precioAux)> 1000000) || !esPrecioValido(precioAux)){
			printf("Error en precio, ingrese un precio valido $: ");
			gets(precioAux);
		}
		*precio = atof(precioAux);
	}else
		printf("Error en parametro pedirPrecio \n");
}



void pedirCodigoVuelo(char codigoVuelo[]){
	if(codigoVuelo){
		printf("Ingrese el codigo de vuelo del pasajero: ");
		gets(codigoVuelo);
		fflush(stdin);
		while(strlen(codigoVuelo) >7 || strlen(codigoVuelo) <= 0){
			printf("Ingrese un codigo de vuelo mas corto/largo, hasta 7 caracteres: ");
			gets(codigoVuelo);
			fflush(stdin);
		}
	}else
		printf("Error en parametros de pedirCodigoVuelo \n");
}



int pedirDatosAlta (Passenger* pasajero,LinkedList* listaTiposPasajeros,LinkedList* listaEstadosVuelos){
	int todoOk = 0;

	if(pasajero && listaTiposPasajeros && listaEstadosVuelos){

		pedirNombre(pasajero->nombre);
		pedirApellido(pasajero->apellido);
		pedirPrecio(&pasajero->precio);
		pedirCodigoVuelo(pasajero->codigoVuelo);
		pedirTipoPasajero(listaTiposPasajeros,&pasajero->idTipoPasajero);
		pedirEstadoVuelo(listaEstadosVuelos,&pasajero->idEstadoVuelo);
		todoOk = 1;
	}
	return todoOk;


}

int pedirId(){
	int id;
	printf("Ingrese el ID: ");
	fflush(stdin);
	scanf(" %d",&id);
	fflush(stdin);
	return id;
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

int pedirMenu(){
    int respuesta;

	printf("\t\t\t\t\t\t***Trabajo Practico numero 3***\n");
	printf("\t\t\t\t\t\t  Programacion I- Laboratorio I\n");
	printf("\t\t\t\t\t  Tecnicatura Superior en Programacion UTN-FRA \n");
	printf("Alumno: Pablo Cugliari | Division: 1A \n");
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

