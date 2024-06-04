#include<iostream>
#include<vector>
#include<cmath>

using std::cerr;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::max;

template<class T>
struct Node {
	T data;
	Node* left;
	Node* right;
	Node* parent;
	int depth;

	Node() {}
	Node(T d, Node* l = nullptr, Node* r = nullptr,Node* p = nullptr) {
		data = d;
		left = l;
		right = r;
		parent = p;
		depth = 0;
	}
};

