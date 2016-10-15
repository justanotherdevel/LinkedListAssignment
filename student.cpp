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
	*
	***********************************************************************************
*/

#include "student.h"
#include <cstring>

//Assignment operation as default assignment will fail due to string
student Students::operator= (){
	Students ret;			//Variable to copy and return
	ret.rollNo = this->rollNo;
	ret.marks = this->marks;
	strcpy (ret.name, this->name);
	return ret;
}

//This let's the function be used in cout.
ostream& operator<< (ostream &out, Students disp){
	out << "Name of the student: " << disp.name;
	out << "\nRoll number: " << disp.rollNo;
	out << "\nMarks: " << disp.marks;
	return out;
}

//Checks equality for two objects of structure student
bool Students::operator== (Students check) const{
	return (check.rollNo == this->rollNo);
}