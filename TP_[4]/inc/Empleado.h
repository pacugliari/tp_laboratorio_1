#include "../inc/LinkedList.h"

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
}eEmpleado;


#endif // EMPLEADO_H_INCLUDED

//OTROS
int mostrarEmpleado (eEmpleado* e);
void mostrarEncabezadoEmpleado();
LinkedList* cargarArchivoEmpleados();

//Constructores
eEmpleado* new_Empleado();
eEmpleado* new_EmpleadoParam(int legajo,char* nombre,char* apellido,char sexo,float sueldo);
eEmpleado* new_EmpleadoString(char* legajo,char* nombre,char* apellido,char* sexo,char* sueldo);

//Setters
int empleadoSetLegajo(eEmpleado* e,int legajo);
int empleadoSetNombre(eEmpleado* e,char* nombre);
int empleadoSetApellido(eEmpleado* e,char* apellido);
int empleadoSetSexo(eEmpleado* e,char sexo);
int empleadoSetSueldo(eEmpleado* e,float sueldo);

//Getters
int empleadoGetLegajo(eEmpleado* e,int* legajo); //CARGA EL CAMPO e.legajo en legajo
int empleadoGetNombre(eEmpleado* e,char* nombre);
int empleadoGetApellido(eEmpleado* e,char* apellido);
int empleadoGetNombreCompleto(eEmpleado* e,char* nombreCompleto);
int empleadoGetSexo(eEmpleado* e,char* sexo);//CARGA EL CHAR, F O M
int empleadoGetSexoString(eEmpleado* e,char* sexo);//CARGA STRING, FEMENINO O MASCULINO
int empleadoGetSueldo(eEmpleado* e,float* sueldo);


//Destructor
void destroy_Empleado(eEmpleado* e);
int destroy_ListaEmpleados(LinkedList* lista);

//Comparadoras
int empleadoComparaNombre(void* a,void* b);
int empleadoComparaSexo(void* a,void* b);
int empleadoComparaLegajo(void* a,void* b);
int empleadoComparaSueldo(void* a,void* b);
