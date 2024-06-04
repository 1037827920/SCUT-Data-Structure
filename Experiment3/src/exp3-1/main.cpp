#include "MyconsoleEngine.h"
#include"insertsionSort.hpp"
#include"bubbleSort.hpp"
#include"selectionSort.hpp"
#include"mergeSort.hpp"
#include"quickSort.hpp"
#include"heapSort.hpp"
#include"radixSort.hpp"

//随机生成数据序列
void generateData(vector<int>&arr);

//打印数组
void print(vector<int>& arr);

//测试排序有无错误
void test(vector<int>& arr);

int main() {
	vector<int>arr1(100);
	vector<int>arr2(1000);
	vector<int>arr3(10000);

	generateData(arr1);
	test(arr1);
	generateData(arr2);
	generateData(arr3);

	cout << "第一组：";
	print(arr1);

	vector<string>v;
	v.push_back("插入排序");
	v.push_back("冒泡排序");
	v.push_back("选择排序");
	v.push_back("归并排序");
	v.push_back("快速排序");
	v.push_back("堆排序");
	v.push_back("基数排序");
	/*每种排序要各执行三次*/
	//第一组序列
	cout << "-----第一组序列---- - " << endl;
	for (int i = 0; i < 3; i++) {
		cout << "第" << i + 1 << "次" << endl;

		for (int j = 0; j < 7; j++) {
			cout << v[j] << "：";
			vector<int>temp(arr1.begin(), arr1.end());
			switch (j)
			{
			case 0:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				insertsionSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
				break;
			case 1:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				bubbleSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
				break;
			case 2:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				selectionSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
				break;
			case 3:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				mergeSort(temp, 0, temp.size() - 1);
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
				break;
			case 4:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				quickSort(temp, 0, temp.size()-1);
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
				break;
			case 5:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				heapSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
				break;
			case 6:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				radixSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			default:
				break;
			}
		}
	}
	//第二组序列
	cout << "-----第二组序列---- - " << endl;
	for (int i = 0; i < 3; i++) {
		cout << "第" << i + 1 << "次" << endl;

		for (int j = 0; j < 7; j++) {
			cout << v[j] << "：";
			vector<int>temp(arr2.begin(), arr2.end());
			switch (j)
			{
			case 0:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				insertsionSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			break;
			case 1:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				bubbleSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			break;
			case 2:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				selectionSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			break;
			case 3:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				mergeSort(temp, 0, temp.size() - 1);
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			break;
			case 4:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				quickSort(temp, 0, temp.size() - 1);
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			break;
			case 5:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				heapSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			break;
			case 6:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				radixSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			default:
				break;
			}
		}
	}
	//第三组序列
	cout << "-----第三组序列---- - " << endl;
	for (int i = 0; i < 3; i++) {
		cout << "第" << i + 1 << "次" << endl;

		for (int j = 0; j < 7; j++) {
			cout << v[j] << "：";
			vector<int>temp(arr3.begin(), arr3.end());
			switch (j)
			{
			case 0:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				insertsionSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			break;
			case 1:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				bubbleSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			break;
			case 2:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				selectionSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			break;
			case 3:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				mergeSort(temp, 0, temp.size() - 1);
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			break;
			case 4:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				quickSort(temp, 0, temp.size()-1);
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			break;
			case 5:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				heapSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			break;
			case 6:
			{
				auto startTime = std::chrono::high_resolution_clock::now();
				radixSort(temp, temp.size());
				auto endTime = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
				cout << duration.count() << "纳秒" << endl;
			}
			default:
				break;
			}
		}
	}
	

	return 0;
}

/*
* 学号：202230481028
* 姓名：黄铭涛
* 完成时间：2023.11.18 16:07
*/
//随机生成数据序列
void generateData(vector<int>&arr) {
	int min = 0, max = arr.size();
	random_device seed;
	ranlux48 engine(seed());
	uniform_int_distribution<>distrib(min, max);
	int randomValue;

	for (int i = 0; i < arr.size(); i++) {
		randomValue = distrib(engine);
		arr[i] = randomValue;
	}
}
//打印数组
void print(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
//测试排序有无错误
void test(vector<int>& arr) {
	cout << "排序前：";
	print(arr);
	cout << endl;

	vector<int>temp1 = arr;
	cout << "插入排序后：";
	insertsionSort(temp1, temp1.size());
	print(temp1);
	cout << endl;

	vector<int>temp2 = arr;
	cout << "冒泡排序后：";
	bubbleSort(temp2, temp2.size());
	print(temp2);
	cout << endl;

	vector<int>temp3 = arr;
	cout << "选择排序后：";
	selectionSort(temp3, temp3.size());
	print(temp3);
	cout << endl;

	vector<int>temp4 = arr;
	cout << "归并排序后：";
	mergeSort(temp4, 0, temp4.size() - 1);
	print(temp4);
	cout << endl;

	vector<int>temp5 = arr;
	cout << "快速排序后：";
	quickSort(temp5, 0, temp5.size()-1);
	print(temp5);
	cout << endl;

	vector<int>temp6 = arr;
	cout << "堆排序后：";
	heapSort(temp6, temp6.size());
	print(temp6);
	cout << endl;

	vector<int>temp7 = arr;
	cout << "基数排序后：";
	radixSort(temp7, temp7.size());
	print(temp7);
	cout << endl;
}
