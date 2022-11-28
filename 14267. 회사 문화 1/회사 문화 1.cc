#include <iostream>
using namespace std;

int im[100001];	//직속상사정보
int dp[100001];

int main() {

	int n, m;
	cin >> n >> m;

	int j;
	int b;	//직속상사번호
	for (j = 1; j <= n; j++) {
		cin >> b;
		if (b == -1) continue;
		im[j] = b;
	}

	int i, w; //직원번호, 칭찬수치
	for (j = 0; j < m; j++) {
		cin >> i >> w;
		dp[i] += w;
	}

	for (j = 1; j <= n; j++) {
		dp[j] += dp[im[j]];
		cout << dp[j] << " ";
	}


	return 0;
}