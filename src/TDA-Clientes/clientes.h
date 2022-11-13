#include "clientesStruct.h"

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