#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int N, M, S;
	int C = 0;
	string L, id;
	int s = 0;
	
	cin >> N >> M >> S;

	queue<pair<int, int>> alpa[26];

	char tmp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			alpa[tmp - 97].push(make_pair(i, j));
		}
	}
	cin >> id;

	pair <int, int> start = make_pair(0, 0);
	pair <int, int> exit = make_pair(N - 1, M - 1);
	bool stop = true;
	while (stop) {
		string s;
		pair<int, int> m = start;
		for (int i = 0; i < S; i++) {
			if (!alpa[id[i] - 97].empty()) {
				int j;
				pair <int, int> p = alpa[id[i] - 97].front();
				alpa[id[i] - 97].pop();
				if (p.first > start.first) {
					for (j = 0; j < p.first - start.first; j++) {
						s.append("D");
					}
				}
				else if (p.first < start.first) {
					for (j = 0; j < start.first - p.first; j++) {
						s.append("U");
					}
				}

				if (p.second > start.second) {
					for (j = 0; j < p.second - start.second; j++) {
						s.append("R");
					}
				}
				else if (p.second < start.second) {
					for (j = 0; j < start.second - p.second; j++) {
						s.append("L");
					}
				}
				s.append("P");
				start = p;
			}
			else {
				int j;
				s = "";
				if (exit.first > m.first) {
					for (j = 0; j < exit.first - m.first; j++) {
						s.append("D");
					}
				}
				else if (exit.first < m.first) {
					for (j = 0; j < m.first - exit.first; j++) {
						s.append("U");
					}
				}

				if (exit.second > m.second) {
					for (j = 0; j < exit.second - m.second; j++) {
						s.append("R");
					}
				}
				else if (exit.second < m.second) {
					for (j = 0; j < m.second - exit.second; j++) {
						s.append("L");
					}
				}
				stop = false;
				C--;
				break;
			}
		}
		L.append(s);
		C++;
	}

	printf("%d %d\n%s", C, L.length(), L.c_str());
	return 0;
}