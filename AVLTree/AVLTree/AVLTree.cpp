#include "AVLTree.h"

#include <algorithm>
#include <iostream>

using namespace std;

template<class T>
AVLTree<T>::AVLTree()
{
}

template<class T>
AVLTree<T>::~AVLTree()
{
	delete root;
}

template<class T>
const T& AVLTree<T>::search(const T& x) const
{
	AVLNode<T>* currentNode = root;
	while (currentNode)
	{
		if (x > currentNode->element)
		{
			currentNode = currentNode->right;
		}
		else if (x < currentNode->element)
		{
			currentNode = currentNode->left;
		}
		else
		{
			return currentNode->element;
		}
	}
	return NULL;
}

//outputs the keys, rotated CCW 90 degrees
//using reverse in-order traversal
template<class T>
void AVLTree<T>::showAvlST() const
{
	if (root == 0)
	{
		cout << "Empty tree" << endl;
	}
	else
	{
		cout << endl;
		showAvlSTHelper(root, 1);
		cout << endl;
	}
}

//recursive helper for showAvlST
//outputs the subtree with root at p
//level is the level of the node at p within the tree
template<class T>
void AVLTree<T>::showAvlSTHelper(AVLNode<T>* p, int level) const
{
	//if the subtree is not empty
	if (p != 0)
	{
		//output right subtree
		showAvlSTHelper(p->right, level + 1);
		for (int j = 0; j < level; j++) cout << "\t"; //set j to int
		//output key
		cout << " " << p->element;
		//two children
		if ((p->left != 0) && (p->right != 0)) cout << "<";
		//only right child
		else if (p->right != 0) cout << "/";
		//only left child
		else if (p->left != 0) cout << "\\";
		cout << endl;
		//output left subtree
		showAvlSTHelper(p->left, level + 1);
	}
}

//outputs the balance factors, rotated CCW 90 degrees
//using reverse in-order traversal
template<class T>
void AVLTree<T>::showBF() const
{
	if (root == 0)
	{
		cout << "Empty tree" << endl;
	}
	else
	{
		cout << endl;
		showBFHelper(root, 1);
		cout << endl;
	}
}

//recursive helper for showBF
//outputs the balance factors of subtree with root at p
//level is the level of the node at p within the tree
template<class T>
void AVLTree<T>::showBFHelper(AVLNode<T>* p, int level) const
{
	//if the subtree is not empty
	if (p != 0)
	{
		//output right subtree
		showBFHelper(p->right, level + 1);
		for (int j = 0; j < level; j++) cout << "\t"; //set j to int
		//output balance factor
		cout << " " << p->balanceFactor;
		//two children
		if ((p->left != 0) && (p->right != 0)) cout << "<";
		//only right child
		else if (p->right != 0) cout << "/";
		//only left child
		else if (p->left != 0) cout << "\\";
		cout << endl;
		//output left subtree
		showBFHelper(p->left, level + 1);
	}
}

template<class T>
AVLNode<T>* AVLTree<T>::insertElement(AVLNode<T>* node, const T& x)
{
	if (node == NULL)
	{
		AVLNode<T> tempNode = AVLNode<T>(x, NULL, NULL, 0);
		root = tempNode;
		return root;
	}
	else if (x < node->element)
	{
		node->left = insert(node->left, x);
	}
	else if (x > node->element)
	{
		node->right = insert(node->right, x);
	}
	//duplicate key; do not insert it
	else
	{
		return node;
	}

	//update node height
	node->height = max(node->left->height, node->right->height);

	int currentBalance = node->calculateBalanceFactor();

	if (currentBalance > 1)
	{
		//LL
		if (x < node->left->element)
		{
			LLRotateWithLeftChild(node);
		}
		//LR
		else if (x > node->left->element)
		{
			LRDoubleWithLeftChild(node);
		}
	}
	else if (currentBalance < -1)
	{
		//RR
		if (x > node->right->element)
		{
			RRRotateWithRightChild(node);
		}
		//RL
		else if (x < node->right->element)
		{
			RLDoubleWithRightChild(node);
		}
	}
	return node;
}

template<class T>
void AVLTree<T>::LLRotateWithLeftChild(AVLNode<T>*& t) const
{
	AVLNode<T>* t1 = t->left;
	//single rotate to right
	t->left = t1->right;
	t1->right = t;
	//update height
	t->height = max(t->left->height, t->right->height) + 1;
	t1->height = max(t1->left->height, t1->right->height) + 1;
	//set new root
	t = t1;
}

template<class T>
void AVLTree<T>::RRRotateWithRightChild(AVLNode<T>*& t) const
{
	AVLNode<T>* t1 = t->right;
	//single rotate to left
	t->right = t1->left;
	t1->left = t;
	//update height
	t->height = max(t->left->height, t->right->height) + 1;
	t1->height = max(t1->left->height, t1->right->height) + 1;
	//set new root
	t = t1;
}

template<class T>
void AVLTree<T>::LRDoubleWithLeftChild(AVLNode<T>*& t) const
{
	//single rotate to left
	RRRotateWithRightChild(t->left);

	//single rotate to right
	LLRotateWithLeftChild(t);
}

template<class T>
void AVLTree<T>::RLDoubleWithRightChild(AVLNode<T>*& t) const
{
	//single rotate to right
	LLRotateWithLeftChild(t->right);

	//single rotate to left
	RRRotateWithRightChild(t);
}

template<class T>
AVLNode<T>* AVLTree<T>::getRoot() const //added function to access the root
{
	return root;
}

template<class T>
int AVLNode<T>::calculateBalanceFactor()
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (left)
	{
		leftHeight = left->height;
	}
	if (right)
	{
		rightHeight = right->height;
	}
	balanceFactor = leftHeight - rightHeight;
	return balanceFactor;
}