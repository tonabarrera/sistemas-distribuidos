principal: Archivo.o principal.o
	g++ -std=c++11 -lpthread Archivo.o principal.o -o principal
Archivo.o: Archivo.cpp
	g++ -Wall -c Archivo.cpp
principal.o: principal.cpp
	g++ -Wall -c principal.cpp
clean:
	rm *.o ./principal