#include"MyconsoleEngine.h"

//快速排序
void quickSort(vector<int>& arr, int left, int right) {
	if (left < right) {
		//选择中间元素作为分区点
		int pivot = arr[(left + right) / 2];
		int i = left;
		int j = right;

		//分区操作
		while (i <= j) {
			while (arr[i] < pivot) {
				i++;
			}
			while (arr[j] > pivot) {
				j--;
			}
			if (i <= j) {
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}

		//递归左右两部分
		if (left < j) {
			quickSort(arr, left, j);
		}
		if (i < right) {
			quickSort(arr, i, right);
		}
	}
}