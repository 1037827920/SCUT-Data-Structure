#include"GraphMatrix.h"
#include"GraphList.h"

/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023.11.29 00:00
*/

int main() {
	//邻接矩阵 
	GraphMatrix gm1;
	int choice = 0;

	bool isExecute = true;
	while (isExecute) {
		cout << setw(50) << "------邻接矩阵------" << endl;
		cout << "0、退出对邻接矩阵的操作" << endl;
		cout << "1、增加边" << endl;
		cout << "2、删除边" << endl;
		cout << "3、增加点(只能继续往后增加)" << endl;
		cout << "4、删除点(只能删除序号最大的点)" << endl;
		cout << "5、遍历图" << endl;
		cout << "6、遍历邻接矩阵" << endl;
		cout << "输入要进行的操作：";
		cin >> choice;
		switch (choice)
		{
		case 0: {
			isExecute = false;
		}break;
		case 1: {
			gm1.addEdge();
		}break;
		case 2: {
			gm1.deleteEdge();
		}break;
		case 3: {
			//只能继续往后增加
			gm1.addVertex();
		}break;
		case 4: {
			//只能删除序号最大的点
			gm1.deleteVertex();
		}break;
		case 5: {
			cout << "输入要从哪个顶点开始遍历：" ;
			int v;
			cin >> v;
			gm1.bfs(v);
			cout << endl;
			gm1.dfs(v);
			cout << endl;
			
		}break;
		case 6: {
			gm1.printMatrix();
		}break;
		default:
			break;
		}

		system("pause");
		system("cls");
	}

	//邻接链表
	GraphList gm2;
	choice = 0;

	isExecute = true;
	while (isExecute) {
		cout << setw(50) << "------邻接链表------" << endl;
		cout << "0、退出对邻接链表的操作" << endl;
		cout << "1、增加边" << endl;
		cout << "2、删除边" << endl;
		cout << "3、增加点(只能继续往后增加)" << endl;
		cout << "4、删除点(只能删除序号最大的点)" << endl;
		cout << "5、遍历图" << endl;
		cout << "6、遍历邻接链表" << endl;
		cout << "输入要进行的操作：";
		cin >> choice;
		switch (choice)
		{
		case 0: {
			isExecute = false;
		}break;
		case 1: {
			gm2.addEdge();
		}break;
		case 2: {
			gm2.deleteEdge();
		}break;
		case 3: {
			//只能继续往后增加
			gm2.addVertex();
		}break;
		case 4: {
			//只能删除序号最大的点
			gm2.deleteVertex();
		}break;
		case 5: {
			cout << "输入要从哪个顶点开始遍历：";
			int v;
			cin >> v;
			gm2.bfs(v);
			cout << endl;
			gm2.dfs(v);
			cout << endl;

		}break;
		case 6: {
			gm2.printList();
		}break;
		default:
			break;
		}

		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}