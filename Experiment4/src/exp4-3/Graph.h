#include"MyConsoleEngine.h"

class Graph {
private:
	int numOfVertex;
	vector<vector<int> >adjacent;

	/*查找目前从起点到每个点的距离中的最小值，然后返回这个点索引，从这个点开始计算去未访问点的最短路径*/
	int findMinDistance(const vector<int>& distance,const vector<bool>& visit);
public:
	Graph(int num);

	/*添加边*/
	void addEdge(int v,int w,int weight);

	/*最短路径算法*/
	void dijkstra(int startVertex,int endVertex);//startVertex是起点
};