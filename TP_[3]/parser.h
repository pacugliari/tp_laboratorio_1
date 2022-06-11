/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*, puntero a archivo con los datos a parsear
 * \param pArrayListPassenger LinkedList*, lista donde se guardar los datos parseados
 * \param int* pId, puntero a id para ir autoincrementandola
 * \param LinkedList* tiposPasajeros, lista de tipos de pasajeros
 * \param LinkedList* estadosVuelos, lista de estados de vuelos
 * \return int , devuelve la cantidad de datos parseados
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger,int* pId,LinkedList* tiposPasajeros,LinkedList* estadosVuelos);

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE*, puntero a archivo con los datos a parsear
 * \param pArrayListPassenger LinkedList*, lista donde se guardar los datos parseados
 * \param int* pId, puntero a id para ir autoincrementandola
 * \return int , devuelve la cantidad de datos parseados
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger,int* pId);

/// @fn int esCadenaValida(char*)
/// @brief valida si una cadena tiene caracteres validos imprimibles en C
///
/// @param char* cadena, cadena a validar
/// @return si es caracter valido (a..z,A...Z,-, ) devuelve 1 , sino 0 (ascentos, o simbolos no imprimibles)
int esCadenaValida(char* cadena);
