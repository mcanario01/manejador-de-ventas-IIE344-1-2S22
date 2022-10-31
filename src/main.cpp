/* Universidad de La Frontera
* Ingeniería Civil Telemática
*
* IIE-344 Estructura de Datos y Algoritmos
*
* Tarea 2
*
* Autor: Martin Tomás Canario Dauros (m.canario01@ufromail.cl)
* 
* Fecha: 28 de octubre de 2022.
* 
* Descripción general del programa:
* manejador-de-ventas es un programa que se utilizaría para mantener una lista ordenada
* que relacione vendedores con sus clientes, dicha lista tendrá información como los datos
* personales tanto de vendedores como clientes y también sus deudas y cobros.
*/

#include <stdio.h>
#include <string.h>
#include "ventas.h"

using namespace std;

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

/* 
* Nombre de la función: listarVendedores.
* Tipo de función: void.
* Parámetros: “ventas” de tipo FILE.
* Dato de retorno: N/A
* Descripción de la función: 
    La función listarVendedores lista todos los vendedores de un archivo determinado.
*/
void listarVendedores(cabeceraVendedor vendedor);

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
* Parámetros:   “ventas” de tipo FILE.
                "vendedores" de tipo cabeceraVendedor.
* Dato de retorno: N/A
* Descripción de la función: 
    Borra un vendedor en particular de una lista de vendedores y de el archivo en cuestión.
*/
void borrarVendedor(cabeceraVendedor &vendedores);

/* 
* Nombre de la función: crearVendedor.
* Tipo de función: void.
* Parámetros:   “ventas” de tipo FILE.
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
//Cliente buscarClientePorRut(cabeceraCliente vendedores);

/* 
* Nombre de la función: listarClientesPorVendedor.
* Tipo de función: void.
* Parámetros: "vendedores" de tipo cabeceraVendedor.
* Dato de retorno: N/A
* Descripción de la función: 
    Lista todos los clientes de un vendedor en particular.
*/
//void listarClientesPorVendedor(cabeceraVendedor vendedores);

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

int main(int argc, char *argv[])
{
    /* 
    printf("\n\n------ Manejador de vendedores -------\n\n");
    printf("Vendedores actuales:\n");
    printf("--------------------\n\n");
    FILE * ventas = fopen(argv[1], "a+");
    cabeceraVendedor vendedores;
    recargarVendedores(ventas, vendedores);
    listarVendedores(vendedores);
    bool termino = 1;
    while (termino)
    {    
        printf("\n\n\tElija la operación que desea realizar:\n\n");
        printf("\t\t1. Crear un vendedor.\n");
        printf("\t\t2. Borrar un vendedor.\n");
        printf("\t\t3. Borrar un vendedor por RUT.\n");
        printf("\t\t4. Buscar vendedor por RUT.\n");
        printf("\t\t5. Buscar cliente por RUT.\n");
        printf("\t\t6. Listar todos los vendedores.\n");
        printf("\t\t7. Listar clientes por vendedor.\n");
        printf("\t\t8. Guardar vendedores.\n");
        printf("\t\t9. Salir.\n");
        printf("\tOpción:");
        int opcion;
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
            {
                crearVendedor(vendedores);
                break;
            }
            case 2:
            {
                borrarVendedor(vendedores);
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                break;
            }
            case 8:
            {
                guardarVendedores(ventas, vendedores);
                break;
            }
            case 9:
            {
                printf("\n¿Desea guardar los cambios? (1. Si / 2. No): ");
                int guardar_cambios;
                scanf("%d", &guardar_cambios);
                if (guardar_cambios == 1)
                {
                    guardarVendedores(ventas, vendedores);
                }
                termino = 0;
                break;
            }
            
            default:
            {
                printf("Opción inválida.");
                break;
            }
        }
    } */


    FILE * ventas = fopen(argv[1], "a+");
    cabeceraVendedor vendedores;
    crearVendedor(vendedores);
    listarVendedores(vendedores);
    guardarVendedores(ventas, vendedores);

    fclose(ventas);
    return 0;
}


