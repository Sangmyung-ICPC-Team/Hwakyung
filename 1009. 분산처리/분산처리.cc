#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int t, a, b, ans = 1;

	cin >> t; 
	
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		ans = 1;

		for (int j = 0; j < b; j++) {
			ans *= a;
			ans %= 10;
		}
		if (ans) {
			cout << ans << "\n";
		}
		else {
			cout << 10 << "\n";
		}
	}

	return 0;
}