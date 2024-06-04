#include"MyconsoleEngine.h"

//冒泡排序
void bubbleSort(vector<int>& arr, int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}