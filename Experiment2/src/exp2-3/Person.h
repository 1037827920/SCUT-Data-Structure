#include"MyConsoleEngine.h"

class Person {
public:
	/*构造函数*/
	Person();
	Person(string n, vector<string>p,vector<string>mailbox);

	/*析构函数*/
	~Person();

	/*获取联系人信息*/
	string getName();
	vector<string> getPhoneNumber();
	vector<string> getMailbox();
	/*修改联系人信息*/
	void setName(string n);
	void addPhoneNumber(string p);
	void deletePhoneNumber(string p);
	void addMailbox(string m);
	void deleteMailbox(string m);

	/*查找手机号是否存在*/
	bool findPhoneNumber(string p);
	/*查找邮箱是否存在*/
	bool findMailbox(string m);

	/*输出该联系人的信息*/
	void showPerson();

	/*重载==*/
	bool operator==(const Person& other)const;
private:
	string name;
	vector<string> phoneNumber;
	vector<string> mailbox;
};
