emisor: emisor.o PaqueteDatagrama.o SocketMulticast.o SocketDatagrama.o
	g++ emisor.o PaqueteDatagrama.o SocketMulticast.o SocketDatagrama.o -o ./emisor
receptor: receptor.o PaqueteDatagrama.o SocketMulticast.o SocketDatagrama.o
	g++ receptor.o PaqueteDatagrama.o SocketMulticast.o SocketDatagrama.o -o ./receptor
PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ -Wall -c PaqueteDatagrama.cpp
SocketMulticast.o: SocketMulticast.cpp
	g++ -Wall -c SocketMulticast.cpp
SocketDatagrama.o: SocketDatagrama.cpp
	g++ -Wall -c SocketDatagrama.cpp
emisor.o: emisor.cpp
	g++ -Wall -c emisor.cpp
receptor.o: receptor.cpp
	g++ -Wall -c receptor.cpp
clean:
	rm *.o *.out ./emisor ./receptor