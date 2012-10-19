#include <cstdlib>
#include <iostream>
#include "VectorD.hpp"

int main(int argc, char** argv){
	VectorD v1(8);
	
	VectorD v2(8);
	
	v1.setACoordonnee(5, 23.23);
	v1.setACoordonnee(2, 6.4);
	v2.setACoordonnee(5, 42.23);
	v2.setACoordonnee(2, 7.4);
	
	v1.display();
	v2.display();
	
	v2.addWith(v1);
	v2.display();
	
	std::cout<<">> Norme de V1 ["<<v1.getNorm()<<"]"<<std::endl;
	std::cout<<">> Norme de V2 ["<<v2.getNorm()<<"]"<<std::endl;
	
	v1.normalize();
	v2.normalize();
	std::cout<<">> Norme de V1 ["<<v1.getNorm()<<"]"<<std::endl;
	std::cout<<">> Norme de V2 ["<<v2.getNorm()<<"]"<<std::endl;
	
	saveAVectorD(v1, "vector_data.txt");
	saveAVectorD(v2, "vector_data.txt");
	
	return EXIT_SUCCESS;
}
