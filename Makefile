all: main

main: main.o ItemType.o BinaryTree.o
	g++ main.o ItemType.o BinaryTree.o -o main

main.o: main.cpp
	g++ -c main.cpp

ItemType.o: ItemType.cpp
	g++ -c ItemType.cpp

BinaryTree.o: BinaryTree.cpp
	g++ -c BinaryTree.cpp

clean:
	rm ItemType.o main.o BinaryTree.o main
