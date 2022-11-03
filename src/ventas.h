#include <stdio.h>
#include "ventasStruct.h"

bool vacia(cabeceraVendedor vendedor);
int primero(cabeceraVendedor vendedor);
int anterior(int p, cabeceraVendedor vendedor);
int siguiente(int p, cabeceraVendedor vendedor);
int fin(cabeceraVendedor vendedor);
void inserta(Vendedor x, int p, cabeceraVendedor &vendedor);
Vendedor recupera(int p, cabeceraVendedor vendedor);
int localiza(Vendedor x, cabeceraVendedor vendedor);
void suprime(int p, cabeceraVendedor&vendedor);
void anula(cabeceraVendedor&vendedor);

bool operator ==(Vendedor vendedor1, Vendedor vendedor2);
void copiar(Vendedor &vendedor1, Vendedor vendedor2);



bool vacia(cabeceraCliente clientes);
int primero(cabeceraCliente clientes);
int anterior(int p, cabeceraCliente clientes);
int siguiente(int p, cabeceraCliente clientes);
int fin(cabeceraCliente clientes);
void inserta(Cliente x, int p, cabeceraCliente &clientes);
Cliente recupera(int p, cabeceraCliente clientes);
int localiza(Cliente x, cabeceraCliente clientes);
void suprime(int p, cabeceraCliente&clientes);
void anula(cabeceraCliente&clientes);

bool operator ==(Cliente cliente1, Cliente cliente2);
void copiar(Cliente &cliente1, Cliente cliente2);