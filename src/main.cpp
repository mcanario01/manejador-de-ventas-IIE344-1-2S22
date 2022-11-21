/* Universidad de La Frontera
* Ingeniería Civil Telemática
*
* IIE-344 Estructura de Datos y Algoritmos
*
* Tarea 2
*
* Autor: Martin Tomás Canario Dauros (m.canario01@ufromail.cl)
* 
* Fecha: 28 de octubre de 2022.
* 
* Descripción general del programa:
* manejador-de-ventas es un programa que se utilizaría para mantener una lista ordenada
* que relacione vendedores con sus clientes, dicha lista tendrá información como los datos
* personales tanto de vendedores como clientes y también sus deudas y cobros.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ventas.h"
#include "./TDA-Clientes/clientes.h"
#include "./TDA-Vendedores/vendedores.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc > 2)
	{   
		printf("Muchos argumentos!");
		return 1;
	}

	system("clear");

	printf("\n\n------ Manejador de vendedores -------\n\n");
	FILE * ventas = fopen(argv[1], "a+");
	cabeceraVendedor vendedores;
	printf("1\n");
	recargar(ventas, vendedores);
	bool termino = 1;
	while (termino)
	{	
		printf("\tElija la operación que desea realizar:\n\n");
		printf("\t\t1. Crear un vendedor.\n");
		printf("\t\t2. Borrar un vendedor.\n");
		printf("\t\t3. Borrar un vendedor por RUT.\n");
		printf("\t\t4. Buscar vendedor por RUT.\n");
		printf("\t\t5. Listar todos los vendedores.\n");
		printf("\n\t\t6. Crear un cliente.\n");
		printf("\t\t7. Buscar cliente por RUT.\n");
		printf("\t\t8. Listar clientes por vendedor.\n");
		printf("\n\t\t9. Guardar.\n");
		printf("\t\t10. Salir.\n\n");
		printf("\tOpción:");
		int opcion;
		scanf("%d", &opcion);

		switch (opcion)
		{
			case 1:
			{
				crearVendedor(vendedores);
				break;
			}
			case 2:
			{
				borrarVendedor(vendedores);
				break;
			}
			case 3:
			{
				printf("\n\nIngrese un RUT: ");
				char rut[15];
				scanf("%s", rut);
				borrarVendedorPorRut(rut, vendedores);
				break;
			}
			case 4:
			{
				printf("\n\nIngrese un RUT: ");
				char rut[15];
				scanf("%s", rut);
				buscarVendedorPorRut(rut, vendedores);
				break;
			}
			case 5:
			{
				listarVendedores(vendedores);
				break;
			}
			case 6:
			{
				crearCliente(vendedores);
				break;
			}
			case 7:
			{
				break;
			}
			case 8:
			{
				printf("\n\nElija el vendedor de la lista de clientes:");
				printf("\n----------------------------------\n");
				listarVendedores(vendedores);
				printf("\nOpcion:");
				int opcion_listado_clientes;
				scanf("%d", &opcion_listado_clientes);
				Vendedor vendedor_aux;
				copiar(vendedor_aux, recupera(opcion_listado_clientes, vendedores));
				listarClientes(vendedor_aux.clientes);
				break;
			}
			case 9:
			{
				guardar(ventas, vendedores);
				break;
			}
			case 10:
			{
				printf("\n¿Desea guardar los cambios? (1. Si / 2. No): ");
				int guardar_cambios;
				scanf("%d", &guardar_cambios);
				if (guardar_cambios == 1)
				{
					guardar(ventas, vendedores);
				}
				termino = 0;
				break;
			}
			
			default:
			{
				printf("Opción inválida.");
				break;
			}
		}
	}

	fclose(ventas);
	return 0;	
}