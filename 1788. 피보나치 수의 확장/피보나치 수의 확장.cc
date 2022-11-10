#include <iostream>
#include <algorithm>
using namespace std;

int fibo[1000001];

int main() {
	int n;
	cin >> n;

	if (n > 0) {
		fibo[0] = 0;
		fibo[1] = 1;
		for (int i = 2; i <= n; i++) {
			fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000000;
		}
	}
	else {
		fibo[0] = 1;
		fibo[1] = 0;
		n = -n + 1;
		for (int i = 2; i <= n; i++) {
			fibo[i] = (fibo[i - 2] - fibo[i - 1]) % 1000000000;
		}
	}

	if (fibo[n] > 0) {
		cout << 1 << "\n" << fibo[n];
	}
	else if (fibo[n] == 0) {
		cout << 0 << "\n" << 0;
	}
	else {
		cout << -1 << "\n" << (-fibo[n]);
	}

	return 0;
}