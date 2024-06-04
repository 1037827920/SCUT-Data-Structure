#include"AddressBook.h"


int main() {
	//实例化通讯录对象
	AddressBook addressBook;
	int choice = -1;

	addressBook.menu();
	while (cin >> choice) {

		switch (choice)
		{
		case 0:
			exit(0);
			break;
		case 1:
			addressBook.addContacts();
			break;
		case 2:
			addressBook.modifyContatcts();
			break;
		case 3:
			addressBook.deleteContacts();
			break;
		case 4:
			addressBook.findContacts();
			break;
		case 5:
			addressBook.showAllContacts();
			break;
		}
		addressBook.saveContacts();
		system("pause");
		system("cls");
		addressBook.menu();
	}

	return 0;
}
