run: servidor
	./servidor
servidor: servidor.o gfx.o PaqueteDatagrama.o SocketDatagrama.o
	g++ SocketDatagrama.o gfx.o PaqueteDatagrama.o servidor.o -o servidor -lX11 -lm
servidor.o: servidor.cpp
	g++ -Wall -c servidor.cpp
PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ -Wall -c PaqueteDatagrama.cpp
SocketDatagrama.o:SocketDatagrama.cpp 
	g++ -Wall -c SocketDatagrama.cpp
gfx.o: gfx.c
	gcc -Wall -c gfx.c
clean:
	rm *.o *.out ./cliente ./servidor