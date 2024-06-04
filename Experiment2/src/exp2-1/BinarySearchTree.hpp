
#include"Node.h"

template<class T>
class BinarySearchTree {
	using BinNode = Node<T>*;
public:
	BinarySearchTree(T d);
	~BinarySearchTree();

	/*创建一个二叉搜索树*/
	void createBST(T d);

	/*插入新结点*/
	void insert(T x);

	/*查找*/
	bool find(T x);

	/*移除*/
	void remove(T x);

	/*前序遍历*/
	void preOrderTraversal();
	/*中序遍历*/
	void inOrderTraversal();
	/*后序遍历*/
	void postOrderTraversal();

	/*输出树的叶子结点*/
	void printChildNumber();

	/*更新结点的深度*/
	void updataDepth(BinNode node);

private:
	BinNode root;//根结点
	int number;//结点数
	int childNumber;//记录所有深度不为0的结点个数

	/*前序遍历*/
	void m_preOrderTraversal(BinNode node);
	/*中序遍历*/
	void m_inOrderTraversal(BinNode node);
	/*后序遍历*/
	void m_postOrderTraversal(BinNode node);

	/*输出树的叶子结点*/
	void m_printChildNumber(BinNode node);
};

/*构造函数*/
template<class T>
BinarySearchTree<T>::BinarySearchTree(T d) {

	createBST(d);
}

/*析构函数*/
template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
	delete root;
}

/*创建一个二叉搜索树*/
/*
* 学号：202230481028
* 姓名：黄铭涛 
* 完成时间：2023.10.19 0:19
*/
template<class T>
void BinarySearchTree<T>::createBST(T d) {
	root = new Node<T>(d);
	number++;
}

