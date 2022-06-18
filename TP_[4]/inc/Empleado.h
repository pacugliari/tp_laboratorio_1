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
/// @fn int mostrarEmpleado(eEmpleado*)
/// @brief muestra la informacion por consola de un empleado
///
/// @param eEmpleado* e, puntero a la estrucutra que contiene los dato a mostrar
/// @return si los parametros son correctos retorna 1 , sino 0
int mostrarEmpleado (eEmpleado* e);

/// @fn void mostrarEncabezadoEmpleado()
/// @brief muestra por consola el encabezado con la informacion de un empleado (ID,NOMBRE,APELLIDO,SEXO,SUELDO)
///
void mostrarEncabezadoEmpleado();

/// @fn LinkedList cargarArchivoEmpleados*()
/// @brief carga desde un archivo de datos (empleados.csv)  de prueba en una LinkedList
///
/// @return retorna NULL si hubo algun error o el puntero a la lista con los empleados cargados
LinkedList* cargarArchivoEmpleados();

//Constructores
/// @fn eEmpleado new_Empleado*()
/// @brief crea en memoria dinamica un nuevo empleado
///
/// @return NULL si hubo error o el puntero al empleado creado
eEmpleado* new_Empleado();

/// @fn eEmpleado new_EmpleadoParam*(int, char*, char*, char, float)
/// @brief crea en memoria dinamica un nuevo empleado con los datos pasados por parametro
///
/// @param int legajo, entero con el legajo o id del empleado
/// @param char* nombre, puntero a cadena que contiene el nombre
/// @param char* apellido, puntero a cadena que contiene el apellido
/// @param char sexo, caracter que contiene el sexo, m -> masculino o f-> femenino
/// @param float sueldo, flotante con el sueldo del empleado
/// @return NULL si hubo error o el puntero al empleado creado
eEmpleado* new_EmpleadoParam(int legajo,char* nombre,char* apellido,char sexo,float sueldo);

/// @fn eEmpleado new_EmpleadoString*(char*, char*, char*, char*, char*)
/// @brief crea en memoria dinamica un nuevo empleado con los datos pasadaos por parametro en formato string
///
/// @param char* legajo, puntero a cadena legajo la cual se castea a entero
/// @param char* nombre, puntero a cadena nombre
/// @param char* apellido, puntero a cadena apellido
/// @param char* sexo, puntero a cadena sexo que se castea a char
/// @param char* sueldo,puntero a cadena sueldo que se castea a float
/// @return
eEmpleado* new_EmpleadoString(char* legajo,char* nombre,char* apellido,char* sexo,char* sueldo);

//Setters
/// @fn int empleadoSetLegajo(eEmpleado*, int)
/// @brief asigno el legajo del parametro en el campo legajo de la estructura del parametro
///
/// @param eEmpleado* e, puntero a estructura eEmpleado al cual se le asigna el legajo
/// @param int legajo, entero con el legajo a guardar en la estructura
/// @return si los parametros son correctos retorna 1 , sino 0
int empleadoSetLegajo(eEmpleado* e,int legajo);

/// @fn int empleadoSetNombre(eEmpleado*, char*)
/// @brief asigna el nombre del parametro en el campo nombre de la estructura del parametro
///
/// @param eEmpleado* e, puntero a estructura eEmpleado al cual se le asigna el nombre
/// @param char* nombre, puntero a cadena con el nombre a guardar en la estructura
/// @return si los parametros son correctos retorna 1 , sino 0
int empleadoSetNombre(eEmpleado* e,char* nombre);

/// @fn int empleadoSetApellido(eEmpleado*, char*)
/// @brief asigna el apellido del parametro en el campo apellido de la estructura del parametro
///
/// @param eEmpleado* e, puntero a estructura eEmpleado al cual se le asigna el apellido
/// @param char* apellido, puntero a cadena con el apellido a guardar en la estructura
/// @return si los parametros son correctos retorna 1 , sino 0
int empleadoSetApellido(eEmpleado* e,char* apellido);

/// @fn int empleadoSetSexo(eEmpleado*, char)
/// @brief asigna el sexo del parametro en el campo sexo de la estructura del parametro
///
/// @param eEmpleado* e, puntero a estructura eEmpleado al cual se le asigna el sexo
/// @param char sexo, caracter con el sexo a guardar en la estructura
/// @return si los parametros son correctos retorna 1 , sino 0
int empleadoSetSexo(eEmpleado* e,char sexo);


/// @fn int empleadoSetSueldo(eEmpleado*, float)
/// @brief asigna el sueldo del parametro en el campo sueldo de la estructura del parametro
///
/// @param eEmpleado* e, puntero a estructura eEmpleado al cual se le asigna el sueldo
/// @param float sueldo, flotante con el sueldo a guardar en la estructura
/// @return si los parametros son correctos retorna 1 , sino 0
int empleadoSetSueldo(eEmpleado* e,float sueldo);

//Getters
/// @fn int empleadoGetLegajo(eEmpleado*, int*)
/// @brief devuelve en el legajo del parametro el campo legajo de la estructura del parametro
///
/// @param eEmpleado* e, puntero a estructura eEmpleado al cual se quiere obtener el legajo
/// @param int legajo, entero con el legajo a devolver de la estructura
/// @return si los parametros son correctos retorna 1 , sino 0
int empleadoGetLegajo(eEmpleado* e,int* legajo); //CARGA EL CAMPO e.legajo en legajo

