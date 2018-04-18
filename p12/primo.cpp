#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	unsigned int n = 4294967291;
	
	unsigned int i = 1;
	
	
	for(i = 2; i<n; i++){
		if((n%i) == 0){
			cout << "no primo\n";
			exit(0);
			break;
		}			
	}
	
	cout << "primo\n";
}

// 45.3 %
// 45.3  