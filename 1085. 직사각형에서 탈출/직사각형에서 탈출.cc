#include <iostream>
using namespace std;

#define min(a, b) ((a)<(b)?(a):(b))

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int x, y, w, h;

    cin >> x >> y >> w >> h;

    int ans = 1000;

    ans = min(ans, x);
    ans = min(ans, y);
    ans = min(ans, w - x);
    ans = min(ans, h - y);

    cout << ans;

    return 0;
}