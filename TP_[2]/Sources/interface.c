#include "../Headers/interface.h"

int mostrarMenu(){
	int respuesta;

	do{
		printf("1) ALTA \n");
		printf("2) MODIFICAR \n");
		printf("3) BAJA \n");
		printf("4) INFORMAR \n");
		printf("5) SALIR \n");
		scanf("%d",&respuesta);
		fflush(stdin);

		if(respuesta <1 || respuesta > 9){
			printf("Error en la opcion del menu, vuelva a ingresar \n");
		}
	}while (respuesta <1 || respuesta > 9);

	return respuesta;

}

void mostrarPrecios(float* resultados){
	printf("Total de los pasajes: %.2f \n",resultados[0]);
	printf("Promedio de los pasajes: %.2f \n",resultados[1]);
	printf("Cantidad de pasajeros que superan el precio promedio: %d \n",(int)resultados[2]);
}

void mostrarSubMenu(Passenger* list){
	int respuesta;
	float preciosCalculados[3];//0-TOTAL,1-PROMEDIO,2-CONTADOR QUE SUPERAN EL PROMEDIO

	do{
		printf("1) Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero \n");
		printf("2) Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio. \n");
		printf("3) Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");
		scanf("%d",&respuesta);
		fflush(stdin);

		if(respuesta <1 || respuesta > 3){
			printf("Error en la opcion del menu, vuelva a ingresar \n");
		}
	}while (respuesta <1 || respuesta > 3);

	switch(respuesta){
		case 1:
			sortPassengers(list,CANT_PASAJEROS,ASC);
			printPassenger(list,CANT_PASAJEROS);
		break;
		case 2:
			if(calculatePricesPassengers(list,CANT_PASAJEROS,preciosCalculados)){
				mostrarPrecios(preciosCalculados);
			}
		break;
		case 3:
			sortPassengersByCode(list,CANT_PASAJEROS,ASC);
			printPassengerActive(list,CANT_PASAJEROS);
		break;
	}

}

void pedirDatosPasajero(Passenger* pasajero,int tipo){
	//char nombre[51];
	//char apellido[51];
	//float precio;
	//char flyCode[10];
	//int estadoVuelo;
	//int tipoPasajero;

	if(tipo){
		//PARA ALTA

	}else{
		//PARA MODIFICAR
	}


}

int pedirId(){
	int id;
	printf("Ingrese el ID \n");
	fflush(stdin);
	scanf(" %d",&id);
	fflush(stdin);
	return id;
}

void ejecutarMenu(Passenger* arrayPassengers,int* cantidadPasajerosCargados){
	int respuestaMenu;
	int idBusqueda;

	Passenger pasajero;

	do{
		respuestaMenu = mostrarMenu();
		switch(respuestaMenu){
			case 1:
				//ALTA
				pedirDatosPasajero(&pasajero,ALTA);
				if(!addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),pasajero.name,pasajero.lastName,
						pasajero.price,pasajero.typePassenger,pasajero.statusFlight,pasajero.flycode))
					cantidadPasajerosCargados++;
			break;
			case 2:
				//MODIFICAR
				idBusqueda = pedirId();
				pedirDatosPasajero(&pasajero,MODIFICAR);
				modifyPassenger(arrayPassengers,CANT_PASAJEROS,idBusqueda,pasajero.name,pasajero.lastName,pasajero.price,pasajero.typePassenger,
						pasajero.flycode);
			break;
			case 3:
				//BAJA
				idBusqueda = pedirId();
				if(-1 != findPassengerById(arrayPassengers,CANT_PASAJEROS,idBusqueda)){
					if(!removePassenger(arrayPassengers,CANT_PASAJEROS,idBusqueda)){
						printf("Pasajero dado de BAJA de manera exitosa \n");
					}

				}
			break;
			case 4:
				mostrarSubMenu(arrayPassengers);
			break;
			case 5:
				printf("Saliendo \n");
			break;
			case 6:
				sortPassengers(arrayPassengers,CANT_PASAJEROS,ASC);
			break;
			case 7:
				sortPassengers(arrayPassengers,CANT_PASAJEROS,DESC);
			break;
			case 8:
				sortPassengersByCode(arrayPassengers,CANT_PASAJEROS,ASC);
			break;
			case 9:
				sortPassengersByCode(arrayPassengers,CANT_PASAJEROS,DESC);
			break;
		}
	}while(respuestaMenu != 5);
}


void ejecutarPrograma(){

	Passenger arrayPassengers [CANT_PASAJEROS] ={};
	int cantidadPasajerosCargados = 0;

	if(!initPassengers(arrayPassengers,CANT_PASAJEROS)){

			//HARDCODEO DATOS DE PRUEBA
			addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Pablo","Cugliari",100,1,1,"PA1006");
			addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Beto","Cugliari",200,2,0,"PA1006");
			addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Mirta","Mena",300,3,1,"PA1004");
			addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Antonio","Mena",400,4,0,"PA1003");
			addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Donna","Benfenati",500,5,1,"PA1002");
			addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Gian","Benfenati",600,6,0,"PA1001");
			cantidadPasajerosCargados = 6;
			//FIN HARDCODEO DATOS

			ejecutarMenu(arrayPassengers,&cantidadPasajerosCargados);

	}else{
		printf("Error al iniciar el programa \n");
	}


}
