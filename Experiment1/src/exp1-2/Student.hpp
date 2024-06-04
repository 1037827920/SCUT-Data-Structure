#include"SequenceList.hpp"

/*定义学生结构体*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 21时43分
*/
struct Student
{
	//学号
	ll number;
	//学生姓名
	string name;
	//成绩 采用课程名称作为键，课程分数作为值
	unordered_map<string, int>scores;

	/*构造函数*/
	Student() {}
	Student(ll n, string N) :
		number(n), name(N) {}
	Student(ll n, string N, unordered_map<string, int>s) :
		number(n), name(N), scores(s) {}

	//重载运算符
	bool operator<(const Student& temp)
	{
		return number < temp.number;
	}
	bool operator>(const Student& temp)
	{
		return number > temp.number;
	}

	//遍历scores容器中的元素
	void printScores()
	{
		if (scores.size() == 0)
		{
			cout << "该同学暂时未录入任何成绩!" << endl;
			return;
		}
		//创建一个临时的vector容器
		vector<pair<string, ll>> temp(scores.begin(), scores.end());
		//对vector容器的第二个元素按照从大到小的顺序排序
		sort(temp.begin(), temp.end(), [](const pair<string, ll>& a, const pair<string, ll>& b) {return a.second > b.second; });

		cout << setw(45) << "课程名" << setw(10) << "分数" << endl;
		for (int i = 0; i < temp.size(); i++)
		{
			cout <<setw(45) << temp[i].first << setw(10)<< temp[i].second << endl;
		}
	}
};