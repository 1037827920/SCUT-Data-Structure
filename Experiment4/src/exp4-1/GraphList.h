#include"MyConsoleEngine.h"

class GraphList {
private:
	int numOfVertex;
	list<int>* adjacent;

	/*添加边*/
	void m_addEdge(int v, int w);

	/*删除边*/
	void m_deleteEdge(int v, int w);

	/*增加点*/
	void m_addVertex();

	/*删除点*/
	void m_deleteVertex();

	/*广度优先遍历*/
	void m_bfs(int startVertex,vector<bool>& visit);

	/*深度优先遍历*/
	void m_dfs(int stratVertex,vector<bool>& visit);

public:
	/*构造函数*/
	GraphList(int num = 6);

	/*添加边*/
	void addEdge();

	/*删除边*/
	void deleteEdge();

	/*增加点*/
	void addVertex();

	/*删除点*/
	void deleteVertex();

	/*打印邻接链表*/
	void printList();

	/*广度优先遍历*/
	void bfs(int startVertex);

	/*深度优先遍历*/
	void dfs(int startVertex);
};