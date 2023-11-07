#include <bits/stdc++.h>
using namespace std;

int main() {
    int value, max = 0, index = -1;
    for (int i = 1; i <= 9; i++) {
        cin >> value;
        if (value > max) {
            max = value;
            index = i;
        }
    }

    cout << max << '\n' << index;
}