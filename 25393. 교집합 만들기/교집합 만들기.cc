#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))

int L[10000001];
int R[10000001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	fill(L, L + 10000001, -1);
	fill(R, R + 10000001, 10000001);

	int N, Q;
	int ans = -1;

	int l = 0, r = 0;
	set<pair<int, int>> ns;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> l >> r;
		ns.insert({ l, r });

		L[l] = max(L[l], r);
		R[r] = min(R[r], l);
	}

	cin >> Q;

	for (int i = 0; i < Q; i++) {
		ans = -1;
		cin >> l >> r;
		if (L[l] != -1 && R[r] != 10000001) {
			if (ns.count({ l, r }) == 1) {
				ans = 1;
			}
			else {
				if (L[l] > r && R[r] < l) {
					ans = 2;
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}