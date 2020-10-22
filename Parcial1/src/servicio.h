/*
 * servicio.h
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct
{
    int id; //comienza en 20000
    char servDesc[26];
    float precio;
    int isEmpty;
}Servicio;

/**
 * \brief Imprimo la tabla con los datos cargados al array de servicio
 *  \param Array de tipo servicio a imprimir
 *  \param Tamanio maximo de la lista
 *  \return Retorna 0 si se imprime la lista con exito, -1 si no.
 */
int printServicio(Servicio *pArray, int limite);

/**
 * \brief Realiza la busqueda de un servicio por ID
 *  \param Array de tipo servicio
 *  \param Tamanio maximo de la lista
 * 	\param El ID a buscar en el array de servicio
 *  \return Retorna la posicion donde se encuentra ese ID, -1 si no lo encuentra
 */
int findServicioById(Servicio *pArray, int limite, int id);

/*
 * \brief Revisa si existe un ID en el array de servicio.
 * \param Array de tipo servicio
 * \param Tamanio de la lista
 * \param El ID a buscar en el array de marcas
 * \return Retorna 0 si existe el ID, -1 si no.
 */
int checkServicio(Servicio *pServicio, int limite, int inputServicio);

#endif /* SERVICIO_H_ */
