Binary Tree Zigzag Level Order Traversal (Please refer to the docx version of README for better understanding)


There are different ways to traverse a binary tree. The zigzag level order traversal of a binary tree covers all the nodes of the tree such that each level is traversed left to right or right to left alternatively.

Given the root node of a binary tree, return an array depicting the zigzag level order traversal.

Note: The first level is traversed left to right.

zigzag-level-order-traversal
Testing
Input Format
The first line contains an integer T denoting the number of test cases.

For each test case, the input has 2 lines:

The first line contains an integer n denoting the number of nodes in the tree (including the NULL nodes).
The second line contains n space-separated integers that will form the binary tree. The integers follow level order traversal of the tree where -1 indicates a NULL node.
Output Format
For each test case, the output contains a line with space-separated integers representing the zigzag level order traversal of the binary tree.

Sample Input
5
7
1 2 -1 4 -1 5 6
3
6 -1 4
7
8 -1 9 -1 10 11 12
5
28 14 11 -1 48
1
6
Expected Output
1 2 4 6 5
6 4
8 9 10 12 11
28 11 14 48
6