/*插入新结点*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-28 22:32
*/
template<class T>
void BinarySearchTree<T>::insert(T x) {
	//先查找插入值是否在树中存在
	bool isFind = find(x);
	if (isFind) {
		cout << "该结点值已经在树中存在！" << endl;
		return;
	}

	if (root == nullptr) {
		root = new Node<T>(x);
		number++;
		return;
	}
	else {
		BinNode temp = root;
		BinNode newNode = new Node<T>(x);
		while (temp != nullptr) {
			if (x < temp->data) {
				if (temp->left == nullptr) {
					number++;
					temp->left = newNode;
					newNode->parent = temp;
					updataDepth(temp);
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else if (x > temp->data) {
				if (temp->right == nullptr) {
					number++;
					temp->right = newNode;
					newNode->parent = temp;
					updataDepth(temp);
					return;
				}
				else {
					temp = temp->right;
				}
			}
		}
	}
}

/*查找*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023.10.29 0:11
*/
template<class T>
bool BinarySearchTree<T>::find(T x) {
	BinNode temp = root;
	while (temp != nullptr) {
		if (x > temp->data)
			temp = temp->right;
		else if (x < temp->data)
			temp = temp->left;
		else
			return true;
	}
	return false;
}

/*移除*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023.10.29 14:01
*/
template<class T>
void BinarySearchTree<T>::remove(T x) {
	BinNode temp = root;
	if (temp == nullptr) {
		cout << "该树是空的，不能再移除值了！" << endl;
	}

	BinNode cur = temp;
	BinNode parent = nullptr;

	//查找树中是否有该点，将cur移动到该点
	while (cur) {
		if (cur->data == x)
			break;
		else if (cur->data > x) {
			parent = cur;
			cur = cur->left;
		}
		else {
			parent = cur;
			cur = cur->right;
		}
	}

	//结点不存在
	if (cur == nullptr){
		cout << "要删除的结点不存在！" << endl;
		return;
	}
	//结点存在
	number--;
	//叶子结点
	if (cur->left == nullptr && cur->right == nullptr) {
		if (cur == parent->left) {
			parent->left = nullptr;
		}
		else {
			parent->right = nullptr;
		}
	}
	//左节点不存在->只有右结点
	else if (cur->left == nullptr) {
		if (parent == nullptr) {
			root = cur->right;
			root->parent = nullptr;
		}
		else {
			if (cur == parent->left) {
				parent->left = cur->right;
				cur->right->parent = parent;
			}
			else {
				parent->right = cur->right;
				cur->right->parent = parent;
			}
		}
	}
	//右结点不存在->只有左结点
	else if (cur->right == nullptr) {
		if (parent == nullptr) {
			root = cur->left;
			root->parent = nullptr;
		}
		else {
			if (cur == parent->left) {
				parent->left = cur->left;
				cur->left->parent = parent;
			}
			else {
				parent->right = cur->left;
				cur->left->parent = parent;
			}
		}
	}
	//有两个孩子
	else {
		//找到右子树的最小值，在最左结点
		BinNode delNode = cur->right;
		parent = cur;
		while (delNode->left != nullptr) {
			parent = delNode;
			delNode = delNode->left;
		}
		cur->data = delNode->data;

		if (delNode == parent->left){
			parent->left = delNode->right;
			delNode->right->parent = parent;
		}
		else if (delNode == parent->right){
			parent->right = delNode->right;
			delNode->right->parent = parent;
		}
		cur = delNode;
	}
	BinNode p = parent;
	//更新结点深度
	while (p) {
		updataDepth(p);
		p = p->parent;
	}
}

/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023.10.29 0:34
*/
/*前序遍历*/
template<class T>
void BinarySearchTree<T>::m_preOrderTraversal(BinNode node) {
	//递归终点
	if (node == nullptr)
		return;

	//访问当前结点数据
	cout << node->data << " ";
	//递归遍历左子树
	m_preOrderTraversal(node->left);
	//递归遍历右子树
	m_preOrderTraversal(node->right);
}
/*中序遍历*/
template<class T>
void BinarySearchTree<T>::m_inOrderTraversal(BinNode node) {
	//递归终点
	if (node == nullptr)
		return;

	//递归遍历左子树
	m_inOrderTraversal(node->left);
	//访问当前结点数据
	cout << node->data << " ";
	//递归遍历右子树
	m_inOrderTraversal(node->right);
}
/*后序遍历*/
template<class T>
void BinarySearchTree<T>::m_postOrderTraversal(BinNode node) {
	//递归终点
	if (node == nullptr)
		return;

	//递归遍历左子树
	m_postOrderTraversal(node->left);
	//递归遍历右子树
	m_postOrderTraversal(node->right);
	//访问当前结点数据
	cout << node->data << " ";
}

/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023.10.29 0:45
*/
/*前序遍历*/
template<class T>
void BinarySearchTree<T>::preOrderTraversal() {
	BinNode temp = root;
	cout << "前序遍历：" << endl;
	m_preOrderTraversal(temp);
	cout << endl;
}
/*中序遍历*/
template<class T>
void BinarySearchTree<T>::inOrderTraversal() {
	BinNode temp = root;
	cout << "中序遍历：" << endl;
	m_inOrderTraversal(temp);
	cout << endl;
	cout << "该树的结点数量：" << number << endl;
}
/*后序遍历*/
template<class T>
void BinarySearchTree<T>::postOrderTraversal() {
	BinNode temp = root;
	cout << "后序遍历：" << endl;
	m_postOrderTraversal(temp);
	cout << endl;
}

/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023.10.29 13:42
*/
/*输出树的叶子结点*/
template<class T>
void BinarySearchTree<T>::m_printChildNumber(BinNode node) {
	//递归终点
	if (node == nullptr)
		return;

	//递归遍历左子树
	m_printChildNumber(node->left);
	if (node->depth != 0)
		childNumber++;
	m_printChildNumber(node->right);

}
/*输出树的叶子结点数量*/
template<class T>
void BinarySearchTree<T>::printChildNumber() {
	childNumber = 0;
	BinNode temp = root;
	m_printChildNumber(temp);
	cout << "树的叶子结点的数量为：" << number - childNumber << endl;
}

/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023.10.29 15:26
*/
/*更新结点的深度*/
template<class T>
void BinarySearchTree<T>::updataDepth(BinNode node) {
	if (node == nullptr) {
		return;
	}
	else {
		int depthLeft, depthRight;
		if (node->left != nullptr)
			depthLeft = node->left->depth;
		else
			depthLeft = 0;
		if (node->right != nullptr)
			depthRight = node->right->depth;
		else
			depthRight = 0;
		node->depth = max(depthLeft, depthRight) + 1;
		if (node->left == nullptr && node->right == nullptr)
			node->depth = 0;
	}
}