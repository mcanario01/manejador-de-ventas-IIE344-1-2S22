#include <stdio.h>
#include <string.h>
#include "ventas.h"

bool vacia(cabeceraVendedor vendedor)
{
	return fin(vendedor)==primero(vendedor);
}

int primero(cabeceraVendedor vendedor)
{
	return 1;
}

int anterior(int p, cabeceraVendedor vendedor)
{
	return p-1;
}

int siguiente(int p, cabeceraVendedor vendedor)
{
	return p+1;
}

int fin(cabeceraVendedor vendedor)
{
	int c=1;
	nodoVendedor*aux = vendedor.primero;
	while(aux!=NULL)
    {
		aux = aux->sgte;
		c++;
	}
	return c;
}

void inserta(Vendedor x, int p, cabeceraVendedor &vendedor)
{
	nodoVendedor* nuevo = new nodoVendedor(x);
	nodoVendedor* aux = vendedor.primero;
	if(p == primero(vendedor))
    {
		nuevo->sgte = vendedor.primero;
		vendedor.primero = nuevo;
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

Vendedor recupera(int p, cabeceraVendedor vendedor)
{
	nodoVendedor* aux = vendedor.primero;
	for(int i = 1 ; i < p ; i++)
    {
		aux = aux->sgte;
	}
	return aux->dato;
}

int localiza(Vendedor x , cabeceraVendedor vendedor)
{
	for(int i = primero(vendedor) ; i < fin(vendedor) ; i = siguiente(i, vendedor))
    {
		if(recupera(i, vendedor) == x)
        {
			return i;
		}
	}
	return fin(vendedor);
}

void suprime(int p, cabeceraVendedor &vendedor)
{

	nodoVendedor* aux = vendedor.primero;

	if(p == primero(vendedor))
    {
		vendedor.primero = aux->sgte;
	}
    else
    {
		nodoVendedor* aux2 = vendedor.primero;
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

void anula(cabeceraVendedor &vendedor)
{
	while(!vacia(vendedor))
    {
		suprime(primero(vendedor),vendedor);
    }
}

bool operator ==(Vendedor vendedor1, Vendedor vendedor2)
{
	return vendedor1.cuenta == vendedor2.cuenta && !strcmp(vendedor1.nombre, vendedor2.nombre) && !strcmp(vendedor1.apellido, vendedor2.apellido) && !strcmp(vendedor1.rut, vendedor2.rut) && !strcmp(vendedor1.rut, vendedor2.rut) && vendedor1.telefono == vendedor2.telefono && !strcmp(vendedor1.direccion, vendedor2.direccion) && vendedor1.edad == vendedor2.edad && !strcmp(vendedor1.profesion, vendedor2.profesion) && vendedor1.deuda == vendedor2.deuda;
} 

void copiarVendedor(Vendedor &vendedor1, Vendedor vendedor2)
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
}