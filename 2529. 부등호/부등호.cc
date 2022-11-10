#include <iostream>
#include <algorithm>
using namespace std;

int k;
char sign[9];
bool visited[10];
string str;
string ans_min = "9999999999";
string ans_max = "0000000000";

bool check(int a, int b, int v) {
	if (sign[v] == '<') {
		return a < b;
	}
	else if(sign[v] == '>') {
		return a > b;
	}
	return false;
}

void solve() {
	if (str.size() == k + 1) {
		ans_min = min(ans_min, str);
		ans_max = max(ans_max, str);
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (str.empty() || !visited[i] && check(str.back() - '0', i, str.size() - 1)) {
				visited[i] = true;
				str.push_back(i + '0');
				
				solve();

				visited[i] = false;
				str.pop_back();
			}
		}
	}
}

int main() {
	
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> sign[i];
	}

	solve();

	cout << ans_max << "\n";
	cout << ans_min;

	return 0;

}