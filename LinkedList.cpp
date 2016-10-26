/*
	*This is the implementation file of for LinkedList.h
	*Please include the said header and then either use this implementation
	*or create a different one yourself (or feel free to modify this one.)
*/

/*
	********************************Possible Errors***********************************
	*In AppendNode, the loop to traverse to the end of the list.
	************************************END********************************************
*/

#include "LinkedList.h"
#include "student.h"
#include <iostream>

//Gets the information of the students from the user.
inline void getInfo (node &temp){
	cin >> temp;
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
	node input;
	getInfo (input);		//Gets the information from the user
	Node temp = new node (input);	//Creates a new object
	temp->next = head;
	head = temp;				//Head again points to the top
	count++;					//Increases the current size of list
}

//Adds new student data at the end of the list.
void LinkedList::AppendNode (){
	node input;
	getInfo (input);		//Gets the information from the user
	Node temp = new node (input);
	temp->next = 0;
	//Handles the case where the list is empty 
	if (count == 0){
		head = temp;
		count++;
		return;
	}
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
	cout << "\nEnter the roll number following which you want the node to be inserted (will be appended to the list if the roll number is not found): ";
	cin >> roll;
	node input;
	getInfo (input);		//Gets the information from the user
	Node insert = new node (input);
	//Handles the case when the list is empty
	if (count == 0){
		head = insert;
		insert->next = 0;
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
		temp = temp->next;				//Forgot to add this step. Iterates the pointer to next node.
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
		temp = temp->next;
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
		temp = temp->next;
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
	Node temp = head, prev = head;
	if (count == 1){
		head = 0;				//Head now again points to 0
		delete temp;
		count--;
		return;
	}
	temp = temp->next;
	while (temp){
		if (!temp->next){ 		//Iterates temp to the next node
			prev->next = 0;		//prev->next now points to null.
			delete temp;
			break;
		}	
		prev = temp;			//prev now points to current
		temp = temp->next;		//
	}
	count--;				//Reduces the size of the list by 1
}

void LinkedList::DeleteNode (){
	int roll;
	cout << "\nEnter roll no. of the student whose data you want to delete: ";
	cin >> roll;
	if (roll == head->rollNo){
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
		prev = temp;			//Prev now points to the next node (temp).
	}
	if (flag == false){
		cout << "\nStudent data not found.";
	}
}

//Reverses the list
void LinkedList::ReverseList (){
	Node prev, current, next;
	prev = 0;						//Ensures that the last element will be NULL
	current = head;
	while (current){
		next = current->next;		//next points to next
		current->next = prev;		//link changed to prev
		prev = current;				//prev points to current
		current = next;				//current is iterated
	}
	head = prev;					//head now points to the current top
}


//Prints the union of the two listF
void ListUnion (LinkedList A, LinkedList B){
	Node tempA = A.head, tempB = B.head;		//Initializes iterators to both list
	while (tempA){
		cout << *tempA << endl;					//Prints entire list A without checking anything
		tempA = tempA->next;
	}
	while (tempB){
		bool flag = true;					//Assumes that we need to print the node of list B
		tempA = A.head;			
		while (tempA){
			if (*tempA == *tempB){
				flag = false;				//If the node was already present in node A, don't print it again
				break;
			}
			tempA = tempA->next;
		}
		if (flag == true)
			cout << *tempB << endl;			//Print only after checking if it is required
		tempB = tempB->next;
	}
}

//Prints the details of the students that are common in both the list.
void ListIntersection (const LinkedList A,const LinkedList B){
	Node tempA = A.head, tempB = B.head;
	while (tempA){
		bool flag = false;			//Assumes the node is not a part of the intersection
		tempB = B.head;				//Initializes iterator to List B
		while (tempB){
			if (*tempA == *tempB){
				flag = true;		//If node is a part of intersection, marks flag to be true
				break;
			}
			tempB = tempB->next;	//Iterates list B
		}
		if (flag == true)
			cout << *tempA << endl;		//Prints node if it is a part of interscection
		tempA = tempA->next;
	}
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