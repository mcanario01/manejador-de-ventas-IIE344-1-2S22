# Manejador de ventas.
Este programa es un administrador de vendedores y sus clientes. Maneja una lista de vendedores y los relaciona con clientes mediante uso de programación con estructuras de C++.

## Compilación.
Para compilar este programa, primero descarga o clona el repositorio con:
```bash
git clone https://github.com/mcanario01/manejador-de-ventas-IIE344-1-2S22
```
Luego, ingresa a la carpeta /manejador-de-ventas-IIE344-1-2S22/src:
```bash
cd /manejador-de-ventas-IIE344-1-2S22/src
```
Y compila:
```bash
make
```
Puedes compilar y ejecutar con el .txt por defecto con:
```bash
make run
```

## Uso.
El funcionamiento del programa es bastante sencillo, para ejecutarlo usa:
```bash
./manejador-de-vendedores <ruta de archivo .txt>
```
Siendo la `<ruta del archivo .txt>` una ruta cualquiera a un archivo de dicha extensión (No inluye los corchetes).

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
		7. Borrar un cliente.
		8. Buscar cliente por RUT.
		9. Listar clientes por vendedor.

		10. Guardar.
		11. Salir.
```
Puedes escoger cualquier opción listada escribiendo su número.
***
#### 1) Crear un vendedor.
Crea un nuevo vendedor, te pedirá todos los datos correspondientes. [Ver recomendaciones.](https://github.com/mcanario01/manejador-de-ventas-IIE344-1-2S22#recomendaciones)
***
#### 2) Borrar un vendedor.
Borra un vendedor, ingresa el número del vendedor que quieras borrar. 
***
#### 3) Buscar un vendedor por RUT.
Encuentra un vendedor dado un RUT que escribas. [Ver recomendaciones.](https://github.com/mcanario01/manejador-de-ventas-IIE344-1-2S22#recomendaciones)
***
#### 4) Borrar un vendedor por RUT.
Elimina un vendedor dado un RUT que escribas. [Ver recomendaciones.](https://github.com/mcanario01/manejador-de-ventas-IIE344-1-2S22#recomendaciones)
***
#### 5) Listar todos los vendedores.
Listará todos los vendedores actuales, escribirá por pantalla algo del tipo:
```bash
N°	Nombre	Apelli.	Telefono	Direcc. Edad	Deuda	Profes.	RUT		Cuenta
-------------------------------------------------------------------------------------------
1	Marcela	Ramirez	31298371	Mariano	20	0	Psico	23981266	481020
2	Roberto	Saldia	31298774	SantaRo	21	3812	Saul	31827855	319820
3	Martin	Canario	39812735	Puyehue	22	0	Telemat	39182755	019289
```
Nota que cada dato está separado por un tab, pero los datos podrán verse desplazados según el largo de estos (Ver recomendaciones para evitar descuadres).
***
#### 6) Crear un cliente
Crea un cliente en un vendedor que elijas, te pedirá los datos y finalmente debes ingresar el numero de vendedor. [Ver recomendaciones.](https://github.com/mcanario01/manejador-de-ventas-IIE344-1-2S22#recomendaciones)
***
#### 7) Borrar un cliente.
Borra un cliente, ingresa el número del cliente que quieras borrar, luego de elegir un vendedor. 
***
#### 8) Buscar un cliente por RUT.
Encuentra un cliente dado un RUT que escribas en una lista de clientes de un vendedor en particular. [Ver recomendaciones.](https://github.com/mcanario01/manejador-de-ventas-IIE344-1-2S22#recomendaciones)
***
#### 9) Listar clientes por vendedor.
Encuentra todos los clientes de un vendedor dado, debes ingresar el número de vendedor.
***
## Recomendaciones: 
* Los RUT se escriben sin puntos guión **ni dígito verificador**. *Ej: 11222333*.
* **No puedes ingresar datos que contengan espacios.**
* No es recomendable escribir Nombre, Apellido, Dirección (Direc.) ni Profesión (Profes.) con **más de 7 carácteres**.