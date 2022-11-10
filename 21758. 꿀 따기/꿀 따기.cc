#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int* arr;
	int* pre;
	int result = 0;

	cin >> N;
	arr = new int[N];
	pre = new int[N];

	cin >> arr[0];
	pre[0] = arr[0];
	for (int i = 1; i < N; i++) {
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	}

	for (int i = 1; i < N; i++) {
		result = max(pre[N - 1] - pre[i] + pre[N - 1] - pre[0] - arr[i], result);
	}

	for (int i = 1; i < N - 1; i++) {
		result = max(pre[i] - pre[0] + pre[N - 2] - pre[i - 1], result);
	}

	for (int i = 1; i < N - 1; i++) {
		result = max(pre[i-1] + pre[N-2] - arr[i], result);
	}

	cout << result;

	return 0;
}