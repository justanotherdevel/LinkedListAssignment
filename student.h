/*
	*This is a header file that declares the structure Students
	*Implementation of the same can be found in student.cpp
*/

#ifndef __STUDENTS__
#define __STUDENTS__

#include <cstring>

struct Students{
	int rollNo;			//Stores roll no.
	string name;		//Stores name
	double marks;		//Stores marks
	Students operator= ();
	//Overloading << operator to use in cout
	friend ostream& operator<< (ostream &, Students);
	//To check equality of two operator.
	bool operator== (Students) const;
	//Some constructors including one copy constructor
	Students ();
	Students (const Students &);
	Students (int, string, double);
}

#endif