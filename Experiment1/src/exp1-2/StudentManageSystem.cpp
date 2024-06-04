#include"StudentManageSystem.h"

/*构造函数*/
StudentManageSystem::StudentManageSystem()
{
	filename = "data.txt";
	StudentManageSystem::readFile(filename);
}

/*析构函数*/
StudentManageSystem::~StudentManageSystem()
{

}

/*读取文件*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-07 19时03分
*/
void StudentManageSystem::readFile(string filename)
{
	ifstream inFile(filename);
	if (!inFile)
	{
		cerr << "文件打开失败！" << endl;
		return;
	}

	string line;
	while (getline(inFile, line))
	{
		std::istringstream iss(line);
		ll number;
		string name;
		//读取学号
		iss >> number;
		//读取姓名
		iss >> name;

		unordered_map<string, int>temp;
		string curriculumName;
		int score;
		//读取课程成绩
		while (iss >> curriculumName)
		{
			iss >> score;
			temp[curriculumName] = score;
		}

		Student newStudent(number, name, temp);
		StudentManageSystem::students.append(newStudent);
	}
	inFile.close();
}

/*保存文件*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-07 17时12分
*/
void StudentManageSystem::saveFile(string filename)
{
	ofstream outFile(filename);
	if (!outFile)
	{
		cerr << "文件打开失败！" << endl;
		return;
	}

	for (int i = 0; i < StudentManageSystem::students.length(); i++)
	{
		Student temp = StudentManageSystem::students.find(i);
		//保存学号和姓名
		outFile << temp.number << " " << temp.name << " ";
		//保存课程成绩
		vector<pair<string, int>> score(temp.scores.begin(), temp.scores.end());
		for (int j = 0; j < score.size(); j++)
		{
			outFile << score[j].first << " " << score[j].second << (j == score.size() - 1 ? "\n" : " ");
		}
	}
	outFile.close();
}

/*菜单显示*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-06 19时54分
*/
void StudentManageSystem::menu()
{
	cout << "                                ********************************" << endl;
	cout << "                                *                              *" << endl;
	cout << "                                *   欢迎使用学生管理系统       *" << endl;
	cout << "                                *                              *" << endl;
	cout << "                                * 输入对应的数字进行相应的操作 *" << endl;
	cout << "                                *                              *" << endl;
	cout << "                                *    0：退出学生管理系统       *" << endl;
	/*成绩查找
	* 1、根据学生信息查找其所有课程成绩
	*
	* 2、根据学生及课程名查找课程成绩
	*/
	cout << "                                *    1：成绩的查找             *" << endl;
	/*显示学生课程成绩*/
	cout << "                                *    2：显示学生课程成绩       *" << endl;
	/*添加学生信息*/
	cout << "                                *    3：添加学生信息           *" << endl;
	/*添加学生课程成绩*/
	cout << "                                *    4：添加学生课程成绩       *" << endl;
	/*删除学生课程成绩*/
	cout << "                                *    5：删除学生课程成绩       *" << endl;
	/*显示已录入学生的信息*/
	cout << "                                *    6：显示已录入的学生信息   *" << endl;
	/*删除学生信息*/
	cout << "                                *    7、删除学生信息           *" << endl;
	cout << "                                *                              *" << endl;
	cout << "                                ********************************" << endl;
	cout << ">请选择您的操作：" << endl;
	cout << ">";
}

/*成绩查找*/
void StudentManageSystem::searchScore()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++成绩查找+++++++++++++++++++++++++++++++++++++++++++++" << endl;
	//获取要查找的学生学号
	ll oldNumber;
	cout << ">请输入要查找的学生的学号：";
	cin >> oldNumber;

	if (oldNumber <= 0 || oldNumber > 9223372036845775807)
	{
		cout << ">输入的学号是违法的！" << endl;
		return;
	}
	//获取该同学在顺序表中的索引
	int pos = StudentManageSystem::findStudent(oldNumber);
	if (pos == -1)
	{
		cout << ">没有找到该同学！" << endl;
		return;
	}

	//获取要查询的课程名
	string curriculumName;
	cout << ">请输入要查找的课程名：";
	cin >> curriculumName;
	unordered_map<string, int>::iterator it = StudentManageSystem::students.find(pos).scores.find(curriculumName);
	if (it == StudentManageSystem::students.find(pos).scores.end())
	{
		cout << ">这位同学没有" << curriculumName << "的成绩" << endl;
		return;
	}

	cout << ">这位同学的" << curriculumName << "的成绩为" << StudentManageSystem::students.find(pos).scores[curriculumName] << endl;
}

