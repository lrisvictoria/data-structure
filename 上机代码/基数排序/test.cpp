#include <iostream>
#include <queue>

using namespace std;

#define K 3
#define RADIX 10

queue<int> q[RADIX];

// value : 278
// k : 0

// 获得数位值
int GetKey(int val, int k)
{
	int key = 0;
	while (k >= 0) {
		key = val % 10;
		val /= 10;
		k--;
	}
	return key;
}

void Distribute(int a[], int l, int r, int k)
{
	// 将数据入到正确下标的队列中
	for (int i = l; i < r; i++) {
		int key = GetKey(a[i], k);
		q[key].push(a[i]);
	}
}

void Collect(int a[])
{
	int cnt = 0;
	for (int i = 0; i < RADIX; i++) {
		// 按照先进先出，出掉每一个队列中的元素
		// 放回原数组中
		while (!q[i].empty()) {
			a[cnt++] = q[i].front();
			q[i].pop();
		}
	}
}

void RadixSort(int a[], int l, int r) // 左闭右开 [left, right)
{
	for (int i = 0; i < K; i++) {
		// 分发数据
		Distribute(a, l, r, i); // i 就是当前数位
		// 回收数据
		Collect(a);
	}
}

int main()
{
	int a[] = { 83, 909, 110, 78, 12, 77, 789, 361, 521, 212 };
	int sz = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < sz; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	RadixSort(a, 0, sz);

	for (int i = 0; i < sz; i++) {
		cout << a[i] << " ";
	}

	return 0;
} 