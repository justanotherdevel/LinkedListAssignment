# LinkedListAssignment
Linked list based assignment for data structure.

##Details about structure Students:
	Data Members:
	*rollNo (integer): Stores the roll number of the student.
	*name (string): Stores the name of the student.
	*marks (float): Stores the marks of the student.
	
	Member Functions:
	*overloaded operator "<<" (friend) to allow use of cout.
	*overloaded operator ">>" (friend) to allow use of cin.
	*operator '==' to check if two students are the same.
	*Constructor Students() to allow declaration without providing parameter.
	*Constructor Students(const Students &) to copy data from existing object.
	*Students (int, string, double) to initialize with given data.
	*~Students: Destructor which does nothing in the current implementation but can be utilized if we allocate memory dynamically.

	Alias:
	*node is an alias for Students.
	*link is an alias for node*.
	*Node is an alias for link.

##Details about class LinkedList:
	Data Members:
	*head (Node): Points to the first node.
	*count: Keeps track of the current size of the list.

	Member Functions:
	*LinkedList(): Constructor that initializes the head and count.
	*~LinkedList(): Destructor which deletes the entire list while freeing the memory used by each node.
	*PrependNode(): Adds a new node at the beginning of the list.
	*AppendNode(): Adds a new node at the end of the list.
	*InsertNode(): Inserts a new node after the student whose roll number is provided.
	*SearchNode(): Searches and prints the details of the student based on the roll number.
	*PrintNode(): Prints the node based on the roll number.
	*PrintList(): Prints the entire list on the screen.
	*DeleteFirstNode(): Deletes the first node and changes head to point to the next node.
	*DeleteLastNode(): Deletes the last node from the list.
	*ReverseList(): Reverses the order of the list such that the last node is now the head and the head is the last node.
	*ListUnion() (friend): Prints the nodes of two list while printing ignoring the second appearance of the same node.
	*ListIntersection() (friend): Prints the nodes which are common to both the list.
	*FindMthToLast(): Prints the Mth node from the end of the list.

##Structure of saving the file:
	Header files:
	*student.h: Declares the structure Students.
	*LinkedList.h: Declares the class LinkedList.

	Implementation files:
	*student.cpp: Defines the functions of the structure Students.
	*LinkedList.cpp: Defines the functions of the class LinkedList.
	*main.cpp: It is the interface file which also contains int main () and the program begins execution at this file.
	*makefile.mak: A GNU makefile to automate the compilation and linking process.

