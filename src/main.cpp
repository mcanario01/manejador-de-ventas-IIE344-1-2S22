#include <stdio.h>
#include "ventas.h"

void crearVendedor();


void listarVendedores(FILE* ventas, cabeceraVendedor &vendedores);

int main()
{
    cabeceraVendedor vendedor1;
    FILE * ventas = fopen("../dat/ventas.txt", "a+");
    crearVendedor(ventas);
    
    return 0;
}


void crearVendedor(FILE * ventas)
{
    //creación de un contacto auxiliar de forma dinamica
    nodoVendedor * aux_vendedor = new nodoVendedor;
    //petición de datos de nuevo contacto al usuario
    printf("Nombre: \n");
    scanf("%s", aux_vendedor->dato.nombre);
    printf("Apellido: \n");
    scanf("%s", aux_vendedor->dato.apellido);
    printf("Número telefónico: \n");
    scanf("%d", &aux_vendedor->dato.telefono);
    printf("Direccion: \n");
    scanf("%s", aux_vendedor->dato.direccion);
    printf("Edad: \n");
    scanf("%s", aux_vendedor->dato.edad);
    printf("Deuda: \n");
    scanf("%s", aux_vendedor->dato.deuda);
    printf("Profesión: \n");
    scanf("%s", aux_vendedor->dato.profesion);
    printf("RUT: \n");
    scanf("%s", aux_vendedor->dato.rut);
    //escritura de archivo según los datos pedidos
    fprintf(ventas, "\n%s %s %l %s %d %l %s %s", aux_vendedor->dato.nombre, aux_vendedor->dato.apellido, &aux_vendedor->dato.telefono, aux_vendedor->dato.direccion, aux_vendedor->dato.edad, aux_vendedor->dato.deuda, aux_vendedor->dato.profesion, aux_vendedor->dato.rut);
    //cierre de archivo y eliminación de objeto
    delete aux_vendedor;
    fclose(ventas);
}

void listarVendedores(FILE* ventas)
{
    //apertura de archivo
    //bucle que itera hasta el fin de archivo
    while (!feof(ventas))
    {
        nodoVendedor * aux_vendedor = new nodoVendedor;
        //escaneo de datos
        fscanf(ventas, "\n%s %s %l %s %d %l %s %s", aux_vendedor->dato.nombre, aux_vendedor->dato.apellido, &aux_vendedor->dato.telefono, aux_vendedor->dato.direccion, &aux_vendedor->dato.edad, &aux_vendedor->dato.deuda, aux_vendedor->dato.profesion, aux_vendedor->dato.rut);
        //muestra de datos por pantalla
        printf("\t%s\t%s\t%l\t%s\t%d\t%l\t%s\t%s\n", aux_vendedor->dato.nombre, aux_vendedor->dato.apellido, &aux_vendedor->dato.telefono, aux_vendedor->dato.direccion, aux_vendedor->dato.edad, aux_vendedor->dato.deuda, aux_vendedor->dato.profesion, aux_vendedor->dato.rut);
        //cierre de archivo y eliminación de objeto
        delete aux_vendedor;
    }
    fclose(ventas);
}

void recargarVendedores(FILE* ventas, cabeceraVendedor &vendedores)
{
    //suprime todas las entradas de la lista 'vendedores' sin borrar la lista.
    while(fin(vendedores) == 1)
    {
        suprime(fin(vendedores) - 1, vendedores);   
    }
    
    while (!feof(ventas))
    {
        nodoVendedor * aux_vendedor = new nodoVendedor;
        //escaneo de datos
        fscanf(ventas, "\n%s %s %l %s %d %l %s %s", aux_vendedor->dato.nombre, aux_vendedor->dato.apellido, &aux_vendedor->dato.telefono, aux_vendedor->dato.direccion, &aux_vendedor->dato.edad, &aux_vendedor->dato.deuda, aux_vendedor->dato.profesion, aux_vendedor->dato.rut);
        inserta(aux_vendedor->dato, fin(vendedores), vendedores);
        //cierre de archivo y eliminación de objeto
        delete aux_vendedor;
    }
    fclose(ventas);
}