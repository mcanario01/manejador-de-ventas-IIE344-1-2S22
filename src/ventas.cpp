#include "ventas.h"
#include "./TDA-Clientes/clientes.h"
#include "./TDA-Vendedores/vendedores.h"
#include <stdio.h>
#include <string.h>

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
	printf("\nDeuda: ");
	scanf("%ld", &vendedor_aux.deuda);
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
	Vendedor vendedor_aux;
	copiar(vendedor_aux, recupera(opcion, vendedores));

	/*
		El error de segmentación al crear un cliente probablemente esté aquí, no se como
		resolverlo, pero sé que tiene que ver con un error en el manejo de memoria.
		Dado a este error, tampoco pude implementar la parte de cargar los clientes de
		cada vendedor que están escritos en el archivo .txt.
	*/

	inserta(cliente_aux, fin(vendedor_aux.clientes), vendedor_aux.clientes);
	suprime(opcion, vendedores);
	inserta(vendedor_aux, opcion, vendedores);
	//printf("Cliente creado! -> %s %s ", recupera(fin(recupera(opcion,vendedores).clientes),recupera(opcion,vendedores).clientes).nombre, recupera(fin(recupera(opcion,vendedores).clientes),recupera(opcion,vendedores).clientes).apellido);
}

void listarVendedores(cabeceraVendedor vendedores)
{
	printf("\n\nN°\tNombre\tApelli.\tTel.\tDir.\tEdad\tDeuda\tProf.\tRUT\tCuenta\n");
	printf("-------------------------------------------------------------------\n");
	for (int i = primero(vendedores); i < fin(vendedores); i = siguiente(i, vendedores))
	{
		Vendedor *vendedor_aux = new Vendedor;
		copiar(*vendedor_aux,recupera(i, vendedores));
		printf("%d\t%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%ld\n",
		i,
		vendedor_aux->nombre, 
		vendedor_aux->apellido, 
		vendedor_aux->telefono, 
		vendedor_aux->direccion, 
		vendedor_aux->edad, 
		vendedor_aux->deuda, 
		vendedor_aux->profesion, 
		vendedor_aux->rut,
		vendedor_aux->cuenta);
		delete vendedor_aux;
	}
}

void listarClientes(cabeceraCliente clientes)
{
	printf("\n\nN°\tNombre\tApelli.\tTel.\tDir.\tEdad\tDeuda\tProf.\tRUT\t#Cobro\n");
	printf("-------------------------------------------------------------------\n");
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
	printf("1\n");

	rewind(ventas);



	int i = 0;
	while (!feof(ventas))
	{
		
		Vendedor aux_vendedor;

		printf("%d\n", i);
		i++;
		char indicador[1];
		fscanf(ventas, "%s", indicador);
		if(!strcmp(indicador, "V"))
		{
			//escaneo de datos
			fscanf(ventas, "%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%ld\n", 
			aux_vendedor.nombre, 
			aux_vendedor.apellido, 
			&aux_vendedor.telefono, 
			aux_vendedor.direccion, 
			&aux_vendedor.edad, 
			&aux_vendedor.deuda, 
			aux_vendedor.profesion, 
			aux_vendedor.rut,
			&aux_vendedor.cuenta);

			//impresión por pantalla temporal
			printf("%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%ld", 
			aux_vendedor.nombre, 
			aux_vendedor.apellido,
			aux_vendedor.telefono, 
			aux_vendedor.direccion, 
			aux_vendedor.edad, 
			aux_vendedor.deuda, 
			aux_vendedor.profesion, 
			aux_vendedor.rut,
			aux_vendedor.cuenta);
		}
		if(!strcmp(indicador, "C"))
		{
			char rut[15];
			Cliente cliente_aux;
			fscanf(ventas, "%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%s\t%s",
			cliente_aux.nombre, 
			cliente_aux.apellido, 
			&cliente_aux.telefono, 
			cliente_aux.direccion, 
			&cliente_aux.edad, 
			&cliente_aux.deuda, 
			cliente_aux.profesion, 
			cliente_aux.rut,
			cliente_aux.fechaCobro,
			rut);
			inserta(cliente_aux, fin(aux_vendedor.clientes), aux_vendedor.clientes);
		}		
		
		inserta(aux_vendedor, fin(vendedores), vendedores);
	}
}

void borrarVendedor(cabeceraVendedor &vendedores)
{
	listarVendedores(vendedores);
	printf("Elija el vendedor que desea borrar: ");
	int numero;
	scanf("%d", &numero);
	suprime(numero, vendedores);
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
		}
		else
		{
			printf("No se encontró un vendedor con ese RUT.");
		}
		delete vendedor_aux;
	}
}

Vendedor buscarVendedorPorRut(char rut[], cabeceraVendedor vendedores)
{
	for (int i = primero(vendedores); i < fin(vendedores); i = siguiente(i, vendedores))
	{
		//muestra de datos por pantalla
		Vendedor vendedor_aux;
		copiar(vendedor_aux,recupera(i, vendedores));
		if (!strcmp(rut, vendedor_aux.rut))
		{
			return vendedor_aux;
		}
	}
	printf("No se encontró un vendedor con ese RUT.");
	Vendedor vendedor_nulo;
	return vendedor_nulo;
}

void guardar(FILE * ventas, cabeceraVendedor vendedores)
{
	freopen(NULL, "w+", ventas);
	for (int i = primero(vendedores); i < fin(vendedores); i = siguiente(i, vendedores))
	{
		//muestra de datos por pantalla
		Vendedor vendedor_aux;
		copiar(vendedor_aux,recupera(i, vendedores));
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
			Cliente cliente_aux;
			copiar(cliente_aux, recupera(j, vendedor_aux.clientes));
			fprintf(ventas, "\nC\t%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%s\t%s\n",
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