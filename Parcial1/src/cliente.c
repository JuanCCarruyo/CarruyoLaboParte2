/*
 * cliente.c
 *
 *  Created on: Oct 21, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utnInputs.h"
#include "cliente.h"

void harcodeoClientes(Cliente *pArray,int limite)
{
	int i;
	int id[5]={1,2,3,4,5};
	char nombre[][51]={"Jonathan","Joseph  ","Jotaro  ","Josuke  ","Giorno  "};
	char apellido[][51]={"Joestar    ","Joestar    ","Kujo       ","Higashikata","Giovanna   "};
	for (i = 0; i < 5; i++){

		pArray[i].id=id[i];
		strcpy(pArray[i].nombre,nombre[i]);
		strcpy(pArray[i].apellido,apellido[i]);
		pArray[i].isEmpty = 0;
	}
}

int findClienteById(Cliente *pArray, int limite, int id) {
	int retorno = -1;
	int i;
	int flag = 0;

	if (pArray != NULL && limite > 0){
	for (i = 0; i < limite; i++) {
		if (pArray[i].isEmpty != 1) {
			if (pArray[i].id == id) {
				flag = 1;
				retorno = i;
				break;
			}
		}
	}}

	if (flag == 0) {
		retorno = -1;
	}

	return retorno;
}

int checkCliente(Cliente *pCliente, int limite, int inputCliente)
{
	int retorno = -1;
	int i;

	if (pCliente != NULL && limite > 0) {
			for (i = 0; i < limite; i++) {
				if (pCliente[i].id == inputCliente) {
					retorno = 0;
					break;
				}
			}
		}


	return retorno;
}

int printCliente(Cliente *pArray, int limite){
	int retorno = -1;
	int i;
	if (pArray != NULL && limite > 0) {
		printf("\n__________________________________________");
		printf("\n| ID: |  Nombre:     | Apellido:          | ");
		printf("\n|_____|______________|____________________|\n");
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty != 1) {
				printf("|%d    |  %s    |  %s       |\n",
						pArray[i].id,pArray[i].nombre,pArray[i].apellido);
			}
		}
		retorno = 0;
	}
	return retorno;
}
