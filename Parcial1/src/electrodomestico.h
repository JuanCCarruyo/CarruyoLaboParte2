/*
 * electrodomestico.h
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

#include "marca.h"

typedef struct
{
    int id;
    int serie;
    int idMarca;
    int modelo;
    int isEmpty;
}Electro;

/*
 * \brief Carga de manera automatica algunos electrodomesticos.
 * \param Array de tipo electrodomesticos
 * \param Tamanio de la lista de clientes
 * \return Es void, no retorna.
 */
void harcodeoElectro(Electro *pArray,int limite);

/*
 * \brief Realiza el ingreso de la carga de un electrodomestico nuevo al array de electrodomesticos.
 * \param Array de tipo electrodomesticos
 * \param Array de tipo marcas
 * \param Tamanio maximo de la lista
 * \param Contador de electrodomesticos
 * \return Retorna 0 si se realiza la carga con exito, -1 si no.
 */
int altaElectro(Electro *pArray, Marca *pMarca, int limite, int *contElectro);

/*
 * \brief Revisa si existe un ID en el array de electrodomesticos.
 * \param Array de tipo electrodomesticos
 * \param Tamanio de la lista
 * \param El ID a buscar en el array de electrodomesticos
 * \return Retorna 0 si existe el ID, -1 si no.
 */
int checkElectro(Electro *pElectro, int limite, int inputElectro);

/*
 * \brief Realiza la carga de un electrodomestico nuevo al array de electrodomesticos.
 * \param Array de tipo electrodomesticos
 * \param Tamanio maximo de la lista
 * \param ID a cargar en el array
 * \param Serie a cargar en el array
 * \param ID de marca a ser utilizado en el array
 * \param Modelo a cargar en el array
 * \param Contador de electrodomesticos
 * \return Retorna 0 si se agrega con exito el electrodomesticos, -1 si no.
 */
int addElectro(Electro *pArray, int limite, int id, int serie, int idMarca, int modelo, int *contElectro);

/**
 * \brief Imprimo la tabla con los datos cargados al array de electrodomesticos
 *  \param Array de tipo electrodomesticos a imprimir
 *  \param Tamanio maximo de la lista
 *  \return Retorna 0 si se imprime la lista con exito, -1 si no.
 */
int printElectro(Electro *pArray, Marca *pMarca, int limite);

/**
 * \brief Inicializa el array de electrodomesticos colocando isEmpty = 0.
 *  \param Array de tipo electrodomesticos
 *  \param Tamanio maximo de la lista
 *  \return Retorna 0 si se inicializa el array con exito, -1 si no.
 */
int initElectro(Electro *pArray, int limite);

/**
 * \brief Realiza la baja de un elemento del array de electrodomesticos
 *  \param Array de tipo electrodomesticos
 *  \param Tamanio maximo de la lista
 *  \param ID del elemento que se desea dar de baja
 *  \param Contador de electrodomesticos
 *  \return Retorna 0 si se da de baja el elemento con exito, -1 si no.
 */
int removeElectro(Electro *pArray, int limite, int id, int *contElectro);

/**
 * \brief Realiza la busqueda de un electrodomestico por ID
 *  \param Array de tipo electrodomesticos
 *  \param Tamanio maximo de la lista
 * 	\param El ID a buscar en el array de electrodomesticos
 *  \return Retorna la posicion donde se encuentra ese ID, -1 si no lo encuentra
 */
int findElectroById(Electro *pArray, int limite, int id);

/**
 * \brief Busca y modifica los datos del array de electrodomesticos
 *  \param Array de tipo electrodomesticos
 *  \param Numero de indice que se desea modificar
 *  \return Retorna 0 si se modifica el elemento con exito, -1 si no.
 */
int modifyElectro(Electro* pArray, int indice);

/*
 * \brief Ordena el array de electrodomesticos por modelo y numero de serie
 *  \param Array de tipo electrodomesticos a ordenar
 *  \param Tamanio maximo de la lista
 *  \param Tipo de orden que se desea utilizar (1 ascendente)
 *  \return	Retorna 0 si se sortea con exito, -1 si no.
 */
int sortElectro(Electro *pArray, int limite, int orden);

/**
 * \brief Realiza la busqueda de la primera ubicacion vacia en el array de electrodomesticos y devuelve la posicion de indice
 *  \param Array de tipo electrodomesticos
 *  \param Tamanio maximo de la lista
 * 	\param Puntero de primera posicion vacia a devolver
 *  \return Retorna 0 si encuentra un espacio vacio, -1 si no lo encuentra
 */
int findEmptyE(Electro *pArray, int limite, int *pos);

/*
 * \brief Busca cual es la marca con la mayor cantidad de electrodomesticos
 *  \param Array de tipo electrodomesticos
 *  \param Tamanio maximo de la lista
 *  \param Puntero que guarda la marca con la mayor cantidad de electrodomesticos
 *  \return	Retorna 0 si encuentra la marca con exito, -1 si no.
 */
int checkMayorMarca(Electro *pElectro, int limite, int *mayorMarca);

/*
 * \brief Cuenta la cantidad de electrodomesticos de la misma marca
 *  \param Array de tipo electrodomesticos
 *  \param Array de tipo marcas
 *  \param Tamanio maximo de la lista
 *  \return	Retorna 0 si realiza las cuentas con exito, -1 si no.
 */
int contadoresMarcas(Electro *pElectro, Marca *pMarca, int limite, int *contadorElectro);

#endif /* ELECTRODOMESTICO_H_ */
