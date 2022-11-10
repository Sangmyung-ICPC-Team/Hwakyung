#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int arr[50];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    if (N == 1) {
        cout << arr[0] * arr[0] << "\n";
    }
    else {
        sort(arr, arr + N);
        cout << arr[0] * arr[N - 1] << "\n";
    }

    return 0;
}