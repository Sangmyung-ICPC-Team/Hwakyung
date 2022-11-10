#include <iostream>
#include <stack>
using namespace std;

struct Tower {
	int height;
	int pos;
};

int main() {
	int n = 0;
	cin >> n;

	Tower* towers = new Tower[n];
	stack<Tower> s;

	for (int i = 0; i < n; i++) {
		cin >> towers[i].height;
		towers[i].pos = i + 1;
	}

	for (int i = 0; i < n; i++) {
		while (s.empty() == false) {
			if (s.top().height < towers[i].height) {
				s.pop();
			}
			else {
				cout << s.top().pos << " ";
				break;
			}
		}

		if (s.empty() == true) {
			cout << 0 << " ";
		}

		s.push(towers[i]);
	}
	return 0;
}