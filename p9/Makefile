run: ejercicio
	./ejercicio
ejercicio: ejercicio7.o Semaforo.o
	g++ -std=c++11 -lpthread Semaforo.o ejercicio7.o -o ejercicio
ejercicio7.o: ejercicio7.cpp
	g++ -Wall -c ejercicio7.cpp
Semaforo.o:Semaforo.cpp 
	g++ -Wall -c Semaforo.cpp
clean:
	rm *.o *.out ./ejercicio
