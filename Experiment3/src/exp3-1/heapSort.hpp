#include"MyconsoleEngine.h"

//堆排序
void maxHeapify(vector<int>& arr, int start, int end) {
	//父结点和子结点指针
	int parent = start;
	int son = parent * 2 + 1;
	//若子结点指针在范围内才做比较
	while (son <= end) {
		//先比较两个子结点，选择最大的
		if (son + 1 <= end && arr[son] < arr[son + 1]) {
			son++;
		}
		//如果父结点大于子结点代表调整完毕，直接跳出函数
		if (arr[parent] > arr[son]) {
			return;
		}
		else {
			swap(arr[parent], arr[son]);
			parent = son;
			son = parent * 2 + 1;
		}
	}
}
void heapSort(vector<int>& arr, int len) {
	//初始化，从最后一个父结点开始调整
	for (int i = len / 2 - 1; i >= 0; i--) {
		maxHeapify(arr, i, len - 1);
	}

	//先将第一个元素和最后一个元素交换，再进行一次平衡操作
	for (int i = len - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		maxHeapify(arr, 0, i - 1);
	}
}