/*显示学生课程成绩*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-06 23时36分
*/
void StudentManageSystem::showStudentScores()
{
	cout << "++++++++++++++++++++++++++++++++++++++显示学生所有课程成绩+++++++++++++++++++++++++++++++++++++++" << endl;
	//获得想要查找的同学的学号
	ll oldNumber;
	cout << ">请输入您要查找的同学的学号：";
	cin >> oldNumber;
	//判断输入的学号是否违法
	if (oldNumber <= 0 || oldNumber > 9223372036845775807)
	{
		cout << ">输入的学号是违法的！" << endl;
		return;
	}
	//获取该同学在顺序表中的索引
	int pos = StudentManageSystem::findStudent(oldNumber);
	if (pos == -1)
	{
		cout << ">没有找到该同学！" << endl;
		return;
	}

	StudentManageSystem::students.find(pos).printScores();
}
/*显示以录入学生的信息*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-06 20时04分
*/
void StudentManageSystem::showStudentInfo()
{
	cout << "++++++++++++++++++++++++++++++++++++++++已录入的学生信息+++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
	if (StudentManageSystem::students.length() == 0)
	{
		cout << ">目前还未录入任何同学的信息！" << endl;
		return;
	}
	StudentManageSystem::students.quickSort(0, students.length() - 1);
	cout << setw(45) << "学号" << setw(20) << "姓名" << endl;
	cout << "                              +------------------------------------------+" << endl << endl;
	for (int i = 0; i < StudentManageSystem::students.length(); i++)
	{
		cout << setw(45) << StudentManageSystem::students.find(i).number << setw(20) << StudentManageSystem::students.find(i).name << endl;
		cout << "                              +------------------------------------------+" << endl << endl;
	}
}

/*添加学生信息*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-06 19时55分
*/
void StudentManageSystem::addStudentInfo()
{
	cout << "+++++++++++++++++++++++++++++++++++++++++添加学生信息++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
	//获取学生学号
	ll newNumber;
	cout << ">请输入学生的学号：";
	cin >> newNumber;
	//判断输入的学号是否违法
	if (newNumber <= 0 || newNumber > 9223372036845775807)
	{
		cout << ">输入的学号是违法的！" << endl;
		return;
	}

	//先判断系统中是否已经录入该同学
	//如果没有，则继续后面的操作
	//如果有，则停止录入
	int pos = StudentManageSystem::findStudent(newNumber);
	if (pos != -1)
	{
		cout << ">系统中已经有了该同学的信息，无需重复录入" << endl;
		return;
	}

	//获取学生姓名
	string newName;
	cout << ">请输入学生的姓名：";
	cin >> newName;
	Student newStudent(newNumber, newName);
	StudentManageSystem::students.append(newStudent);
	cout << ">添加成功！" << endl;

	//每次添加学生后进行进行排序
	students.quickSort(0, students.length() - 1);

	//保存数据
	StudentManageSystem::saveFile(filename);
}

