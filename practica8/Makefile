run: principal
	./principal origen.txt destino.txt
principal: Archivo.o principal.o
	g++ Archivo.o principal.o -o principal
Archivo.o: Archivo.cpp
	g++ -Wall -c Archivo.cpp
principal.o: principal.cpp
	g++ -Wall -c principal.cpp

clean:
	rm *.o ./principal