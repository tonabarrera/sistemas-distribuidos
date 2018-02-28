#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include "Coordenada.h"
#include <vector>
#include "math.h"
using namespace std;


class PoligonoIrreg{
	private:
		vector<Coordenada> vertices;
	public:
		PoligonoIrreg(int = 0);
		
	void anadeVertice(Coordenada);
	void imprimeVertices();

    void ordenarVertices();

    static bool comparacion(Coordenada a, Coordenada b);

	
};
#endif
