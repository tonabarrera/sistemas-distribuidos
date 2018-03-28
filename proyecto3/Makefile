run: principal
	./principal > frecuencias.txt
principal: Archivo.o Semaforo.o principal.o
	g++ -std=c++11 -lpthread Archivo.o principal.o -o principal
Archivo.o: Archivo.cpp
	g++ -Wall -c Archivo.cpp
Semaforo.o: Semaforo.cpp
	g++ -Wall -c Semaforo.cpp
principal.o: principal.cpp
	g++ -Wall -c principal.cpp

clean:
	rm *.o ./principal