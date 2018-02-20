#include <iostream>
using namespace std;

int main(){
	const double PI = 3.1415926;
	int radio;
	float area;
	
	cout << "!!Hola!!!.\n";
	cout << "Declara el radio del círculo:  ";
	cin >> radio;
	//PI = 3.16;
	area = PI * radio * radio;
	
	cout << "El área es: " << area << "\n";
	return 0;
}
