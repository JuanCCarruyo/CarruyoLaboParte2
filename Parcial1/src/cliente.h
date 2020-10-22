/*
 * cliente.h
 *
 *  Created on: Oct 21, 2020
 *      Author: david
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    int isEmpty;
}Cliente;

/*
 * \brief Carga de manera automatica algunos clientes.
 * \param Array de tipo cliente
 * \param Tamanio de la lista de clientes
 * \return Es void, no retorna.
 */
void harcodeoClientes(Cliente *pArray,int limite);

/**
 * \brief Realiza la busqueda de un cliente por ID
 *  \param Array de tipo cliente
 *  \param Tamanio maximo de la lista
 * 	\param El ID a buscar en el array de cliente
 *  \return Retorna la posicion donde se encuentra ese ID, -1 si no lo encuentra
 */
int findClienteById(Cliente *pArray, int limite, int id);

/*
 * \brief Revisa si existe un ID en el array de cliente.
 * \param Array de tipo cliente
 * \param Tamanio de la lista
 * \param El ID a buscar en el array de cliente
 * \return Retorna 0 si existe el ID, -1 si no.
 */
int checkCliente(Cliente *pCliente, int limite, int inputCliente);

/**
 * \brief Imprime la tabla con los datos cargados al array de cliente
 *  \param Array de tipo cliente a imprimir
 *  \param Tamanio maximo de la lista
 *  \return Retorna 0 si se imprime la lista con exito, -1 si no.
 */
int printCliente(Cliente *pArray, int limite);

#endif /* CLIENTE_H_ */
