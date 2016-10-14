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

#ifndef __STUDENTS__
#define __STUDENTS__

#include <cstring>

struct students{
	int rollNo;			//Stores roll no.
	string name;		//Stores name
	double marks;		//Stores marks
	students operator= ();
	//Overloading << operator to use in cout
	friend ostream& operator<< (ostream &, const students);
	//To check equality of two operator.
	bool operator== (const students) const;
	//Some constructors including one copy constructor
	students ();
	students (const students &);
	students (int, string, double);
}

#endif