void crearVendedor(cabeceraVendedor &vendedores)
{
    //petición de datos de nuevo contacto al usuario
    Vendedor vendedor_aux;
    printf("\nNombre: ");
    scanf("%s", vendedor_aux.nombre);
    printf("\nApellido: ");
    scanf("%s", vendedor_aux.apellido);
    printf("\nNúmero telefónico: ");
    scanf("%ld", &vendedor_aux.telefono);
    printf("\nDireccion: ");
    scanf("%s", vendedor_aux.direccion);
    printf("\nEdad: ");
    scanf("%d", &vendedor_aux.edad);
    printf("\nDeuda: ");
    scanf("%ld", &vendedor_aux.deuda);
    printf("\nProfesión: ");
    scanf("%s", vendedor_aux.profesion);
    printf("\nRUT: ");
    scanf("%s", vendedor_aux.rut);
    printf("\nCuenta: ");
    scanf("%ld", &vendedor_aux.cuenta);
    inserta(vendedor_aux, fin(vendedores), vendedores);
    //escritura de archivo según los datos pedidos
}

void listarVendedores(cabeceraVendedor vendedor)
{
    //apertura de archivo
    //bucle que itera hasta el fin de archivo
    const int numero_vendedores = fin(vendedor);
    for (int i = primero(vendedor); i < fin(vendedor); i = siguiente(i, vendedor))
    {
        //escaneo de datos
        //muestra de datos por pantalla
        Vendedor *vendedor_aux = new Vendedor;
        copiarVendedor(*vendedor_aux,recupera(i, vendedor));
        printf("%d\t%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%ld\n",
        i,
        vendedor_aux->nombre, 
        vendedor_aux->apellido, 
        vendedor_aux->telefono, 
        vendedor_aux->direccion, 
        vendedor_aux->edad, 
        vendedor_aux->deuda, 
        vendedor_aux->profesion, 
        vendedor_aux->rut,
        vendedor_aux->cuenta);
        delete vendedor_aux;
    }
}

void recargarVendedores(FILE* ventas, cabeceraVendedor &vendedores)
{
    //suprime todas las entradas de la lista 'vendedores' sin borrar la lista.
    while(fin(vendedores) != 1)
    {
        suprime(fin(vendedores) - 1, vendedores);   
    }

    while (!feof(ventas))
    {
        char v[1];
        nodoVendedor * aux_vendedor = new nodoVendedor;
        //escaneo de datos
        fscanf(ventas, "%s\t%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%ld", 
        v,
        aux_vendedor->dato.nombre, 
        aux_vendedor->dato.apellido, 
        &aux_vendedor->dato.telefono, 
        aux_vendedor->dato.direccion, 
        &aux_vendedor->dato.edad, 
        &aux_vendedor->dato.deuda, 
        aux_vendedor->dato.profesion, 
        aux_vendedor->dato.rut,
        &aux_vendedor->dato.cuenta);
        if(!strcmp(v,"V"))
        {
            inserta(aux_vendedor->dato, fin(vendedores), vendedores);
        }
        //cierre de archivo y eliminación de objeto
        delete aux_vendedor;
    }
}


void borrarVendedor(cabeceraVendedor &vendedores)
{
    listarVendedores(vendedores);
    printf("Elija el vendedor que desea borrar: ");
    int numero;
    scanf("%d", &numero);
    suprime(numero, vendedores);
}

void guardarVendedores(FILE * ventas, cabeceraVendedor vendedores)
{
    freopen(NULL, "w+", ventas);
    for (int i = primero(vendedores); i < fin(vendedores); i = siguiente(i, vendedores))
    {
        //muestra de datos por pantalla
        Vendedor vendedor_aux;
        copiarVendedor(vendedor_aux,recupera(i, vendedores));
        fprintf(ventas, "\nV\t%s\t%s\t%ld\t%s\t%d\t%ld\t%s\t%s\t%ld", 
        vendedor_aux.nombre, 
        vendedor_aux.apellido, 
        vendedor_aux.telefono, 
        vendedor_aux.direccion, 
        vendedor_aux.edad, 
        vendedor_aux.deuda, 
        vendedor_aux.profesion, 
        vendedor_aux.rut,
        vendedor_aux.cuenta);
    }
    freopen(NULL, "a+", ventas);
}