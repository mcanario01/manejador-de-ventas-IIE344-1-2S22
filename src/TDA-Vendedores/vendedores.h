#include "vendedoresStruct.h"

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
