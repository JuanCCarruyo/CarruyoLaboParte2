/*
 ============================================================================
 Name        : modeloABM.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utnInputs.h"
#include "fecha.h"
#include "marca.h"
#include "electrodomestico.h"
#include "servicio.h"
#include "reparacion.h"
#include "cliente.h"

#define MAX 5

int main(void) {
	setbuf(stdout, NULL);

	Marca marcas[]={{1000, "Wirpool",0}, {1001, "Sony   ",0}, {1002, "Liliana",0}, {1003, "Gafa   ",0}, {1004, "Philips\0",0}};

	Servicio servicio[]= {{20000, "Garantia     ", 250,0}, {20001, "Mantenimiento", 500,0}, {20002, "Repuestos    ", 400,0}, {20003, "Refaccion    \0", 600,0}};
                                   //8                            13                               9                           9
	Electro arrayElectro[MAX];
	Reparacion arrayRep[MAX];
	eFecha arrayFecha[MAX];
	Cliente arrayClientes[MAX];
	int contElectro=0;
	int contRep=0;
	int contFecha=0;

	int opcion;
	int resultadoInicializar;
	int resultadoInicializar2;
	int resultadoInicializar3;
	int resultadoMenu;
	int resultadoCargaElectro;
	int flagAltaElectro=1;
	int flagAltaReparacion=1;
	int resultadoBajaElectro;
	int resultadoFindElectroById;
	int resultadoRemoveElectro;
	int resultadoModElectro;
	int resultadoModifyElectro;
	int resultadoPrintMarca;
	int resultadoPrintServicio;
	int resultadoPrintCliente;
	int resultadoSortElectro;
	int resultadoPrintElectro;
	int resultadoPrintRep;
	int resultadoAltaReparacion;
	int resContadoresClientes;

	int opcion2;
	int resultadoMenuInformes;
	int resContadoresMarcas;

	int contadorElectro[MAX];
	int contadorCliente[MAX];


	int inputID;

	resultadoInicializar = initElectro(arrayElectro, MAX);
	resultadoInicializar2 = initRep(arrayRep, MAX);
	resultadoInicializar3 = initFecha(arrayFecha, MAX);
	harcodeoClientes(arrayClientes,MAX);
	harcodeoElectro(arrayElectro,MAX);
	harcodeoReparacion(arrayRep,MAX);

	do {
			if (resultadoInicializar == -1 || resultadoInicializar2 == -1 || resultadoInicializar3 == -1) {
				printf("\nERROR AL INICIALIZAR");
				system("pause");
				break;
			}
			system("CLS");


			resultadoMenu = getInt(&opcion,
					"Menu de Opciones\n"
					"1- ALTA ELECTRODOMESTICO \n"
					"2- MODIFICAR ELECTRODOMESTICO\n"
					"3- BAJA ELECTRODOMESTICO\n"
					"4- LISTAR ELECTRODOMESTICO \n"
					"5- LISTAR MARCAS \n"
					"6- LISTAR SERVICIOS \n"
					"7- LISTAR CLIENTES \n"
					"8- ALTA REPARACION \n"
					"9- LISTAR REPARACIONES \n"
					"10- LISTAR INFORMES \n",
							"\nError: Seleccione una opcion valida.\n", 1, 10, 3);

			if (resultadoMenu != 0) {
				printf("\nERROR FATAL");
				system("pause");
				break;
			}

			switch (opcion) {
			case 1: // ALTA ELECTRODOMESTICO
				flagAltaElectro = 1;

				resultadoCargaElectro = altaElectro(arrayElectro, marcas, MAX, &contElectro);
				if (resultadoCargaElectro != 0) {
					flagAltaElectro = 0;
					printf("\nError en la Carga.\n");
					system("pause");
				}


				break;

			case 2: //MODIFICAR ELECTRODOMESTICO
				if(flagAltaElectro == 1)
				{

					resultadoModElectro = getInt(&inputID, "\nIngrese el ID del electrodomestico: ",
							"\nERROR: Ingrese un ID valido", 1, MAX, 10);

					if (resultadoModElectro != 0) {
						printf("\nError ingresando ID.\n");
						system("pause");
					} else {
						resultadoFindElectroById = findElectroById(arrayElectro,
						MAX, inputID);

						if (resultadoFindElectroById == -1) {
							printf("\nNo se encontro electrodomestico con ese ID.");
							system("pause");
						} else {
							resultadoModifyElectro = modifyElectro(arrayElectro, resultadoFindElectroById);
							if (resultadoModifyElectro == 0){
								printf("\nSe modifico un electrodomestico con exito.\n");
								system("pause");
							}
							else if (resultadoModifyElectro == -1)
							{
								printf("\nHubo un error modificando el electrodomestico.\n");
								system("pause");
							}
						}
					}
				}
				else
				{
					printf("\nDebe cargar algun electrodomestico antes de Modificar. \n");
				}

				break;
			case 3: //BAJA ELECTRODOMESTICO

				if(flagAltaElectro == 1)
				{

					resultadoBajaElectro = getInt(&inputID, "\nIngrese el ID del electrodomestico: ",
							"\nERROR: Ingrese un ID valido", 1, MAX, 10);

					if (resultadoBajaElectro != 0) {
						printf("\nError ingresando ID.\n");
						system("pause");
					} else {
						resultadoFindElectroById = findElectroById(arrayElectro,
						MAX, inputID);

						if (resultadoFindElectroById == -1) {
							printf("\nNo se encontro electrodomestico con ese ID.");
							system("pause");
						} else {
							resultadoRemoveElectro = removeElectro(arrayElectro,
							MAX, resultadoFindElectroById, &contElectro);
							if (resultadoRemoveElectro != 0) {
								printf("\nError removiendo electrodomestico.\n");
								system("pause");
							}
							printf("\nSe dio de baja a el electrodomestico con exito.\n");
							system("pause");
						}
					}

				}
				else
				{
					printf("\nDebe cargar algun electrodomestico antes de Bajar. \n");
				}

				break;
			case 4: //LISTAR ELECTRODOMESTICO

				resultadoSortElectro = sortElectro(arrayElectro, MAX, 1);
				if (resultadoSortElectro != 0) {
					printf("\nError en el ordenamiento.\n");
					system("pause");
				}

				resultadoPrintElectro = printElectro(arrayElectro, marcas, MAX);
				if (resultadoPrintElectro != 0) {
					printf("\nError mostrando los empleados.\n");
					system("pause");
				}
				system("pause");
				break;


			case 5: //LISTAR MARCAS

				resultadoPrintMarca = printMarca(marcas,MAX);
				if (resultadoPrintMarca != 0)
				{
					printf("\nError mostrando las marcas.\n");
					system("pause");
				}
				system("pause");

				break;


			case 6: //LISTAR SERVICIOS

				resultadoPrintServicio = printServicio(servicio,4);
				if (resultadoPrintServicio != 0)
				{
					printf("\nError mostrando los servicios.\n");
					system("pause");
				}
				system("pause");


				break;

			case 7: //LISTAR CLIENTES

				resultadoPrintCliente = printCliente(arrayClientes,MAX);
				if (resultadoPrintCliente != 0)
				{
					printf("\nError mostrando los clientes.\n");
					system("pause");
				}
				system("pause");


				break;

			case 8:  //ALTA REPARACION
				if(flagAltaElectro == 1)
				{
					flagAltaReparacion = 1;

					resultadoAltaReparacion = altaReparacion(arrayRep, arrayElectro, servicio, arrayFecha, arrayClientes, MAX, &contRep, &contFecha);
					if (resultadoAltaReparacion != 0) {
						flagAltaReparacion = 0;
						printf("\nError en la Carga.\n");
						system("pause");
					}
				}
				else
				{
					printf("\nDebe cargar algun electrodomestico antes de hacer una reparacion. \n");
				}

				break;

			case 9: //LISTAR REPARACIONES

				if(flagAltaElectro == 1 && flagAltaReparacion == 1)
				{
					resultadoPrintRep = printRep(arrayRep, arrayClientes, servicio, MAX);
					if (resultadoPrintRep != 0) {
						printf("\nError mostrando las reparaciones.\n");
						system("pause");
					}
					system("pause");

				}
				else
				{
					printf("\nDebe cargar algun electrodomestico antes de hacer una reparacion. \n");
				}

				break;

			case 10: //INFORMES

				resultadoMenuInformes = getInt(&opcion2,
						"Menu de Opciones\n"
						"1- INFORMAR LA MARCA CON MAS ELECTRODOMESTICOS \n"
						"2- INFORMAR EL CLIENTE CON MAS REPARACIONES\n"
						"3- INFORMAR \n"
						"4- INFORMAR  \n"
						"5- INFORMAR  \n",
								"\nError: Seleccione una opcion valida.\n", 1, 5, 3);

				if (resultadoMenuInformes != 0) {
					printf("\nERROR FATAL");
					system("pause");
					break;
				}

				switch(opcion2)
				{

				case 1:

					resContadoresMarcas = contadoresMarcas(arrayElectro, marcas, MAX, contadorElectro);
					if (resContadoresMarcas != 0) {
						printf("\nERROR FATAL");
						system("pause");
						break;
					}
					system("pause");

					break;

				case 2:

					resContadoresClientes = contadoresClientes(arrayRep, arrayClientes, MAX, contadorCliente);
					if (resContadoresClientes != 0) {
						printf("\nERROR FATAL");
						system("pause");
						break;
					}
					system("pause");


					break;





				}



				break;


			}

		} while (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5 || opcion == 6 || opcion == 7 || opcion == 8|| opcion == 9 || opcion == 10);


	return EXIT_SUCCESS;
}
