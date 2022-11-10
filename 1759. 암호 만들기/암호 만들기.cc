#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;
vector<char> str;
vector<char> passward;
int vowel, constonse;

void dfs(int pre) {
    if (passward.size() == L) {
        if (vowel > 0 && constonse > 1) {
            for (int i = 0; i < L; i++) {
                cout << passward[i];
            }
            cout << "\n";
        }
 
        return;
    }
    
    for (int i = pre; i < C; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') vowel++;
        else constonse++;

        passward.push_back(str[i]);
        dfs(i + 1);

        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') vowel--;
        else constonse--;

        passward.pop_back();
    }
}

int main() {
    cin >> L >> C;

    char tmp;
    for (int i = 0; i < C; i++) {
        cin >> tmp;
        str.push_back(tmp);
    }

    sort(str.begin(), str.end());
    
    dfs(0);
    
    return 0;
}