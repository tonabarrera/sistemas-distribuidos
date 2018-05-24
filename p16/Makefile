run: cliente
	./cliente
cliente: cliente.o Paquetedatagrama.o Socketdatagrama.o Solicitud.o
	g++ Socketdatagrama.o Solicitud.o Paquetedatagrama.o cliente.o -o cliente
cliente.o: cliente.cpp
	g++ -Wall -c cliente.cpp
Paquetedatagrama.o: Paquetedatagrama.cpp
	g++ -Wall -c Paquetedatagrama.cpp
Socketdatagrama.o:Socketdatagrama.cpp 
	g++ -Wall -c Socketdatagrama.cpp
Solicitud.o: Solicitud.cpp
	gcc -Wall -c Solicitud.cpp
clean:
	rm *.o *.out ./cliente