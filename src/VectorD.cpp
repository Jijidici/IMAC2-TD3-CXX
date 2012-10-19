#include <cstdlib>
#include <iostream>
#include "VectorD.hpp"

VectorD::VectorD(){
	this->coordonnee = NULL;
	this->nb_coord = 0;
	
	std::cout<<" > Constructeur par defaut"<<std::endl;
}

VectorD::VectorD(int nb_coordonnee){
	this->coordonnee = NULL;
	int i =0;
	
	this->coordonnee = new double[nb_coordonnee];
	for(i=0;i<nb_coordonnee;++i){
		this->coordonnee[i] = 0;
	}
	
	this->nb_coord = nb_coordonnee;
	
	std::cout<<" > Constructeur perso"<<std::endl;
}

VectorD::VectorD(const VectorD &v){
	int i =0;
	this->coordonnee = NULL;
	this->nb_coord = v.nb_coord;
	
	this->coordonnee = new double[this->nb_coord];
	for(i=0;i<this->nb_coord;++i){
		this->coordonnee[i] = v.coordonnee[i];
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