#include"MyconsoleEngine.h"

//选择排序
void selectionSort(vector<int>& arr, int length) {
	for (int i = 0; i < length - 1; i++) {
		int min = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(arr[min], arr[i]);
	}
}