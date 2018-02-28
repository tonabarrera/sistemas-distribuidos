combo: combo.cpp PoligonoIrreg.o
	g++ combo.cpp PoligonoIrreg.o Coordenada.o -o combo
PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c 
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
