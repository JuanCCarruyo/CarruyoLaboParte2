/*
 * reparacion.h
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#ifndef REPARACION_H_
#define REPARACION_H_

#include "fecha.h"
#include "electrodomestico.h"
#include "servicio.h"
#include "cliente.h"

typedef struct
{
int id;
int serie;
int idCliente;
int idServicio;
eFecha fecha;
int isEmpty;
}Reparacion;

/*
 * \brief Carga de manera automatica algunas reparaciones.
 * \param Array de tipo reparacion
 * \param Tamanio de la lista de reparacion
 * \return Es void, no retorna.
 */
void harcodeoReparacion(Reparacion *pArray,int limite);

/*
 * \brief Realiza el ingreso de la carga de una reparacion nueva al array de reparacion.
 * \param Array de tipo reparacion
 * \param Array de tipo electrodomesticos
 * \param Array de tipo servicio
 * \param Array de tipo eFecha
 * \param Array de tipo Cliente
 * \param Tamanio maximo de la lista
 * \param Contador de reparaciones
 * \param Contador de fechas
 * \return Retorna 0 si se realiza la carga con exito, -1 si no.
 */
int altaReparacion(Reparacion *pArray, Electro *pElectro, Servicio *pServicio, eFecha *pFecha, Cliente *pCliente, int limite, int *contRep, int *contFecha);

/*
 * \brief Realiza la carga de una reparacion nueva al array de reparacion.
 * \param Array de tipo reparacion
 * \param Tamanio maximo de la lista
 * \param ID a cargar en el array
 * \param Serie a cargar en el array
 * \param ID de cliente a ser utilizado en el array
 * \param ID de servicio a ser utilizado en el array
 * \param Array de tipo eFecha
 * \param Contador de reparaciones
 * \return Retorna 0 si se agrega con exito la reparacion, -1 si no.
 */
int addRep(Reparacion *pArray, int limite, int id, int serie, int idCliente, int idServicio, eFecha *fecha, int *contReparacion);

/**
 * \brief Imprimo la tabla con los datos cargados al array de reparacion
 *  \param Array de tipo reparacion a imprimir
 *  \param Array de tipo cliente a imprimir
 *  \param Array de tipo servicio a imprimir
 *  \param Tamanio maximo de la lista
 *  \return Retorna 0 si se imprime la lista con exito, -1 si no.
 */
int printRep(Reparacion *pArray, Cliente *pCliente, Servicio *pServicio, int limite);

/**
 * \brief Inicializa el array de reparacion colocando isEmpty = 0.
 *  \param Array de tipo reparacion
 *  \param Tamanio maximo de la lista
 *  \return Retorna 0 si se inicializa el array con exito, -1 si no.
 */
int initRep(Reparacion *pArray, int limite);

/**
 * \brief Realiza la busqueda de la primera ubicacion vacia en el array de servicio y devuelve la posicion de indice
 *  \param Array de tipo servicio
 *  \param Tamanio maximo de la lista
 * 	\param Puntero de primera posicion vacia a devolver
 *  \return Retorna 0 si encuentra un espacio vacio, -1 si no lo encuentra
 */
int findEmptyR(Reparacion *pArray, int limite, int *pos);


int contadoresClientes(Reparacion *pArray, Cliente *pCliente, int limite, int *contadorCliente);

#endif /* REPARACION_H_ */
