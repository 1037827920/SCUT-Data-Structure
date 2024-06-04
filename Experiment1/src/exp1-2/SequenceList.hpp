#include<fstream>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
#include<string>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<Windows.h>
#include<iomanip>

#define MORE_CAPACITY 10
#define ll long long

using std::ifstream;
using std::ofstream;
using std::string;
using std::unordered_map;
using std::vector;
using std::pair;
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::setw;

/*变长顺序表的声明*/
template<class Object>
class SequenceList
{
public:
	/*构造函数*/
	SequenceList();
	SequenceList(const SequenceList<Object>& temp);
	/*析构函数*/
	~SequenceList();

	/*初始化顺序表*/
	void init(string filename = "test01.txt");

	/*调整容量*/
	void resize(int choice);

	/*插入元素*/
	//在pos前面插入元素
	void insert(int pos, const Object& data);

	/*移除元素*/
	//删除pos位置的元素
	void remove(int pos);

	/*追加元素*/
	void append(const Object& data);

	/*遍历元素*/
	void print();

	/*输出指定元素的位置*/
	int at(const Object& data) const;

	/*输出指定位置的元素*/
	Object& find(int pos);
	const Object& find(int pos) const;

	/*判断顺序表是否为空*/
	void isEmpty();

	/*获得顺序表元素数量*/
	int length() const;

	/*快速排序*/
	void quickSort(int left, int right);

private:
	int size;
	int capacity;

	//存放数据的数组 这里用指针，因为大小是可变的
	Object* array;
};



/*变长顺序表的实现*/
/*构造函数*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 15时38分
* 这部分代码时间复杂度为O(1)
*/
template<class Object>
SequenceList<Object>::SequenceList()
{
	SequenceList<Object>::size = 0;
	SequenceList<Object>::capacity = MORE_CAPACITY;
	SequenceList<Object>::array = new Object[SequenceList<Object>::capacity];
}
template<class Object>
//这部分代码时间复杂度为O(n),n为temp的元素数量
SequenceList<Object>::SequenceList(const SequenceList<Object>& temp)
{
	SequenceList<Object>::size = temp.size;
	SequenceList<Object>::capacity = MORE_CAPACITY + SequenceList<Object>::size;
	SequenceList<Object>::array = new Object[SequenceList<Object>::capacity];
	for (int i = 0; i < temp.size; i++)
	{
		SequenceList<Object>::array[i] = temp.array[i];
	}
}
/*析构函数*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 15时41分
* 这部分代码时间复杂度为O(1)
*/
template<class Object>
SequenceList<Object>::~SequenceList()
{

}

/*初始化顺序表*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 15时37分
* 这部分代码时间复杂度为O(n)，n为被读取文件的行数
*/
template<class Object>
void SequenceList<Object>::init(string filename)
{
	ifstream inFile(filename);
	if (!inFile)
	{
		cerr << "文件不存在！" << endl;
	}
	else
	{
		SequenceList<Object>::capacity = MORE_CAPACITY;
		SequenceList<Object>::array = new Object[SequenceList<Object>::capacity];
		if (inFile.peek() == ifstream::traits_type::eof())
		{
			cout << "文件为空" << endl;
			SequenceList<Object>::size = 0;
		}
		else
		{
			Object line;
			while (getline(inFile, line))
			{
				SequenceList<Object>::append(line);
				SequenceList<Object>::resize();
			}
			cout << "文件读取完成" << endl;
		}
	}
	inFile.close();
}

/*调整容量(自动的)*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 00时10分
* 这部分代码时间复杂度为O(n)
*/
template<class Object>
void SequenceList<Object>::resize(int choice)
{
	if(choice == 1)
	{
		//元素数量达到容量上限
		if (SequenceList<Object>::size == SequenceList<Object>::capacity)
		{
			Object* oldArray = SequenceList<Object>::array;
			SequenceList<Object>::capacity = SequenceList<Object>::size * 2;
			SequenceList<Object>::array = new Object[SequenceList<Object>::capacity];
			for (int i = 0; i < SequenceList<Object>::size; i++)
			{
				array[i] = oldArray[i];
			}
		}
	}
	if(choice == 2)
	{
		//元素数量小于容量一定比例
		if (SequenceList<Object>::capacity > SequenceList<Object>::size*4 )
		{
			Object* oldArray = SequenceList<Object>::array;
			SequenceList<Object>::capacity = SequenceList<Object>::capacity /2;
			SequenceList<Object>::array = new Object[SequenceList<Object>::capacity];
			for (int i = 0; i < SequenceList<Object>::size; i++)
			{
				SequenceList<Object>::array[i] = oldArray[i];
			}
		}
	}
}

