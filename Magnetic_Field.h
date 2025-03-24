#ifndef MAGNETIC_FIELD_H
#define MAGNETIC_FIELD_H

class Magnetic_Field {
	
	private:
		double *E;
	public:
		Magnetic_Field();
		Magnetic_Field(double x,double y,double z);
		~Magnetic_Field();

		void setE(double x, double y, double z);
		double calculateMagnitude()const;
		void unitVector(double unitVec[3]) const;
		double getX()const;
		double getY()const;
		double getZ()const;		
		

};

#endif