/// @fn int empleadoGetNombre(eEmpleado*, char*)
/// @brief devuelve en el nombre del parametro el campo nombre de la estructura del parametro
///
/// @param eEmpleado* e, puntero a estructura eEmpleado al cual se le quiere obtener el nombre
/// @param char* nombre, puntero a cadena con el nombre a devolver de la estructura
/// @return si los parametros son correctos retorna 1 , sino 0
int empleadoGetNombre(eEmpleado* e,char* nombre);

/// @fn int empleadoGetApellido(eEmpleado*, char*)
/// @brief devuelve en el apellido del parametro el campo apellido de la estructura del parametro
///
/// @param eEmpleado* e, puntero a estructura eEmpleado al cual se le quiere obtener el apellido
/// @param char* apellido, puntero a cadena con el apellido a devolver de la estructura
/// @return si los parametros son correctos retorna 1 , sino 0
int empleadoGetApellido(eEmpleado* e,char* apellido);

/// @fn int empleadoGetNombreCompleto(eEmpleado*, char*)
/// @brief devuelve en el nombreCompleto del parametro el campo apellido+campo nombre concatenado de la estructura del parametro
///
/// @param eEmpleado* e, puntero a estructura eEmpleado al cual se le quiere obtener el nombreCompleto
/// @param char* nombreCompleto, puntero a cadena con el nombreCompleto a devolver de la estructura
/// @return si los parametros son correctos retorna 1 , sino 0
int empleadoGetNombreCompleto(eEmpleado* e,char* nombreCompleto);

/// @fn int empleadoGetSexo(eEmpleado*, char*)
/// @brief devuelve en el sexo del parametro el campo sexo de la estructura del parametro
///
/// @param eEmpleado* e, puntero a estructura eEmpleado al cual se le quiere obtener el sexo
/// @param char sexo, caracter con el sexo a devolver de la estructura
/// @return si los parametros son correctos retorna 1 , sino 0
int empleadoGetSexo(eEmpleado* e,char* sexo);//CARGA EL CHAR, F O M

/// @fn int empleadoGetSexoString(eEmpleado*, char*)
/// @brief devuelve en el sexo del parametro el campo sexo en formato string de la estructura del parametro
///
/// @param eEmpleado* e, puntero a estructura eEmpleado al cual se le quiere obtener el sexo en formato string
/// @param char* sexo, puntero a cadena con el sexo a devolver de la estructura
/// @return si los parametros son correctos retorna 1 , sino 0
int empleadoGetSexoString(eEmpleado* e,char* sexo);//CARGA STRING, FEMENINO O MASCULINO

/// @fn int empleadoGetSueldo(eEmpleado*, float*)
/// @brief devuelve en el sueldo del parametro el campo sueldo en formato string de la estructura del parametro
///
/// @param eEmpleado* e, puntero a estructura eEmpleado al cual se le quiere obtener el sueldo
/// @param float sueldo, float con el sueldo a devolver de la estructura
/// @return si los parametros son correctos retorna 1 , sino 0
int empleadoGetSueldo(eEmpleado* e,float* sueldo);


//Destructor

/// @fn void destroy_Empleado(eEmpleado*)
/// @brief libera la memoria dinamica del puntero pasado por parametro
///
/// @param eEmpleado* e, puntero a estructura eEmpleado a liberar
void destroy_Empleado(eEmpleado* e);

/// @fn int destroy_ListaEmpleados(LinkedList*)
/// @brief libera de memoria dinamica los empleados cargados en la lista del parametro haciendo free de todos
///
/// @param LinkedList* lista, lista de empleados a liberar su memoria
/// @return si los parametros son correctos devuelve 1, sino 0
int destroy_ListaEmpleados(LinkedList* lista);

//Comparadoras
/// @fn int empleadoComparaNombre(void*, void*)
/// @brief compara 2 nombres  de estructuras eEmpleado
///
/// @param void* a, puntero a void, internamente se castea eEmpleado*
/// @param void* b, puntero a void, internamente se castea eEmpleado*
/// @return si el nombre de a>b retorna 1, si a=b retorna 0 sino -1
int empleadoComparaNombre(void* a,void* b);

/// @fn int empleadoComparaSexo(void*, void*)
/// @brief compara 2 sexos  de estructuras eEmpleado
///
/// @param void* a, puntero a void, internamente se castea eEmpleado*
/// @param void* b, puntero a void, internamente se castea eEmpleado*
/// @return si el sexo de a>b retorna 1, si a=b retorna 0 sino -1
int empleadoComparaSexo(void* a,void* b);

/// @fn int empleadoComparaLegajo(void*, void*)
/// @brief compara 2 legajos  de estructuras eEmpleado
///
/// @param void* a, puntero a void, internamente se castea eEmpleado*
/// @param void* b, puntero a void, internamente se castea eEmpleado*
/// @return si el legajo de a>b retorna 1, si a=b retorna 0 sino -1
int empleadoComparaLegajo(void* a,void* b);

/// @fn int empleadoComparaSueldo(void*, void*)
/// @brief compara 2 sueldos  de estructuras eEmpleado
///
/// @param void* a, puntero a void, internamente se castea eEmpleado*
/// @param void* b, puntero a void, internamente se castea eEmpleado*
/// @return si el sueldo de a>b retorna 1, si a=b retorna 0 sino -1
int empleadoComparaSueldo(void* a,void* b);
