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
				// Crear vendedor
				crearVendedor(vendedores);
				break;
			}
			case 2:
			{
				// Borrar vendedor
				borrarVendedor(vendedores);
				break;
			}
			case 3:
			{
				// Borrar vendedor por RUT
				printf("\n\nIngrese un RUT: ");
				char rut[15];
				scanf("%s", rut);
				borrarVendedorPorRut(rut, vendedores);
				break;
			}
			case 4:
			{
				// Buscar vendedor por RUT
				printf("\n\nIngrese un RUT: ");
				char rut[15];
				scanf("%s", rut);
				int vendedor_pos = buscarVendedorPorRut(rut, vendedores);
				if(vendedor_pos != 0)
				{
					Vendedor vendedor_aux = recupera(vendedor_pos, vendedores);
					printf("\n\nNombre\tApelli.\tTel.\tDir.\tEdad\tDeuda\tProf.\tRUT\tCuenta\n");
					printf("-------------------------------------------------------------------\n");
					printf("%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%ld\n",
					vendedor_aux.nombre, 
					vendedor_aux.apellido, 
					vendedor_aux.telefono, 
					vendedor_aux.direccion, 
					vendedor_aux.edad, 
					vendedor_aux.deuda, 
					vendedor_aux.profesion, 
					vendedor_aux.rut,
					vendedor_aux.cuenta);
				}
				else
				{
					printf("\nNo se encontró un vendedor con ese RUT!\n");
				}
				break;
			}
			case 5:
			{
				// Listar todos los vendedores
				listarVendedores(vendedores);
				break;
			}
			case 6:
			{
				// Crear un cliente en un vendedor en particular
				crearCliente(vendedores);
				break;
			}
			case 7:
			{
				// Buscar cliente por RUT
				
				printf("\n\nElija un vendedor:");
				printf("\n----------------------------------\n");
				listarVendedores(vendedores);
				printf("\nOpcion:");
				int opcion_listado_clientes;
				scanf("%d", &opcion_listado_clientes);
				Vendedor vendedor_aux = recupera(opcion_listado_clientes, vendedores);


				printf("\n\nIngrese un RUT: ");
				char rut[15];
				scanf("%s", rut);
				int cliente_pos = buscarClientePorRut(rut, vendedor_aux.clientes);
				if(cliente_pos != 0)
				{
					Cliente cliente_aux = recupera(cliente_pos, vendedor_aux.clientes);
					printf("\n\nNombre\tApelli.\tTel.\tDir.\tEdad\tDeuda\tProf.\tRUT\t#Cobro\n");
					printf("-------------------------------------------------------------------\n");
					printf("%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%s\n",
					cliente_aux.nombre, 
					cliente_aux.apellido, 
					cliente_aux.telefono, 
					cliente_aux.direccion, 
					cliente_aux.edad, 
					cliente_aux.deuda, 
					cliente_aux.profesion, 
					cliente_aux.rut,
					cliente_aux.fechaCobro);
				}
				else
				{
					printf("\nNo se encontró un cliente de %s %s con ese RUT!\n", vendedor_aux.nombre, vendedor_aux.apellido);
				}
				break;
			}
			case 8:
			{
				// Listar todos los vendedores de un cliente
				printf("\n\nElija un vendedor:");
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
				// Guardar lista de vendedores
				guardar(ventas, vendedores);
				break;
			}
			case 10:
			{
				// Salir (pregunta si guardar o no)
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
				// Opción no valida
				printf("Opción inválida.");
				break;
			}
		}
	}

	fclose(ventas);
	return 0;	
}