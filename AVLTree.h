#pragma once //not in original file?

template<class T>
class AVLTree;

template<class T>
class AVLNode
{
public:
	T element;
	AVLNode* left;
	AVLNode* right;
	int height;
	int balanceFactor = 100; //initialized balanceFactor with something unlikely to get past an error

	AVLNode(const T theElement, AVLNode* lt, AVLNode* rt, int h = 1) :
		element(theElement), left(lt), right(rt), height(h) {}

	int calculateBalanceFactor();

	friend class AVLTree<T>;
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
	AVLNode<T>* insertElement(AVLNode<T>* node, const T& x);

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