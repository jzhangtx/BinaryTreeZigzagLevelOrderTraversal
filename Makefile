BinaryTreeZigzagTraversal: BinaryTreeZigzagTraversal.o
	g++ -g -o BinaryTreeZigzagTraversal.exe BinaryTreeZigzagTraversal.o -pthread    

BinaryTreeZigzagTraversal.o: BinaryTreeZigzagTraversal/BinaryTreeZigzagTraversal.cpp
	g++ -g  -c -pthread BinaryTreeZigzagTraversal/BinaryTreeZigzagTraversal.cpp
