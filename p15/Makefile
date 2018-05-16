run: cliente
	./cliente
cliente: cliente.o paquetedatagrama.o socketdatagrama.o Solicitud.o
	g++ socketdatagrama.o Solicitud.o paquetedatagrama.o cliente.o -o cliente
cliente.o: cliente.cpp
	g++ -Wall -c cliente.cpp
paquetedatagrama.o: paquetedatagrama.cpp
	g++ -Wall -c paquetedatagrama.cpp
socketdatagrama.o:socketdatagrama.cpp 
	g++ -Wall -c socketdatagrama.cpp
Solicitud.o: Solicitud.cpp
	gcc -Wall -c Solicitud.cpp
clean:
	rm *.o *.out ./cliente