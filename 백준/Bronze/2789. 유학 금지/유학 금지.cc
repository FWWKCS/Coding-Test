#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set<char> sensor = {'C','A','M','B','R','I','D','G','E'};
    string input; cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (sensor.find(input[i]) != sensor.end()) input[i] = ' ';
    }

    for (int i = 0; i < input.length(); i++) {
        if (input[i] != ' ') cout << input[i];
    }
}