all:
	g++ -c ./TDA-Clientes/clientes.cpp
	g++ -c ./TDA-Vendedores/vendedores.cpp
	g++ -c ventas.cpp
	g++ -c main.cpp
	g++ -o manejador-de-vendedores clientes.o vendedores.o ventas.o main.o
	rm *.o

run:
	g++ -c ./TDA-Clientes/clientes.cpp
	g++ -c ./TDA-Vendedores/vendedores.cpp
	g++ -c ventas.cpp
	g++ -c main.cpp
	g++ -o manejador-de-vendedores clientes.o vendedores.o ventas.o main.o
	rm *.o
	./manejador-de-vendedores ../dat/ventas.txt