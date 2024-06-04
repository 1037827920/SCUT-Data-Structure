#include"MyConsoleEngine.h"

//无向图邻接矩阵
class GraphMatrix {
private:
	//邻接矩阵
	vector<vector<int> >matrix;
	//顶点数
	int numOfVertex;

	/*广度优先遍历*/
	void m_bfs(int startVertex,vector<bool>&visit);

	/*深度优先遍历*/
	void m_dfs(int stratVertex,vector<bool>&visit);

	/*添加边*/
	void m_addEdge(int v, int w);

	/*删除边*/
	void m_deleteEdge(int v, int w);

	/*增加点*/
	void m_addVertex();

	/*删除点*/
	void m_deleteVertex();

public:
	/*构造函数*/
	GraphMatrix(int num = 6);

	/*重置邻接矩阵*/
	void resizeMatrix(int num);

	/*广度优先遍历*/
	void bfs(int startVertex);

	/*深度优先遍历*/
	void dfs(int startVertex);

	/*添加边*/
	void addEdge();

	/*删除边*/
	void deleteEdge();

	/*打印邻接矩阵*/
	void printMatrix();

	/*增加点*/
	void addVertex();

	/*删除点*/
	void deleteVertex();
};