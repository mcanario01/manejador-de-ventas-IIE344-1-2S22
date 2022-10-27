#ifndef VENDEDOR_STRUCT_H
#define VENDEDOR_STRUCT_H

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
    //struct cabeceraCliente* clientes;
};

struct cabeceraVendedor
{
    int largo; 
    struct nodoVendedor* primero;
	cabeceraVendedor(){
		primero=NULL;
	}
};

struct nodoVendedor
{
    struct Vendedor dato; 
    struct nodoVendedor* sgte;
	nodoVendedor(){
		sgte=NULL;
	}
	nodoVendedor(Vendedor x){
		nodoVendedor();
		dato=x;
	}
};

#endif

/*
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
}; 

struct nodoCliente{
    struct Cliente dato; 
    struct nodoCliente* sgte;
	nodoCliente(){
		sgte=NULL;
	}
	nodoCliente(Vendedor x){
		nodoCliente();
		dato=x;
	}
}; 

struct cabeceraCliente{
    int largo; 
    struct nodoCliente* primero;
	cabeceraCliente(){
		primero=NULL;
	}
}; 

#endif

*/
