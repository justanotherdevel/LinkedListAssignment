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
	cin.clear ();
	cin.ignore (1000, '\n');
	getline (cin, name);
	//Ensuring that cin is free of error flags and the buffer is clean
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

//Adds new student data at the beginning of the list.
void LinkedList::PrependNode (){		//Adds a new node at the beginning of the list
	int rollNo;
	string name;
	double marks;
	getInfo (rollNo, name, marks);		//Gets the information from the user
	Node temp = new node (rollNo, name, marks);	//Creates a new object
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

//Insert node after certain roll number.
//If the roll number is not present, insert at the end of the list.
void LinkedList::InsertNode (){
	int roll;
	cout << "\nEnter the roll number following which you want the node to be inserted: ";
	cin >> roll;
	int rollNo;
	string name;
	double marks;
	getInfo (rollNo, name, marks);		//Gets the information from the user
	Node insert = new node (rollNo, name, marks);
	if (head->rollNo == roll){		//Handles the case where head is the desired object
		insert->next = head->next;
		head->next = insert;
		count++;
		return;
	}
	bool flag = false;
	Node temp = head;
	while (temp->next){
		if (temp->rollNo == roll){
			flag = true;
			insert->next = temp->next;
			temp->next = insert;
			break;
		}
	}
	if (flag == false){
		temp->next = insert;
		insert->next = 0;
	}
	count++;
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
			cout << *temp;			//Change this if overlading fails.
			break;
		}
	}
	if (flag == false){
		cout << "Student data not found.";
	}
} 

//Prints the details of the student given the roll number.
void LinkedList::PrintNode (){
	int roll;
	cout << "\nEnter Roll number you want to check: ";
	cin >> roll;
	Node temp = head;
	bool flag = false;
	while (temp){
		if (temp->rollNo == roll){
			cout << *temp;			//Prints the details of the student
			flag = true;
			break;
		}
	}
	if (flag == false){
		cout << "\nStudent details not present in the list.";
	}
}

//Prints the entire list.
void LinkedList::PrintList (){
	if (count == 0){
		cout << "List is empty.";
		return;
	}
	Node temp = head;
	while (temp){
		cout << *temp << endl;
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
	int roll;
	cout << "\nEnter roll no. of the student whose data you want to delete: ";
	cin >> roll;
	if (roll = head->rollNo){
		DeleteFirstNode();		//Don't use this method if head is the required object
		return;
	}
	Node temp = head, prev = head;
	int flag = false;
	while (temp->next){
		//We can immediately iterate temp as we've already checked that the first object is not the required object.
		temp = temp->next;			//temp now points to the node after previous.
		if (temp->rollNo == roll){		//If node is found
			prev->next = temp->next;	//Prev now points the node next of temp removing temp from list.
			delete temp;				//Frees the memory
			count--;					//Reduces the size by 1
			flag = true;
			break;
		}
		prev = prev->next;			//Prev now points to the next node (temp).
	}
	if (flag == false){
		cout << "\nStudent data not found.";
	}
}

//Reverses the list
void LinkedList::ReverseList (){
	Node currentNode, prevNode, nextNode;
	currentNode = prevNode = nextNode = head;
	currentNode = currentNode->next;	//current node now points to the object next of head
	while (currentNode){
		nextNode = currentNode->next;
		if (nextNode == 0){
			head = currentNode;			//Changes the head
		}
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
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
	N--;
	Node temp = head;
	while (N--){			//Changes temp to the node we want.
		temp = temp->next;
	}
	cout << *temp;
}