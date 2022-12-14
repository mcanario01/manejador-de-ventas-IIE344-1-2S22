#include "clientes.h"
#include <stdio.h>
#include <string.h>

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