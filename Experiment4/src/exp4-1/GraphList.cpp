#include"GraphList.h"

/*私有函数*/
/*添加边*/
void GraphList::m_addEdge(int v, int w) {
	adjacent[v].push_back(w);
	adjacent[w].push_back(v);
}

/*删除边*/
void GraphList::m_deleteEdge(int v, int w) {
	adjacent[v].remove(w);
	adjacent[w].remove(v);
}

/*增加点*/
void GraphList::m_addVertex() {
	list<int>* temp = adjacent;
	numOfVertex++;
	adjacent = new list<int>[numOfVertex];
	for (int i = 0; i < numOfVertex - 1; i++) {
		list<int>::iterator it = temp[i].begin();
		while (it != temp[i].end()) {
			adjacent[i].push_back(*it);
			it++;
		}
	}
}

/*删除点*/
void GraphList::m_deleteVertex() {
	list<int>* temp = adjacent;
	numOfVertex--;
	adjacent = new list<int>[numOfVertex];
	for (int i = 0; i < numOfVertex; i++) {
		list<int>::iterator it = temp[i].begin();
		while (it != temp[i].end()) {
			adjacent[i].push_back(*it);
			it++;
		}
	}
}

/*广度优先遍历*/
void GraphList::m_bfs(int startVertex,vector<bool>& visit) {
	//访问第一个结点并将其入队
	cout << startVertex << " ";
	visit[startVertex] = true;
	queue<int>q;
	q.push(startVertex);
	
	//开始遍历
	while (!q.empty()) {
		//出队
		int top = q.front();
		q.pop();

		//根据邻接链表看这个出队点的可访问点
		list<int>temp = adjacent[top];
		list<int>::iterator it = temp.begin();
		while (it != temp.end()) {
			if (visit[*it] == false) {
				cout << *it << " ";
				visit[*it] = true;
				q.push(*it);
			}
			it++;
		}
	}
}

/*深度优先遍历*/
void GraphList::m_dfs(int startVertex, vector<bool>& visit) {
	cout << startVertex << " ";
	visit[startVertex] = true;

	list<int>temp = adjacent[startVertex];
	list<int>::iterator it = temp.begin();
	while (it != temp.end()) {
		if (visit[*it] == false) {
			m_dfs(*it, visit);
		}
		it++;
	}
}

/*公有函数*/
/*构造函数*/
GraphList::GraphList(int num) {
	numOfVertex = num;
	adjacent = new list<int>[num];

	//构造初始图
	m_addEdge(0, 5);
	m_addEdge(0, 1);
	m_addEdge(0, 3);
	m_addEdge(3, 4);
	m_addEdge(1, 2);
}

/*添加边*/
void GraphList::addEdge() {
	cout << "输入两个顶点，为两个顶点添加一条边：";
	int v, w;
	cin >> v >> w;
	list<int>temp = adjacent[v];
	list<int>::iterator it = temp.begin();
	while (it != temp.end()) {
		if (*it == w) {
			cout << "这两个顶点已经存在边！" << endl;
			return;
		}
		it++;
	}
	m_addEdge(v, w);
	cout << "添加成功！" << endl;
}

/*删除边*/
void GraphList::deleteEdge() {
	cout << "输入两个顶点，删除这两个顶点的边：";
	int v, w;
	cin >> v >> w;
	list<int>temp = adjacent[v];
	list<int>::iterator it = temp.begin();
	while (it != temp.end()) {
		if (*it == w) {
			m_deleteEdge(v, w);
			cout << "删除成功！" << endl;
			return;
		}
		it++;
	}
	
	cout << "这两个顶点不存在边，无法删除！" << endl;
}

/*增加点*/
void GraphList::addVertex() {
	m_addVertex();
	cout << "添加成功！" << endl;
}

/*删除点*/
void GraphList::deleteVertex() {
	m_deleteVertex();
	cout << "删除成功！" << endl;
}

/*打印邻接链表*/
void GraphList::printList() {
	for (int i = 0; i < numOfVertex; i++){
		cout << i << "->";
		list<int>::iterator it = adjacent[i].begin();
		while (it != adjacent[i].end()) {
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
}

/*广度优先遍历*/
void GraphList::bfs(int startVertex) {
	if (startVertex < 0 || startVertex >= numOfVertex) {
		cout << "不存在该顶点" << endl;
		return;
	}

	//存储结点的访问情况
	vector<bool>visit(numOfVertex, false);

	cout << "广度优先遍历图：";
	m_bfs(startVertex, visit);
	cout << endl;
}

/*深度优先遍历*/
void GraphList::dfs(int startVertex) {
	if (startVertex < 0 || startVertex >= numOfVertex) {
		cout << "不存在该顶点" << endl;
		return;
	}
	
	vector<bool>visit(numOfVertex, false);

	cout << "深度优先遍历图：";
	m_dfs(startVertex, visit);
	cout << endl;
}