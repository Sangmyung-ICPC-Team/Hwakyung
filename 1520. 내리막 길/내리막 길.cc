#include <iostream>
using namespace std;

int M, N;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int map[500][500];	//[M][N]
int dp[500][500];

int dfs(int x, int y) {
	if (x == N - 1 && y == M - 1) return 1;

	if (dp[y][x] == -1) {
		dp[y][x] = 0;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (map[ny][nx] < map[y][x]) {
					dp[y][x] += dfs(nx, ny);
				}
			}
		}
	}

	return dp[y][x];
}

int main() {

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	int ans = dfs(0, 0);

	cout << ans;

	return 0;
}