#include <stdio.h>
#include <string.h>
#include "ventas.h"

//###################################################################################
//################# TDA de Lista (de Vendedores) ####################################
//###################################################################################

bool vacia(cabeceraVendedor vendedores)
{
	return fin(vendedores)==primero(vendedores);
}

int primero(cabeceraVendedor vendedores)
{
	return 1;
}

int anterior(int p, cabeceraVendedor vendedores)
{
	return p-1;
}

int siguiente(int p, cabeceraVendedor vendedores)
{
	return p+1;
}

int fin(cabeceraVendedor vendedores)
{
	int c=1;
	nodoVendedor*aux = vendedores.primero;
	while(aux!=NULL)
    {
		aux = aux->sgte;
		c++;
	}
	return c;
}

void inserta(Vendedor x, int p, cabeceraVendedor &vendedores)
{
	nodoVendedor* nuevo = new nodoVendedor(x);
	nodoVendedor* aux = vendedores.primero;
	if(p == primero(vendedores))
    {
		nuevo->sgte = vendedores.primero;
		vendedores.primero = nuevo;
	}
    else
    {
		for(int i = 0 ; i < p - 2 ; i++)
        {
			aux = aux->sgte;
		}
		nuevo->sgte = aux->sgte;
		aux->sgte = nuevo;
	}
}

Vendedor recupera(int p, cabeceraVendedor vendedores)
{
	nodoVendedor* aux = vendedores.primero;
	for(int i = 1 ; i < p ; i++)
    {
		aux = aux->sgte;
	}
	return aux->dato;
}

int localiza(Vendedor x , cabeceraVendedor vendedores)
{
	for(int i = primero(vendedores) ; i < fin(vendedores) ; i = siguiente(i, vendedores))
    {
		if(recupera(i, vendedores) == x)
        {
			return i;
		}
	}
	return fin(vendedores);
}

void suprime(int p, cabeceraVendedor &vendedores)
{

	nodoVendedor* aux = vendedores.primero;

	if(p == primero(vendedores))
    {
		vendedores.primero = aux->sgte;
	}
    else
    {
		nodoVendedor* aux2 = vendedores.primero;
		for(int i = 0 ; i < p - 2 ; i++)
        {
			aux2 = aux2->sgte;
		}
		aux = aux2->sgte;
		aux2->sgte = aux->sgte;
	}
	aux->sgte = NULL;
	delete aux;
}

void anula(cabeceraVendedor &vendedores)
{
	while(!vacia(vendedores))
    {
		suprime(primero(vendedores),vendedores);
    }
}

bool operator ==(Vendedor vendedor1, Vendedor vendedor2)
{
	return 
	vendedor1.cuenta == vendedor2.cuenta 
	&& !strcmp(vendedor1.nombre, vendedor2.nombre) 
	&& !strcmp(vendedor1.apellido, vendedor2.apellido) 
	&& !strcmp(vendedor1.rut, vendedor2.rut) 
	&& vendedor1.telefono == vendedor2.telefono 
	&& !strcmp(vendedor1.direccion, vendedor2.direccion) 
	&& vendedor1.edad == vendedor2.edad 
	&& !strcmp(vendedor1.profesion, vendedor2.profesion) 
	&& vendedor1.deuda == vendedor2.deuda;
} 

void copiar(Vendedor &vendedor1, Vendedor vendedor2)
{
	strcpy(vendedor1.nombre, vendedor2.nombre);
	strcpy(vendedor1.apellido, vendedor2.apellido);
	strcpy(vendedor1.direccion, vendedor2.direccion);
	strcpy(vendedor1.profesion, vendedor2.profesion);
	strcpy(vendedor1.rut, vendedor2.rut);
	vendedor1.cuenta = vendedor2.cuenta;
	vendedor1.telefono = vendedor2.telefono;
	vendedor1.edad = vendedor2.edad;
	vendedor1.deuda = vendedor2.deuda;
	vendedor1.clientes = vendedor2.clientes;
}

//###################################################################################
//################# TDA de Lista (de Clientes) ######################################
//###################################################################################

bool vacia(cabeceraCliente clientes)
{
	return fin(clientes)==primero(clientes);
}

int primero(cabeceraCliente clientes)
{
	return 1;
}

int anterior(int p, cabeceraCliente clientes)
{
	return p-1;
}

int siguiente(int p, cabeceraCliente clientes)
{
	return p+1;
}

int fin(cabeceraCliente clientes)
{
	int c=1;
	nodoCliente*aux = clientes.primero;
	while(aux!=NULL)
    {
		aux = aux->sgte;
		c++;
	}
	return c;
}

