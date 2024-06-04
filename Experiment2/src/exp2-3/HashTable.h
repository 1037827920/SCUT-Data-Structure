#include"MyConsoleEngine.h"
#include"Person.h"

class HashTable {
public:
	/*构造函数*/
	HashTable();

	/*析构函数*/
	~HashTable();

	/*判断某个键是否在散列表中*/
	bool contains(Person& x) const;

	/*清空散列表*/
	void makeEmpty();
	/*添加键*/
	void insert(Person& x);
	/*移除键*/
	void remove(Person& x);
	
	/*搜索联系人通讯信息*/
	void searchPerson(const string&key);
	/*编辑联系人信息*/
	void modifyPerson(const string&key);
	/*显示联系人信息*/
	void showPerson();

	/*读取文件*/
	void readPerson();
	/*写入文件*/
	void savePerson();

private:
	//存放键的容器，使用链地址法解决冲突
	vector<list<Person> >theLists;
	//目前存放的大小
	int currentSize;

	/*属于这个散列表的散列函数*/
	int myHash(string key)const;
	/*对散列表进行扩容*/
	void rehash();

	/*判断质数*/
	bool isPrime(int n);
	/*下一个质数*/
	int nextPrime(int n);
};