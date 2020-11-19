#include "AVLTree.cpp"

#include <iostream>

/*
Team 2 Homework 3 AVL Tree
*/

using namespace std;

int main()
{
	cout << "------------------- AVL1 -------------------" << endl;
	AVLTree<int> tree1 = AVLTree<int>();

	tree1.insertElement(4);
	tree1.insertElement(10);
	tree1.insertElement(3);
	tree1.insertElement(6);
	tree1.insertElement(5);
	tree1.insertElement(25);

	cout << "Printing keys:" << endl;
	tree1.showAvlST();
	cout << "Printing balance factors:" << endl;
	tree1.showBF();

	cout << endl;

	cout << "------------------- AVL2 -------------------" << endl;
	AVLTree<int> tree2 = AVLTree<int>();

	tree2.insertElement(10);
	tree2.insertElement(20);
	tree2.insertElement(30);
	tree2.insertElement(40);
	tree2.insertElement(50);
	tree2.insertElement(60);
	tree2.insertElement(70);

	cout << "Printing keys:" << endl;
	tree2.showAvlST();
	cout << "Printing balance factors:" << endl;
	tree2.showBF();

	cout << endl;

	cout << "------------------- AVL3 -------------------" << endl;
	AVLTree<int> tree3 = AVLTree<int>();

	tree3.insertElement(0);
	tree3.insertElement(-1);
	tree3.insertElement(-2);
	tree3.insertElement(-3);
	tree3.insertElement(-4);
	tree3.insertElement(-5);
	tree3.insertElement(1);

	cout << "Printing keys:" << endl;
	tree3.showAvlST();
	cout << "Printing balance factors:" << endl;
	tree3.showBF();

	cout << endl;

	cout << "------------------- AVL4 -------------------" << endl;
	AVLTree<int> tree4 = AVLTree<int>();

	tree4.insertElement(18);
	tree4.insertElement(11);
	tree4.insertElement(17);
	tree4.insertElement(12);
	tree4.insertElement(16);
	tree4.insertElement(13);
	tree4.insertElement(15);
	tree4.insertElement(14);

	cout << "Printing keys:" << endl;
	tree4.showAvlST();
	cout << "Printing balance factors:" << endl;
	tree4.showBF();

	cout << endl;
}