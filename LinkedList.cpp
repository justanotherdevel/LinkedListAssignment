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
	*
	************************************END********************************************
*/

#include "LinkedList.h"
#include "student.h"
#include <iostream>

LinkedList::LinkedList (){

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

