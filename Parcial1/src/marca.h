/*
 * marca.h
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct
{
 int id; //comienza en 1000
 char marcDesc[21]; // max 20 caracteres
 int isEmpty;
}Marca;

/**
 * \brief Imprimo la tabla con los datos cargados al array de marca
 *  \param Array de tipo marca a imprimir
 *  \param Tamanio maximo de la lista
 *  \return Retorna 0 si se imprime la lista con exito, -1 si no.
 */
int printMarca(Marca *pArray, int limite);

/*
 * \brief Revisa si existe un ID en el array de marcas.
 * \param Array de tipo Marcas
 * \param Tamanio de la lista
 * \param El ID a buscar en el array de marcas
 * \return Retorna 0 si existe el ID, -1 si no.
 */
int checkMarca(Marca *pArray, int limite, int inputMarca);

/**
 * \brief Realiza la busqueda de una marca por ID
 *  \param Array de tipo marca
 *  \param Tamanio maximo de la lista
 * 	\param El ID a buscar en el array de marca
 *  \return Retorna la posicion donde se encuentra ese ID, -1 si no lo encuentra
 */
int findMarcaById(Marca *pArray, int limite, int id);

#endif /* MARCA_H_ */
