#include <string.h>
#ifndef CLIENTE_STRUCT_H
#define CLIENTE_STRUCT_H

struct Cliente
{
    char nombre[15]; 
    char apellido[15]; 
    char rut[10];
    long telefono; 
    char direccion[50]; 
    int edad; 
    char profesion[30]; 
    long deuda;
    char fechaCobro[11];
    Cliente()
    {
        telefono = 0;
        edad = 0;
        deuda = 0;
    }
}; 

struct nodoCliente{
    struct Cliente dato; 
    struct nodoCliente* sgte;
	nodoCliente()
    {
		sgte=NULL;
	}
	nodoCliente(Cliente x)
    {
		nodoCliente();
		dato=x;
	}
}; 

struct cabeceraCliente{
    int largo; 
    struct nodoCliente* primero;
	cabeceraCliente()
    {
		primero=NULL;
	}
}; 

#endif