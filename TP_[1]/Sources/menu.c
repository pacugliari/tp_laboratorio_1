/*
 * menu.c
 *
 *  Created on: 1 abr. 2022
 *      Author: PACugliari
 */


#include "../Headers/menu.h"


int mostrarMenu(void){
	int respuesta;

	do{
		printf(" 1. Ingresar Kilometros: ( km=x) \n");
		printf(" 2. Ingresar Precio de Vuelos: (Aerolineas=y, Latam=z) \n");
		printf(" 3. Calcular todos los costos \n");
		printf(" 4. Informar Resultados \n");
		printf(" 5. Carga forzada de datos \n");
		printf(" 6. Salir \n");

		scanf("%d",&respuesta);
		fflush(stdin);
		system("cls");
	}while(respuesta < 1 || respuesta > 6);


	return respuesta;
}

void mostrarResultados(float* resultados,float kilometros,float precioAerolineas, float precioLatam,int esCorrectoCalculo){
	if(esCorrectoCalculo){
		printf("KMs Ingresados: %.2f km \n",kilometros);
		printf(" \n");
		printf("Precio Aerolineas: $%.2f \n",precioAerolineas);
		printf("a) Precio con tarjeta de debito: $%.2f \n",resultados[0]);
		printf("b) Precio con tarjeta de credito: $%.2f \n",resultados[1]);
		printf("c) Precio pagando con bitcoin : $%f \n",resultados[2]);
		printf("d) Precio unitario: $%.2f \n",resultados[3]);
		printf(" \n");
		printf("Precio Latam: $%.2f \n",precioLatam);
		printf("a) Precio con tarjeta de debito: $%.2f \n",resultados[4]);
		printf("b) Precio con tarjeta de credito: $%.2f \n",resultados[5]);
		printf("c) Precio pagando con bitcoin : $%f \n",resultados[6]);
		printf("d) Precio unitario: $%.2f \n",resultados[7]);
		printf(" \n");
		printf("La diferencia de precio es : $%.2f \n",resultados[8]);
		printf(" \n");
	}else{
		printf("No se calcularon los costos \n\n");
	}
}

float obtenerKilometros(void){
	float kilometrosIngresados=0;

	do{
		printf("Ingrese los kilometros \n");
		scanf("%f",&kilometrosIngresados);
		fflush(stdin);

		if(kilometrosIngresados <=0){
			printf("Error en kilometros ingresados, ingrese un valor mayor que cero \n");
		}

	}while(kilometrosIngresados <=0);

	system("cls");
	printf("Kilomtros cargados correctamente \n\n");
	return kilometrosIngresados;
}

char mostrarOpcionesVuelos(void){
	char vueloElegido;
	printf("Ingrese el vuelo a elegir, Aerolineas=y, Latam=z \n");
	do{
		fflush(stdin);
		scanf("%c",&vueloElegido);
		vueloElegido = tolower(vueloElegido);
		fflush(stdin);

		if(vueloElegido != 'y' && vueloElegido != 'z'){
			printf("Ingreso una opcion invalida, Aerolineas=y, Latam=z \n");
		}
	}while(vueloElegido != 'y' && vueloElegido != 'z');

	return vueloElegido;
}

/// @fn float obtenerPrecio(void)
/// @brief pide el ingreso del precio del vuelo validandolo
///
/// @return float, retorna el precio ingresado por el usuario ya validado
float obtenerPrecio (void){
	float precio;
	printf("Ingrese el precio \n");
	do{
		scanf("%f",&precio);
		if(precio <= 0){
			printf("Error en precio ingresado, ingrese un precio mayor a cero \n");
		}
	}while(precio <= 0);

	fflush(stdin);
	system("cls");

	return precio;
}

void calcularPrecios(char opcionesVuelos,float* precioLatam,float* precioAerolineas){
	if(opcionesVuelos == 'y'){
		*precioAerolineas = obtenerPrecio();
		printf("Precio de Aerolineas cargado correctamente \n\n");
	}else{
		*precioLatam = obtenerPrecio();
		printf("Precio de Latam cargado correctamente \n\n");
	}
}

void mostrarMensajeFinPrograma(void){
	printf("Gracias por usar el programa \n");
}

void mostrarMensajeErrorMenu(void){
	printf("Ingreso una opcion invalida, vuelva a ingresar \n");
}
