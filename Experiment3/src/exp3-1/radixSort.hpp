#include"MyconsoleEngine.h"

//基数排序
//辅助函数，求数据的最大位数
int maxBit(vector<int>& arr, int len) {
	//最大数
	int maxData = arr[0];
	for (int i = 1; i < len; i++) {
		if (maxData < arr[i]) {
			maxData = arr[i];
		}
	}

	int d = 1;
	int p = 10;
	while (maxData >= p) {
		maxData /= 10;
		d++;
	}

	return d;
}
void radixSort(vector<int>& arr, int len) {
	int d = maxBit(arr, len);
	vector<int>temp(len);
	vector<int>count(10);
	int i, j, k;
	int radix = 1;

	//进行d次排序
	for (int i = 1; i <= d; i++) {
		//每次分配前清空计数器
		for (j = 0; j < 10; j++)
			count[j] = 0;
		//统计每个桶中的记录数
		for (j = 0; j < len; j++) {
			k = (arr[j] / radix) % 10;
			count[k]++;
		}
		//将temp中位置依次分配给每个桶
		for (j = 1; j < 10; j++) {
			count[j] += count[j - 1];
		}
		for (j = len - 1; j >= 0; j--) {
			k = (arr[j] / radix) % 10;
			temp[count[k] - 1] = arr[j];
			count[k]--;
		}
		for (j = 0; j < len; j++) {
			arr[j] = temp[j];
		}
		radix = radix * 10;
	}
}