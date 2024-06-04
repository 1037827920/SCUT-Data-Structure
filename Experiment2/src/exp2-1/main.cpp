#include"BinarySearchTree.hpp"

int main() {
	//生成三棵树，并以三种遍历方式遍历
	int rootValue = 15;
	//生成第一个树
	BinarySearchTree<int>firstBST(rootValue);
	firstBST.insert(14);
	firstBST.insert(7);
	firstBST.insert(8);
	firstBST.insert(17);
	firstBST.insert(16);
	firstBST.insert(100);
	firstBST.insert(78);

	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "第一棵树的遍历" << endl;
	//前序遍历
	firstBST.preOrderTraversal();
	//中序遍历
	firstBST.inOrderTraversal();
	//后序遍历
	firstBST.postOrderTraversal();
	cout << "-----------------------------------------------------------------------------" << endl;

	//生成第二个树
	rootValue = 90;
	BinarySearchTree<int>secondBST(rootValue);
	secondBST.insert(78);
	secondBST.insert(50);
	secondBST.insert(45);
	secondBST.insert(55);
	secondBST.insert(80);
	secondBST.insert(81);
	secondBST.insert(100);

	cout << "第二棵树的遍历" << endl;
	//前序遍历
	secondBST.preOrderTraversal();
	//中序遍历
	secondBST.inOrderTraversal();
	//后序遍历
	secondBST.postOrderTraversal();
	cout << "-----------------------------------------------------------------------------" << endl;

	//生成第三个树
	rootValue = 3;
	BinarySearchTree<int>thirdBST(rootValue);
	thirdBST.insert(2);
	thirdBST.insert(1);
	thirdBST.insert(4);
	thirdBST.insert(5);
	thirdBST.insert(6);
	thirdBST.insert(7);
	thirdBST.insert(8);

	cout << "第三棵树的遍历" << endl;
	//前序遍历
	thirdBST.preOrderTraversal();
	//中序遍历
	thirdBST.inOrderTraversal();
	//后序遍历
	thirdBST.postOrderTraversal();
	cout << "-----------------------------------------------------------------------------" << endl;
	
	system("pause");

	//输出这些数的叶子结点
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "第一棵";
	firstBST.printChildNumber();
	cout << "第二棵";
	secondBST.printChildNumber();
	cout << "第三棵";
	thirdBST.printChildNumber();
	cout << "-----------------------------------------------------------------------------" << endl;

	system("pause");

	//测试插入值
	int input;
	int choice;
	bool execute1 = true;
	while (execute1) {
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "请输入要插入哪一棵数（输入除1、2、3之外的数字为退出插入操作）：";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "请输入要插入的值：";
			cin >> input;
			firstBST.insert(input);
			cout << "第一棵树插入后的";
			firstBST.inOrderTraversal();
			cout << "第一棵插入后";
			firstBST.printChildNumber();
		}break;
		case 2:
		{
			cout << "请输入要插入的值：";
			cin >> input;
			secondBST.insert(input);
			cout << "第二棵树插入后的";
			secondBST.inOrderTraversal();
			cout << "第二棵插入后";
			secondBST.printChildNumber();
		}break;
		case 3:
		{
			cout << "请输入要插入的值：";
			cin >> input;
			thirdBST.insert(input);
			cout << "第三棵树插入后的";
			thirdBST.inOrderTraversal();
			cout << "第三棵插入后";
			thirdBST.printChildNumber();
		}break;
		default:
		{
			execute1 = false;
			cout << "退出插入操作！" << endl;
		}break;
		}
	}

	//测试删除值
	bool execute2 = true;
	while (execute2) {
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "请输入要删除哪一棵数（输入1、2、3之外数字为退出删除操作）：";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "请输入要删除的值：";
			cin >> input;
			firstBST.remove(input);
			cout << "第一棵树删除后的";
			firstBST.inOrderTraversal();
			cout << "第一棵插入后";
			firstBST.printChildNumber();
		}
		break;
		case 2:
		{
			cout << "请输入要删除的值：";
			cin >> input;
			secondBST.remove(input);
			cout << "第二棵树删除后的";
			secondBST.inOrderTraversal();
			cout << "第二棵插入后";
			secondBST.printChildNumber();
		}
		break;
		case 3:
		{
			cout << "请输入要删除的值：";
			cin >> input;
			thirdBST.remove(input);
			cout << "第三棵树删除后的";
			secondBST.inOrderTraversal();
			cout << "第三棵插入后";
			thirdBST.printChildNumber();
		}
		break;
		default:
		{
			execute2 = false;
			cout << "退出删除操作！" << endl;
		}
		break;
		}
	}


	return 0;
}