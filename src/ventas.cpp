#include "ventas.h"
#include "./TDA-Clientes/clientes.h"
#include "./TDA-Vendedores/vendedores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syscall.h>

//###################################################################################
//################# Funciones de Manejador de vendedores ############################
//###################################################################################

void crearVendedor(cabeceraVendedor &vendedores)
{
	//petición de datos de nuevo contacto al usuario
	Vendedor vendedor_aux; 
	printf("\nNombre: ");
	scanf("%s", vendedor_aux.nombre);
	printf("\nApellido: ");
	scanf("%s", vendedor_aux.apellido);
	printf("\nNúmero telefónico: ");
	scanf("%ld", &vendedor_aux.telefono);
	printf("\nDireccion: ");
	scanf("%s", vendedor_aux.direccion);
	printf("\nEdad: ");
	scanf("%d", &vendedor_aux.edad);
	// printf("\nDeuda: ");
	// scanf("%ld", &vendedor_aux.deuda);
	printf("\nProfesión: ");
	scanf("%s", vendedor_aux.profesion);
	printf("\nRUT: ");
	scanf("%s", vendedor_aux.rut);
	printf("\nCuenta: ");
	scanf("%ld", &vendedor_aux.cuenta);
	inserta(vendedor_aux, fin(vendedores), vendedores);
}

void crearCliente(cabeceraVendedor &vendedores)
{
	Cliente cliente_aux;
	printf("\nNombre: ");
	scanf("%s", cliente_aux.nombre);
	printf("\nApellido: ");
	scanf("%s", cliente_aux.apellido);
	printf("\nRUT: ");
	scanf("%s", cliente_aux.rut);
	printf("\nTelefono: ");
	scanf("%ld", &cliente_aux.telefono);
	printf("\nDireccion: ");
	scanf("%s", cliente_aux.direccion);
	printf("\nEdad: ");
	scanf("%d", &cliente_aux.edad);
	printf("\nProfesion: ");
	scanf("%s", cliente_aux.profesion);
	printf("\nDeuda: ");
	scanf("%ld", &cliente_aux.deuda);
	printf("\nFecha de cobro: ");
	scanf("%s", cliente_aux.fechaCobro);

	printf("\n\nElija el vendedor de este cliente.");
	printf("\n----------------------------------\n");
	listarVendedores(vendedores);
	printf("\nOpcion:");
	int opcion;
	scanf("%d", &opcion);
	Vendedor vendedor_aux = recupera(opcion, vendedores);
	vendedor_aux.deuda += cliente_aux.deuda;
	inserta(cliente_aux, fin(vendedor_aux.clientes), vendedor_aux.clientes);
	suprime(opcion, vendedores);
	inserta(vendedor_aux, opcion, vendedores);
}

