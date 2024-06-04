#include"HashTable.h"

/*
*					private
*/
/*属于这个散列表的散列函数*/
int HashTable::myHash(string key)const{
	int hashValue = 0;

	for (int i = 0; i < key.size(); i++) {
		hashValue = 37 * hashValue + key[i];
	}

	hashValue %= theLists.size();
	if (hashValue < 0) {
		hashValue += theLists.size();
	}

	return hashValue;
}
/*对散列表进行扩容*/
void HashTable::rehash() {
	//保存老的散列表
	vector<list<Person> >oldLists = theLists;

	//为新的散列表定义好容量
	theLists.resize(nextPrime(2 * theLists.size()));
	//清空每个链表
	for (int i = 0; i < theLists.size(); i++) {
		theLists[i].clear();
	}

	currentSize = 0;
	for (int i = 0; i <= oldLists.size(); i++) {
		list<Person>::iterator it = oldLists[i].begin();
		while (it != oldLists[i].end()) {
			insert(*it++);
		}
	}
}

/*判断质数*/
bool HashTable::isPrime(int n) {
	if (n < 2) {
		return false;
	}
	else if (n > 2) {
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				return false;
			}
		}
	}

	return true;
}
/*下一个质数*/
int HashTable::nextPrime(int n) {
	if (n < 2) {
		return 2;
	}
	while (!isPrime(++n)) {

	}

	return n;
}



/*
*					public
*/
/*构造函数*/
HashTable::HashTable() {
	theLists.resize(5);//初始设置为5
	currentSize = 0;//初始存放值为0
	makeEmpty();
}

/*析构函数*/
HashTable::~HashTable() {

}

/*判断某个键是否在散列表中*/
bool HashTable::contains(Person& x) const {
	const list<Person>& which = theLists[myHash(x.getName())];
	return find(which.begin(), which.end(), x) != which.end();
}

/*清空散列表*/
void HashTable::makeEmpty() {
	for (int i = 0; i < theLists.size(); i++) {
		theLists[i].clear();
	}
}
/*添加键*/
void HashTable::insert(Person& x) {
	list<Person>& whichList = theLists[myHash(x.getName())];
	if (find(whichList.begin(), whichList.end(), x) != whichList.end()) {
		cout << ">该联系人已经存在于通讯录中！" << endl;
		return;
	}
	whichList.push_back(x);

	if (++currentSize > theLists.size()) {
		rehash();
	}

	return;
}
/*移除键*/
void HashTable::remove(Person& x) {
	list<Person>& whichList = theLists[myHash(x.getName())];
	list<Person>::iterator it = find(whichList.begin(), whichList.end(), x);

	if (it == whichList.end()) {
		cout<<">该联系人不存在于通讯录！"<<endl;
		return;
	}

	whichList.erase(it);
	currentSize--;
	cout << ">删除成功！" << endl;
	return;
}

