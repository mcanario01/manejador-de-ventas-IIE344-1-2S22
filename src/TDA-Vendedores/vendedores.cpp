#include <stdio.h>
#include <string.h>
#include "vendedores.h"

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
	vendedor1.clientes.primero = vendedor2.clientes.primero;
}