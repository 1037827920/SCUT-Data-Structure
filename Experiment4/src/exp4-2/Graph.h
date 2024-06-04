#include"MyConsoleEngine.h"

class Graph {
private:
	int numOfVertex;//图的顶点数
	vector<list<int> >adjacent;//图的邻接链表
	vector<int>inDegree;//图顶点的入度
	vector<int>topolo;//拓扑排序数组

	/*计算每个顶点的入度*/
	void findInDegree();

public:
	/*构造函数*/
	Graph(int num);

	/*添加边*/
	void addEdge(int v, int w);

	/*删除边*/
	void deleteEdge(int v, int w);

	/*输出每个顶点的入度*/
	void printInDegree();

	/*拓扑排序*/
	bool TopologicalSort();

	/*输出拓扑排序序列*/
	void printTopo();
};