#ifndef __VECTORD__
#define __VECTORD__

class VectorD{
	private: 
		double* coordonnee;
		int nb_coord;
		
	public:
		VectorD();
		VectorD(int nb_coordonnee);
		VectorD(const VectorD &v);
		
		double getACoordonnee(int id);
		void setACoordonnee(int id, double iCoord);
		
		void display();
		float getNorm();
		void normalize();
		void addWith(const VectorD &v);
		
		~VectorD();
};

#endif
