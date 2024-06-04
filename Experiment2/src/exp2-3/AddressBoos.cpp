#include"AddressBook.h"

/*构造函数和析构函数*/
AddressBook::AddressBook() {
	readContacts();
}
AddressBook::~AddressBook() {
}

/*显示菜单*/
void AddressBook::menu() {
	cout << "                              *****************************" << endl;
	cout << "                              *   0、退出通讯录           *" << endl;
	cout << "                              *   1、新增联系人           *" << endl;
	cout << "                              *   2、编辑联系人信息       *" << endl;
	cout << "                              *   3、删除联系人           *" << endl;
	cout << "                              *   4、查找联系人通讯信息   *" << endl;
	cout << "                              *   5、显示所有联系人       *" << endl;
	cout << "                              *****************************" << endl;
	cout << ">请输入要进行的操作：";
}

/*新增联系人*/
void AddressBook::addContacts() {
	Person tPerson;
	string temp;
	cout << ">-------新增联系人-------" << endl;
	cout << ">输入姓名：";
	cin >> temp;
	tPerson.setName(temp);
	cout << ">输入手机号码(如果无则输入0)：";
	cin >> temp;
	if (temp != "0") {
		tPerson.addPhoneNumber(temp);
	}
	cout << ">输入邮箱(如果无则输入0)：";
	cin >> temp;
	if (temp != "0") {
		tPerson.addMailbox(temp);
	}

	hashTable.insert(tPerson);
	cout << ">新增成功！" << endl;
}

/*编辑联系人信息*/
void AddressBook::modifyContatcts() {
	cout << "-------编辑联系人信息-------" << endl;
	cout << ">输入要修改的联系人姓名：";
	string temp;
	cin >> temp;

	hashTable.modifyPerson(temp);
}

/*删除联系人*/
void AddressBook::deleteContacts() {
	cout << "-------删除联系人-------" << endl;
	string temp;
	cout << ">输入要删除联系人的姓名：";
	cin >> temp;

	Person tPerson;
	tPerson.setName(temp);
	hashTable.remove(tPerson);
}

/*查找联系人通讯信息*/
void AddressBook::findContacts() {
	cout << "-------查找联系人通讯信息-------" << endl;
	string temp;
	cout << ">输入要查找的联系人姓名：";
	cin >> temp;

	hashTable.searchPerson(temp);
}

/*显示所有联系人*/
void AddressBook::showAllContacts() {
	cout << "-------显示所有联系人-------" << endl;
	hashTable.showPerson();
}

/*读取文件*/
void AddressBook::readContacts() {
	hashTable.readPerson();
}
/*保存文件*/
void AddressBook::saveContacts() {
	hashTable.savePerson();
}