#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> visited;
vector<int>* grahp;
bool isPossible = true;

void dfs(int i) {
	for (int n : grahp[i]) {
		if (visited[n] == 0) {
			visited[n] = 3 - visited[i];
			dfs(n);
		}

		if (visited[i] == visited[n]) {
			isPossible = false;
		}
	}
}

int main() {
	int t, n, m, v, e;
	cin >> t;

	while (t > 0) {
		cin >> n >> m;

		grahp = new vector<int>[n + 1];
		visited = vector<int>(n + 1);
		isPossible = true;

		for (int i = 0; i < m; i++) {
			cin >> e >> v;
			grahp[e].push_back(v);
			grahp[v].push_back(e);
		}
		
		for (int i = 1; i < n + 1; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				dfs(i);
			}
		}

		if (isPossible) cout << "possible\n";
		else cout << "impossible\n";

		t--;
	}

	return 0;
}
