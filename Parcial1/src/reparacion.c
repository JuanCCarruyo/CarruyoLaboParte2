/*
 * reparacion.c
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "reparacion.h"
#include "electrodomestico.h"
#include "servicio.h"
#include "utnInputs.h"
#include "marca.h"
#include "fecha.h"
#include "cliente.h"


void harcodeoReparacion(Reparacion *pArray,int limite)
{
	int i;
	int id[5]={1,2,3,4,5};
	int serie[5]={20321,69696,40203,20003,20002};
	int idCliente[5]={4,3,3,4,2};
	int idServicio[5]={20001,20001,20000,20003,20002};
	eFecha fecha[]={{1,25,8,2020},{2,13,2,2019},{3,11,9,2001},{4,20,4,2020},{5,4,8,1997}};
	int isEmpty[5]={0,0,0,0,0};
	for (i = 0; i < 5; i++){

		pArray[i].id=id[i];
		pArray[i].idCliente=idCliente[i];
		pArray[i].serie=serie[i];
		pArray[i].idServicio=idServicio[i];
		pArray[i].fecha=fecha[i];
		pArray[i].isEmpty=isEmpty[i];
	}
}

int altaReparacion(Reparacion *pArray, Electro *pElectro, Servicio *pServicio, eFecha *pFecha, Cliente *pCliente, int limite, int *contRep, int *contFecha) {

	int resultadoAddRep = 0;
	int resultadoGetFecha = 0;
	int retorno = -1;


	int auxId=0;
	int serie;


	int idElectro;
	int residElectro=0;
	int idServicio;
	int residServicio=0;
	int indiceElec;

	int idCliente;
	int residCliente=0;
//	int indiceCliente;


	if (pArray != NULL && limite > 0){

	do{
		if(residElectro!=0){
			printf("\nError, ID invalido: ");
		}
	printf("\nIngrese el ID del Electrodomestico: ");
	scanf("%d", &idElectro);
	residElectro = checkElectro(pElectro, limite, idElectro);
	}while (residElectro!=0);

	do{
		if(residServicio!=0){
			printf("\nError, ID invalido: ");
		}
	printf("\nIngrese el ID del Servicio: ");
	scanf("%d", &idServicio);
	residServicio = checkServicio(pServicio, limite, idServicio);
	}while (residServicio!=0);

	do{
		if(residCliente!=0){
			printf("\nError, ID invalido: ");
		}
	printf("\nIngrese el ID del Cliente: ");
	scanf("%d", &idCliente);
	residCliente = checkCliente(pCliente, limite, idCliente);
	}while (residCliente!=0);

	indiceElec = findElectroById(pElectro, limite, idElectro);
	serie = pElectro[indiceElec].serie;


//	indiceCliente = findClienteById(pCliente, limite, idCliente);



	resultadoGetFecha = getFecha(pFecha, limite, "\nError.", 10, contFecha);
	if (resultadoGetFecha != 0) {
		printf("\nError ingresando Fecha.\n");
		system("pause");
	}

	resultadoAddRep = addRep(pArray, limite, auxId, serie, idCliente, idServicio, pFecha, contRep);

	if (resultadoAddRep != 0) {
		printf("\nError agregando reparacion.\n");
		system("pause");
	} else {

		retorno = 0;
		system("pause");
	}
}

	return retorno;

}


int addRep(Reparacion *pArray, int limite, int id, int serie, int idCliente, int idServicio, eFecha *fecha, int *contReparacion) {
	int retorno = -1;
	int i;
	int contador = *contReparacion;

	if (findEmptyR(pArray, limite, &i) == 0) {
		contador++;
		*contReparacion = contador;

		pArray[i].id = *contReparacion;
		pArray[i].serie = serie;
		pArray[i].idCliente = idCliente;
		pArray[i].idServicio = idServicio;
		pArray[i].fecha.dia = fecha[i].dia;
		pArray[i].fecha.mes = fecha[i].mes;
		pArray[i].fecha.anio = fecha[i].anio;
		pArray[i].isEmpty = 0;

		retorno = 0;

	} else {
		retorno = -1;
		printf("\nNo hay espacio para mas empleados.");
	}

	return retorno;
}

int printRep(Reparacion *pArray, Cliente *pCliente, Servicio *pServicio, int limite){
	int retorno = -1;
	int i;
	int idCliente;
	int idClientePos;
	int idServicio;
	int idServicioPos;



	if (pArray != NULL && limite > 0) {
		printf("\n___________________________________________________________________________________________________________");
		printf("\n| ID:      |   Serie:      |  Nombre:     |   Apellido:        |  Servicio:           |      Fecha:        | ");
		printf("\n|__________|_______________|______________|____________________|______________________|____________________|\n");
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty != 1) {

				idCliente = pArray[i].idCliente;
				idClientePos = findClienteById(pCliente, limite, idCliente);

				idServicio = pArray[i].idServicio;
				idServicioPos = findServicioById(pServicio, limite, idServicio);


				printf("|%d         |   %d       |  %s    |  %s       |   %s      |     %d/%d/%d      \n",
					pArray[i].id,    pArray[i].serie,   pCliente[idClientePos].nombre,pCliente[idClientePos].apellido,   pServicio[idServicioPos].servDesc,       pArray[i].fecha.dia,pArray[i].fecha.mes,pArray[i].fecha.anio);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int initRep(Reparacion *pArray, int limite) {
	int retorno = -1;
	int i;

	if (pArray != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int findEmptyR(Reparacion *pArray, int limite, int *pos) {
	int retorno = -1;
	int i;

	if (pArray != NULL && limite > 0 && pos != NULL) {
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty == 1) {
				retorno = 0;
				*pos = i;
				break;
			}
		}
	}

	return retorno;
}

int contadoresClientes(Reparacion *pArray, Cliente *pCliente, int limite, int *contadorCliente)
{
	int retorno = -1;
	int i;
	int j;



	int max=-1;
	char nombre[51];
	char apellido[51];



	if (pArray != NULL && pCliente != NULL && limite > 0) {
			for (i = 0; i < 5; i++)
			{
				contadorCliente[i]=0;
			}
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < limite; j++)
				{
					if(pArray[j].idCliente == pCliente[i].id && pArray[j].isEmpty == 0)
					{
						contadorCliente[i]++;
					}
				}
			}

			for (i = 0; i < 5; i++)
			{
				if(max<contadorCliente[i])
				{
					max = contadorCliente[i];
					strncpy(nombre,pCliente[i].nombre,51);
					strncpy(apellido,pCliente[i].apellido,51);
				}
			}




			printf("\nEl cliente con mas reparaciones es %s %s\n",nombre,apellido);

			retorno = 0;

		}

	return retorno;
}
