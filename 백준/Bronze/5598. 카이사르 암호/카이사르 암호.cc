#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int value;
    string input;
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        value = int(input[i]) - 3;
        if (value < 65) value += 26;

        cout << char(value);
    }
}