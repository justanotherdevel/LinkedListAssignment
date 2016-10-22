/*
	*This is a header file that declares the structure Students
	*Implementation of the same can be found in student.cpp
*/

#ifndef __STUDENTS__
#define __STUDENTS__

#include <string>
#include <iostream>

using namespace std;

struct Students{
	Students *next;
	int rollNo;			//Stores roll no.
	string name;		//Stores name
	double marks;		//Stores marks
	//Overloading << operator to use in cout
	friend ostream& operator<< (ostream&, Students&);
	friend istream& operator>> (istream &input, Students&);
	//To check equality of two operator.
	bool operator== (Students) const;
	//Some constructors including one copy constructor
	Students ();
	Students (const Students &);
	Students (int, string, double);
	~Students ();				//Destructor
};

typedef Students node;
typedef node *link;
typedef link Node;

#endif