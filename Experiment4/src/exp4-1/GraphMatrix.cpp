#include"GraphMatrix.h"

/*私有函数*/
/*广度优先遍历*/
void GraphMatrix::m_bfs(int startVertex,vector<bool>& visit) {
	//访问第一个结点并将其入队
	cout << startVertex << " ";
	visit[startVertex] = true;
	queue<int>q;
	q.push(startVertex);

	//开始广度优先遍历
	while(!q.empty()){
		//取出队首
		int top = q.front();
		q.pop();

		//根据邻接矩阵看这个取出点的可访问点
		for (int i = 0; i < numOfVertex; i++) {
			if (matrix[top][i] == 1 && !visit[i]) {
				cout << i << " ";
				visit[i] = true;
				q.push(i);
			}
		}
	}
}

/*深度优先遍历*/
void GraphMatrix::m_dfs(int startVertex, vector<bool>& visit) {
	//访问到结点
	cout << startVertex << " ";
	visit[startVertex] = true;

	for (int i = 0; i < numOfVertex; i++) {
		if (matrix[startVertex][i] == 1 && !visit[i]) {
			m_dfs(i, visit);
		}
	}
}


/*添加边*/
void GraphMatrix::m_addEdge(int v, int w) {
	if (v == w || v < 0 || v >= numOfVertex || w < 0 || w >= numOfVertex) {
		cout << "输入的顶点是违法的！" << endl;
		return;
	}

	matrix[v][w] = 1;
	matrix[w][v] = 1;
}

/*删除边*/
void GraphMatrix::m_deleteEdge(int v, int w) {
	matrix[v][w] = 0;
	matrix[v][w] = 0;
}

/*增加点*/
void GraphMatrix::m_addVertex() {
	numOfVertex++;
	resizeMatrix(numOfVertex);
}

/*删除点*/
void GraphMatrix::m_deleteVertex() {
	numOfVertex--;
	resizeMatrix(numOfVertex);
}

/*公有函数*/
/*构造函数*/
GraphMatrix::GraphMatrix(int num) {
	numOfVertex = num;
	matrix.resize(numOfVertex, vector<int>(numOfVertex, 0));

	//构造初始图
	m_addEdge(0, 5);
	m_addEdge(0, 1);
	m_addEdge(0, 3);
	m_addEdge(3, 4);
	m_addEdge(1, 2);
}

/*重置邻接矩阵*/
void GraphMatrix::resizeMatrix(int num){
	vector<vector<int>> temp = matrix;
	matrix.resize(num, vector<int>(num, 0));
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].resize(num,0);
	}
	int size = temp.size() <= matrix.size() ? temp.size() : matrix.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = temp[i][j];
		}
	}
}

/*广度优先遍历*/
void GraphMatrix::bfs(int startVertex) {
	if (startVertex < 0 || startVertex >= numOfVertex) {
		cout << "不存在该顶点" << endl;
		return;
	}

	//存储结点的访问情况
	vector<bool>visit(numOfVertex, false);

	cout << "广度优先遍历图：";
	m_bfs(startVertex,visit);
	cout << endl;
}

/*深度优先遍历*/
void GraphMatrix::dfs(int startVertex) {
	if (startVertex < 0 || startVertex >= numOfVertex) {
		cout << "不存在该顶点" << endl;
		return;
	}

	//存储结点的访问情况
	vector<bool>visit(numOfVertex, false);

	cout << "深度优先遍历图：";
	m_dfs(startVertex, visit);
	cout << endl;
}

/*添加边*/
void GraphMatrix::addEdge() {
	cout << "输入两个顶点，为两个顶点添加一条边：";
	int v, w;
	cin >> v >> w;
	if (matrix[v][w] == 1) {
		cout << "这两个顶点已经存在边！不用重复添加！" << endl;
		return;
	}
	m_addEdge(v, w);
	cout << "添加成功！" << endl;
}

/*删除边*/
void GraphMatrix::deleteEdge() {
	cout << "输入两个顶点，删除这两个顶点的边：";
	int v, w;
	cin >> v >> w;
	if (matrix[v][w] == 0) {
		cout << "这两个顶点不存在边，无法删除！" << endl;
		return;
	}
	m_deleteEdge(v, w);
	cout << "删除成功！" << endl;
}

/*打印邻接矩阵*/
void GraphMatrix::printMatrix() {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

/*增加点*/
void GraphMatrix::addVertex() {
	m_addVertex();
	cout << "添加成功！" << endl;
}

/*删除点*/
void GraphMatrix::deleteVertex() {
	m_deleteVertex();
	cout << "删除成功！" << endl;
}