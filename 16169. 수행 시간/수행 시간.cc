#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Computer {
	int t; //동작속도
	int i; //위치
};

vector<Computer> arr[101];
vector<Computer> dp[101];

int main() {
	int n, c, t, ans = 0;
	cin >> n;

	arr[0].push_back({ 0, 0 });
	dp[0].push_back({ 0, 0 });

	for (int i = 1; i < n + 1; i++) {
		cin >> c >> t;
		arr[c].push_back({ t, i });
		if (c == 1) {
			dp[1].push_back({ t, i });
			ans = max(ans, t);
		};
	}


	for (int i = 2; !arr[i].empty(); i++) {
		for (Computer j : arr[i]) {
			int t_max = 0;
			for (Computer k : dp[i - 1]) {
				int dist = (j.i - k.i) * (j.i - k.i);
				t_max = max(t_max, k.t + dist + j.t);
			}
			dp[i].push_back({ t_max, j.i });
			ans = max(ans, t_max);
		}
	}

	cout << ans;

	return 0;

}