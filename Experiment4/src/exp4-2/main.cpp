#include"Graph.h"

int main() {
	Graph g1(8);//有向无环图
	g1.addEdge(0, 2);
	g1.addEdge(0, 3);
	g1.addEdge(1, 3);
	g1.addEdge(1, 4);
	g1.addEdge(2, 5);
	g1.addEdge(3, 5);
	g1.addEdge(4, 6);
	g1.addEdge(5, 7);
	g1.addEdge(6, 7);
	Graph g2(4);//有向有环图
	g2.addEdge(0, 1);
	g2.addEdge(1, 3);
	g2.addEdge(3, 2);
	g2.addEdge(2, 1);

	cout << "图1是否能存在回路？" << endl;
	if (g1.TopologicalSort()) {
		cout << "不存在！" << endl;
		g1.printTopo();
	}
	else {
		cout << "存在！" << endl;
	}
	cout << "图2是否存在回路？" << endl;
	if (g2.TopologicalSort()) {
		cout << "不存在！" << endl;
		g2.printTopo();
	}
	else {
		cout << "存在！" << endl;
	}

	return 0;
}