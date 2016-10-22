/*
	*This is the implementation file of for LinkedList.h
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
	*In AppendNode, the loop to traverse to the end of the list.
	*Change display methods if overloading fails.
	************************************END********************************************
*/

#include "LinkedList.h"
#include "student.h"
#include <iostream>

//Gets the information of the students from the user.
inline void getInfo (int &roll, string &name, double &marks){
	cout << "\nEnter rollNo: ";
	cin >> roll;
	cout << "Enter Name: ";
	getline (cin, name);
	//Ensuring that cin is free of error flags and the buffer is clean
	cin.clear ();
	cin.ignore (1000, '\n');
	cout << "Enter marks: ";
	cin >> marks;
}

LinkedList::LinkedList (){
	head = 0;
	count = 0;
}

//Takes care of the memory when the list goes out of scope.
LinkedList::~LinkedList(){
	while (head){
		Node temp = head;
		head = head->next;	//head now points to the next node
		delete temp;		//Deletes the current node.
		count--;			//Reduces the count of number of node by 1
	}
}

void LinkedList::AllocateNode (){

}

//Adds new student data at the beginning of the list.
void LinkedList::PrependNode (){		//Adds a new node at the beginning of the list
	int rollNo;
	string name;
	double marks;
	getInfo (rollNo, name, marks);		//Gets the information from the user
	Students *temp = new Students (rollNo, name, marks);	//Creates a new object
	temp->next = head;
	head = temp;				//Head again points to the top
	count++;					//Increases the current size of list
}

//Adds new student data at the end of the list.
void LinkedList::AppendNode (){
	int rollNo;
	string name;
	double marks;
	getInfo (rollNo, name, marks);		//Gets the information from the user
	Node temp = new node (rollNo, name, marks);
	temp->next = 0;
	Node temp2 = head;
	while (temp2->next){			//Goes to the end of the list
		temp2 = temp2->next;		//Check for correctness 1.
	}
	temp2->next = temp;
	count++;						//Increases the size of the list
}

void LinkedList::InsertNode (){

}

//Search the list based on the roll no. of the student
void LinkedList::SearchNode (){
	cout << "\nEnter roll no. to search: ";
	bool flag = false;			//Stores if node was found
	int roll;
	cin >> roll;
	Node temp = head;
	while (temp){
		if (temp->rollNo == roll){
			flag = true;
			cout << temp;			//Change this if overlading fails.
			break;
		}
	}
	if (flag == false){
		cout << "Student data not found.";
	}
} 

//Prints the entire list.
void LinkedList::PrintList (){
	Node temp = head;
	while (temp){
		cout << temp << endl;
		temp = temp->next;		//Iterates temp to the next node.
	}
}

//Deletes the first node from the beginning.
void LinkedList::DeleteFirstNode (){
	Node temp = head;
	head = head->next;		//Head points to the next node (which will now be the top)
	delete temp;
	count--;				//Reduces the current size of the list by 1.
}

//Deletes the last node of the list
void LinkedList::DeleteLastNode (){
	Node temp = head;
	while (temp->next){
		temp = temp->next; 		//Iterates temp to the next node
	}
	delete temp;			//Hopefully temp still points to the last node :P
	count--;				//Reduces the size of the list by 1
}

void LinkedList::DeleteNode (){

}

void LinkedList::ReverseList (){

}

void LinkedList::ListUnion (){

}

void LinkedList::ListIntersection (){

}

void LinkedList::FindMthToLast (){
	int N;
	cout << "\nEnter which element you want to print form the end of the list: ";
	cin >> N;
	N = count - N;			//Computes the position from the beginning
	Node temp = head;
	while (N--){			//Changes temp to the node we want.
		temp = temp->next;
	}
	cout << temp;
}

