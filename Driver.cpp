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

	tree1.insertElement(4);
	tree1.insertElement(10);
	tree1.insertElement(3);
	tree1.insertElement(6);
	tree1.insertElement(5);
	tree1.insertElement(25);

	cout << "Printing tree:" << endl;
	tree1.showAvlST();
	cout << "Printing balance factors:" << endl;
	tree1.showBF();

}