#ifndef ELECTRICFIELD_H
#define ELECTRICFIELD_H

class Electric_Field {
	
	private:
		double *E;

	public:
		Electric_Field();
		~Electric_Field();

		Electric_Field(double x, double y, double z);
		double calculateMagnitude()const;
		double calcInnerProduct() const;
		
		void setE(double x,double y,double z);
		double getX()const;
		double getY()const;
		double getZ()const;

};

#endif
