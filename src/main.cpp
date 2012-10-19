#include <cstdlib>
#include <iostream>
#include "VectorD.hpp"

int main(int argc, char** argv){	
	VectorD* v = createVectorsFromFile("inner_vector_data.txt");
	
	v[0].setACoordonnee(1, 13.23);
	v[0].setACoordonnee(3, 12.4);
	v[1].setACoordonnee(6, 2.105);
	v[1].setACoordonnee(0, 7.4);
	
	v[0].display();
	v[1].display();
	
	v[1].addWith(v[0]);
	v[1].display();
	
	std::cout<<">> Norme de V1 ["<<v[0].getNorm()<<"]"<<std::endl;
	std::cout<<">> Norme de V2 ["<<v[1].getNorm()<<"]"<<std::endl;
	
	v[0].normalize();
	v[1].normalize();
	std::cout<<">> Norme de V1 ["<<v[0].getNorm()<<"]"<<std::endl;
	std::cout<<">> Norme de V2 ["<<v[1].getNorm()<<"]"<<std::endl;
	
	saveAVectorD(v[0], "vector_data.txt");
	saveAVectorD(v[1], "vector_data.txt");
	
	delete[] v;
	
	return EXIT_SUCCESS;
}
