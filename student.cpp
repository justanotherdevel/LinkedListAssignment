/*
	*This file implements the structure declared in student.h
	*Please include the said header and then either use this implementation
	*or create a different one yourself (or feel free to modify this one.)
*/

/*
	*********************Things to include in documentation***************************
	*
	*************************************END******************************************
*/

/*
	********************************Possible Errors***********************************
	*Overloading operators '<<' and '>>' not working.
	*Commenting out the issue part
	*Program will compile successfully to an object file.
	*Use the following compilation command:
	*	g++ -c -o student.o student.cpp -std=c++14
	***********************************************************************************
*/

#include "student.h"
#include <string>

using namespace std;

/*
//This let's the structure be used in cout.
ostream& operator<< (ostream &out, const Students &disp){
	out << "Name of the student: " << disp.name
		<< "\nRoll number: " << disp.rollNo
		<< "\nMarks: " << disp.marks;
	return out;
}

//This let's the structure be used in cin
istream& operator>> (istream &in, Students &input){
	cout << "Enter name: ";
	input >> input.name;
	cout << "Enter roll no: ";
	input >> input.rollNo;
	cout << "Enter marks: ";
	input >> input.marks;
	return input;
}
*/
//Checks equality for two objects of structure student
bool Students::operator== (Students check) const{
	return (check.rollNo == this->rollNo);
}

Students::Students (){}		//Ensures that you can still create an object without giving the required parameters.

Students::Students (const Students &cpy){		//Copy constructor to copy 
	//Copies all data to the new object
	rollNo = cpy.rollNo;
	name = cpy.name;					//Copies the name
	marks = cpy.marks;
}

//Initializes the object with the provided data
Students::Students (int RollNo, string Name, double Marks){
	rollNo = RollNo;
	name = Name;
	marks = Marks;
}

Students::~Students (){}			//There is no dynamic memory that needs to be taken care of
