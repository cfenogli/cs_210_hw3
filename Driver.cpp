#include "AVLTree.cpp"

#include <iostream>

/*
Team 2 Homework 3 AVL Tree
*/

using namespace std;

int main()
{
	//create tree object
	AVLTree<int> tree1 = AVLTree<int>();

	tree1.insertElement(tree1.getRoot(), 4);
	tree1.insertElement(tree1.getRoot(), 10);
	tree1.insertElement(tree1.getRoot(), 3);
	tree1.insertElement(tree1.getRoot(), 6);
	tree1.insertElement(tree1.getRoot(), 5);
	tree1.insertElement(tree1.getRoot(), 25);
	tree1.showAvlST();
	tree1.showBF();

}