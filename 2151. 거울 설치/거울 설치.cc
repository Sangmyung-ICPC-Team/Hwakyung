#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Pos {
	int x;
	int y;
	int dir;
};

char map[50][50];
int check[50][50][4];

int main() {

	int N = 0;
	cin >> N;

	int doorX1 = 0, doorY1 = 0, doorX2 = 0, doorY2 = 0;	//두 문의 x, y 좌표

	int ans = INT_MAX;

	queue <Pos> Q;

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	bool first = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				if (first) {
					doorX1 = j;
					doorY1 = i;
					first = false;
					map[i][j] = '*';
				}
				else {
					doorX2 = j;
					doorY2 = i;
				}
			}

			for (int k = 0; k < 4; k++) {
				check[i][j][k] = INT_MAX;
			}
		}
	}

	Pos tmp;
	for (int i = 0; i < 4; i++) {
		int nx = doorX1 + dx[i];
		int ny = doorY1 + dy[i];
		if (nx > -1 && ny > -1 && nx < N && ny < N && map[ny][nx] != '*') {
			tmp.x = doorX1;
			tmp.y = doorY1;
			tmp.dir = i;
			check[doorY1][doorX1][i] = 0;
			Q.push(tmp);
		}
	}

	while (!Q.empty()) {
		tmp = Q.front();
		Q.pop();
		int cx = tmp.x;
		int cy = tmp.y;
		int cdir = tmp.dir;

		int nx = cx + dx[tmp.dir];
		int ny = cy + dy[tmp.dir];

		tmp.x = nx;
		tmp.y = ny;

		if (nx > -1 && ny > -1 && nx < N && ny < N && map[ny][nx] != '*') {
			if (map[ny][nx] == '#') {
				ans = min(ans, check[cy][cx][cdir]);
			}
			else if (map[ny][nx] == '.') {
				if (check[ny][nx][cdir] > check[cy][cx][cdir]) {
					check[ny][nx][cdir] = check[cy][cx][cdir];
					Q.push(tmp);
				}
			}
			else if (map[ny][nx] == '!') {
				if (check[ny][nx][cdir] > check[cy][cx][cdir]) {
					check[ny][nx][cdir] = check[cy][cx][cdir];
					Q.push(tmp);
				}
				
				int ndir = (cdir + 1) % 4;
				if (check[ny][nx][ndir] > check[cy][cx][cdir] + 1) {
					check[ny][nx][ndir] = check[cy][cx][cdir] + 1;
					tmp.dir = ndir;
					Q.push(tmp);
				}
				ndir = (cdir + 3) % 4;
				if (check[ny][nx][ndir] > check[cy][cx][cdir] + 1) {
					check[ny][nx][ndir] = check[cy][cx][cdir] + 1;
					tmp.dir = ndir;
					Q.push(tmp);
				}
			}
		}
	}

	cout << ans;

	return 0;
}