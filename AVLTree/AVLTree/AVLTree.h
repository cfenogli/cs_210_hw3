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
	int balanceFactor;

	AVLNode(const T& theElement, AVLNode* lt, AVLNode* rt, int h = 1) :
		element(theElement), left(lt), right(rt), height(h) {}

	void calculateBalanceFactor();

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
	void insertElement(const T& x);

	void LLRotateWithLeftChild(AVLNode<T>*& t) const;
	void RRRotateWithRightChild(AVLNode<T>*& t) const;

	void LRDoubleWithLeftChild(AVLNode<T>*& t) const;
	void RLDoubleWithRightChild(AVLNode<T>*& t) const;

private:
	AVLNode<T>* root;

	void showAvlSTHelper(AVLNode<T>* p, int level) const;
	void showBFHelper(AVLNode<T>* p, int level) const;
};