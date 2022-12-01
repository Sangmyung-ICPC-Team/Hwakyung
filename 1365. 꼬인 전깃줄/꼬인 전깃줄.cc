#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> v, int t) {
	int left = 0, right = v.size();
	while (left <= right) {
		int mid = (left + right) / 2;
		if (v[mid] >= t) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	
	return left;
}

int main() {

	int n, i;
	cin >> n;

	vector<int> linked, lis;

	int pole;
	for (i = 0; i < n; i++) {
		cin >> pole;
		linked.push_back(pole);
	}

	lis.push_back(linked[0]);
	for (i = 1; i < n; i++) {
		if (lis.back() < linked[i]) {
			lis.push_back(linked[i]);
		}
		else {
			int num = binary_search(lis, linked[i]);
			lis[num] = linked[i];
		}
	}

	cout << n - lis.size();

	return 0;
}