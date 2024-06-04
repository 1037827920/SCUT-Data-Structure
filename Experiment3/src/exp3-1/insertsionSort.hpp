#include"MyconsoleEngine.h"

//插入排序
void insertsionSort(vector<int>& arr, int length) {
	for (int i = 1; i < length; i++) {
		int key = arr[i];
		int j = i - 1;
		while ((j >= 0) && (key < arr[j])) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}