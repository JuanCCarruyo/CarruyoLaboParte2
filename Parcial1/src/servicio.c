/*
 * servicio.c
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "servicio.h"

int printServicio(Servicio *pArray, int limite) {
	int retorno = -1;
	int i;
	if (pArray != NULL && limite > 0) {
		printf("\n_____________________________________________");
		printf("\n| ID:      | Descripcion:      |  Precio:    | ");
		printf("\n|__________|___________________|_____________|\n");
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty != 1) {
				printf("|%d     |%s      |  $%.2f    |\n",
						pArray[i].id,pArray[i].servDesc,pArray[i].precio);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int findServicioById(Servicio *pArray, int limite, int id) {
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


int checkServicio(Servicio *pServicio, int limite, int inputServicio)
{
	int retorno = -1;
	int i;

	if (pServicio != NULL && limite > 0) {
			for (i = 0; i < limite; i++) {
				if (pServicio[i].id == inputServicio) {
					retorno = 0;
					break;
				}
			}
		}


	return retorno;
}


