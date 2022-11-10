#include <iostream>
#include <set>
using namespace std;

int main() {

	int A, B;
	set<int> a, b;

	cin >> A >> B;

	int tmp;

	for (int i = 0; i < A; i++) {
		cin >> tmp;
		a.insert(tmp);
	}

	for (int i = 0; i < B; i++) {
		cin >> tmp;
		b.insert(tmp);
	}

	for (auto it = a.begin(); it != a.end();) {
		tmp = *it;
		if (b.count(*it)) {
			it++;
			a.erase(tmp);
		}
		else {
			it++;
		}
	}

	cout << a.size() << "\n";
	for (auto it = a.begin(); it != a.end(); it++) {
		cout << *it << " ";
	}


	return 0;
}