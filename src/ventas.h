#include <stdio.h>
#include "./TDA-Vendedores/vendedoresStruct.h"
#include "./TDA-Clientes/clientesStruct.h"

//###################################################################################
//################# Funciones de Manejador de vendedores ############################
//###################################################################################

/* 
* Nombre de la función: crearVendedor.
* Tipo de función: void.
* Parámetros: “vendedores” de tipo cabeceraVendedor.
* Dato de retorno: N/A
* Descripción de la función: 
	Pide los datos y crea una nueva entrada en la lista de vendedores.
*/
void crearVendedor(cabeceraVendedor &vendedores);

/* 
* Nombre de la función: crearClientes.
* Tipo de función: void.
* Parámetros: “clientes” de tipo cabeceraCliente.
* Dato de retorno: N/A
* Descripción de la función: 
	Pide los datos y crea una nueva entrada en la lista de Clientes en un vendedor en particular.
*/
void crearCliente(cabeceraVendedor &vendedores);

/* 
* Nombre de la función: listarVendedores.
* Tipo de función: void.
* Parámetros: “vendedores” de tipo cabeceraVendedor.
* Dato de retorno: N/A
* Descripción de la función: 
	La función listarVendedores lista todos los vendedores de una lista de vendedores.
*/
void listarVendedores(cabeceraVendedor vendedores);

/* 
* Nombre de la función: listarClientes.
* Tipo de función: void.
* Parámetros: “clientes” de tipo cabeceraCliente.
* Dato de retorno: N/A
* Descripción de la función: 
	La función listarClientes lista todos los Clientes de un vendedor determinado.
*/
void listarClientes(cabeceraCliente clientes);

/* 
* Nombre de la función: recargar.
* Tipo de función: void.
* Parámetros:   “ventas” de tipo FILE.
				"vendedores" de tipo cabeceraVendedor.
* Dato de retorno: N/A
* Descripción de la función: 
	La función recargar carga en una lista (cabeceraVendedor) todos los
	vendedores y los clientes de cada vendedor de un archivo en particular según
	un formato estipulado.
*/
void recargar(FILE* ventas, cabeceraVendedor &vendedores);

/* 
* Nombre de la función: borrar.
* Tipo de función: void.
* Parámetros: "vendedores" de tipo cabeceraVendedor.
* Dato de retorno: N/A
* Descripción de la función: 
	Borra un vendedor en particular de una lista de vendedores.
*/
void borrar(cabeceraVendedor &vendedores);

/* 
* Nombre de la función: borrar.
* Tipo de función: void.
* Parámetros: 	"clientes" de tipo cabeceraCliente.
				"vendedor" de tipo Vendedor.
* Dato de retorno: N/A
* Descripción de la función: 
	Borra un cliente en particular de una lista de clientes de un vendedor
	en particular.
*/
void borrar(Vendedor &vendedor, cabeceraCliente &clientes);

/* 
* Nombre de la función: borrarVendedorPorRut.
* Tipo de función: void.
* Parámetros:   “rut” de tipo char[].
				"vendedores" de tipo cabeceraVendedor.
* Dato de retorno: N/A
* Descripción de la función: 
	Borra un vendedor en particular de una lista de vendedores dado un RUT.
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
int buscarVendedorPorRut(char rut[], cabeceraVendedor vendedores);

/* 
* Nombre de la función: buscarClientePorRut.
* Tipo de función: Cliente.
* Parámetros:   “rut” de tipo char[].
				"Clientes" de tipo cabeceraCliente.
* Dato de retorno: "Cliente" de tipo Cliente.
* Descripción de la función: 
	Devuelve un Cliente coincidente filtrado por RUT en la lista de clientes de
	un vendedor en particular.
*/
int buscarClientePorRut(char rut[], cabeceraCliente clientes);

/* 
* Nombre de la función: listarClientesPorVendedor.
* Tipo de función: void.
* Parámetros:   “ventas” de tipo FILE.
				"vendedores" de tipo cabeceraVendedor.
* Dato de retorno: N/A
* Descripción de la función: 
	Sobreescribe el archivo en el que se está trabajando.
*/
void guardar(FILE * ventas, cabeceraVendedor vendedores);