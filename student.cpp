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
	*Use the following compilation command:
	*	g++ -c -o student.o student.cpp -std=c++14
	*Or else use the provided make file to build the entire project
	************************************END********************************************
*/

#include "student.h"
#include <string>
#include <iostream>

using namespace std;


//This let's the structure be used in cout.
ostream& operator<< (ostream &os, Students &stu){
	os << "Roll number: " << stu.rollNo
	   << "\nName: " << stu.name
	   << "\nMarks: " << stu.marks;
	return os;
}

//This let's the structure be used in cin
istream& operator >> (istream &in, Students &input){
	cout << "\nEnter Roll No: ";
	in >> input.rollNo;
	in.clear();
	in.ignore (1000, '\n');
	cout << "Enter Name: ";
	getline (in, input.name);
	cout << "Enter Marks: ";
	in >> input.marks;
	return in;
}


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