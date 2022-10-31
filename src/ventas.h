#include <stdio.h>
#include "ventasStruct.h"

bool vacia(cabeceraVendedor lista);
int primero(cabeceraVendedor lista);
int anterior(int p, cabeceraVendedor lista);
int siguiente(int p, cabeceraVendedor lista);
int fin(cabeceraVendedor lista);
void inserta(Vendedor x, int p, cabeceraVendedor &lista);
Vendedor recupera(int p, cabeceraVendedor lista);
int localiza(Vendedor x, cabeceraVendedor lista);
//void imprime(cabeceraVendedor lista);
void suprime(int p, cabeceraVendedor&lista);
void anula(cabeceraVendedor&lista);

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