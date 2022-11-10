#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	int n, t, s;
	cin >> n;

	vector<pair<int, int>> tasks;

	for (int i = 0; i < n; i++) {
		cin >> t >> s;
		tasks.push_back(make_pair(t, s));
	}

	sort(tasks.begin(), tasks.end(), cmp);

	int m = 1000001;
	for (int i = 0; i < n; i++) {
		if (tasks[i].second > m) {
			m -= tasks[i].first;
		}
		else {
			m = tasks[i].second - tasks[i].first;
		}
	}
	if (m < 0) cout << -1;
	else cout << m;

	return 0;
}