/*搜索联系人通讯信息*/
void HashTable::searchPerson(const string& key) {
	list<Person>& whichList = theLists[myHash(key)];
	Person tPerson;
	tPerson.setName(key);
	list<Person>::iterator it = find(whichList.begin(), whichList.end(), tPerson);

	if (it == whichList.end()) {
		cout << ">未找到该联系人！" << endl;
		return;
	}
	(*it).showPerson();
}
/*编辑联系人信息*/
void HashTable::modifyPerson(const string& key) {
	list<Person>& whichList = theLists[myHash(key)];
	Person tPerson;
	tPerson.setName(key);
	list<Person>::iterator it = find(whichList.begin(), whichList.end(), tPerson);

	if (it == whichList.end()) {
		cout << ">未找到该联系人！" << endl;
		return;
	}

	cout << ">1、增加手机号码" << endl;
	cout << ">2、删除手机号码" << endl;
	cout << ">3、修改手机号码" << endl;
	cout << ">4、增加邮箱" << endl;
	cout << ">5、删除邮箱" << endl;
	cout << ">6、修改邮箱" << endl;

	int choice = -1;
	cout << ">输入要进行的操作：";
	cin >> choice;
	switch (choice)
	{
	case 1: {
		cout << ">输入要增加的手机号：";
		string temp;
		cin >> temp;
		(*it).addPhoneNumber(temp);
		cout << ">增加成功！" << endl;
	}
		break;
	case 2: {
		cout << ">输入要删除的手机号：";
		string temp;
		cin >> temp;
		(*it).deletePhoneNumber(temp);
		cout << ">删除成功！" << endl;
	}
		break;
	case 3: {
		cout << ">输入要修改的手机号：";
		string temp;
		cin >> temp;
		bool isFind = (*it).findPhoneNumber(temp);
		if (!isFind) {
			cout << ">没有找到该手机号！" << endl;
			return;
		}
		//删除老的手机号
		(*it).deletePhoneNumber(temp);
		cout << ">输入修改后的手机号：";
		cin >> temp;
		//增加新的手机号
		(*it).addPhoneNumber(temp);
		cout << ">修改成功！" << endl;
	}
		break;
	case 4: {
		cout << ">输入要增加的邮箱：";
		string temp;
		cin >> temp;
		(*it).addMailbox(temp);
		cout << ">增加成功！" << endl;
	}
		break;
	case 5: {
		cout << ">输入要删除的邮箱：";
		string temp;
		cin >> temp;
		(*it).deleteMailbox(temp);
		cout << ">删除成功！" << endl;
	}
		break;
	case 6: {
		cout << ">输入要修改的邮箱：";
		string temp;
		cin >> temp;
		bool isFind = (*it).findMailbox(temp);
		if (!isFind) {
			cout << ">没有找到该邮箱！" << endl;
			return;
		}
		//删除老的邮箱
		(*it).deleteMailbox(temp);
		cout << ">输入修改后的邮箱：";
		cin >> temp;
		//增加新的邮箱
		(*it).addMailbox(temp);
		cout << ">修改成功！" << endl;
	}
		break;
	default:
		break;
	}
}

/*显示联系人信息*/
void HashTable::showPerson() {
	if (theLists.size() == 0) {
		cout << "该通讯录暂时未录入任何信息！" << endl;
		return;
	}

	for (int i = 0; i < theLists.size(); i++) {
		list<Person>::iterator it = theLists[i].begin();

		while (it != theLists[i].end()) {
			(*it).showPerson();
			it++;
			cout << "----------------------------" << endl;
		}
	}
}

/*读取文件*/
void HashTable::readPerson() {
	ifstream inFile("data.txt");
	if (!inFile) {
		cout << "文件读取失败！" << endl;
		return;
	}

	string line1;
	while(getline(inFile,line1)) {
		//读取第一行——姓名
		istringstream iss1(line1);
		string tName;
		iss1 >> tName;

		//读取第二行——电话号码
		string line2;
		getline(inFile, line2);
		istringstream iss2(line2);
		vector<string>tPhoneNumber;
		string temp;
		while (iss2 >> temp) {
			tPhoneNumber.push_back(temp);
		}

		//读取第三行——邮箱
		string line3;
		getline(inFile, line3);
		istringstream iss3(line3);
		vector<string>tMailbox;
		while (iss3 >> temp) {
			tMailbox.push_back(temp);
		}

		Person p(tName, tPhoneNumber, tMailbox);
		insert(p);
	}

	inFile.close();
}
/*写入文件*/
void HashTable::savePerson() {
	ofstream outFile("data.txt");
	if (!outFile) {
		cout << "文件写入失败！" << endl;
		return;
	}

	for (int i = 0; i < theLists.size(); i++) {
		list<Person>::iterator it = theLists[i].begin();
		while (it != theLists[i].end()) {
			outFile << (*it).getName() << endl;
			vector<string>p = (*it).getPhoneNumber();
			for (int j = 0; j < p.size(); j++) {
				outFile << p[j] << " ";
			}
			outFile << endl;
			vector<string>m = (*it).getMailbox();
			for (int j = 0; j < m.size(); j++) {
				outFile << m[j] << " ";
			}
			outFile << endl;
			it++;
		}
	}
	
	outFile.close();
}