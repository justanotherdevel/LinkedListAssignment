/*
	*This file declares the LinkedList class.
	*Implementation of the same can be found in LinkedList.cpp
*/
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

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
		friend void ListUnion(LinkedList, LinkedList);
		friend void ListIntersection(const LinkedList, const LinkedList);
		void FindMthToLast();
};

#endif
