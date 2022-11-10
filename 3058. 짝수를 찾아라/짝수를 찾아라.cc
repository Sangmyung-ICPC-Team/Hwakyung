#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, s = 0, m = 101;
	cin >> t;

	int arr[7];
	while (t--)
	{
		s = 0; m = 101;

		for (int i = 0; i < 7; i++) {
			cin >> arr[i];
			if (arr[i] % 2 == 0) {
				s += arr[i];
				m = min(m, arr[i]);
			}
		}

		cout << s << " " << m << "\n";
	}

	return 0;
}