void listarVendedores(cabeceraVendedor vendedores)
{
	printf("\n\nN°\tNombre\tApelli.\tTelefono\tDir.\tEdad\tDeuda\tProfes.\tRUT\t\tCuenta\n");
	printf("----------------------------------------------------------------------------------------------\n");
	for (int i = primero(vendedores); i < fin(vendedores); i = siguiente(i, vendedores))
	{
		Vendedor vendedor_aux;
		vendedor_aux = recupera(i, vendedores);
		// copiar(*vendedor_aux,recupera(i, vendedores));
		printf("%d\t%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%ld\n",
		i,
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
}

void listarClientes(cabeceraCliente clientes)
{
	printf("\n\nN°\tNombre\tApelli.\tTelefono\tDir.\tEdad\tDeuda\tProfes.\tRUT\t\t#Cobro\n");
	printf("----------------------------------------------------------------------------------------------\n");
	for (int i = primero(clientes); i < fin(clientes); i = siguiente(i, clientes))
	{
		Cliente *cliente_aux = new Cliente;
		copiar(*cliente_aux,recupera(i, clientes));
		printf("%d\t%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%s\n",
		i,
		cliente_aux->nombre, 
		cliente_aux->apellido, 
		cliente_aux->telefono, 
		cliente_aux->direccion, 
		cliente_aux->edad, 
		cliente_aux->deuda, 
		cliente_aux->profesion, 
		cliente_aux->rut,
		cliente_aux->fechaCobro);
		delete cliente_aux;
	}
}

void recargar(FILE* ventas, cabeceraVendedor &vendedores)
{
	//suprime todas las entradas de la lista 'vendedores' sin borrar la lista.
	while(fin(vendedores) != 1)
	{
		suprime(fin(vendedores) - 1, vendedores);   
	}

	while (!feof(ventas))
	{
		char indicador[1];
		fscanf(ventas, "%s", indicador);
		if(!strcmp(indicador, "V"))
		{
			//escaneo de datos
			long deuda_aux;
			Vendedor *aux_vendedor = new Vendedor;
			fscanf(ventas, "%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%ld", 
			aux_vendedor->nombre, 
			aux_vendedor->apellido, 
			&aux_vendedor->telefono, 
			aux_vendedor->direccion, 
			&aux_vendedor->edad, 
			&deuda_aux, // DEUDA
			aux_vendedor->profesion, 
			aux_vendedor->rut,
			&aux_vendedor->cuenta);
			inserta(*aux_vendedor, fin(vendedores), vendedores);
			delete aux_vendedor;
		}
		if(!strcmp(indicador, "C"))
		{
			char rut_vendedor[8];
			Cliente cliente_aux;
			fscanf(ventas, "%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%s\t%s",
			cliente_aux.nombre, 
			cliente_aux.apellido, 
			&cliente_aux.telefono, 
			cliente_aux.direccion, 
			&cliente_aux.edad, 
			&cliente_aux.deuda, // DEUDA
			cliente_aux.profesion, 
			cliente_aux.rut,
			cliente_aux.fechaCobro,
			rut_vendedor);

			Vendedor vendedor_aux = recupera(fin(vendedores)-1, vendedores);
			vendedor_aux.deuda += cliente_aux.deuda;
			inserta(cliente_aux, fin(vendedor_aux.clientes), vendedor_aux.clientes);
			suprime(fin(vendedores)-1, vendedores);
			inserta(vendedor_aux, fin(vendedores), vendedores);
		}
	}
}

void borrar(cabeceraVendedor &vendedores)
{
	listarVendedores(vendedores);
	printf("\nOpcion: ");
	int numero;
	scanf("%d", &numero);
	suprime(numero, vendedores);
}

void borrar(Vendedor &vendedor, cabeceraCliente &clientes)
{
	listarClientes(clientes);
	printf("\nOpcion: ");
	int numero;
	scanf("%d", &numero);
	Cliente cliente_aux = recupera(numero, clientes);
	vendedor.deuda -= cliente_aux.deuda;
	suprime(numero, clientes);
}

void borrarVendedorPorRut(char rut[], cabeceraVendedor &vendedores)
{
	for (int i = primero(vendedores); i < fin(vendedores); i = siguiente(i, vendedores))
	{
		//muestra de datos por pantalla
		Vendedor *vendedor_aux = new Vendedor;
		copiar(*vendedor_aux,recupera(i, vendedores));
		if (!strcmp(rut, vendedor_aux->rut))
		{
			suprime(i, vendedores);
			return;
		}
		delete vendedor_aux;
		printf("No se encontró un vendedor con ese RUT.");
		return;
	}
}

int buscarVendedorPorRut(char rut[], cabeceraVendedor vendedores)
{
	for (int i = primero(vendedores); i < fin(vendedores); i = siguiente(i, vendedores))
	{
		Vendedor vendedor_aux = recupera(i, vendedores);
		if (!strcmp(rut, vendedor_aux.rut))
		{
			return i;
		}
	}
	return 0;
}


int buscarClientePorRut(char rut[], cabeceraCliente clientes)
{
	for (int i = primero(clientes); i < fin(clientes); i = siguiente(i, clientes))
	{
		Cliente cliente_aux = recupera(i, clientes);
		if (!strcmp(rut, cliente_aux.rut))
		{
			return i;
		}
	}
	return 0;
}

void guardar(FILE * ventas, cabeceraVendedor vendedores)
{
	freopen(NULL, "w+", ventas);
	for (int i = primero(vendedores); i < fin(vendedores); i = siguiente(i, vendedores))
	{
		//muestra de datos por pantalla
		Vendedor vendedor_aux = recupera(i, vendedores);
		fprintf(ventas, "\nV\t%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%ld", 
		vendedor_aux.nombre, 
		vendedor_aux.apellido, 
		vendedor_aux.telefono, 
		vendedor_aux.direccion, 
		vendedor_aux.edad, 
		vendedor_aux.deuda, 
		vendedor_aux.profesion, 
		vendedor_aux.rut,
		vendedor_aux.cuenta);
		for (int j = primero(vendedor_aux.clientes); j < fin(vendedor_aux.clientes); j = siguiente(j, vendedor_aux.clientes))
		{
			Cliente cliente_aux = recupera(j, vendedor_aux.clientes);
			fprintf(ventas, "\nC\t%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%s\t%s",
			cliente_aux.nombre, 
			cliente_aux.apellido, 
			cliente_aux.telefono, 
			cliente_aux.direccion, 
			cliente_aux.edad, 
			cliente_aux.deuda, 
			cliente_aux.profesion, 
			cliente_aux.rut,
			cliente_aux.fechaCobro,
			vendedor_aux.rut);

		}
	}
	freopen(NULL, "a+", ventas);
}