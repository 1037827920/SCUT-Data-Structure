#include<iostream>
#include<string>
#include<stack>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stack;
using std::vector;

struct BinNode {
	string data;
	BinNode* left;
	BinNode* right;

	BinNode() {}
	BinNode(string d, BinNode* l = nullptr, BinNode* r = nullptr) {
		data = d;
		left = l;
		right = r;
	}
};

//检查一个字符串是否为运算符
bool isOperator(const string& token);

//构建表达式树
BinNode* buildExpressionTreeFromPostfix(const vector<string>& input);

//中序遍历
void inOrderTraversal(BinNode* node);

int main() {
	vector<string> input = { "a","b","c","*","+","d","e","*","f","+","g","*","+" };
	BinNode* root = buildExpressionTreeFromPostfix(input);
	if (root) {
		inOrderTraversal(root);
		cout << endl;
	}

	vector<string> input2 = { "a","b","c","*","+","d","e","*","f","+","g","*","+" ,"-"};
	root = buildExpressionTreeFromPostfix(input2);
	if (root) {
		inOrderTraversal(root);
		cout << endl;
	}

	cout << "输入你要的后缀表达式：";
	vector<string>input3;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		string temp;
		temp = c;
		input3.push_back(temp);
	}
	root = buildExpressionTreeFromPostfix(input3);
	if (root) {
		inOrderTraversal(root);
		cout << endl;
	}
	

	return 0;
}

//检查一个字符串是否为运算符
bool isOperator(const string& token) {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}
//构建表达式树
BinNode* buildExpressionTreeFromPostfix(const vector<string>& input) {
	//存放表达式树的栈
	stack<BinNode*> s;

	//开始压栈操作
	for (const string& token : input) {
		//依次读取字符串
		BinNode* newNode = new BinNode(token);

		//不是操作符就直接压入
		if (!isOperator(token)) {
			s.push(newNode);
		}
		else {
			//如果操作符是"-"，有可能为单目运算符
			if (token == "-") {
				//如果此时的栈是空的，说明违法的后缀表达式
				if (s.empty()) {
					cout << "这个后缀表达式是违法的！" << endl;
					return nullptr;
				}
				else if (s.size() == 1) {
					newNode->right = s.top();
					s.pop();
				}
				else {
					newNode->right = s.top();
					s.pop();
					newNode->left = s.top();
					s.pop();
				}
			}
			else {
				if (s.size() < 2) {
					cout << "这个后缀表达式是违法的！" << endl;
					return nullptr;
				}

				newNode->right = s.top();
				s.pop();
				newNode->left = s.top();
				s.pop();
			}
			s.push(newNode);
		}
	}
	if (s.size() != 1) {
		cout << "这个后缀表达式是违法的！" << endl;
		return nullptr;
	}

	return s.top();
}
//中序遍历
void inOrderTraversal(BinNode* node) {
	//递归终点
	if (node == nullptr)
		return;
	if (node->data == "+" || node->data == "-")
		cout << "(";
	inOrderTraversal(node->left);
	cout << node->data << " ";
	inOrderTraversal(node->right);
	if (node->data == "+" || node->data == "-")
		cout << ")";
}
