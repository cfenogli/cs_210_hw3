#pragma once //not in original file?

template<class T>
class AVLTree;

template<class T>
class AVLNode
{
public:
	T element;
	AVLNode* left = 0;
	AVLNode* right = 0;
	int balanceFactor = 0;

	int getHeight() const;
	void setHeight(int newHeight);

	AVLNode(const T theElement, int h = 1) :
		element(theElement), height(h) {}

	int calculateBalanceFactor();

	friend class AVLTree<T>;

private:
	int height;
};


template <class T>
class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	const T& search(const T& x) const;
	void showAvlST() const;
	void showBF() const;
	void insertElement(const T& x);
	AVLNode<T>* insert(AVLNode<T>* root, const T& x);

	void LLRotateWithLeftChild(AVLNode<T>*& t) const;
	void RRRotateWithRightChild(AVLNode<T>*& t) const;

	void LRDoubleWithLeftChild(AVLNode<T>*& t) const;
	void RLDoubleWithRightChild(AVLNode<T>*& t) const;

	AVLNode<T>* getRoot() const;
	void setRoot(AVLNode<T>* newRoot);

private:
	AVLNode<T>* root;

	void showAvlSTHelper(AVLNode<T>* p, int level) const;
	void showBFHelper(AVLNode<T>* p, int level) const;
};