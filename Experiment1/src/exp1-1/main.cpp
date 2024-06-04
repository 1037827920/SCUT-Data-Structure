#include"List.hpp"

/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 16时09分
*/
int main()
{
	string filename = "test01.txt";
	cout << "***************************" << endl;
	cout << "创建四班学号的变长顺序表" << endl;
	SequenceList<string>fourClass;
	cout << "创建成功！" << endl;
	cout << "***************************" << endl << endl;

	cout << "***************************" << endl;
	cout << "判断顺序表是否为空" << endl;
	fourClass.isEmpty();
	cout << "***************************" << endl << endl;

	cout << "***************************" << endl;
	cout << "开始初始化顺序表" << endl;
	fourClass.init(filename);
	cout << "初始化成功！" << endl;
	cout << "***************************" << endl << endl;

	cout << "***************************" << endl;
	cout << "判断顺序表是否为空" << endl;
	fourClass.isEmpty();
	cout << "***************************" << endl << endl;

	cout << "***************************" << endl;
	cout << "开始遍历顺序表" << endl;
	fourClass.print();
	cout << "遍历成功！" << endl;
	cout << "***************************" << endl << endl;

	system("pause");
	cout << "***************************" << endl;
	cout << "插入新数据" << endl;
	fourClass.append("202230480151");
	cout << "大小为：" << fourClass.length() << endl;
	cout << "开始遍历顺序表" << endl;
	fourClass.print();
	cout << "遍历成功！" << endl;
	cout << "***************************" << endl;
	
	system("pause");
	cout << "***************************" << endl;
	cout << "删除一个数据" << endl;
	fourClass.remove(0);
	cout << "大小为：" << fourClass.length() << endl;
	cout << "开始遍历顺序表" << endl;
	fourClass.print();
	cout << "遍历成功！" << endl;
	cout << "***************************" << endl << endl;

	cout << "***************************" << endl;
	cout << "删除两个数据" << endl;
	fourClass.remove(0);
	cout << "大小为：" << fourClass.length() << endl;
	cout << "开始遍历顺序表" << endl;
	fourClass.print();
	cout << "遍历成功！" << endl;
	cout << "***************************" << endl << endl;

	cout << "***************************" << endl;
	cout << "删除三个数据" << endl;
	fourClass.remove(0);
	cout << "大小为：" << fourClass.length() << endl;
	cout << "开始遍历顺序表" << endl;
	fourClass.print();
	cout << "遍历成功！" << endl;
	cout << "***************************" << endl << endl;

	cout << "***************************" << endl;
	cout << "删除四个数据" << endl;
	fourClass.remove(0);
	cout << "大小为：" << fourClass.length() << endl;
	cout << "开始遍历顺序表" << endl;
	fourClass.print();
	cout << "遍历成功！" << endl;
	cout << "***************************" << endl << endl;

	cout << "***************************" << endl;
	cout << "删除五个数据" << endl;
	fourClass.remove(0);
	cout << "大小为：" << fourClass.length() << endl;
	cout << "开始遍历顺序表" << endl;
	fourClass.print();
	cout << "遍历成功！" << endl;
	cout << "***************************" << endl << endl;
	system("pause");

	cout << "***************************" << endl;
	cout << "输出特定位置的元素" << endl;
	cout << "第2个位置的元素为" << fourClass.find(2) << endl;
	cout << "***************************" << endl << endl;

	cout << "***************************" << endl;
	cout << "在特定位置插入新元素" << endl;
	string newData = "202230091036";
	fourClass.insert(2, newData);
	cout << "插入成功！" << endl;
	cout << "***************************" << endl << endl;

	cout << "***************************" << endl;
	cout << "输出特定位置的元素" << endl;
	cout << "第2个位置的元素为" << fourClass.find(2) << endl;
	cout << "***************************" << endl << endl;

	cout << "***************************" << endl;
	cout << "输出特定元素的位置" << endl;
	cout << "元素为202230483381的位置为" << fourClass.at("202230483381") << endl;
	cout << "***************************" << endl << endl;

	cout << "***************************" << endl;
	cout << "输出特定元素的位置" << endl;
	cout << "元素为202230483381的位置为" << fourClass.at("202230483381") << endl;
	cout << "***************************" << endl << endl;

	cout << "***************************" << endl;
	cout << "该顺序表的大小为" << fourClass.length() << endl;
	cout << "***************************" << endl << endl;

	system("pause");
	return 0;
}