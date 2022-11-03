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
		5. Listar todos los vendedores.
		6. Crear un cliente.
		7. Buscar cliente por RUT.
		8. Listar clientes por vendedor.
		9. Guardar vendedores.
		10. Salir.
```
Puedes escoger cualquier opción listada escribiendo su número.

#### Crear un vendedor.
Crea un nuevo vendedor, te pedirá todos los datos correspondientes. Nota que **no puedes ingresar datos que contengan espacios**.
#### Borrar un vendedor.
Borra un vendedor, ingresa el número del vendedor que quieras borrar. También puedes elegir borrar un vendedor por RUT, en cuyo caso, pedirá un RUT válido. Nota que los RUT se escriben sin puntos ni guión y **tampoco dígito verificador**.
#### Buscar un vendedor por RUT.
Encuentra un vendedor dado un RUT que escribas. (La información de como se escriben los RUT están en el punto anterior)
#### Listar todos los vendedores.
Listará todos los vendedores actuales, escribirá por pantalla algo del tipo:
```bash
1       Marcela Ramirez 312983712       Mariano 20      0       Psico   239812  48102
2       Roberto Saldia  312987748       SantaRosa       21      3812    Saul    318278  319820
3       Martin  Canario 3981273 Puyehue 22      0       Telematica      3918273 3019289
```
Nota que cada dato está separado por un tab, pero los datos podrán verse desplazados según el largo de estos.
#### Crear un cliente
Crea un cliente en un vendedor que elijas, te pedirá los datos y finalmente debes ingresar el numero de vendedor.
#### Buscar un vendedor por RUT.
Encuentra un cliente dado un RUT que escribas. (La información de como se escriben los RUT están en el punto de arriba)
#### Listar clientes por vendedor.
Encuentra todos los clientes de un vendedor dado, debes ingresar el número de vendedor.
