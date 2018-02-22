prac_compo: prac_compo.o Rectangulo.o Coordenada.o
	g++ prac_compo.o Rectangulo.o Coordenada.o -o prac_compo
prac_compo.o: prac_compo.cpp
	g++ prac_compo.cpp -c
Rectangulo.o: Rectangulo.cpp Coordenada.o
	g++ Rectangulo.cpp -c
Coordenada.o: Coordenada.cpp
	g++ Coordenada.cpp -c
clean:
	rm *.o *.out prac_compo