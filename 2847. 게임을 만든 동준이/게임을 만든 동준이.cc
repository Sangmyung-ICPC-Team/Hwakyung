#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int t = arr[n - 1];
	int ans = 0;
	for (int i = n - 2; i > -1; i--) {
		if (arr[i] >= t) {
			ans += arr[i] - t + 1;
			t = t - 1;
		}
		else {
			t = arr[i];
		}
	}

	cout << ans;

	return 0;
}