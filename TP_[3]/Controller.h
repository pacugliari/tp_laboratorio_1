#include "Passenger.h"
#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger,int* pId);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger,int* pId);
int controller_addPassenger(LinkedList* pArrayListPassenger,int* pId,LinkedList* tiposPasajeros,LinkedList* estadosVuelos);
int controller_editPassenger(LinkedList* pArrayListPassenger,LinkedList* tiposPasajeros,LinkedList* estadosVuelos);
int controller_removePassenger(LinkedList* pArrayListPassenger,LinkedList* tiposPasajeros,LinkedList* estadosVuelos);
int controller_ListPassenger(LinkedList* pArrayListPassenger,LinkedList* tiposPasajeros,LinkedList* estadosVuelos);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger,LinkedList* tiposPasajeros,LinkedList* estadosVuelos);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
void printPassengerData (Passenger p,LinkedList* listaTiposPasajeros,LinkedList* listaEstadosVuelos);


