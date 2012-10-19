#include <cstdlib>
#include <iostream>
#include <cmath>
#include "VectorD.hpp"

VectorD::VectorD(){
	this->coordonnee = NULL;
	this->nb_coord = 0;
	
	std::cout<<" > Constructeur par defaut"<<std::endl;
}

VectorD::VectorD(int nb_coordonnee){
	this->coordonnee = NULL;
	int i =0;
	
	if(nb_coordonnee <= 0){
		std::cout<<" > Valeurs d'entree incorrecte pour constructeur VectorD(size)"<<std::endl;
		this->nb_coord = 0;
		return;
	}
	
	this->nb_coord = nb_coordonnee;
	this->coordonnee = new double[nb_coordonnee];
	for(i=0;i<nb_coordonnee;++i){
		this->coordonnee[i] = 0;
	}
	
	std::cout<<" > Constructeur perso"<<std::endl;
}

VectorD::VectorD(const VectorD &v){
	int i =0;
	this->coordonnee = NULL;
	this->nb_coord = v.nb_coord;
	
	this->coordonnee = new double[this->nb_coord];
	if(this->nb_coord != 0){
		for(i=0;i<this->nb_coord;++i){
			this->coordonnee[i] = v.coordonnee[i];
		}
	}
	
	std::cout<<" > Constructeur par recopie"<<std::endl;
}

double VectorD::getACoordonnee(int id){
	if(id < 0){
		id = 0;
	}
	
	if(id >= this->nb_coord){
		id = this->nb_coord;
	}
	
	return this->coordonnee[id];
}

void VectorD::setACoordonnee(int id, double iCoord){
	if(id<0 || id>= this->nb_coord){
		std::cout<<"Identifiant incorrect pour la modification de valeurs dans le vecteur."<<std::endl;
		return;
	}
	
	this->coordonnee[id] = iCoord;
}

void VectorD::display(){
	int i=0;
	
	for(i=0;i<this->nb_coord;++i){
		std::cout<<this->coordonnee[i]<<"\t";
	}
	std::cout<<std::endl;
}

float VectorD::getNorm(){
	float norm_result = 0;
	int i=0;
	
	for(i=0;i<this->nb_coord;++i){
		norm_result += this->coordonnee[i]*this->coordonnee[i];
	}
	return sqrt(norm_result);
}

void VectorD::normalize(){
	float vec_norm = this->getNorm();
	int i = 0;
	
	if(vec_norm == 0){
		std::cout<<"[=> In NORMALIZE function, vector norm is equal to 0 |||| Math Error."<<std::endl;
		return;
	}
	
	for(i=0;i<this->nb_coord;++i){
		this->coordonnee[i] = this->coordonnee[i]/vec_norm;
	}
}


void VectorD::addWith(const VectorD &v){
	int i = 0;
	
	if(this->nb_coord != v.nb_coord){
		std::cout<<"[=> In ADDWITH function, vectors haven't got the same size |||| Math Error."<<std::endl;
		return;
	}
	
	for(i=0;i<this->nb_coord;++i){
		this->coordonnee[i] += v.coordonnee[i];
	}
}

VectorD::~VectorD(){
	delete[] this->coordonnee;
	this->coordonnee = NULL;
	std::cout<<"I broke it! Violently!!!"<<std::endl;
}
