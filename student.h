/*
	*This is a header file that declares the structure Students
	*Implementation of the same can be found in student.cpp
*/

#ifndef __STUDENTS__
#define __STUDENTS__

#include <string>

using namespace std;


class Students{
	private:
		int rollNo;			//Stores roll no.
		string name;		//Stores name
		double marks;		//Stores marks
		//Overloading << operator to use in cout
		friend ostream& operator<< (ostream&, const Students&);
		friend istream& operator>> (istream &input, Students&);
		//To check equality of two operator.
		bool operator== (Students) const;
		//Some constructors including one copy constructor
		Students ();
		Students (const Students &);
		Students (int, string, double);
		~Students ();				//Destructor
};

#endif