/*
 * fecha.c
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utnInputs.h"
#include "fecha.h"

int getFecha(eFecha *pArray, int limite, char* mensajeError, int reintentos, int *contFecha)
{

	int ret=0;
	int anio;
	int mes;
	int dia;
	int maxDias;
	int rescheckAnioBisiesto; //retorna 0 si es bisiesto, 1 si no
	int resaddFecha;

	printf("\nIngrese la fecha: ");
	while(reintentos>0)
	{
		printf("\nIngrese el Anio:");
		if(scanf("%d",&anio)==1){
		if(anio<=2020 && anio>=1990)
			{
			rescheckAnioBisiesto = checkAnioBisiesto(anio);
			break;
			}
		}
		fflush(stdin);
		reintentos--;
		printf(mensajeError);
	}
	while(reintentos>0)
	{
		printf("\nIngrese el Mes: (en numero)");
		if(scanf("%d",&mes)==1){
		if(mes<=12 && mes>=1)
			{break;}
		}
		fflush(stdin);
		reintentos--;
		printf(mensajeError);
	}
	while(reintentos>0)
	{
		printf("\nIngrese el Dia: ");
		if(scanf("%d",&dia)==1){
			switch(mes)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				maxDias = 31;
				break;

			case 4:
			case 6:
			case 9:
			case 11:
				maxDias = 30;
				break;

			case 2:
				switch(rescheckAnioBisiesto)
				{
				case 0:
					maxDias = 29;
					break;
				case 1:
					maxDias = 28;
					break;
				}
			}
		if(dia<=maxDias && dia>=1)
			{break;}
		}
		fflush(stdin);
		reintentos--;
		printf(mensajeError);
	}

	if(reintentos==0)
	{
		ret=-1;
	}
	else
	{
		ret=0;
		resaddFecha = addFecha(pArray, limite, dia, mes, anio, contFecha);
		if (resaddFecha!=0)
		{
			printf("\nError agregando fecha.");

		}
	}
		return ret;
}

int addFecha(eFecha *pArray, int limite, int dia, int mes, int anio, int *contFecha) {
	int retorno = -1;
	int i;
	int contador = *contFecha;

	if (findEmptyF(pArray, limite, &i) == 0) {
		contador++;
		*contFecha = contador;

		pArray[i].id = *contFecha;
		pArray[i].dia = dia;
		pArray[i].mes = mes;
		pArray[i].anio = anio;
		pArray[i].isEmpty = 0;

		retorno = 0;

	} else {
		retorno = -1;
		printf("\nNo hay espacio para mas fechas.");
	}

	return retorno;
}

int removeFecha(eFecha *pArray, int limite, int id, int *contFecha) {
	int retorno = -1;
	int contador = *contFecha;

	if (pArray != NULL && limite > 0) {
		pArray[id].isEmpty = 1;
		contador--;
		*contFecha = contador;
		retorno = 0;
	}
	return retorno;
}


int findFechaById(eFecha *pArray, int limite, int id) {
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

int initFecha(eFecha *pArray, int limite) {
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

int findEmptyF(eFecha *pArray, int limite, int *pos) {
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

int checkAnioBisiesto(int anio){
	int retorno = -1;

	if ( ((anio % 4 == 0) && (anio % 100 != 0)) || anio % 400 == 0 )
	{
		retorno = 0;
	}
	else
	{
		retorno = 1;
	}

	return retorno;
}
