#include <stdio.h>
#include "ventasStruct.h"

//###################################################################################
//################# TDA de Lista (de Vendedores) ####################################
//###################################################################################

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

/* 
* Nombre de la función: copiar.
* Tipo de función: void.
* Parámetros:	“vendedor1” de tipo Vendedor.
				“vendedor2” de tipo Vendedor.
* Dato de retorno: N/A
* Descripción de la función: 
	Copia vendedor2 a vendedor1.
*/
void copiar(Vendedor &vendedor1, Vendedor vendedor2);

//###################################################################################
//################# TDA de Lista (de Clientes) ######################################
//###################################################################################

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

/* 
* Nombre de la función: copiar.
* Tipo de función: void.
* Parámetros:	“cliente1” de tipo Cliente.
				“cliente2” de tipo Cliente.
* Dato de retorno: N/A
* Descripción de la función: 
	Copia cliente2 a cliente1.
*/
void copiar(Cliente &cliente1, Cliente cliente2);

//###################################################################################
//################# Funciones de Manejador de vendedores ############################
//###################################################################################

/* 
* Nombre de la función: crearVendedor.
* Tipo de función: void.
* Parámetros: “ventas” de tipo FILE.
* Dato de retorno: N/A
* Descripción de la función: 
	La función crearVendedor escribe una nueva entrada en el archivo en cuestion en el que se 
	guarda la lista de vendedores.
*/
void crearVendedor(cabeceraVendedor &vendedores);

void crearCliente(cabeceraVendedor &vendedores);

/* 
* Nombre de la función: listarVendedores.
* Tipo de función: void.
* Parámetros: “ventas” de tipo FILE.
* Dato de retorno: N/A
* Descripción de la función: 
	La función listarVendedores lista todos los vendedores de un archivo determinado.
*/
void listarVendedores(cabeceraVendedor vendedores);

/* 
* Nombre de la función: recargarVendedores.
* Tipo de función: void.
* Parámetros:   “ventas” de tipo FILE.
				"vendedores" de tipo cabeceraVendedor.
* Dato de retorno: N/A
* Descripción de la función: 
	La función recargarVendedores carga en una lista (cabeceraVendedor) todos los
	vendedores de un archivo en particular.
*/
void recargarVendedores(FILE* ventas, cabeceraVendedor &vendedores);

/* 
* Nombre de la función: borrarVendedor.
* Tipo de función: void.
* Parámetros: "vendedores" de tipo cabeceraVendedor.
* Dato de retorno: N/A
* Descripción de la función: 
	Borra un vendedor en particular de una lista de vendedores y de el archivo en cuestión.
*/
void borrarVendedor(cabeceraVendedor &vendedores);

/* 
* Nombre de la función: borrarVendedorPorRut.
* Tipo de función: void.
* Parámetros:   “rut” de tipo char[].
				"vendedores" de tipo cabeceraVendedor.
* Dato de retorno: N/A
* Descripción de la función: 
	Borra un vendedor en particular de una lista de vendedores y de el archivo en cuestión.
*/
void borrarVendedorPorRut(char rut[], cabeceraVendedor &vendedores);

/* 
* Nombre de la función: buscarVendedorPorRut.
* Tipo de función: Vendedor.
* Parámetros:   “rut” de tipo char[].
				"vendedores" de tipo cabeceraVendedor.
* Dato de retorno: "vendedor" de tipo Vendedor.
* Descripción de la función: 
	Devuelve un vendedor coincidente filtrado por RUT.
*/
Vendedor buscarVendedorPorRut(char rut[], cabeceraVendedor vendedores);

/* 
* Nombre de la función: crearVendedor.
* Tipo de función: void.
* Parámetros: "vendedores" de tipo cabeceraVendedor.
* Dato de retorno: "cliente" de tipo Cliente
* Descripción de la función: 
	La función crearVendedor escribe una nueva entrada en el archivo en cuestion en el que se 
	guarda la lista de vendedores.
*/
Cliente buscarClientePorRut(char rut[], cabeceraCliente vendedores);

/* 
* Nombre de la función: listarClientesPorVendedor.
* Tipo de función: void.
* Parámetros: "vendedores" de tipo cabeceraVendedor.
* Dato de retorno: N/A
* Descripción de la función: 
	Lista todos los clientes de un vendedor en particular.
*/
void listarClientesPorVendedor(cabeceraVendedor vendedores);

/* 
* Nombre de la función: listarClientesPorVendedor.
* Tipo de función: void.
* Parámetros:   “ventas” de tipo FILE.
				"vendedores" de tipo cabeceraVendedor.
* Dato de retorno: N/A
* Descripción de la función: 
	Sobreescribe el archivo en el que se está trabajando.
*/
void guardarVendedores(FILE * ventas, cabeceraVendedor vendedores);
