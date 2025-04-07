#ifndef MAGNETIC_FIELD_H
#define MAGNETIC_FIELD_H
#include "field.h"

class Magnetic_Field : public Field{
	
	private:
		double storedMagValue;
	public:
		Magnetic_Field();
		Magnetic_Field(double x,double y,double z);
				
		//func definitions
		void setE(double x, double y, double z);
		double calculateMagnitude()const;
		void unitVector(double unitVec[3]) const;
		double magFieldAmpereLaw(double current, double distance)const;
		double getstoredMagField() const;

		//getters
		double getX()const;
		double getY()const;
		double getZ()const;		
		
		friend std::ostream& operator<<(std::ostream& out, const Magnetic_Field& m);
};

#endif
