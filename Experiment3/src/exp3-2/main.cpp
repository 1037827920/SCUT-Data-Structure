#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::string;
using std::transform;

typedef struct HFT {
	double weight;
	int parent, left, right;
	string name;
}HFT, * PHFT;

//选择权值最小的两个结点
void select(const PHFT& H,const int& n,int& s1,int&s2);

//初始化霍夫曼编码
void initHFM(PHFT& H, const int& n);

//进行霍夫曼编码
void createHFCode(const PHFT& H, char** HC, const int& n);

//显示霍夫曼树
void show(const PHFT& H, char** HC, const int& n);

//将电文转换为霍夫曼编码
char** strToHFM(string& str, char** HC);

/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023.11.21 20:39
*/
int main() {
	PHFT H;
	int n = 0;
	cout << "输入需要编码的字母数量：";
	cin >> n;
	//霍夫曼编码数组
	char** HC = new char* [n];
	initHFM(H, n);
	createHFCode(H, HC, n);
	show(H, HC, n);

	cout << "输入要霍夫曼编码的电文：";
	string str;
	cin >> str;
	char** ans;
	ans = strToHFM(str, HC);
	for (int i = 0; i < str.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}


//选择权值最小的两个结点
void select(const PHFT& H,const int& n,int&s1,int&s2) {
	//选择一个权值最小的结点的下标
	for (int i = 0; i < n; i++) {
		if (H[i].parent == 0) {
			s1 = i;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (H[i].parent == 0 && H[s1].weight > H[i].weight) {
			s1 = i;
		}
	}
	//选择另一个权值最小的结点的下标
	for (int i = 0; i < n; i++) {
		if (H[i].parent == 0 && i != s1) {
			s2 = i;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (H[i].parent == 0 && H[s2].weight > H[i].weight && i != s1) {
			s2 = i;
		}
	}
}
//初始化霍夫曼编码
void initHFM(PHFT& H, const int& n) {
	if (n <= 1) return;

	//初始化操作
	int m = 2 * n - 1;
	H = new HFT[m + 1];
	for (int i = 1; i <= m; i++) {
		H[i].parent = 0;
		H[i].left = 0;
		H[i].right = 0;
	}

	//获取要编码的字母和权值
	cout << "输入结点的初始根结点的权值（频率）和大写字母：";
	for (int i = 1; i <= n; i++) {
		cin >> H[i].weight >> H[i].name;
	}

	//选择前两棵权重最低的树进行合并
	for (int i = n + 1; i <= m; i++) {
		int s1, s2;
		select(H, i, s1, s2);
		H[s1].parent = i;
		H[s2].parent = i;
		H[i].left = s1;
		H[i].right = s2;
		H[i].weight = H[s1].weight + H[s2].weight;
	}
}
//进行霍夫曼编码
void createHFCode(const PHFT& H, char** HC, const int& n) {
	char* temp = new char[n];
	temp[n - 1] = '\0';
	int start = 0, cur = 0, father = 0;
	for (int i = 1; i <= n; i++) {
		start = n - 1;
		cur = i;
		father = H[cur].parent;
		//开始回溯到根结点
		while (father != 0) {
			if (H[father].left == cur) {
				temp[--start] = '0';
			}
			else {
				temp[--start] = '1';
			}
			cur = father;
			father = H[cur].parent;
		}
		HC[i] = new char[n - start + 1];
		strcpy_s(HC[i],n-start+1, &temp[start]);
	}

	delete[] temp;
}
//显示霍夫曼树
void show(const PHFT& H, char** HC, const int& n) {
	cout << "索引  权值  父结点  左结点  右结点" << endl;
	cout << left;
	int m = 2 * n - 1;
	for (int i = 1; i <= m; i++) {
		cout << setw(5) << i << " ";
		cout << setw(6) << H[i].weight << " ";
		cout << setw(6) << H[i].parent << " ";
		cout << setw(6) << H[i].left << " ";
		cout << setw(6) << H[i].right << " " << endl;
	}
	cout << endl;

	cout << "字母  霍夫曼编码" << endl;
	for (int i = 1; i <= n; i++) {
		cout << setw(5) << H[i].name << "  ";
		cout << setw(7) << HC[i] << " " << endl;
	}
}
//将电文转换为霍夫曼编码
char** strToHFM(string& str, char** HC) {
	//转化为大写
	transform(str.begin(), str.end(), str.begin(), ::toupper);

	char** ans = new char* [str.size()];

	for (int i = 0; i < str.size(); i++) {
		int index = str[i] - 'A' + 1;
		int len = strlen(HC[index]);
		ans[i] = new char[len+1];
		strcpy_s(ans[i], len+1, HC[index]);
	}

	return ans;
}