/*添加学生课程成绩*/
/*
* 学号：20223048028
* 姓名：黄铭涛
* 完成时间：2023-10-06 23时06分
*/
void StudentManageSystem::addStudentScore()
{
	cout << "+++++++++++++++++++++++++++++++++++++++添加学生课程成绩++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
	//获取学生学号
	ll oldNumber;
	cout << ">请输入要录入成绩的同学的学号：";
	cin >> oldNumber;
	//判断输入的学号是否违法
	if (oldNumber <= 0 || oldNumber > 9223372036845775807)
	{
		cout << ">输入的学号是违法的！" << endl;
		return;
	}
	//判断是否能找到该同学
	int pos = StudentManageSystem::findStudent(oldNumber);
	if (pos == -1)
	{
		cout << ">未找到该同学！" << endl;
		return;
	}

	//选择是只录入一门成绩还是多门
	int choice = -1;
	cout << ">请选择是录入一门成绩还是多门成绩（0：录入一门成绩；1：多门成绩）：";
	cin >> choice;

	string newCurriculemName;
	int newScore;

	if (choice == 0)
	{
		//获取课程名
		cout << ">请输入课程名：";
		cin >> newCurriculemName;
		//获取课程分数
		cout << ">请输入课程分数：";
		cin >> newScore;
		if (newScore < 0 || newScore>100)
		{
			cout << ">输入的分数不符合要求，请退出后重新输入" << endl;
			return;
		}

		StudentManageSystem::students.find(pos).scores[newCurriculemName] = newScore;
		cout << ">" << newCurriculemName << "成绩添加成功！" << endl;
	}
	else if (choice == 1)
	{
		while (1)
		{
			//获取课程名
			cout << ">请输入课程名：";
			cin >> newCurriculemName;
			//获取课程分数
			cout << ">请输入课程分数：";
			cin >> newScore;
			if (newScore < 0 || newScore>100)
			{
				cout << ">输入的分数不符合要求！请重新输入！" << endl;
				continue;
			}
			StudentManageSystem::students.find(pos).scores[newCurriculemName] = newScore;
			cout << ">" << newCurriculemName << "成绩添加成功！" << endl;
			int jugde = 0;
			cout << ">是否继续？（0：继续；1：结束）：";
			cin >> jugde;
			if (jugde == 1)
				break;
		}
	}


	//保存数据
	StudentManageSystem::saveFile(filename);
}

/*删除学生课程成绩*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-07 15时33分
*/
void StudentManageSystem::deleteStudentScore()
{
	cout << "+++++++++++++++++++++++++++++++++++++++删除学生课程成绩++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
	//获取要删除的学生的学号
	ll oldNumber;
	cout << ">请输入要删除的学生的学号：";
	cin >> oldNumber;
	//判断输入的学号是否违法
	if (oldNumber <= 0 || oldNumber > 9223372036845775807)
	{
		cout << ">输入的学号是违法的！" << endl;
		return;
	}
	//判断系统中是否有该同学的信息
	int pos = StudentManageSystem::findStudent(oldNumber);
	if (pos == -1)
	{
		cout << ">系统中没有找到该同学！" << endl;
		return;
	}

	//获取要删除的课程信息
	string curriculumName;
	cout << ">请输入要删除的学生的哪一门课程信息：";
	cin >> curriculumName;
	//判断该学生是否有这门课程的信息
	unordered_map<string, int>::iterator it = StudentManageSystem::students.find(pos).scores.find(curriculumName);
	if (it == StudentManageSystem::students.find(pos).scores.end())
	{
		cout << ">这位同学没有" << curriculumName << "这门成绩" << endl;
		return;
	}

	StudentManageSystem::students.find(pos).scores.erase(curriculumName);
	cout << ">删除成功！" << endl;

	//保存数据
	StudentManageSystem::saveFile(filename);
}

/*删除某个学生的信息*/
void StudentManageSystem::deleteStudent()
{
	cout << "++++++++++++++++++++++++++++++++++++++++删除学生信息++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
	//获取要删除的学生的学号
	ll oldNumber;
	cout << ">请输入要删除的学生的学号：";
	cin >> oldNumber;
	//判断输入的学号是否违法
	if (oldNumber <= 0 || oldNumber > 9223372036845775807)
	{
		cout << ">输入的学号是违法的！" << endl;
		return;
	}
	//判断系统中是否有该同学的信息
	int pos = StudentManageSystem::findStudent(oldNumber);
	if (pos == -1)
	{
		cout << ">系统中没有找到该同学！" << endl;
		return;
	}

	//删除操作
	StudentManageSystem::students.remove(pos);
	cout << ">删除成功！" << endl;

	//保存新文件
	StudentManageSystem::saveFile(filename);
}

/*根据学号查找学生操作*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-06 23时05分
*/
int StudentManageSystem::findStudent(ll number)const
{
	//定义双指针
	int left = 0;
	int right = StudentManageSystem::students.length() - 1;
	//开始查找
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (StudentManageSystem::students.find(mid).number == number)
		{
			return mid;
		}
		else if (StudentManageSystem::students.find(mid).number < number)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}