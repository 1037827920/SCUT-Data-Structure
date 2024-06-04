#include"MyconsoleEngine.h"

//归并排序
void merge(vector<int>& arr, int front, int mid, int end) {
	vector<int>leftSubArr(arr.begin() + front, arr.begin() + mid + 1);
	vector<int>rightSubArr(arr.begin() + mid + 1, arr.begin() + end + 1);
	int indexLeft = 0, indexRight = 0;

	leftSubArr.insert(leftSubArr.end(), numeric_limits<int>::max());
	rightSubArr.insert(rightSubArr.end(), numeric_limits<int>::max());

	for (int i = front; i <= end; i++) {
		if (leftSubArr[indexLeft] < rightSubArr[indexRight]) {
			arr[i] = leftSubArr[indexLeft];
			indexLeft++;
		}
		else {
			arr[i] = rightSubArr[indexRight];
			indexRight++;
		}
	}
}
void mergeSort(vector<int>& arr, int front, int end) {
	if (front >= end) {
		return;
	}
	int mid = (front + end) / 2;
	mergeSort(arr, front, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, front, mid, end);
}