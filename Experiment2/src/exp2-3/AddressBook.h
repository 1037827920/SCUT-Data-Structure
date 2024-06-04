#include"HashTable.h"

class AddressBook {
public:
	/*构造函数和析构函数*/
	AddressBook();
	~AddressBook();

	/*显示菜单*/
	void menu();

	/*新增联系人*/
	void addContacts();

	/*编辑联系人信息*/
	void modifyContatcts();

	/*删除联系人*/
	void deleteContacts();

	/*查找联系人通讯信息*/
	void findContacts();

	/*显示所有联系人*/
	void showAllContacts();

	/*读取文件*/
	void readContacts();
	/*保存文件*/
	void saveContacts();

private:
	HashTable hashTable;

};