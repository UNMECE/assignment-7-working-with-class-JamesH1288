#include <iostream>
#include <cmath>
#include "Magnetic_Field.h"
#include "Electric_Field.h"

using namespace std;

//field class definitions
Field::Field(){
	value = new double[3]{0,0,0};
}

Field::Field(double x,double y,double z){
	value = new double[3]{x,y,z};
}

Field::~Field(){
	delete[] value;
}

void Field::setE(double x, double y, double z){
	value[0] = x;
	value[1] = y;
	value[2] = z;
}

void Field::printMag() const{
	std::cout 	<<"components"
			<< value[0] << ", "
			<< value[1] << ", "
			<< value[2] << 
			std::endl;
}

double Field::getX() const{
	return value[0];
}	
double Field::getY() const{
	return value[1];	
}
double Field::getZ() const{
	return value[2];
}


///////////////////////////////////////////////////////////////////////

Electric_Field::Electric_Field(): Field(0,0,0){
	storedElecValue = 0;
}

Electric_Field::Electric_Field(double x,double y,double z){
	storedElecValue = 0;
}

//memory freeing
Electric_Field::~Electric_Field(){}

//magnitude formula function
double Electric_Field::calculateMagnitude()const{
	return std::
		sqrt
		(
		(getX()*getX()) +
		(getY()*getY()) +
		(getZ()*getZ())
		);
}

double Electric_Field::calcInnerProduct()const{
	return	getX()*getX() +
		getY()*getY() +
		getZ()*getZ();
		
}

//setters
void Electric_Field::setE(double x,double y,double z){
	Field::setE(x,y,z);

}

//getters
double Electric_Field::getX()const{
	return Field::getX();
}

double Electric_Field::getY()const{
	return Field::getY();
}

double Electric_Field::getZ()const{
	return Field::getZ();
}

double Electric_Field::elecFieldGaussLaw(double charge,double area){
                //this is the permittivity of free space
                const double epsilon = 8.854e-12;
                storedElecValue = charge / (epsilon*area);
		return storedElecValue;
}

//overloaded function
Electric_Field Electric_Field::operator+(const Electric_Field& rhs){
	double xsum = this->getX()+rhs.getX();
	double ysum = this->getY()+rhs.getY();
	double zsum = this->getZ()+rhs.getZ();
	return Electric_Field(xsum,ysum,zsum);


}

/////////////////////////////////////////////////////////////////////////

//setters
void Magnetic_Field::setE(double x,double y,double z){
	setE(x,y,z);
}

void Magnetic_Field::unitVector(double unitVec[3])const{
	double magnitude = calculateMagnitude();
	
	//returns unitvector when index value is not 0
	if(magnitude!=0){
		unitVec[0] = getX()/magnitude;
		unitVec[1] = getY()/magnitude;
		unitVec[2] = getZ()/magnitude;
	}

	else {
		unitVec[0] = unitVec[1] = unitVec[2]=0.0;	

	}


}

//getters
double Magnetic_Field::getX()const {
	return Field::getX();
}

double Magnetic_Field::getY()const{
	return Field::getY();
}

double Magnetic_Field::getZ()const{
	return Field::getZ();
}

Magnetic_Field::Magnetic_Field(): Field(0,0,0){
	storedMagValue = 0;
}

Magnetic_Field::Magnetic_Field(double x,double y,double z):Field(x,y,z){
	storedMagValue = 0;
}

double Magnetic_Field::calculateMagnitude()const{
	return	
		sqrt
		(
		(getX()*getX())+
		(getY()*getY())+
		(getZ()*getZ())
		);
}

//ampere law function
double Magnetic_Field::magFieldAmpereLaw(double current, double r) const{
	//ampere permiability
	const double mU = 4* M_PI * 1e-7;
	
	return (mU * current) / (2 * M_PI * r);

}


int main(){
	//3 electric field objects
	Electric_Field ObjE1(1e3, 4, 5);
	Electric_Field ObjE2(1.2e4, 2, 1);
	Electric_Field ObjE3(1e4, 1, 9);
	std::cout	<<"Object 1 Inner Product: "
			<< ObjE1.calcInnerProduct()
			<< std::endl;

	std::cout	<<"Electric Field Object Calculations\n"
			<< std::endl;

	std::cout 	<<"Object 1 Magnitude: "
			<< ObjE1.calculateMagnitude()
			<< std::endl;
		
	std::cout	<<"Object 2 Magnitude: "
			<< ObjE2.calculateMagnitude()
			<< std::endl;

	std::cout 	<<"Object 3 Magnitude: "
			<< ObjE3.calculateMagnitude()
			<< std::endl;
	
	Magnetic_Field M_default;

	Electric_Field overLoad = ObjE1 + ObjE2;
	cout << overLoad << endl;	

	//3 magnetic field objects
	Magnetic_Field ObjM1(1e3, 5, 1);
	Magnetic_Field ObjM2(1.5e5, 6, 1.4e2);
	Magnetic_Field ObjM3(1e4, 2, 7);
	double unitVec[3];

	//current and amps 
	double current = 2.1;
	double radius = 0.05;

	//ampereLaw test object	
	double ampereTestObj = ObjM1.magFieldAmpereLaw(current,radius);
	std::cout	<< "Magnetic field: Ampere Law: "
			<< ampereTestObj
			<< "T"
			<< std::endl;

	//charge and area
	double charge = 1e-6;
	double area = 0.04;
	double elecField = ObjE1.elecFieldGaussLaw(charge, area);
	
	//gaussLaw test object
	std::cout	<< "Electric FIeld: Gauss Law: "
			<< elecField
			<< "n/c"
			<< std::endl;	

	ObjM1.unitVector(unitVec);

	std::cout	<< "Unit vector of Object 1: "
			<< unitVec[0] << ","
			<< unitVec[1] << ","
			<< unitVec[2] << ","
			<< std::endl;

	std::cout 	<< "\nMagnetic Field Object calculations\n"
			<< std::endl;

	std::cout	<<"Object 1 Magnitude: "
			<< ObjM1.calculateMagnitude()
			<< std::endl;
	
	std::cout	<<"Object 2 Magnitude: "
			<< ObjM2.calculateMagnitude()
			<< std::endl;


	std::cout 	<< "Object 3 Magnitude: " 
			<< ObjM3.calculateMagnitude()
			<< std::endl;

	
	
	return 0;

}


std::ostream& operator<<(std::ostream& out,const Electric_Field& e){
	out 	<< "Electric field vector: "
		<< e.getX() << ", "
		<< e.getY() << ", "
		<< e.getZ();
	return out;
}
