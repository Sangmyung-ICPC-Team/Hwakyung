#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct resistor {
    string color;
    int value;
    int mul;
};

resistor find_color(resistor* first, resistor* last, string color) {
    for (; first != last; ++first) {
        if (first->color == color) {
            return *first;
        }
    }
    return *last;
}

int main() {

    string colors [] = {
        "black", "brown", "red", "orange", "yellow", 
        "green", "blue", "violet", "grey", "white"
    };
    
    resistor resistors[10];
    
    for (int i = 0; i < 10; i++) {
        resistors[i] = { colors[i], i, (int)pow(10, i) };
    }

    string s1, s2, s3;
    
    cin >> s1 >> s2 >> s3;

    resistor r1 = find_color(resistors, resistors + 10, s1);
    resistor r2 = find_color(resistors, resistors + 10, s2);
    resistor r3 = find_color(resistors, resistors + 10, s3);

    printf("%lld", (long long)(r1.value * 10 + r2.value) * r3.mul);

    return 0;
}