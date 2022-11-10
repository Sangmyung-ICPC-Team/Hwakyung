#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	int arr[8];
	int pre[8];
	int count = 0, sum = 0, result = 0;

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}

	sort(arr, arr + N);

	do {
		count = 0;

		pre[0] = arr[0];
		for (int i = 1; i < N; i++) {
			pre[i] = pre[i - 1] + arr[i];
		}

		for (int i = N - 1; i > 0; i--) {
			for (int j = i - 1; j >= 0; j--) {
				if (pre[i] - pre[j] == 50) {
					count++;
				}
				else if (pre[i] - pre[j] > 50) {
					break;
				}
			}
			result = max(result, count);
		}
	} while (next_permutation(&arr[0], &arr[N - 1]));

	cout << result;

	return 0;
}