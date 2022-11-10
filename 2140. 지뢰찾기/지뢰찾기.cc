#include <iostream>
using namespace std;

char map[100][100];

int main() {

	int N;
	cin >> N;

	int safe = 0;
	int dx[] = { -1, 0, 1 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	if (N == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		int mine = map[0][i] - '0';
		for (int j = 0; j < 3; j++) {
			if (i + dx[j] > 0 && i + dx[j] < N - 1) {
				if (map[1][(i + dx[j])] == '#') {
					if (mine == 0) {
						map[1][i + dx[j]] = 'x';
						safe++;
					}
					else {
						map[1][(i + dx[j])] = '*';
						mine--;
					}
				}
				else if (map[1][i + dx[j]] == '*') {
					mine--;
				}
			}
		}
	}

	for (int i = 1; i < N - 1; i++) {
		int mine = map[i][0] - '0';
		for (int j = 0; j < 3; j++) {
			if (i + dx[j] > 0 && i + dx[j] < N - 1) {

				if (map[i + dx[j]][1] == '#') {
					if (mine == 0) {
						map[i + dx[j]][1] = 'x';
						safe++;
					}
					else {
						map[i + dx[j]][1] = '*';
						mine--;
					}
				}
				else if (map[i + dx[j]][1] == '*') {
					mine--;
				}
			}
		}
	}

	for (int i = 1; i < N - 1; i++) {
		int mine = map[N - 1][i] - '0';
		for (int j = 0; j < 3; j++) {
			if (i + dx[j] > 0 && i + dx[j] < N - 1) {
				if (map[N - 2][i + dx[j]] == '#') {
					if (mine == 0) {
						map[N - 2][i + dx[j]] = 'x';
						safe++;
					}
					else {
						map[N - 2][i + dx[j]] = '*';
						mine--;
					}
				}
				else if (map[N - 2][i + dx[j]] == '*') {
					mine--;
				}
			}
		}
	}

	for (int i = 1; i < N - 1; i++) {
		int mine = map[i][N - 1] - '0';
		for (int j = 0; j < 3; j++) {
			if (i + dx[j] > 0 && i + dx[j] < N - 1) {
				
				if (map[i + dx[j]][N - 2] == '#') {
					if (mine == 0) {
						map[i + dx[j]][N - 2] = 'x';
						safe++;
					}
					else {
						map[i + dx[j]][N - 2] = '*';
						mine--;
					}
				}
				else if (map[i + dx[j]][N - 2] == '*') {
					mine--;
				}
			}
		}
	}

	cout << (N - 2) * (N - 2) - safe << "\n";

	return 0;
}