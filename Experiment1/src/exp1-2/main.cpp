#include"StudentManageSystem.h"

//设置窗口格式
void setWindow();
//隐藏光标
void setCursor();

int main()
{
	//设置窗口大小
	system("mode con cols=100 lines=25");
	//设置缓冲区大小
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD  coord = { 100,1000 };
	SetConsoleScreenBufferSize(hStdOutput, coord);
	//设置窗口格式
	setWindow();
	//隐藏光标
	setCursor();

	StudentManageSystem studentManageSystem;

	int choice = -1;

	studentManageSystem.menu();

	while (cin >> choice)
	{
		switch (choice)
		{
			/*退出系统*/
		case 0:
		{
			cout << ">退出成功！" << endl;
			return 0;
		}break;
		/*查找成绩*/
		case 1:
		{
			system("cls");
			studentManageSystem.searchScore();
		}break;
		/*显示学生课程成绩*/
		case 2:
		{
			system("cls");
			studentManageSystem.showStudentScores();
		}break;
		/*添加学生信息*/
		case 3:
		{
			system("cls");
			studentManageSystem.addStudentInfo();
		}break;
		/*添加学生课程成绩*/
		case 4:
		{
			system("cls");
			studentManageSystem.addStudentScore();;
		}break;
		/*删除学生课程成绩*/
		case 5:
		{
			system("cls");
			studentManageSystem.deleteStudentScore();
		}break;
		/*显示已录入学生信息*/
		case 6:
		{
			system("cls");
			studentManageSystem.showStudentInfo();
		}break;
		/*删除学生信息*/
		case 7:
		{
			system("cls");
			studentManageSystem.deleteStudent();
		}
		}
		cout << ">";
		system("pause");
		system("cls");
		studentManageSystem.menu();
	}
}

//设置窗口格式
void setWindow()
{
	HWND hwnd = GetConsoleWindow();
	LONG_PTR consoleStyle = GetWindowLongPtrA(hwnd, GWL_STYLE);
	//设置窗口格式：去除窗口最大化和最小化按钮
	consoleStyle = consoleStyle & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX;
	SetWindowLongPtrA(hwnd, GWL_STYLE, consoleStyle);

}

//隐藏光标
void setCursor()
{
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 1;

	//获取控制台句柄
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(consoleHandle, &cci);
}