#include <iostream>
using namespace std;

#define min(a, b) ((a)<(b)?(a):(b))

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string chess[8];

    int cnt = 0;

    for (int i = 0; i < 8; i++) {
        cin >> chess[i];
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            if (i % 2 == 0) {
                if (chess[i][j * 2] == 'F') cnt++;
            }
            else {
                if (chess[i][j * 2 + 1] == 'F') cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}