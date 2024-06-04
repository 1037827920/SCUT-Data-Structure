#include"Student.hpp"

class StudentManageSystem
{
public:
	/*构造函数*/
	StudentManageSystem();

	/*析构函数*/
	~StudentManageSystem();

	/*读取文件*/
	void readFile(string filename);

	/*保存文件*/
	void saveFile(string filename);

	/*菜单显示*/
	void menu();

	/*成绩查找*/
	void searchScore();

	/*显示学生课程成绩*/
	void showStudentScores();
	/*显示以录入学生的信息*/
	void showStudentInfo();

	/*添加学生信息*/
	void addStudentInfo();

	/*添加学生课程成绩*/
	void addStudentScore();

	/*删除学生课程成绩*/
	void deleteStudentScore();

	/*删除某个学生的信息*/
	void deleteStudent();

	//根据学号查找学生操作
	int findStudent(ll number)const;

private:
	//储存学生的信息
	SequenceList<Student> students;
	//读写文件名
	string filename;
};