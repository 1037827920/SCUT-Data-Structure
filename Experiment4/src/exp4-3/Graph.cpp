#include"Graph.h"

/*私有函数*/
/*查找目前从起点到每个点的距离中的最小值，然后返回这个点索引，从这个点开始计算去未访问点的最短路径*/
int Graph::findMinDistance(const vector<int>& distance, const vector<bool>& visit) {
	int minDistance = numeric_limits<int>::max();
	int minIndex = -1;

	for (int i = 0; i < distance.size(); i++) {
		if (visit[i] == false && distance[i] < minDistance) {//该点还未被访问且距离是最短距离
			minDistance = distance[i];
			minIndex = i;
		}
	}

	return minIndex;
}

/*公有函数*/
Graph::Graph(int num){
	numOfVertex = num;
	adjacent.resize(num, vector<int>(num, 0));
}

/*添加边*/
void Graph::addEdge(int v,int w,int weight) {
	adjacent[v][w] = weight;
}

/*最短路径算法*/
void Graph::dijkstra(int startVertex,int endVertex) {//startVertex是起点
	//起点到终点的路径
	vector<int>path(numOfVertex);
	//刚开始起点到其他顶点的距离都为无穷大，除了自身
	vector<int>distance(numOfVertex, numeric_limits<int>::max());
	distance[startVertex] = 0;
	//查看某个点是否被访问
	vector<bool>visit(numOfVertex, false);

	//只需要找到numOfVertex-1个最小值就行，终点是不需要计算的
	for (int count = 0; count < numOfVertex - 1; count++) {
		int minIndex = findMinDistance(distance, visit);
		//如果最小值没有找到，有可能是图无法到达那个点，而其他可到达的点都已经被访问了
		if (minIndex == -1) {
			continue;
		}
		visit[minIndex] = true;

		//遍历邻接矩阵的这个minIndex的那一行，查看目前最小距离的点的邻居都有谁，然后更新起点到这些邻居的最短路径
		for (int j = 0; j < numOfVertex; j++) {
			//目标点没有被访问过  目标点是minIndex的邻居  
			if (visit[j] == false && adjacent[minIndex][j] && distance[minIndex] + adjacent[minIndex][j] < distance[j]) {
				//更新邻居的最短路径值
				distance[j] = distance[minIndex] + adjacent[minIndex][j];
				//更新该邻居点的前置点
				path[j] = minIndex;
			}
		}
	}

	cout << "最短路径大小为：" << distance[endVertex] << endl;
	cout << "最短路径：";
	cout << "古筝 <- ";
	while (endVertex != startVertex) {
		switch (path[endVertex])
		{
		case 0: {
			cout << "肖邦的乐谱";
		}break;
		case 1: {
			cout << "周杰伦唱片 <- ";
		}break;
		case 2: {
			cout << "陈奕迅限量版黑胶唱片 <- ";
		}break;
		case 3: {
			cout << "鼓 <- ";
		}break;
		case 4: {
			cout << "吉他 <-";
		}break;
		default:
			break;
		}
		endVertex = path[endVertex];
	}
	cout << endl;
}