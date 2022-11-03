# Manejador de ventas.
Este programa es un administrador de vendedores y sus clientes. Maneja una lista de vendedores y los relaciona con clientes mediante uso de programación con estructuras de C++.

## Compilación.
Para compilar este programa, primero descarga o clona el repositorio con:
```bash
git clone https://github.com/mcanario01/manejador-de-ventas-IIE344-1-2S22
```
Luego, ingresa a la carpeta /src:
```bash
cd /src
```
Y compila:
```bash
make
```
El archivo makefile ejecutará automáticamente el programa con el archivo .txt por defecto, pero también puedes ejecutarlo cuando quieras con:
```bash
./manejador-de-vendedores <ruta de archivo .txt>
```

## Uso.
El funcionamiento del programa es bastante sencillo, para ejecutarlo usa:
```bash
./manejador-de-vendedores <ruta de archivo .txt>
```
Siendo la ruta del archivo .txt una ruta cualquiera a un archivo de dicha extensión.

### Funcionamiento.
Al iniciarse, el programa indicará lo siguiente:
```bash
------ Manejador de vendedores -------



        Elija la operación que desea realizar:

                1. Crear un vendedor.
                2. Borrar un vendedor.
                3. Borrar un vendedor por RUT.
                4. Buscar vendedor por RUT.
                5. Crear un cliente.
                6. Buscar cliente por RUT.
                7. Listar todos los vendedores.
                8. Listar clientes por vendedor.
                9. Guardar vendedores.
                10. Salir.
```
Puedes escoger cualquier opción listada escribiendo su número.