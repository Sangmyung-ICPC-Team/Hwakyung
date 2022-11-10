#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cout.width(2);
    cout.fill('0');

    int N, F;
    cin >> N >> F;

    int n = N % 100; //N의 가장 뒤 두 자리
    int mod = N % F;

    if (n < mod) {
        cout << (n + F - mod);
    }
    else {
        cout << (n - mod) % F;
    }
    return 0;
}