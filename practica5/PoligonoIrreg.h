#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include "Coordenada.h"
#include <vector>
using namespace std;
class PoligonoIrreg{
	private:
		vector<Coordenada> vertices;
	public:
		PoligonoIrreg();
		
	void anadeVertice(Coordenada);
	void imprimeVertices();
};
#endif