void inserta(Cliente x, int p, cabeceraCliente &clientes)
{
	nodoCliente* nuevo = new nodoCliente(x);
	nodoCliente* aux = clientes.primero;
	if(p == primero(clientes))
    {
		nuevo->sgte = clientes.primero;
		clientes.primero = nuevo;
	}
    else
    {
		for(int i = 0 ; i < p - 2 ; i++)
        {
			aux = aux->sgte;
		}
		nuevo->sgte = aux->sgte;
		aux->sgte = nuevo;
	}
}

Cliente recupera(int p, cabeceraCliente clientes)
{
	nodoCliente* aux = clientes.primero;
	for(int i = 1 ; i < p ; i++)
    {
		aux = aux->sgte;
	}
	return aux->dato;
}

int localiza(Cliente x , cabeceraCliente clientes)
{
	for(int i = primero(clientes) ; i < fin(clientes) ; i = siguiente(i, clientes))
    {
		if(recupera(i, clientes) == x)
        {
			return i;
		}
	}
	return fin(clientes);
}

void suprime(int p, cabeceraCliente &clientes)
{

	nodoCliente* aux = clientes.primero;

	if(p == primero(clientes))
    {
		clientes.primero = aux->sgte;
	}
    else
    {
		nodoCliente* aux2 = clientes.primero;
		for(int i = 0 ; i < p - 2 ; i++)
        {
			aux2 = aux2->sgte;
		}
		aux = aux2->sgte;
		aux2->sgte = aux->sgte;
	}
	aux->sgte = NULL;
	delete aux;
}

void anula(cabeceraCliente &clientes)
{
	while(!vacia(clientes))
    {
		suprime(primero(clientes),clientes);
    }
}

bool operator ==(Cliente cliente1, Cliente cliente2)
{
	return 
	!strcmp(cliente1.nombre, cliente2.nombre) 
	&& !strcmp(cliente1.apellido, cliente2.apellido) 
	&& !strcmp(cliente1.rut, cliente2.rut) 
	&& !strcmp(cliente1.rut, cliente2.rut) 
	&& cliente1.telefono == cliente2.telefono 
	&& !strcmp(cliente1.direccion, cliente2.direccion) 
	&& cliente1.edad == cliente2.edad 
	&& !strcmp(cliente1.profesion, cliente2.profesion) 
	&& cliente1.deuda == cliente2.deuda;
} 

void copiar(Cliente &cliente1, Cliente cliente2)
{
	strcpy(cliente1.nombre, cliente2.nombre);
	strcpy(cliente1.apellido, cliente2.apellido);
	strcpy(cliente1.rut, cliente2.rut);
	cliente1.telefono = cliente2.telefono;
	strcpy(cliente1.direccion, cliente2.direccion);
	cliente1.edad = cliente2.edad;
	strcpy(cliente1.profesion, cliente2.profesion);
	cliente1.deuda = cliente2.deuda;
	strcpy(cliente1.fechaCobro, cliente2.fechaCobro);
}

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
	inserta(cliente_aux, fin(*vendedor_aux.clientes), *vendedor_aux.clientes);
	suprime(opcion, vendedores);
	inserta(vendedor_aux, opcion, vendedores);
}

void listarVendedores(cabeceraVendedor vendedores)
{
	//apertura de archivo
	//bucle que itera hasta el fin de archivo
	const int numero_vendedores = fin(vendedores);
	for (int i = primero(vendedores); i < fin(vendedores); i = siguiente(i, vendedores))
	{
		//escaneo de datos
		//muestra de datos por pantalla
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

void recargarVendedores(FILE* ventas, cabeceraVendedor &vendedores)
{
	//suprime todas las entradas de la lista 'vendedores' sin borrar la lista.
	while(fin(vendedores) != 1)
	{
		suprime(fin(vendedores) - 1, vendedores);   
	}

	while (!feof(ventas))
	{
		char v[1];
		nodoVendedor * aux_vendedor = new nodoVendedor;
		//escaneo de datos
		fscanf(ventas, "%s\t%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%ld", 
		v,
		aux_vendedor->dato.nombre, 
		aux_vendedor->dato.apellido, 
		&aux_vendedor->dato.telefono, 
		aux_vendedor->dato.direccion, 
		&aux_vendedor->dato.edad, 
		&aux_vendedor->dato.deuda, 
		aux_vendedor->dato.profesion, 
		aux_vendedor->dato.rut,
		&aux_vendedor->dato.cuenta);
		if(!strcmp(v,"V"))
		{
			inserta(aux_vendedor->dato, fin(vendedores), vendedores);
		}
		//cierre de archivo y eliminación de objeto
		delete aux_vendedor;
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
	const int numero_vendedores = fin(vendedores);
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
	const int numero_vendedores = fin(vendedores);
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

void guardarVendedores(FILE * ventas, cabeceraVendedor vendedores)
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
	}
	freopen(NULL, "a+", ventas);
}