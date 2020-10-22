/*
 * fecha.h
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#ifndef FECHA_H_
#define FECHA_H_


typedef struct
{
	int id;
	int dia;
	int mes;
	int anio;
	int isEmpty;
}eFecha;

/**
 * \brief Pide al usuario que ingrese una fecha y la valida
 *  \param Array de tipo eFecha
 *  \param Tamanio maximo de la lista
 *  \param Mensaje a mostrar en caso de Error
 *  \param Cantidad de reintentos a ingresar una fecha
 *  \param Contador de fechas
 *  \return Retorna 0 si se pudo ingresar la fecha con exito, -1 si no
 */
int getFecha(eFecha *pArray, int limite, char* mensajeError, int reintentos, int *contFecha);

/*
 * \brief Realiza la carga de una fecha nuevo al array de eFecha.
 * \param Array de tipo eFecha
 * \param Tamanio maximo de la lista
 * \param Dia a cargar en el array
 * \param Mes a cargar en el array
 * \param Anio a cargar en el array
 * \param Contador de fechas
 * \return Retorna 0 si se agrega con exito la fecha, -1 si no.
 */
int addFecha(eFecha *pArray, int limite, int dia, int mes, int anio, int *contFecha);

/**
 * \brief Realiza la baja de un elemento del array de eFecha
 *  \param Array de tipo eFecha
 *  \param Tamanio maximo de la lista
 *  \param ID del elemento que se desea dar de baja
 *  \param Contador de fechas
 *  \return Retorna 0 si se da de baja el elemento con exito, -1 si no.
 */
int removeFecha(eFecha *pArray, int limite, int id, int *contFecha);

/**
 * \brief Realiza la busqueda de una fecha por ID
 *  \param Array de tipo eFecha
 *  \param Tamanio maximo de la lista
 * 	\param El ID a buscar en el array de eFecha
 *  \return Retorna la posicion donde se encuentra ese ID, -1 si no lo encuentra
 */
int findFechaById(eFecha *pArray, int limite, int id);

/**
 * \brief Inicializa el array de eFecha colocando isEmpty = 0.
 *  \param Array de tipo eFecha
 *  \param Tamanio maximo de la lista
 *  \return Retorna 0 si se inicializa el array con exito, -1 si no.
 */
int initFecha(eFecha *pArray, int limite);

/**
 * \brief Realiza la busqueda de la primera ubicacion vacia en el array de eFecha y devuelve la posicion de indice
 *  \param Array de tipo eFecha
 *  \param Tamanio maximo de la lista
 * 	\param Puntero de primera posicion vacia a devolver
 *  \return Retorna 0 si encuentra un espacio vacio, -1 si no lo encuentra
 */
int findEmptyF(eFecha *pArray, int limite, int *pos);

/**
 * \brief Determina si un anio es bisiesto o no
 *  \param El anio a ingresar
 *  \return Retorna 0 si es bisiesto, 1 si no
 */
int checkAnioBisiesto(int anio);


#endif /* FECHA_H_ */
