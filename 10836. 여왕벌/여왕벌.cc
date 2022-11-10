#include <iostream>
using namespace std;

#define max(a, b) ((a)>(b)?(a):(b))
int hive[700][700];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> m >> n;

	int t = m;
	int a;
	for (int i = 0; i < n + 1; i++) {
		t = m;
		if (i == 0) {
			for (int j = 0; j < 2 * m - 1; j++) {
				if (--t > 0) {
					hive[t][0] += 1;
				}
				else {
					hive[0][-t] += 1;
				}
			}
		}
		else {
			for (int j = 0; j < 3; j++) {
				cin >> a;
				switch (j) {
				case 0:
					t -= a;
					break;
				case 1:
				case 2:
					for (int k = 0; k < a; k++) {
						if (--t > 0) {
							hive[t][0] += j;
						}
						else {
							hive[0][-t] += j;
						}
					}
					break;
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
        cout << hive[i][0] << " ";
		for (int j = 1; j < m; j++) {
			cout << hive[0][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}