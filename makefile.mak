all: LinkedListAssignment

LinkedListAssignment: *.o
	g++ *.o -o LinkedListAssignment -std=c++14

*.o: *.cpp
	g++ -c *.cpp -std=c++14

clean:
	rm *.o LinkedListAssignment