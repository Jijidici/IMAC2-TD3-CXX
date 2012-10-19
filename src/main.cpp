#include <cstdlib>
#include <iostream>
#include "VectorD.hpp"

int main(int argc, char** argv){
	VectorD v1(8);
	v1.setACoordonnee(5, 23.23);
	
	VectorD v2 = v1;
	
	v1.setACoordonnee(1, 6.4);
	v2.setACoordonnee(2, 7.4);
	v1.display();
	v2.display();
	
	
	return EXIT_SUCCESS;
}
