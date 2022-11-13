#include <string.h>
#ifndef VENDEDOR_STRUCT_H
#define VENDEDOR_STRUCT_H

#include "../TDA-Clientes/clientesStruct.h"

struct Vendedor
{
    long cuenta; 
    char nombre[15]; 
    char apellido[15]; 
    char rut[10];
    long telefono; 
    char direccion[50]; 
    int edad; 
    char profesion[30]; 
    long deuda;
    struct cabeceraCliente clientes;
    Vendedor()
    {
        cuenta = 0;
        telefono = 0;
        edad = 0;
        deuda = 0;
    }
};

struct cabeceraVendedor
{
    int largo; 
    struct nodoVendedor* primero;
	cabeceraVendedor()
    {
		primero=NULL;
	}
};

struct nodoVendedor
{
    struct Vendedor dato; 
    struct nodoVendedor* sgte;
	nodoVendedor()
    {
		sgte=NULL;
	}
	nodoVendedor(Vendedor x)
    {
		nodoVendedor();
		dato=x;
	}
};

#endif