/*插入元素*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 00时26分
* 最好情况的时间复杂度为O(1)，即在顺序表的开头插入元素，且不用进行扩容；
* 最坏情况的时间复杂度为O(n)，即在顺序表的末尾插入元素；
* 平均情况时间复杂度为O(n)
*/
//在pos前面插入元素
template<class Object>
void SequenceList<Object>::insert(int pos, const Object& data)
{
	SequenceList<Object>::size++;
	//检查是否需要扩容
	SequenceList<Object>::resize(1);
	//将pos后的元素全部后移一个位置
	for (int i = SequenceList<Object>::size - 1; i > pos; i--)
	{
		SequenceList<Object>::array[i] = SequenceList<Object>::array[i - 1];
	}
	SequenceList<Object>::array[pos] = data;
}

/*移除元素*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 12时14分
* 最好情况的时间复杂度为O(1)，即删除位置为n-1时，且此时不用进行缩容的操作；
* 最坏情况的时间复杂度为O(n)，即删除第一个元素；
* 平均情况为O(n)。
*/
//删除pos位置的元素
template<class Object>
void SequenceList<Object>::remove(int pos)
{
	SequenceList<Object>::size--;
	//检查是否需要缩容
	SequenceList<Object>::resize(2);
	//将pos后的元素全部前移一个位置
	for (int i = pos; i < SequenceList<Object>::size; i++)
	{
		SequenceList<Object>::array[i] = SequenceList<Object>::array[i + 1];
	}
}

/*追加元素*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 15时04分
* 该操作的时间复杂度为O(n)，n为元素数量
*/
template<class Object>
void SequenceList<Object>::append(const Object& data)
{
	SequenceList<Object>::size++;
	SequenceList<Object>::resize(1);
	SequenceList<Object>::array[SequenceList<Object>::size - 1] = data;
}

/*遍历元素*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 15时08分
* 时间复杂度为O(n)，n为当前元素的数量
*/
template<class Object>
void SequenceList<Object>::print()
{
	//直接利用循环遍历数组
	for (int i = 0; i < SequenceList<Object>::size; i++)
	{
		cout << SequenceList<Object>::array[i] << endl;
	}
}

/*输出指定元素的位置*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 15时19分
* 时间复杂度最好情况为O(2)，最坏情况为O(n)，平均情况为O(n)，n为元素数量
*/
template<class Object>
int SequenceList<Object>::at(const Object& data) const
{
	for (int i = 0; i < SequenceList<Object>::size; i++)
	{
		if (SequenceList<Object>::array[i] == data)
		{
			return i;
		}
	}
	return -1;
}

/*输出指定位置的元素*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 15时25分
* 时间复杂度为O(1)
*/
template<class Object>
Object& SequenceList<Object>::find(int pos)
{
	if (pos >= 0 && pos < SequenceList<Object>::size)
	{
		return SequenceList<Object>::array[pos];
	}
	else
	{
		cerr << "非法索引值" << endl;
	}
}
template<class Object>
const Object& SequenceList<Object>::find(int pos) const
{
	if (pos >= 0 && pos < SequenceList<Object>::size)
	{
		return SequenceList<Object>::array[pos];
	}
	else
	{
		cerr << "非法索引值" << endl;
		return Object();
	}
}

/*判断顺序表是否为空*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 15时26分
* 时间复杂度为O(1)
*/
template<class Object>
void SequenceList<Object>::isEmpty()
{
	bool is_empty = SequenceList<Object>::size == 0;
	if (is_empty)
	{
		cout << "该顺序表为空" << endl;
	}
	else
	{
		cout << "顺序表不为空" << endl;
	}
}

/*获得顺序表元素数量*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-05 15时28分
* 时间复杂度为O(1)
*/
template<class Object>
int  SequenceList<Object>::length() const
{
	return SequenceList<Object>::size;
}

/*快速排序*/
/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023-10-06 20时47分
*/
template<class Object>
void SequenceList<Object>::quickSort(int left, int right)
{
	if (left < right)
	{
		//选择中间元素分区点
		Object pivot = SequenceList<Object>::array[(left + right) / 2];
		int i = left;
		int j = right;

		//分区操作
		while (i <= j)
		{
			while (SequenceList<Object>::array[i] < pivot)
			{
				i++;
			}
			while (SequenceList<Object>::array[j] > pivot)
			{
				j--;
			}
			if (i <= j)
			{
				swap(SequenceList<Object>::array[i], SequenceList<Object>::array[j]);
				i++;
				j--;
			}
		}
		//递归左右两部分
		if (left < j)
		{
			SequenceList<Object>::quickSort(left, j);
		}
		if (i < right)
		{
			SequenceList<Object>::quickSort(i, right);
		}
	}
}