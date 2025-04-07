#ifndef FIELD_H
#define FIELD_H

class Field {
	private:	
		double *value;
	public:
		//constructors
		Field();

		Field(double x, double y, double z);
		
		~Field();

		void setE(double x, double y, double z);

		void printMag()const;
		
		double getX()const;
		double getY()const;
		double getZ()const;
		
};

#endif
