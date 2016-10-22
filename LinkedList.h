/*
	*This file declares the LinkedList class.
	*Implementation of the same can be found in LinkedList.cpp
*/

#include "student.h"
#include <iostream>

class LinkedList {
		Node head;
		int count;
	public:
		LinkedList();
		~LinkedList();
		void PrependNode();
		void AppendNode();
		void InsertNode();
		void SearchNode();
		void PrintNode();
		void PrintList();
		void DeleteFirstNode();
		void DeleteLastNode();
		void DeleteNode();
		void ReverseList();
		void ListUnion();
		void ListIntersection();
		void FindMthToLast();
};