#include"Person.h"

/*构造函数*/
Person::Person() {}
Person::Person(string n, vector<string>p, vector<string>m) {
	name = n;
	phoneNumber = p;
	mailbox = m;
}

/*析构函数*/
Person::~Person() {}

/*获取联系人信息*/
string Person::getName() {
	return name;
}
vector<string> Person::getPhoneNumber() {
	return phoneNumber;
}
vector<string> Person::getMailbox() {
	return mailbox;
}
/*修改联系人信息*/
void Person::setName(string n) {
	name = n;
	return;
}
void Person::addPhoneNumber(string p) {
	if (find(phoneNumber.begin(), phoneNumber.end(), p) != phoneNumber.end()) {
		cout << ">该电话号码已存在于该联系人中！" << endl;
		return;
	}
	phoneNumber.push_back(p);
	return;
}
void Person::deletePhoneNumber(string p) {
	vector<string>::iterator it = find(phoneNumber.begin(), phoneNumber.end(), p);
	if (it == phoneNumber.end()) {
		cout << ">该联系人不存在此电话号码！" << endl;
		return;
	}
	phoneNumber.erase(it);
	return;
}
void Person::addMailbox(string m) {
	if (find(mailbox.begin(), mailbox.end(), m) != mailbox.end()) {
		cout << ">该邮箱已存在于该联系人中！" << endl;
		return;
	}
	mailbox.push_back(m);
	return;
}
void Person::deleteMailbox(string m) {
	vector<string>::iterator it = find(mailbox.begin(), mailbox.end(), m);
	if (it == mailbox.end()) {
		cout << ">该联系人不存在此邮箱！" << endl;
		return;
	}
	mailbox.erase(it);
	return;
}

/*查找手机号是否存在*/
bool Person::findPhoneNumber(string p) {
	vector<string>::iterator it = find(phoneNumber.begin(), phoneNumber.end(), p);

	if (it == phoneNumber.end()) {
		return false;
	}

	return true;
}
/*查找邮箱是否存在*/
bool Person::findMailbox(string m) {
	vector<string>::iterator it = find(mailbox.begin(), mailbox.end(), m);

	if (it == mailbox.end()) {
		return false;
	}

	return true;
}

/*输出该联系人的信息*/
void Person::showPerson() {
	cout << "姓名：\t\t" << name << endl;
	if(phoneNumber.size()!=0)
		cout << "电话号码：\t";
	for (int i = 0; i < phoneNumber.size(); i++) {
		cout << phoneNumber[i] << endl;
		cout << (i == phoneNumber.size()-1 ? "":"          \t");
	}
	if (mailbox.size() != 0)
		cout << "邮箱：\t\t";
	for (int i = 0; i < mailbox.size(); i++) {
		cout << mailbox[i] << endl;
		cout << (i == mailbox.size() - 1 ? "" : "      \t\t");
	}
	return;
}

/*重载==*/
bool Person::operator==(const Person& other) const{
	return this->name == other.name;
}