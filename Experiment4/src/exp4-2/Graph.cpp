#include"Graph.h"

/*私有函数*/
/*计算每个顶点的入度*/
void Graph::findInDegree(){
	for (int i = 0; i < numOfVertex; i++) {
		inDegree[i] = 0;
	}

	//遍历邻接链表，计算顶点入度
	for (int i = 0; i < numOfVertex; i++) {
		list<int>temp = adjacent[i];
		list<int>::iterator it = temp.begin();
		while (it != temp.end()) {
			inDegree[*it]++;
			it++;
		}
	}
}


/*公有函数*/
/*构造函数*/
Graph::Graph(int num) {
	numOfVertex = num;
	adjacent.resize(num);
	inDegree.resize(num,0);
	topolo.resize(num, 0);
}

/*添加边*/
void Graph::addEdge(int v, int w) {
	adjacent[v].push_back(w);
}

/*删除边*/
void Graph::deleteEdge(int v, int w) {
	list<int>&temp = adjacent[v];
	temp.remove(w);
}

/*输出每个顶点的入度*/
void Graph::printInDegree(){
	findInDegree();
	for (int i = 0; i < inDegree.size(); i++) {
		cout << inDegree[i] << " ";
	}
	cout << endl;
}

/*拓扑排序*/
bool  Graph::TopologicalSort() {

	//计算每个顶点的入度
	findInDegree();
	//创栈来存放入度为0的顶点
	queue<int>q;
	for (int i = 0; i < inDegree.size(); i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	int count = 0;//计数已经排序的点
	while (!q.empty()) {
		//出队
		int top = q.front();
		q.pop();
		//拓扑排序
		topolo[count++] = top;
		
		//对顶点入度进行更新
		list<int>temp = adjacent[top];
		list<int>::iterator it = temp.begin();
		while (it != temp.end()) {
			inDegree[*it]--;
			
			//如果入度为0，继续压入栈中
			if (inDegree[*it] == 0) {
				q.push(*it);
			}

			it++;
		}
	}

	if (count < numOfVertex) return false;
	else return true;
}

/*输出拓扑排序序列*/
void Graph::printTopo() {
	cout << "拓扑排序：";
	for (int i = 0; i < topolo.size(); i++) {
		cout << topolo[i] << " ";
	}
	cout << endl;
}