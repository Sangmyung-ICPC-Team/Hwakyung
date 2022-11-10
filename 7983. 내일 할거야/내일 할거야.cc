#include <iostream>
#include <algorithm>
using namespace std;


struct Task {
	int d;
	int t;
};

bool cmp(Task& p1, Task& p2) {
	return p1.t > p2.t;
}

int main() {
	int n;

	cin >> n;

	Task* tasks;
	tasks = new Task[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &(tasks[i].d));
		scanf("%d", &(tasks[i].t));
	}
	sort(tasks, tasks + n, cmp);

	int result = tasks[0].t;

	for (int i = 0; i < n; i++) {
		if (result > tasks[i].t) result = tasks[i].t;
		result -= tasks[i].d;
	}

	printf("%d", result);

	return 0;
}