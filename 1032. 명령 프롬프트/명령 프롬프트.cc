#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    string str[50];

    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }

    for (int i = 0; i < str[0].length(); i++) {
        char tmp = str[0][i];
        for (int j = 1; j < N; j++) {
            if (tmp != str[j][i]) {
                tmp = '?';
                break;
            }
        }
        cout << tmp;
    }

    return 0;
}