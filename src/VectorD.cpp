#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <limits>
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

void VectorD::allocateMemory(int nb_coordonnee){
	if(nb_coordonnee < 0){
		nb_coordonnee = 0;
	}
	
	this->nb_coord = nb_coordonnee;
	this->coordonnee = new double[this->nb_coord];
	
	for(int i=0;i<this->nb_coord;++i){
		this->coordonnee[i]=0;
	}
	
	std::cout<<" > Allocate "<<this->nb_coord<<" blocks of memory ."<<std::endl;
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

int VectorD::getNbCoord(){
	return this->nb_coord;
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

/*///////////////////////////////////////////////////////////////////////*/


void saveAVectorD(VectorD &vector_tab, char* file_path){
	if(file_path == NULL){
		std::cout<<"[=> In SAVEAVECTORD function, file path is incorrect |||| Inner Value Error."<<std::endl;
		return;
	}
	
	std::ofstream fic(file_path, std::ios::out | std::ios::app);
	if(!fic){
		std::cout<<"[=> In SAVEAVECTORD function, file can't be loaded |||| Extern Error."<<std::endl;
		return;
	}
	std::cout<<" > Fichier "<<file_path<<" is loaded"<<std::endl;
	
	fic<<vector_tab.getNbCoord()<<"\t";
	for(int i=0;i<vector_tab.getNbCoord();++i){
		fic<<vector_tab.getACoordonnee(i)<<"\t";
	}
	fic<<std::endl;
	
	fic.close();
}

VectorD* createVectorsFromFile(char* file_path){
	if(file_path == NULL){
		std::cout<<"[=> In CREATEVECTORSFROMFILE function, file path is incorrect |||| Inner Value Error."<<std::endl;
		return NULL;
	}
	
	std::ifstream fic(file_path, std::ios::in);
	if(!fic){
		std::cout<<"[=> In SAVEAVECTORD function, file can't be loaded |||| Extern Error."<<std::endl;
		return NULL;
	}
	std::cout<<" > Fichier "<<file_path<<" is loaded"<<std::endl;
	
	int nb_lines = 0;
	while(1){
		fic.ignore(std::numeric_limits<int>::max(), '\n');
		if(fic.eof()){
			break;
		}
		nb_lines++;
	}
	std::cout<<"||] NB LINES = "<<nb_lines<<std::endl;
	
	fic.clear();
	fic.seekg(0, std::ios::beg);
	
	VectorD* tab_vectors = new VectorD[nb_lines];
	
	for(int j=0;j<nb_lines;++j){
		int v_nb_coord = 0;
		fic >> v_nb_coord;
		tab_vectors[j].allocateMemory(v_nb_coord);
		
		std::cout<<v_nb_coord<<std::endl;
		for(int i=0;i<v_nb_coord;++i){
			double a_coord = 0.;
			fic >> a_coord;
			std::cout<<"|| "<<j+1<<"e ligne : "<<a_coord<<std::endl;
			tab_vectors[j].setACoordonnee(i, a_coord);
		}
	}
	
	fic.close();
	
	return tab_vectors;
}
