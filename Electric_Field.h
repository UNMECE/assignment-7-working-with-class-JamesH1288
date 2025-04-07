#ifndef ELECTRICFIELD_H
#define ELECTRICFIELD_H
#include "field.h"
#include <iostream>
#include <cmath>

class Electric_Field: public Field {
	
	private:
		double storedElecValue;

	public:
		Electric_Field();
		~Electric_Field();

		Electric_Field(double x, double y, double z);

		Electric_Field(const Electric_Field& other);
		Electric_Field operator+(const Electric_Field& rhs);


		double calculateMagnitude()const;
		double calcInnerProduct() const;
		double elecFieldGaussLaw(double charge, double area);
		double elecFieldDistance(double distance,
		double charge, const double direction[3]);		

		void setE(double x,double y,double z);
		
		double getStoredElecValue()const;
		double getX()const;
		double getY()const;
		double getZ()const;

		friend std::ostream& operator<<(std::ostream& out,const Electric_Field& e);

};

#endif
