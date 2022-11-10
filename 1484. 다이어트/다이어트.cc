#include <iostream>
using namespace std;

int main() {
	int G = 0;
	bool ans = true;
	int a = 2, b = 1;
	int tmp = 0;

	cin >> G;

	while (a != b) {
		tmp = a * a - b * b;
		if (tmp == G) {
			cout << a << "\n";
			a++;
			ans = false;
		}
		else if (tmp > G) {
			b++;
		}
		else if (tmp < G) {
			a++;
		}
	}

	if (ans) {
		cout << -1;
	}

}