#include <iostream>
#include "linkedlist.h"
#include "student.h"

/*
	**********************PROBLEMS/IMPROVEMENTS**************************
	*In future improve the handling of allocation of list to allow
	*addition of more lists while the program is running
	******************************END************************************
*/

//Declaring few global variables.
LinkedList *List;
int nList;				//Stores the number of available list

//A ostream function for beautification of the the display
ostream& pos (ostream &position){
	position << "\n\t\t\t";
	return position;
}

//Displays the menu
inline void menu (){
	system ("cls");
	cout << "\n\n\n" << pos << "\t" << "MENU";
	cout << pos << "1. Allocate Node";
	cout << pos << "2. Prepend Node";
	cout << pos << "3. Append Node";
	cout << pos << "4. Insert Node";
	cout << pos << "5. Search List";
	cout << pos << "6. Print Node";
	cout << pos << "7. Print List";
	cout << pos << "8. Delete First Node";
	cout << pos << "9. Delete Last Node";
	cout << pos << "10. Delete Node";
	cout << pos << "11. Reverse List";
	cout << pos << "12. List Union";
	cout << pos << "13. List Intersection";
	cout << pos << "14. Find Mth from Last";
	cout << pos << "15. Exit";
	cout << pos << "Enter you choice: ";
}

//Acts based on the choice of user
inline bool Choice (int choice){
	int Lnumber, Rnumber;
	static bool flag = false;
	switch (choice){
		case 1:				//Allocate Node
			if (flag == false){
				cout << "How many Lists do you want to allocate? ";
				cin >> nList;
				List = new LinkedList[nList];
			}
			else
				cout << "Lists already allocated. Re-run the program to allocate new lists.";
			break;
		case 2:				//Prepend Node
			cout << "Enter the number of list in which you want to work on: ";
			cin >> Lnumber;
			List[Lnumber-1].PrependNode();
			break;
		case 3:				//Append Node
			cout << "Enter the number of list in which you want to work on: ";
			cin >> Lnumber;
			List[Lnumber-1].AppendNode();
			break;
		case 4:				//Insert Node
			cout << "Enter the number of list in which you want to work on: ";
			cin >> Lnumber;
			List[Lnumber-1].InsertNode();
			break;
		case 5:				//Search Node
			cout << "Enter the number of list in which you want to work on: ";
			cin >> Lnumber;
			List[Lnumber-1].SearchNode();
			break;
		case 6:				//Print Node
			cout << "Enter the number of list in which you want to work on: ";
			cin >> Lnumber;
			List[Lnumber-1].PrintNode();
			break;
		case 7:				//Print List
			cout << "Enter the number of list in which you want to work on: ";
			cin >> Lnumber;
			List[Lnumber-1].PrintList();
			break;
		case 8:				//Delete First Node
			cout << "Enter the number of list in which you want to work on: ";
			cin >> Lnumber;
			List[Lnumber-1].DeleteFirstNode();
			break;
		case 9:				//Delete Last Node
			cout << "Enter the number of list in which you want to work on: ";
			cin >> Lnumber;
			List[Lnumber-1].DeleteLastNode();
			break;
		case 10:			//Delete Node
			cout << "Enter the number of list in which you want to work on: ";
			cin >> Lnumber;
			List[Lnumber-1].DeleteNode();
			break;
		case 11:			//Reverse List
			cout << "Enter the number of list in which you want to work on: ";
			cin >> Lnumber;
			List[Lnumber-1].ReverseList();
			break;
		case 12:			//List Union
			cout << "Enter the lists for which you want to find the union: ";
			cin >> Lnumber >> Rnumber;
			ListUnion(List[Lnumber-1], List[Rnumber-1]);
			break;
		case 13:			//List Intersection
			cout << "Enter the lists for which you want to find the union: ";
			cin >> Lnumber >> Rnumber;
			ListIntersection(List[Lnumber-1], List[Rnumber-1]);
			break;
		case 14:			//Find Mth from the last
			cout << "Enter the number of list in which you want to work: ";
			cin >> Lnumber;
			List[Lnumber-1].FindMthToLast();
			break;
		case 15:			//Exit
			return true;	//Sends Signal to quit program
			break;
		default:			//Handle wrong option
			;
	}
	return false;
}

int main (){
	while (1){
		menu ();			//Displays the menu
		short choice;
		cin >> choice;		//Takes user input
		system ("cls");
		bool exitStat = Choice (choice);	//Takes action depending on the input.
		cout << endl;
		if (exitStat)
			return 0;
		system ("pause");
	}
}