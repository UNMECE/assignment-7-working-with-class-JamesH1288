#include <iostream>
#include <cmath>
#include "Magnetic_Field.h"
#include "Electric_Field.h"

using namespace std;

Electric_Field::Electric_Field(){
	E = new double[3];
}

Electric_Field::Electric_Field(double x,double y,double z){
	E = new double[3];
	E[0]=x;
	E[1]=y;
	E[2]=z;
}

//memory freeing
Electric_Field::~Electric_Field(){
	delete[] E;
}

//magnitude formula function
double Electric_Field::calculateMagnitude()const{
	return std::
		sqrt
		(
		(E[0]*E[0]) +
		(E[1]*E[1]) +
		(E[2]*E[2])
		);
}

double Electric_Field::calcInnerProduct()const{
	return	E[0]*E[0] +
		E[1]*E[1] +
		E[2]*E[2];
		
}

//setters
void Electric_Field::setE(double x,double y,double z){
	E[0] = x;
	E[1] = y;
	E[2] = z;

}

//getters
double Electric_Field::getX()const{
	return E[0];
}

double Electric_Field::getY()const{
	return E[1];
}

double Electric_Field::getZ()const{
	return E[2];
}






//setters
void Magnetic_Field::setE(double x,double y,double z){
	E = new double [3];
	E[0] = x;
	E[1] = y;
	E[2] = z;
}

void Magnetic_Field::unitVector(double unitVec[3])const{
	double magnitude = calculateMagnitude();
	
	//returns unitvector when index value is not 0
	if(magnitude!=0){
		unitVec[0] = E[0]/magnitude;
		unitVec[1] = E[1]/magnitude;
		unitVec[2] = E[2]/magnitude;
	}

	else {
		unitVec[0] = unitVec[1] = unitVec[2]=0.0;	

	}


}

//getters
double Magnetic_Field::getX()const {
	return E[0];
}

double Magnetic_Field::getY()const{
	return E[1];
}

double Magnetic_Field::getZ()const{
	return E[2];
}

Magnetic_Field::Magnetic_Field(){
	E = new double [3];
}

Magnetic_Field::Magnetic_Field(double x,double y,double z){
	E = new double[3];
	E[0]=x;
	E[1]=y;
	E[2]=z;
}

double Magnetic_Field::calculateMagnitude()const{
	return::	
		sqrt
		(
		(E[0]*E[0])+
		(E[1]*E[1])+
		(E[2]*E[2])
		);
}

Magnetic_Field::~Magnetic_Field(){
	delete [] E;
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
	//3 magnetic field objects
	Magnetic_Field ObjM1(1e3, 5, 1);
	Magnetic_Field ObjM2(1.5e5, 6, 1.4e2);
	Magnetic_Field ObjM3(1e4, 2, 7);
	double unitVec[3];
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
