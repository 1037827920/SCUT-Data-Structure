#include"Graph.h"

int main() {
	/*
	* 0：肖邦的乐谱
	* 1：周杰伦海报
	* 2：陈奕迅限量版黑胶唱片
	* 3：鼓
	* 4：吉他
	* 5：古筝
	*/
	Graph g(6);
	g.addEdge(0, 1, 0);
	g.addEdge(0, 2, 50);
	g.addEdge(1, 3, 300);
	g.addEdge(2, 3, 150);
	g.addEdge(1, 4, 350);
	g.addEdge(2, 4, 200);
	g.addEdge(3, 5, 100);
	g.addEdge(4, 5, 200);

	g.dijkstra(0,5);

	system("pause");
	return 0;
}