#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int dp[1001][1001] = { 0, };

int main() {
	int N, M, rx = 0, ry = 0, cmax = -1;
	cin >> N >> M;

	char** island;
	island = new char* [N];
	for (int i = 0; i < N; i++) {
		island[i] = new char[M];
		for (int j = 0; j < M; j++) {
			cin >> island[i][j];
			if (island[i][j] == 'R') {
				rx = j;
				ry = i;
			}
	    }
	}

	for (int j = rx + 1; j < M; j++) {
		for (int i = 0; i < N; i++) {
			//R에서부터 시작한 유효한 위치인지 확인. 유효하지 않으면 벽으로 처리해줌
			if (rx + abs(ry - i) > j) {
				dp[i][j] = -1;
				continue;
			}

			//현재 지점이 벽이면 스킵
			if (island[i][j] == '#') {
				dp[i][j] = -1;
				continue;
			}

			//세방향에 벽이 있는지 확인하고 아니라면 최대값 찾기(첫행과 마지막행은 위쪽, 아래쪽에서 올 수 없음)
			if(i == 0){
				if (dp[i][j - 1] == -1 && dp[i + 1][j - 1] == -1) {
					dp[i][j] = -1;
					continue;
				}
				int temp = max(dp[i][j - 1], dp[i + 1][j - 1]);
				if (island[i][j] == 'C') {
					dp[i][j] = temp + 1;
				}
				else {
					dp[i][j] = temp;
					if (island[i][j] == 'O') cmax = max(dp[i][j], cmax);
				}
			}
			else if(i == N - 1){
				if (dp[i - 1][j - 1] == -1 && dp[i][j - 1] == -1) {
					dp[i][j] = -1;
					continue;
				}
				int temp = max(dp[i][j - 1], dp[i - 1][j - 1]);
				if (island[i][j] == 'C') {
					dp[i][j] = temp + 1;
				}
				else {
					dp[i][j] = temp;
					if (island[i][j] == 'O') cmax = max(dp[i][j], cmax);
				}
			}
			else {
				if (dp[i - 1][j - 1] == -1 && dp[i][j - 1] == -1 && dp[i + 1][j - 1] == -1) {
					dp[i][j] = -1;
					continue;
				}
				int temp = max(dp[i - 1][j - 1], dp[i][j - 1]);
				temp = max(dp[i + 1][j - 1], temp);
				if (island[i][j] == 'C') {
					dp[i][j] = temp + 1;
				}
				else {
					dp[i][j] = temp;
					if (island[i][j] == 'O') cmax = max(dp[i][j], cmax);
				}
			}
		}
	}
    
	cout << cmax;

	return 0;
}
