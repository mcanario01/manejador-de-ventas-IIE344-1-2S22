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
void copiarVendedor(Vendedor &vendedor1, Vendedor vendedor2);
/*
bool vacia(cabeceraCliente lista);
int primero(cabeceraCliente lista);
int anterior(int p, cabeceraCliente lista);
int siguiente(int p, cabeceraCliente lista);
int fin(cabeceraCliente lista);
void inserta(Cliente x, int p, cabeceraCliente &lista);
Cliente recupera(int p, cabeceraCliente lista);
int localiza(Cliente x, cabeceraCliente lista);
void imprime(cabeceraCliente lista);
void suprime(int p, cabeceraCliente &lista);
void anula(cabeceraCliente &lista);
*/