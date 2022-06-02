#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

//FORMATO id,name,lastname,price,flycode,typePassenger,statusFlight

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int r,i=0;
	char var1[50],var3[50],var2[50],var4[50],var5[50],var6[50],var7[50],var8[50];

	if(pFile == NULL && pArrayListPassenger)
	{
	    return -1;
	}
	do
	{
	    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7,var8);
	    if(r==8)
	    {/*
	        arrayPersonas[i].id = atoi(var1);
	        strncpy(arrayPersonas[i].nombre,var2,sizeof(arrayPersonas[i].nombre));
	        strncpy(arrayPersonas[i].apellido,var3,sizeof(arrayPersonas[i].apellido));
	        arrayPersonas[i].edad = atoi(var4);*/
	    	//Passenger* pasajeroNuevo = Passenger_new();

	        i++;
	    }
	    else
	        break;
	}
	while(!feof(pFile) && i< ll_len(pArrayListPassenger));
	fclose(pFile);
	return i;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
